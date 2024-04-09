import sys
import piarm
from eww_robo import *
from eww_robo_misc import *
import logging
import time
import json
from threading import Thread
from threading import Lock
from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
import serial
import wbz_serial
import boto3
#from mpio import Input
from mpio import GPIO
from mpio import LED
from flask import Flask, render_template, Response 

#import random

robo_topic = "/WSG_Apps/EW_DEMO/Robo2"
webserver_topic = "/WSG_Apps/EW_DEMO/Server2"

roboLock = Lock()
onoffLock = Lock()
imageUploadLock = Lock()
mqttPublishLock = Lock()
wbzLock = Lock()

ntp_servers = ['de.pool.ntp.org',
              'pool.ntp.org',
              '0.de.pool.ntp.org'
              '1.de.pool.ntp.org',
              '2.de.pool.ntp.org',
              '3.de.pool.ntp.org',
              '0.europe.pool.ntp.org',
              '1.europe.pool.ntp.org',
              '2.europe.pool.ntp.org',
              '3.europe.pool.ntp.org',
              '0.uk.pool.ntp.org',
              '0.in.pool.ntp.org']


#PATTERN_4P= [['A1', 'B2'],['A2', 'B3'],['A3', 'C2'],['A4', 'C3'],
#             ['B2', 'C1'],['B3', 'C4'],
#             ['C1', 'B1'],['C2', 'A2'],['C3', 'B3'],['C4', 'A4'],
#             ['B1', 'A1'],['B3', 'A3']
#            ]


PATTERN_4P= [ ['A1','C3'], ['A3','C1'],
              ['C3','A1'], ['C1','A3']
            ]



robo_motor_data = {
	"Motor_Voltage" : {
	"AXIS_2_MOTOR_ID": 0.0,
        "AXIS_3_MOTOR_ID": 0.0,
        "AXIS_4_MOTOR_ID": 0.0,
        "AXIS_5_MOTOR_ID": 0.0,
        "BASE_MOTOR_ID": 0.0,
        "PICK_DROP_MOTOR_ID": 0.0
	},
	"Motor_Temperature" : {
        "AXIS_2_MOTOR_ID": 0,
        "AXIS_3_MOTOR_ID": 0,
        "AXIS_4_MOTOR_ID": 0,
        "AXIS_5_MOTOR_ID": 0,
        "BASE_MOTOR_ID": 0,
        "PICK_DROP_MOTOR_ID": 0,
        "ROOM_TEMPERATURE_1_ID": 0
	},
        
}
robo_network_parameter = {"sta_ip":{'ip':''}}
camera = {'image_update': {'request':0,'status':0, 'robopic':0}}
robo_msg = {"ROBO_MESSAGE": {"msg": "INITIALIZED ALL PARAMETERS"}}
webserver_onoff = {
    "ROBO_ONOFF":{"OnOffStatus": 0, "image_update":0, "time":0}
    }

peg_status = {
           #"Robo_Pattern":{"A1":1,"A2":1,"A3":1,"A4":1,"B1":0,"B2":0,"B3":0,"B4":0,"C1":0,"C2":0,"C3":0,"C4":0,"D1":0,"D2":0,"D3":0,"D4":0}
           "Robo_Pattern":{"A1":1,"A2":0,"A3":1,"A4":0,"B1":0,"B2":0,"B3":0,"B4":0,"C1":0,"C2":0,"C3":0,"C4":0,"D1":0,"D2":0,"D3":0,"D4":0}
           }

wbz_commad = {
    "Bind":b"invokeCommissioning 8 0\r\n",
    "Temperature":b"readAttribute -b 0 22 0x0402 0\r\n",
    "ArmOrientation":b"readAttribute -b 0 0x30 0xfc00 0\r\n",
    "ArmMovement":b"readAttribute -b 0 0x30 0xfc00 1\r\n",
    "ArmReadAllCC":b"readAttributeMultiple -b 0 0x30 0xfc00 0 2\r\n",
}

# wbz_data = {
    # "ArmOrientation":None,
    # "ArmMovement":None,
    # "Temperature":None,
