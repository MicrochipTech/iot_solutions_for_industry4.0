from flask import Flask, render_template, request,jsonify, flash, redirect,request, url_for, Response
from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
from threading import Thread
import time
import json
import boto3
from threading import Lock

wsMQTTClient = None
robo_topic = "/WSG_Apps/EW_DEMO/Robo2"
server_topic = "/WSG_Apps/EW_DEMO/Server2"

sd_lock = Lock()

initialization_subscribed_data = {
	"Motor_Temperature":{"AXIS_2_MOTOR_ID":0,"BASE_MOTOR_ID":0,"AXIS_3_MOTOR_ID":0,"AXIS_5_MOTOR_ID":0,"AXIS_4_MOTOR_ID":0,"PICK_DROP_MOTOR_ID":0,"ROOM_TEMPERATURE_1_ID": 0},
	"Motor_Voltage":{"AXIS_2_MOTOR_ID":0.0,"BASE_MOTOR_ID":0.0,"AXIS_3_MOTOR_ID":0.0,"AXIS_5_MOTOR_ID":0.0,"AXIS_4_MOTOR_ID":0.0,"PICK_DROP_MOTOR_ID":0.0},
	"ROBO_MESSAGE": {"msg": "INITIALIZED ALL PARAMETERS"},
	"Robo_Pattern":{"A1":0,"A2":0,"A3":0,"A4":0,"B1":0,"B2":0,"B3":0,"B4":0,"C1":0,"C2":0,"C3":0,"C4":0,"D1":0,"D2":0,"D3":0,"D4":0,"E1":0,"E2":0,"E3":0,"E4":0},
    "ROBO_ONOFF": {"OnOffStatus": 0, "image_update":1, "time":0},
}
subscribed_data = initialization_subscribed_data
iot_mqtt_connect_flag = False

webserver_onoff = {
    "ROBO_ONOFF":{
        "OnOffStatus":0
        }
    }

def init_image_S3Bucket():
    # Create a Boto3 session obejct with your IAM user credentials
    session = boto3.Session(aws_access_key_id='aws_access_key_id',aws_secret_access_key='aws_secret_access_key',)

    # Ensure the region name matches the region of your bucket. us-east-1 matches US East (N. Virginia)
    s3 = session.resource('s3')

    # Replace bucket-name with your bucket name, as well as the name of the file you want displayed in your bucket, including the extension
    obj = s3.Object('ew2024', 'robo_image.jpg')
    
    # Put your local file into the bucket by replacing the path-to-local-file with your desired file to upload, including the file extension
    #object.put(Body=open('robo_image.jpg', 'rb'))
    return (s3, obj)

def wsMQTTClientCallback(client, userdata, message):
    global subscribed_data
    print("from topic: ")
    print((message.topic))
    #print(message.payload)
    print("\n\n\n\r--------------\n\n")
    j_flag = False
    try:
        j_data = json.loads(message.payload)
        j_flag = True
        #print "j_data",j_data
    except Exception as e:
        print("Json load error:",e)
        pass
    if j_flag:
        with sd_lock:
            j_flag = False
            for data_keys in list(subscribed_data.keys()):
                if data_keys in j_data:
                    subscribed_data[data_keys] = j_data[data_keys]
                    print("subscribed_data",subscribed_data)
                    print("\n\n\n\r--------------\n\n")