# } 
# def extract_json_data(input_string):
    # parsed_json = None
    # incomplete_string = b''
    # try:
    #    Find the start and end indices of the JSON string
        # start_index = input_string.find('{')
        # end_index = input_string.rfind('}')
        # if(len(input_string) == 0):
            # parsed_json = None
            # incomplete_string = b''
        # elif ((start_index != -1) and (end_index != -1)):
            # json_string = input_string[start_index:end_index + 1]
            # if(len(input_string) >  end_index + 1):
                # incomplete_string = input_string[end_index + 1: ]
            # parsed_json = json.loads(json_string)
        # elif start_index != -1 and end_index == -1:
            # incomplete_string = input_string[start_index:]
        # elif start_index == -1:
            # incomplete_string = input_string
    # except json.JSONDecodeError as e:
        # parsed_json = None
        # print(e)
        # pass
    # finally:
        # return (parsed_json, incomplete_string)

def wbz_read_ArmData(wbz_scom):
    with wbzLock:
        wbz_arm_data = {
            "ArmOrientation":-1,
            "ArmMovement":-1,
        }
        sleep_internal = 0.1
        cnt = wbz_scom.write_data(wbz_commad["ArmReadAllCC"])
        print("wbz arm tx cnt", cnt)
        for i in range(1,200):
            time.sleep(0.1)
            wData = wbz_scom.get_read_data()
            if wData != None:
                break
        print(wData)
        if wData != None:
            try:
                if wData['Read attribute response'] == 'success':
                    for aData in wData['Data']:
                        if( aData['Id'] == '0x0'):
                            wbz_arm_data["ArmOrientation"] = aData['value']
                        if( aData['Id'] == '0x1'):
                            wbz_arm_data["ArmMovement"] = aData['value']
            except:
                print("Error in WBZ Read Arm Data")
                pass
            finally:
                return wbz_arm_data
        else:
            return wbz_arm_data

def wbz_read_TempData(wbz_scom):
    with wbzLock:
        wbz_tempdata = {
            "Temperature":0,
        }
        sleep_internal = 0.1
        cnt = wbz_scom.write_data(wbz_commad["Temperature"])
        print("wbz temp tx cnt", cnt)
        for i in range(1,200):
            time.sleep(0.1)
            wData = wbz_scom.get_read_data()
            if wData != None:
                break
        print(wData)
        if wData != None:
            try:
                if wData['Read attribute response'] == 'success':
                    for aData in wData['Data']:
                        if( aData['Id'] == '0x0'):
                            wbz_tempdata["Temperature"] = aData['value']
                else:
                    wbz_scom.write_data(wbz_commad["Bind"])
            except:
                print("Error in WBZ Read Arm Data")
                pass
            finally:
                return wbz_tempdata
        else:
            wbz_scom.write_data(wbz_commad["Bind"])
            return wbz_tempdata


def wsMQTTClientCallback(client, userdata, message):
    json_wsdata = json.loads(message.payload)
    #print json_wsdata
    if "ROBO_ONOFF" in json_wsdata:
        if "OnOffStatus" in json_wsdata["ROBO_ONOFF"]:
            with onoffLock:
                webserver_onoff["ROBO_ONOFF"]["OnOffStatus"] = int(json_wsdata["ROBO_ONOFF"]["OnOffStatus"])
                print("OnOff Status -->",webserver_onoff)


def pick_peg(robot, roboMQTTClient, wbz_scom, peg_place, motor_offset, motor_angles):
    TOLERANCE = 2
    set_torque_all_motor(robot)
    time.sleep(0.5)

    new_angle = 70
    rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")
    
    rotate_arm(robot, motor_offset, motor_angles["BASE_MOTOR_ID"], "BASE_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_3_MOTOR_ID"], "AXIS_3_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_5_MOTOR_ID"], "AXIS_5_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_4_MOTOR_ID"], "AXIS_4_MOTOR_ID")
    
    rotate_arm(robot, motor_offset, motor_angles["AXIS_2_MOTOR_ID"], "AXIS_2_MOTOR_ID")

    print("Picking..")
    v_init = read_motorVoltage(robot, PICK_DROP_MOTOR_ID)
    pick_flag = False
    while (pick_flag == False):
        while e_button['Emergency_Button1']['status'] == 1:
            time.sleep(0.5)
        armData = wbz_read_ArmData(wbz_scom)
        print("ArmData : ",armData)
        if(armData["ArmOrientation"] == 0 and armData["ArmMovement"] == 0):
            print("ArmData : ",armData)
            (status, time_val) = rotate_a6_finger_motor(robot, PICK+45, motor_offset, 100)
            print("CP :",get_a6_finger_motor(robot, motor_offset))
            v_pick = read_motorVoltage(robot, PICK_DROP_MOTOR_ID)
            print('v_init :',v_init, '  v_pick : ',v_pick)
            if status and (v_pick < (v_init - V_DIFF)): #or (v_init > 7.0 and v_pick <6.90)
                print('picked')
                if peg_place in peg_status["Robo_Pattern"]:
                    peg_status["Robo_Pattern"][peg_place] = 0
                r_data = json.dumps(peg_status, indent=4)
                with mqttPublishLock:
                    try:
                        roboMQTTClient.publishAsync(robo_topic, r_data, 1)
                    except Exception as e:
                        print("Failed to publish:",e)
                        pass                
                while e_button['Emergency_Button1']['status'] == 1:
                    time.sleep(0.5)
                (status, time_val) = rotate_a6_finger_motor(robot, PICK, motor_offset, 100)
                new_angle = 70
                rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")
                pick_flag = True
            else:
                print('not picked.. retrying')
                while e_button['Emergency_Button1']['status'] == 1:
                    time.sleep(0.5)
                (status, time_val) = rotate_a6_finger_motor(robot, PLACE-50, motor_offset, 100)
                #new_angle = 70
                #rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")
                v_init = read_motorVoltage(robot, PICK_DROP_MOTOR_ID)
                rotate_arm(robot, motor_offset, motor_angles["AXIS_5_MOTOR_ID"]+random.randint(-4,4), "AXIS_5_MOTOR_ID")
                rotate_arm(robot, motor_offset, motor_angles["AXIS_4_MOTOR_ID"]+random.randint(-3,3), "AXIS_4_MOTOR_ID")
                rotate_arm(robot, motor_offset, motor_angles["AXIS_2_MOTOR_ID"]+random.randint(0,1), "AXIS_2_MOTOR_ID")
        else:
            print('Orientation not detected not picked.. retrying')
            while e_button['Emergency_Button1']['status'] == 1:
                time.sleep(0.5)
            (status, time_val) = rotate_a6_finger_motor(robot, PLACE-50, motor_offset, 100)
            #new_angle = 70
            #rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")
            v_init = read_motorVoltage(robot, PICK_DROP_MOTOR_ID)
            rotate_arm(robot, motor_offset, motor_angles["AXIS_5_MOTOR_ID"]+random.randint(-4,4), "AXIS_5_MOTOR_ID")
            rotate_arm(robot, motor_offset, motor_angles["AXIS_4_MOTOR_ID"]+random.randint(-3,3), "AXIS_4_MOTOR_ID")
            rotate_arm(robot, motor_offset, motor_angles["AXIS_2_MOTOR_ID"]+random.randint(0,1), "AXIS_2_MOTOR_ID")

def place_peg(robot, roboMQTTClient, wbz_scom, peg_place, motor_offset, motor_angles):
    TOLERANCE = 2
    
    rotate_arm(robot, motor_offset, motor_angles["BASE_MOTOR_ID"], "BASE_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_5_MOTOR_ID"], "AXIS_5_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_3_MOTOR_ID"], "AXIS_3_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_4_MOTOR_ID"] + 2, "AXIS_4_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_2_MOTOR_ID"] - 2, "AXIS_2_MOTOR_ID")
    while e_button['Emergency_Button1']['status'] == 1:
        time.sleep(0.5)
    (status, time_val) = rotate_a6_finger_motor(robot, PLACE, motor_offset, 10)
    time.sleep(ADD_TIME + float(time_val)/1000)
    if peg_place in peg_status["Robo_Pattern"]:
        peg_status["Robo_Pattern"][peg_place] = 1
    r_data = json.dumps(peg_status, indent=4)
    with mqttPublishLock:
        try:
            roboMQTTClient.publishAsync(robo_topic, r_data, 1)
        except Exception as e:
            print("Failed to publish:",e)
            pass

    new_angle = 70
    rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")