def aws_iot_connect():
    global iot_mqtt_connect_flag
    global wsMQTTClient
    wsMQTTClient = AWSIoTMQTTClient("WSG_EW_DEMO_WS2")
    iot_mqtt_connect_flag = False
    while True:
        while not(iot_mqtt_connect_flag):
            try:
                baseReconnectQuietTimeSecond = 1;
                maxReconnectQuietTimeSecond = 32;
                stableConnectionTimeSecond = 20;
                print("Connecting to AWS MQTT client")
                # For certificate based connection
                # For TLS mutual authentication with TLS ALPN extension
                wsMQTTClient.configureEndpoint("awsendpoint.amazonaws.com", 443)
                wsMQTTClient.configureCredentials("AmazonRoot.pem", "private.pem.key", "certificate.pem.crt")
                wsMQTTClient.configureOfflinePublishQueueing(-1)  # Infinite offline Publish queueing
                wsMQTTClient.configureDrainingFrequency(2)  # Draining: 2 Hz
                wsMQTTClient.configureConnectDisconnectTimeout(10)  # 10 sec
                wsMQTTClient.configureMQTTOperationTimeout(15)  # 5 sec
                wsMQTTClient.configureAutoReconnectBackoffTime(baseReconnectQuietTimeSecond, maxReconnectQuietTimeSecond, stableConnectionTimeSecond)
                wsMQTTClient.connect()
                wsMQTTClient.subscribe(robo_topic, 1, wsMQTTClientCallback)
                print("Connected to AWS MQTT client")
                iot_mqtt_connect_flag = True
            except Exception as e:
                print("aws_iot_connect: mqtt connect error> ",e)
                iot_mqtt_connect_flag = False
                pass
        current_time = time.time()
        last_time = 0.0
        try:
            last_time = float(subscribed_data["ROBO_ONOFF"]["time"])
        except Exception as e:
            print("Time Failed",e)
            last_time = 0
            pass
        print("current_time:",current_time,"\r\nLast time:",last_time,"Diff:", current_time-last_time)
        if last_time+90 < current_time:
            with sd_lock:
                subscribed_data["ROBO_ONOFF"]["OnOffStatus"] = 0
                subscribed_data["ROBO_ONOFF"]["image_update"] = 0
                for i in subscribed_data["Motor_Temperature"]:
                    subscribed_data["Motor_Temperature"][i] = 0
                for i in subscribed_data["Motor_Voltage"]:
                    subscribed_data["Motor_Voltage"][i] = 0
                for i in subscribed_data["Robo_Pattern"]:
                    subscribed_data["Motor_Voltage"][i] = 0
                print(subscribed_data)
                subscribed_data["ROBO_MESSAGE"]["msg"] = "Keep Alive timer expired"
            print("Setting everything to 0")
        time.sleep(30)
    print("Exiting the thread_______________________")


#flask app
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('main.html')

def gen(): 
    (s3, obj) = init_image_S3Bucket()	
    """Video streaming generator function.""" 
    while True: 
        # rval, frame = vc.read() 
        # cv2.imwrite('pic.jpg', frame) 
        s3.Bucket(obj.bucket_name).download_file(obj.key, 'peg_board.jpg')
        yield (b'--frame\r\n' 
               b'Content-Type: image/jpeg\r\n\r\n' + open('peg_board.jpg', 'rb').read() + b'\r\n')

@app.route('/video_feed')
def video_feed(): 
    """Video streaming route. Put this in the src attribute of an img tag.""" 
    return Response(gen(), 
                    mimetype='multipart/x-mixed-replace; boundary=frame') 

#background process happening without any refreshing
@app.route('/robo_on_off', methods=['GET', 'POST'])
def turn_robo_on_off():
    global wsMQTTClient
    if request.method == 'POST':
        with sd_lock:
            subscribed_data["ROBO_ONOFF"]["OnOffStatus"] = int(request.form['value'])
        webserver_onoff["ROBO_ONOFF"]["OnOffStatus"] = subscribed_data["ROBO_ONOFF"]["OnOffStatus"]
        messageJson = json.dumps(webserver_onoff)
        if wsMQTTClient.publish(server_topic, messageJson, 1):
            with sd_lock:
                if subscribed_data["ROBO_ONOFF"]["OnOffStatus"] == 1:
                    subscribed_data["ROBO_MESSAGE"]["msg"] = "Robo Turned ON"
                else:
                    subscribed_data["ROBO_MESSAGE"]["msg"] = "Robo Turned OFF"
        else:
            with sd_lock:
                subscribed_data["ROBO_MESSAGE"]["msg"] = "Message not published"
    return "nothing"

@app.route('/webupdate', methods=['GET'])
def web_update():
    global subscribed_data
    global wsMQTTClient
    with sd_lock:
        ret = jsonify(subscribed_data)
        subscribed_data["ROBO_ONOFF"]["image_update"] = 0
        return ret

##@app.after_request
##def add_header(r):
##    """
##    Add headers to both force latest IE rendering engine or Chrome Frame,
##    and also to cache the rendered page for 10 minutes.
##    """
##    r.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
##    r.headers["Pragma"] = "no-cache"
##    r.headers["Expires"] = "0"
##    r.headers['Cache-Control'] = 'public, max-age=0'
##    return r
##
##@app.before_first_request
##def before_first_request_func():
##    print"This function will run once"
    
if __name__ == "__main__":
    with sd_lock:
        subscribed_data = initialization_subscribed_data
    aws_connect_thread = 0
    aws_connect_thread = Thread(target=aws_iot_connect, args=())
    aws_connect_thread.start()
    #app.run()
    print("Waiting for AWS MQTT connection")
    while not iot_mqtt_connect_flag:
        time.sleep(0.5)
    app.run(host="0.0.0.0", port=80)    
    aws_connect_thread.join()