def pick_place(robot, roboMQTTClient, motor_data, wbz_scom, pick, place):
    with onoffLock:
        onoff_status = webserver_onoff["ROBO_ONOFF"]["OnOffStatus"]
    #if (onoff_status) == 1:
    while not onoff_status:
        time.sleep(0.1)
        with onoffLock:
            onoff_status = webserver_onoff["ROBO_ONOFF"]["OnOffStatus"]
    msg = "\r\n\nPicking from " + str(pick) + " Placing at "+str(place)
    print(msg)
    robo_msg["ROBO_MESSAGE"]["msg"] = "Robo IP Address = "+str(robo_network_parameter['sta_ip']['ip'])+msg
    r_data = json.dumps(robo_msg, indent=4)
    with mqttPublishLock:
        try:
            roboMQTTClient.publishAsync(robo_topic, r_data, 1)
        except Exception as e:
            print("Failed to publish:",e)
            pass
    with roboLock:
        pick_peg(robot, roboMQTTClient, wbz_scom, pick, motor_offset, motor_data[pick])
    time.sleep(1)
    with roboLock:
        place_peg(robot, roboMQTTClient, wbz_scom, place, motor_offset, motor_data[place])
    time.sleep(1)


def camera_thread_func():
    video = cv2.VideoCapture('/dev/video0', cv2.CAP_V4L)
    # video.set(3, 160)
    # video.set(4, 120)
    video.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    video.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    video.set(cv2.CAP_PROP_AUTOFOCUS, 0)
    camera['image_update']['request'] = 1
    while True:
        #print "!",camera['image_update']['request'],
        if camera['image_update']['request']:
            rval, frame = video.read()
            if rval:
                frame = cv2.flip( frame, 1 )
                frame = cv2.flip( frame, 0 )
                cv2.imwrite('pic.jpg', frame)
                camera['image_update']['request'] = 0
                camera['image_update']['status'] = 1
        elif camera['image_update']['robopic']:
            video.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
            video.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
            time.sleep(0.2)
            rval, frame = video.read()
            time.sleep(0.2)
            video.set(cv2.CAP_PROP_FRAME_WIDTH, 160)
            video.set(cv2.CAP_PROP_FRAME_HEIGHT, 120)
            if rval:
                frame = cv2.flip( frame, 1 )
                frame = cv2.flip( frame, 0 )
                with imageUploadLock:
                    cv2.imwrite('/root/robo_image.jpg', frame)
                camera['image_update']['robopic'] = 0
                webserver_onoff["ROBO_ONOFF"]["image_update"] = 1

def init_image_S3Bucket():
	# Create a Boto3 session obejct with your IAM user credentials
	session = boto3.Session(aws_access_key_id='aws_access_key_id',aws_secret_access_key='aws_secret_access_key',)
    # Ensure the region name matches the region of your bucket. us-east-1 matches US East (N. Virginia)
	s3 = session.resource('s3')
	# Replace bucket-name with your bucket name, as well as the name of the file you want displayed in your bucket, including the extension
	obj = s3.Object('ew2024', 'robo_image.jpg')
	# Put your local file into the bucket by replacing the path-to-local-file with your desired file to upload, including the file extension
	obj.put(Body=open('robo_image.jpg', 'rb'))
	return obj
 
def upload_image_S3Bucket(obj):
    obj.put(Body=open('robo_image.jpg', 'rb'))

def image_upload_thread_func(obj, roboMQTTClient):
    while True:
        if webserver_onoff["ROBO_ONOFF"]["image_update"]:
            print("image upload started")
            with imageUploadLock:
                try:
                    obj.put(Body=open('robo_image.jpg', 'rb'))
                except Exception as e:
                    print("Failed to upload image to S3 bucket:",e)
                    pass
                #robo_msg["ROBO_MESSAGE"]["msg"] = "Image Uploaded"
                #webserver_onoff.update(robo_msg)
                r_data = json.dumps(webserver_onoff, indent=4)
                with mqttPublishLock:
                    try:
                        roboMQTTClient.publishAsync(robo_topic, r_data, 1)
                    except Exception as e:
                        print("Failed to publish:",e)
                        pass
                webserver_onoff["ROBO_ONOFF"]["image_update"] = 0
                print("image upload completed")
    
def demo_app(robot, motor_data, roboMQTTClient,obj, wbz_scom):
    image_upload_thread = Thread(target=image_upload_thread_func, args=(obj,roboMQTTClient))
    image_upload_thread.start()
    camera['image_update']['robopic'] = 1
    while not camera['image_update']['robopic']:
        time.sleep(0.2)
    # if capture_image():
        # webserver_onoff["ROBO_ONOFF"]["image_update"] = 1
    #robo_msg["ROBO_MESSAGE"]["msg"] = "Robot Turned ON"
    #peg_status.update(robo_msg)
    r_data = json.dumps(peg_status, indent=4)
    with mqttPublishLock:
        try:
            roboMQTTClient.publishAsync(robo_topic, r_data, 1)
        except Exception as e:
            print("Failed to publish:",e)
            pass
    while True:
        with onoffLock:
            onoff_status = webserver_onoff["ROBO_ONOFF"]["OnOffStatus"]
        if (onoff_status) == 1:
            for peg in PATTERN_4P:
                pick_place(robot, roboMQTTClient, motor_data, wbz_scom, peg[0], peg[1])
                camera['image_update']['robopic'] = 1
                while not camera['image_update']['robopic']:
                    time.sleep(0.2)
                print("Waiting to upload image")
                # if capture_image():
                    # webserver_onoff["ROBO_ONOFF"]["image_update"] = 1
                # else:
                    # print "Failed to Upload image"

def robot_thread_func(robot,motor_data,roboMQTTClient, obj, wbz_scom):
    demo_app(robot, motor_data, roboMQTTClient, obj, wbz_scom)
    

def mqtt_monitoring_thread_func(robot, roboMQTTClient, wbz_scom):
    b = LED("blue", False)
    r = LED("red", True)
    prev_room_tempdata = 0
    while True:
        b.write(True)
        with roboLock:
            for mv in robo_motor_data["Motor_Voltage"]:
                robo_motor_data["Motor_Voltage"][mv] = read_motorVoltage(robot, motors[mv])
                time.sleep(0.1)
                #robo_motor_data["Motor_Voltage"][mv] = random.randint(1,12)
            for mt in robo_motor_data["Motor_Temperature"]:
                if mt != "ROOM_TEMPERATURE_1_ID":
                    robo_motor_data["Motor_Temperature"][mt] = read_motorTemperature(robot, motors[mt])
                    time.sleep(0.1)
                    #robo_motor_data["Motor_Temperature"][mt] = random.randint(0,200)
        room_tempdata = wbz_read_TempData(wbz_scom)
        print("Room TempData: ",room_tempdata)
        if( room_tempdata["Temperature"] >= 1 or room_tempdata["Temperature"] <= 10000):
            robo_motor_data["Motor_Temperature"]["ROOM_TEMPERATURE_1_ID"] = round(room_tempdata["Temperature"]/100)        
            prev_room_tempdata = round(room_tempdata["Temperature"]/100)
        if(room_tempdata["Temperature"] == 0):
            robo_motor_data["Motor_Temperature"]["ROOM_TEMPERATURE_1_ID"] =  prev_room_tempdata
        if robo_motor_data["Motor_Temperature"]["ROOM_TEMPERATURE_1_ID"]  >= 45:
            e_button['Emergency_Button1']['status'] = 1
            robo_msg["ROBO_MESSAGE"]["msg"] = "Over Temperature Detected\r\nStopping the Robo\r\nPress and Release Emergency button to Continue"
            robo_motor_data.update(robo_msg)
            data = json.dumps(robo_msg, indent=4)
            with mqttPublishLock:
                try:
                    roboMQTTClient.publishAsync(robo_topic, data, 1)
                except Exception as e:
                    print("Failed to publish:",e)
                    pass            
        webserver_onoff["ROBO_ONOFF"]["time"] = time.time()
        robo_motor_data.update(webserver_onoff)
        data = json.dumps(robo_motor_data, indent=4)
        with mqttPublishLock:
            try:
                roboMQTTClient.publishAsync(robo_topic, data, 1)
            except Exception as e:
                print("Failed to publish:",e)
                pass
        print("Published Motor Data")
        b.write(False)
        time.sleep(5)


# def miwi_iot_mqtt(iot_data):
   # device_name = ''
   # device_id = ''
   # name_index = 0
   # temperature = 77
   # battery = 25.00
   # if iot_data[0:2] == '\x10\x02' and iot_data[-3:-1] == '\x10\x03':
       # iot_data = iot_data.replace('\x10\x10','\x10')
       # name_index = iot_data.find("EW_DEMO_MIWI1")
       # if name_index > 40 and ord(iot_data[name_index-2]) == 32:
           # device_name = iot_data[name_index:-3]
           #print device_name
           # temp_str1 = iot_data[iot_data.find('\x01\x0c')+6:iot_data.find('\x01\x0c')+11]
           # temperature_F = ord(temp_str1[0])+(ord(temp_str1[1])*256)+(ord(temp_str1[2])*65536)+(ord(temp_str1[2])*16777216)

           # temp_str2 = iot_data[iot_data.find('\x01\x0c')+2:iot_data.find('\x01\x0c')+7]
           # temperature_C = float(ord(temp_str2[0])+(ord(temp_str2[1])*256)+(ord(temp_str2[2])*65536)+(ord(temp_str2[2])*16777216))/1000
           # print(device_name," -> ",temperature_C)
           # if temperature > 100:
               # temperature = 100
           # robo_motor_data["Motor_Temperature"]["ROOM_TEMPERATURE_1_ID"] = float(temperature_C)
       # else:
           # print(" to get device name")
        

# def zbee_recv_thread_func(port, scom):
    # start_index = -1
    # data = ''
    # print("zbee_recv_thread_func thread started")
    # while True:
        # if scom.isOpen():
            # miwi_data = ''
            # miwi_data_flag = False
            # try:
                # data += str(scom.read(70))
            # except Exception as e:
                # print("ZIGBEE port closed:",e)
            # miwi_data = data
                    # miwi_data_flag = True
            # if miwi_data_flag == True:
                # data = ''
                # miwi_iot_mqtt(miwi_data)
                # print(miwi_data)
                # miwi_data_flag = False
                
def gpio_thread_func(robot,motor_data,roboMQTTClient):
    print("GPIO Thread started")
    r = GPIO(31, GPIO.IN, initial=GPIO.HIGH)
    key_status = [True, True]
    while True:
        time.sleep(1)
        key_status[0] = r.get()
        if key_status[0]== False and key_status[1] == True:
            print("Emergency Button Pressed")
            key_status[1] = key_status[0]
            if e_button['Emergency_Button1']['status'] == 0:
                #emergency_stop(robot,motor_offset)
                e_button['Emergency_Button1']['status'] = 1
                print("Activated Emergency Button")
                robo_msg["ROBO_MESSAGE"]["msg"] = "Activated Emergency Button"
                r_data = json.dumps(robo_msg, indent=4)
                with mqttPublishLock:
                    try:
                        roboMQTTClient.publishAsync(robo_topic, r_data, 1)
                    except Exception as e:
                        print("Failed to publish:",e)
                        pass
        elif key_status[0] == True and key_status[1] == False:
            print("Emergency Button Released")
            key_status[1] = key_status[0]
            if e_button['Emergency_Button1']["status"] == 1:
                e_button['Emergency_Button1']["status"] = 0
                print("Deactivated Emergency Button")
                robo_msg["ROBO_MESSAGE"]["msg"] = "Deactivated Emergency Button"
                r_data = json.dumps(robo_msg, indent=4)
                with mqttPublishLock:
                    try:
                        roboMQTTClient.publishAsync(robo_topic, r_data, 1)
                    except Exception as e:
                        print("Failed to publish:",e)
                        pass
        
app = Flask(__name__) 

@app.route('/') 
def index(): 
    """Video streaming .""" 
    return render_template('index.html')
    # return render_template('iframe.html')

def gen(): 
    """Video streaming generator function."""
    while True:
        #print "@",camera['image_update']['request'],
        if camera['image_update']['request']:
            continue
        if camera['image_update']['status']:
            yield (b'--frame\r\n' 
              b'Content-Type: image/jpeg\r\n\r\n' + open('pic.jpg', 'rb').read() + b'\r\n')
            camera['image_update']['request'] = 1
            camera['image_update']['status'] = 0

@app.route('/video_feed')
def video_feed(): 
    """Video streaming route. Put this in the src attribute of an img tag.""" 
    return Response(gen(), 
                    mimetype='multipart/x-mixed-replace; boundary=frame') 
                    
if __name__ == "__main__":
    logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.WARNING)
    robot = None
    miwi_recv_thread = None
    gpio_thread = None
    wbz_scom = None
    #logging.getLogger().setLevel(logging.DEBUG)
    robot = piarm.PiArm()
    robot.connect("/dev/ttyUSB0")
    #robot.connect("COM33")
    port = "/dev/ttyACM0"
    #port = "COM60"
    #wbz_port = "/dev/ttyACM1"
    wbz_port = find_wbz_port()
    if(wbz_port != None):
        wbz_scom = wbz_serial.SerialPortHandler(wbz_port, baudrate = 115200, timeout= 0.5)
        wbz_scom.connect()
    else:
        print("Error: WBZ port Not Found - Connecting ttyACM1")
        wbz_scom = wbz_serial.SerialPortHandler("/dev/ttyACM1", baudrate = 115200, timeout= 0.5)
        wbz_scom.connect()

    motor_data = {}
    motor_data = read_json_file(motor_data)
    motor_offset = motor_data['Motor_Offset']
    motors_angle_offset = motor_data['Motor_Angle_Offset']

    rotate_arm(robot, motor_offset, 120, "AXIS_3_MOTOR_ID")
    rotate_arm(robot, motor_offset, 120, "AXIS_2_MOTOR_ID")
    rotate_arm(robot, motor_offset, 120, "AXIS_4_MOTOR_ID")
    rotate_arm(robot, motor_offset, 60, "BASE_MOTOR_ID")
    rotate_arm(robot, motor_offset, 120, "AXIS_5_MOTOR_ID")
    
    robot.adjustAngleOffset(BASE_MOTOR_ID, motors_angle_offset['BASE_MOTOR_ID'])
    robot.adjustAngleOffset(AXIS_2_MOTOR_ID, motors_angle_offset['AXIS_2_MOTOR_ID'])
    robot.adjustAngleOffset(AXIS_3_MOTOR_ID, motors_angle_offset['AXIS_3_MOTOR_ID'])
    robot.adjustAngleOffset(AXIS_4_MOTOR_ID, motors_angle_offset['AXIS_4_MOTOR_ID'])
    robot.adjustAngleOffset(AXIS_5_MOTOR_ID, motors_angle_offset['AXIS_5_MOTOR_ID'])
    robot.adjustAngleOffset(PICK_DROP_MOTOR_ID, motors_angle_offset['PICK_DROP_MOTOR_ID'])
    try:
        ip_addr = get_ip()
    except:
        pass
    if not ip_addr == None:
        robo_network_parameter['sta_ip']['ip'] = ip_addr
        print("Robo Ip Address :",robo_network_parameter['sta_ip']['ip'])
    utc_time = None
    while utc_time == None:
        print("\r\nTrying to get time")
        utc_time = get_ntp_time(ntp_servers, True)
        time.sleep(1)
    baseReconnectQuietTimeSecond = 1;
    maxReconnectQuietTimeSecond = 32;
    stableConnectionTimeSecond = 20;
    # For certificate based connection
    roboMQTTClient = AWSIoTMQTTClient("WSG_EW_DEMO_ROBO2")
    # For TLS mutual authentication with TLS ALPN extension
    roboMQTTClient.configureEndpoint("awsendpoint.amazonaws.com", 443)
    roboMQTTClient.configureCredentials("/root/cert/AmazonRoot.pem", "/root/cert/private.pem.key", "/root/cert/certificate.pem.crt")
    roboMQTTClient.configureOfflinePublishQueueing(-1)  # Infinite offline Publish queueing
    roboMQTTClient.configureDrainingFrequency(2)  # Draining: 2 Hz
    roboMQTTClient.configureConnectDisconnectTimeout(10)  # 10 sec
    roboMQTTClient.configureMQTTOperationTimeout(15)  # 5 sec
    roboMQTTClient.configureAutoReconnectBackoffTime(baseReconnectQuietTimeSecond, maxReconnectQuietTimeSecond, stableConnectionTimeSecond)
    print("Connecting to AWS")
    roboMQTTClient.connect()
    roboMQTTClient.subscribe(webserver_topic, 1, wsMQTTClientCallback)
    print("Connected")
    gpio_thread = Thread(target=gpio_thread_func, args=(robot,motor_data,roboMQTTClient))
    e_button['Emergency_Button1']['status'] = 0
    obj = init_image_S3Bucket()
    gpio_thread.start() 
    mqtt_monitoring_thread = Thread(target=mqtt_monitoring_thread_func, args=(robot, roboMQTTClient, wbz_scom))
    robot_thread = Thread(target=robot_thread_func, args=(robot, motor_data, roboMQTTClient ,obj ,wbz_scom))
    time.sleep(0.5)
    robot_thread.start()
    #time.sleep(10)
    #enable_ap_mode()
    #time.sleep(10)
    mqtt_monitoring_thread.start()
    camera_thread = Thread(target=camera_thread_func, args=())
    camera_thread.start()
    app.run(host='0.0.0.0', threaded=True, port=80)
    mqtt_monitoring_thread.join()
    robot_thread.join()
    print("Exit the code")
    robot.disconnect()
    wbz_scom.disconnect()
    roboMQTTClient.disconnect()


    
                    

