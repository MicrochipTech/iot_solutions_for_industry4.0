#from piarm import PiArm
import piarm
import logging
import time
import json
import random

BASE_MOTOR_ID = 6
AXIS_2_MOTOR_ID = 5
AXIS_3_MOTOR_ID = 4
AXIS_4_MOTOR_ID = 3
AXIS_5_MOTOR_ID = 2
PICK_DROP_MOTOR_ID = 1

TIME_COEFF = 18
ADD_TIME = (float(TIME_COEFF)/100) * 0.75
GET_SLEEP_TIME = 0.05

#PICK = 650
#PLACE = 530
PICK = 600
PLACE = 300
V_DIFF = 0.100
e_button = {'Emergency_Button1':{'status':0}}
peg_board = ['DP','A1','A2','A3','A4','A5','B1','B2','B3','B4','B5','C1','C2','C3','C4','C5','D1','D2','D3','D4','D5','E1','E2','E3','E4','E5']
motors = {
	"BASE_MOTOR_ID" : BASE_MOTOR_ID,
	"AXIS_2_MOTOR_ID" : AXIS_2_MOTOR_ID,
	"AXIS_3_MOTOR_ID" : AXIS_3_MOTOR_ID,
	"AXIS_4_MOTOR_ID" : AXIS_4_MOTOR_ID,
	"AXIS_5_MOTOR_ID" : AXIS_5_MOTOR_ID,
	"PICK_DROP_MOTOR_ID": PICK_DROP_MOTOR_ID
        }

motors_list = [PICK_DROP_MOTOR_ID, AXIS_5_MOTOR_ID, AXIS_4_MOTOR_ID, AXIS_3_MOTOR_ID, AXIS_2_MOTOR_ID, BASE_MOTOR_ID]


def read_motorTemperature(robot, motor_id):
    retry_flag = True
    while retry_flag:
        try:
            temp = robot.tempRead(motor_id)
            if (ord(temp[2]) == motor_id) and (ord(temp[4]) == robot.SERVO_TEMP_READ) and (temp[5] != None):
                retry_flag = False
                return ord(temp[5])
            else:
                raise Exception ("Error in read_motorVoltage")
        except Exception as e:
            pass
            print(("Unable to get motor temperature:",motor_id))
            time.sleep(1.0)

def read_temp_limit(robot, motor_ID):
    temp = robot.readTempLimit(motor_ID)
    max_val = ord(temp[5])
    return (max_val)

def read_motorVoltage(robot, motor_id):
    retry_flag = True
    while retry_flag:
        try:
            temp = robot.voltageRead(motor_id)
            if (ord(temp[2]) == motor_id) and (ord(temp[4]) == robot.SERVO_VIN_READ) and (temp[5] != None) and (temp[6] != None):
                retry_flag = False
                return (float)((256*ord(temp[6])) + ord(temp[5]))/1000
            else:
                raise Exception ("Error in read_motorVoltage")
        except Exception as e:
            print(e)
            print(("Unable to get motor voltage:",motor_id))
            time.sleep(1.0)
            pass

def read_angle_limit(robot, motor_ID):
    temp = robot.readAngleLimit(motor_ID)
    min_val = 256*ord(temp[6])+ord(temp[5])
    max_val = 256*ord(temp[8])+ord(temp[7])
    return (min_val, max_val)

def read_volt_limit(robot, motor_ID):
    temp = robot.readVolLimit(motor_ID)
    min_val = (float)(256*ord(temp[6])+ord(temp[5]))/1000
    max_val = (float)(256*ord(temp[8])+ord(temp[7]))/1000
    return (min_val, max_val)
    
def torque_control(robot, motor_id, status):
    robot.torqueServo(motor_id, status)

def set_torque_all_motor(robot):
    for motor_id in range (1,7):
        torque_control(robot, motor_id,1)

def clear_torque_all_motor(robot):
    for motor_id in range (1,7):
        torque_control(robot, motor_id,0)

def read_motorPosition(robot, motor_id):
    retry_flag = True
    while retry_flag:
        try:
            temp = robot.positionRead(motor_id)
            if (ord(temp[2]) == motor_id) and (ord(temp[4]) == robot.SERVO_POS_READ) and (temp[5] != None) and (temp[6] != None):
                retry_flag = False
                return (256*ord(temp[6])) + ord(temp[5])
            else:
                raise Exception ("Error in read_motorPosition")
        except Exception as e:            
            pass
            print(("Unable to get motor position:",motor_id))
            print(e)
            time.sleep(1.0)
        

def set_motor_position(robot, motor_id, position, time_val = 2000):
    if position >= 0 and position <=1000:
        robot.servoWrite(motor_id, int(position), time_val)
    else:
        print(("Error invalid motor postion requested :",position))

def get_a1_base_motor_position(robot, motor_offset):
    temp = read_motorPosition(robot, BASE_MOTOR_ID)
    angle = round((temp - motor_offset["BASE_MOTOR_ID"])/4.23,0)
    time.sleep(GET_SLEEP_TIME)
    return int(angle)

def get_a2_position(robot, motor_offset):
    temp = read_motorPosition(robot, AXIS_2_MOTOR_ID)
    angle = round((temp - motor_offset["AXIS_2_MOTOR_ID"])/4.23,0)
    time.sleep(GET_SLEEP_TIME)
    return (int(angle))

def get_a3_position(robot, motor_offset):
    temp = read_motorPosition(robot, AXIS_3_MOTOR_ID)
    angle = round((temp - motor_offset["AXIS_3_MOTOR_ID"])/4.23,0)
    time.sleep(GET_SLEEP_TIME)
    return (180 - int(angle))
    #return (int(angle))

def get_a4_position(robot, motor_offset):
    temp = read_motorPosition(robot, AXIS_4_MOTOR_ID)
    angle = round((temp - motor_offset["AXIS_4_MOTOR_ID"])/4.23,0)
    time.sleep(GET_SLEEP_TIME)
    return (int(angle))
    #return (180 - int(angle))

def get_a5_wrist_position(robot, motor_offset):
    temp = read_motorPosition(robot, AXIS_5_MOTOR_ID)
    angle = round((temp - motor_offset["AXIS_5_MOTOR_ID"])/4.23,0)
    time.sleep(GET_SLEEP_TIME)
    return (int(angle))

def get_a6_finger_motor(robot, motor_offset):
    temp = read_motorPosition(robot, PICK_DROP_MOTOR_ID)
    time.sleep(GET_SLEEP_TIME)
    return temp
    
def rotate_a1_base_motor(robot, angle, motor_offset, time_val):
    # This motor rotate from 0 to 180 degre
    if angle >= 0 and angle <= 180:
        if time_val == 0:
            time_val = TIME_COEFF * abs(angle - get_a1_base_motor_position(robot, motor_offset))
        temp = round(motor_offset["BASE_MOTOR_ID"] + (angle * 4.23),0)
        set_motor_position(robot, BASE_MOTOR_ID, int(temp), time_val)
    else:
        print(("A1 Motor: Invalid angle :",angle))
    return time_val

def rotate_a2_motor(robot, angle, motor_offset, time_val):
    if angle >= 70 and angle <= 180:
        if time_val == 0:
            cp = get_a2_position(robot, motor_offset)
            time_val = TIME_COEFF * abs(angle - cp)
        temp = round(motor_offset["AXIS_2_MOTOR_ID"] + (angle * 4.23),0)
        set_motor_position(robot, AXIS_2_MOTOR_ID, int(temp), time_val)
    else:
        print(("A2 Motor: Invalid angle :",angle))
    return time_val

def rotate_a3_motor(robot, angle, motor_offset, time_val):
    if angle >= 90 and angle <= 210:
        if time_val == 0:
            time_val = TIME_COEFF * abs(angle - get_a3_position(robot, motor_offset))
        angle = (180 - angle)
        temp = round(motor_offset["AXIS_3_MOTOR_ID"] + (angle * 4.23),0)
        set_motor_position(robot, AXIS_3_MOTOR_ID, int(temp), time_val)
    else:
        print(("A3 Motor: Invalid angle :",angle))
    return time_val
    

def rotate_a4_motor(robot, angle, motor_offset, time_val):
    if angle >= 90 and angle <= 180:
        if time_val == 0:
            cp = get_a4_position(robot, motor_offset)
            time_val = TIME_COEFF * abs(angle - cp)
        #angle = (180 - angle)
        temp = round(motor_offset["AXIS_4_MOTOR_ID"] + (angle * 4.23),0)
        set_motor_position(robot, AXIS_4_MOTOR_ID, int(temp), time_val)
    else:
        print(("A4 Motor: Invalid angle :",angle))
    return time_val

def rotate_a5_wrist_motor(robot, angle, motor_offset, time_val):
    if angle >= 10 and angle <= 180:
        if time_val == 0:
            time_val = TIME_COEFF * abs(angle - get_a5_wrist_position(robot, motor_offset))
        temp = round(motor_offset["AXIS_5_MOTOR_ID"] + (angle * 4.23),0)
        set_motor_position(robot, AXIS_5_MOTOR_ID, int(temp), time_val)
    else:
        print(("A5 Motor: Invalid angle :",angle))
    return time_val

def rotate_a6_finger_motor(robot, pickNplace, motor_offset, time_val):
    TOLERANCE = 50
    if pickNplace >= 90 and pickNplace < 750:
        set_motor_position(robot, PICK_DROP_MOTOR_ID, pickNplace, 800)
        time.sleep(1)
        #torque_control(robot, PICK_DROP_MOTOR_ID, 1)
        current_val = read_motorPosition(robot, PICK_DROP_MOTOR_ID)
        time.sleep(0.5)
        retry_count = 0
        while not(current_val >=(pickNplace-TOLERANCE) and current_val <=(pickNplace+TOLERANCE)):
            print(("retrying rotate_a6_finger_motor:",current_val))
            set_motor_position(robot, PICK_DROP_MOTOR_ID, pickNplace, 800)
            time.sleep(1.0)
            current_val = read_motorPosition(robot, PICK_DROP_MOTOR_ID)
            time.sleep(0.5)
            retry_count = retry_count +1
            if retry_count >= 2:
                return (False, time_val)
    else:
        print(("Wrong pickNplace value:", pickNplace))
        return (False, time_val)
    return (True, time_val)

get_motor_position = {
	"BASE_MOTOR_ID" : get_a1_base_motor_position,
	"AXIS_2_MOTOR_ID" : get_a2_position,
	"AXIS_3_MOTOR_ID" : get_a3_position,
	"AXIS_4_MOTOR_ID" : get_a4_position,
	"AXIS_5_MOTOR_ID" : get_a5_wrist_position,
	"PICK_DROP_MOTOR_ID": get_a6_finger_motor
        }

rotate_motor = {
	"BASE_MOTOR_ID" : rotate_a1_base_motor,
	"AXIS_2_MOTOR_ID" : rotate_a2_motor,
	"AXIS_3_MOTOR_ID" : rotate_a3_motor,
	"AXIS_4_MOTOR_ID" : rotate_a4_motor,
	"AXIS_5_MOTOR_ID" : rotate_a5_wrist_motor,
	"PICK_DROP_MOTOR_ID": rotate_a6_finger_motor
        }
motor_control = {
    "rotate_motor":rotate_motor, 
    "get_motor_position":get_motor_position
    }


def get_arm_motor_angles(robot, motor_offset):
    set_torque_all_motor(robot)
    current_motors_angles = {}
    time.sleep(0.3)

    current_motors_angles["BASE_MOTOR_ID"] = get_a1_base_motor_position(robot, motor_offset)
    print(("a1_base_motor_position :",current_motors_angles["BASE_MOTOR_ID"]))
    if not (current_motors_angles["BASE_MOTOR_ID"] >= 0 and current_motors_angles["BASE_MOTOR_ID"] <= 180):
       print("Motor angle out of range")
    time.sleep(0.3)

    current_motors_angles["AXIS_2_MOTOR_ID"] = get_a2_position(robot, motor_offset)
    print(("a2_motor_position :",current_motors_angles["AXIS_2_MOTOR_ID"]))
    if not (current_motors_angles["AXIS_2_MOTOR_ID"] >= 70 and current_motors_angles["AXIS_2_MOTOR_ID"] <= 180):
       print("Motor angle out of range")
    time.sleep(0.3)

    current_motors_angles["AXIS_3_MOTOR_ID"] = get_a3_position(robot, motor_offset)
    print(("a3_motor_position :",current_motors_angles["AXIS_3_MOTOR_ID"]))
    if not (current_motors_angles["AXIS_3_MOTOR_ID"] >= 90 and current_motors_angles["AXIS_3_MOTOR_ID"] <= 210):
       print("Motor angle out of range")
    time.sleep(0.3)
    
    current_motors_angles["AXIS_4_MOTOR_ID"] = get_a4_position(robot, motor_offset)
    print(("a4_motor_position :",current_motors_angles["AXIS_4_MOTOR_ID"]))
    if not (current_motors_angles["AXIS_4_MOTOR_ID"] >= 90 and current_motors_angles["AXIS_4_MOTOR_ID"] <= 180):
       print("Motor angle out of range")
    time.sleep(0.3)
    
    current_motors_angles["AXIS_5_MOTOR_ID"] = get_a5_wrist_position(robot, motor_offset)
    print(("a5_wrist_position :",current_motors_angles["AXIS_5_MOTOR_ID"]))
    if not (current_motors_angles["AXIS_5_MOTOR_ID"] >= 10 and current_motors_angles["AXIS_5_MOTOR_ID"] <= 180):
       print("Motor angle out of range")

    clear_torque_all_motor(robot)
    return current_motors_angles


def set_arm_motor_angles(robot, motor_offset, motor_angles):
    set_torque_all_motor(robot)
    time.sleep(0.5)

    torque_control(robot, AXIS_4_MOTOR_ID, 0)
    torque_control(robot, BASE_MOTOR_ID, 0)
    time.sleep(0.5)

    new_angle = 70
    rotate_a2_motor(robot,new_angle, motor_offset, 0)
    curr_angle =  get_a2_position(robot, motor_offset)
    TOLERANCE = 3
    while not(curr_angle >=(new_angle-TOLERANCE) and curr_angle <=(new_angle+TOLERANCE)):
        time.sleep(0.5)
        curr_angle =  get_a2_position(robot, motor_offset)

    set_torque_all_motor(robot)

    new_angle = motor_angles["BASE_MOTOR_ID"]
    rotate_a1_base_motor(robot,new_angle, motor_offset, 0)
    curr_angle =  get_a1_base_motor_position(robot, motor_offset)
    while not(curr_angle >=(new_angle-TOLERANCE) and curr_angle <=(new_angle+TOLERANCE)):
        time.sleep(0.5)
        curr_angle =  get_a1_base_motor_position(robot, motor_offset)

    new_angle = motor_angles["AXIS_3_MOTOR_ID"]
    rotate_a3_motor(robot,new_angle, motor_offset, 0)
    curr_angle =  get_a3_position(robot, motor_offset)
    while not(curr_angle >=(new_angle-TOLERANCE) and curr_angle <=(new_angle+TOLERANCE)):
        time.sleep(0.5)
        curr_angle =  get_a3_position(robot, motor_offset)

    new_angle = motor_angles["AXIS_5_MOTOR_ID"] #sankar
    

    new_angle = motor_angles["AXIS_4_MOTOR_ID"]
    rotate_a4_motor(robot,new_angle, motor_offset, 0)
    curr_angle =  get_a4_position(robot, motor_offset)
    while not(curr_angle >=(new_angle-TOLERANCE) and curr_angle <=(new_angle+TOLERANCE)):
        time.sleep(0.5)
        curr_angle =  get_a4_position(robot, motor_offset)
        0
    new_angle = motor_angles["AXIS_2_MOTOR_ID"]
    rotate_a2_motor(robot,new_angle, motor_offset, 0)
    curr_angle =  get_a2_position(robot, motor_offset)
    while not(curr_angle >=(new_angle-TOLERANCE) and curr_angle <=(new_angle+TOLERANCE)): 
        time.sleep(0.5)
        curr_angle =  get_a2_position(robot, motor_offset)

def rotate_arm(robot, motor_offset, m_angle, motor_id_str):
    TOLERANCE = 2
    #print motor_id_str
    curr_angle = motor_control["get_motor_position"][motor_id_str](robot, motor_offset)
    while e_button['Emergency_Button1']['status'] == 1:
        time.sleep(0.5)
    time_val = motor_control["rotate_motor"][motor_id_str](robot,m_angle, motor_offset, 0)
    count = 0
    while not(curr_angle >=(m_angle-TOLERANCE) and curr_angle <=(m_angle+TOLERANCE)):
        time.sleep(ADD_TIME + float(time_val)/1000)
        while e_button['Emergency_Button1']['status'] == 1:
            time.sleep(0.5)
        curr_angle = motor_control["get_motor_position"][motor_id_str](robot, motor_offset)
        count = count+1
        if count > 5:
            while e_button['Emergency_Button1']['status'] == 1:
                time.sleep(0.5)
            time_val = motor_control["rotate_motor"][motor_id_str](robot,90, motor_offset, 0)
            count = 0
            print(('\tretrying motor_ID :',motor_id_str))
            time.sleep(ADD_TIME + float(time_val)/1000)
            while e_button['Emergency_Button1']['status'] == 1:
                time.sleep(0.5)
            time_val = motor_control["rotate_motor"][motor_id_str](robot,m_angle, motor_offset, 0)
            time.sleep(ADD_TIME + float(time_val)/1000)


def emergency_stop(robot,motor_offset):
    curr_angle = motor_control["get_motor_position"]["BASE_MOTOR_ID"](robot, motor_offset)
    time_val = motor_control["rotate_motor"]["BASE_MOTOR_ID"](robot,curr_angle, motor_offset, 1)

    curr_angle = motor_control["get_motor_position"]["AXIS_5_MOTOR_ID"](robot, motor_offset)
    time_val = motor_control["rotate_motor"]["AXIS_5_MOTOR_ID"](robot,curr_angle, motor_offset, 1)

    curr_angle = motor_control["get_motor_position"]["AXIS_3_MOTOR_ID"](robot, motor_offset)
    time_val = motor_control["rotate_motor"]["AXIS_3_MOTOR_ID"](robot,curr_angle, motor_offset, 1)

    curr_angle = motor_control["get_motor_position"]["AXIS_4_MOTOR_ID"](robot, motor_offset)
    time_val = motor_control["rotate_motor"]["AXIS_4_MOTOR_ID"](robot,curr_angle, motor_offset, 1)

    curr_angle = motor_control["get_motor_position"]["AXIS_2_MOTOR_ID"](robot, motor_offset)
    time_val = motor_control["rotate_motor"]["AXIS_2_MOTOR_ID"](robot,curr_angle, motor_offset, 1)

def load_peg_board_calib_data(json_data, motor_data):
    for p_name in peg_board:        
        if str(p_name) in json_data:
            peg = json_data[str(p_name)]
        else:
            print(("Failed to load Default Position["+p_name+"] data from JSON file"))
            peg = {"AXIS_2_MOTOR_ID": 90, "BASE_MOTOR_ID": 90, "AXIS_3_MOTOR_ID": 90, "AXIS_5_MOTOR_ID": 90, "AXIS_4_MOTOR_ID": 90, "PICK_DROP_MOTOR_ID": 90}
        motor_data[str(p_name)] = peg
    return motor_data

    
def read_json_file(motor_data):
    #with open('eww_robo_calib.json', 'r') as j_file:
    with open('/root/eww_robo_calib.json', 'r') as j_file:
        j_str = j_file.read()
        j_file.close()
    json_data = json.loads(j_str)
    
    if 'Motor_Offset' in json_data:
        motor_offset = json_data['Motor_Offset']
    else:       # Load default value
        print("Failed to load Motor_Offset data from JSON file")
        motor_offset = {"AXIS_2_MOTOR_ID": -250, "BASE_MOTOR_ID": 10, "AXIS_3_MOTOR_ID": 120, "AXIS_5_MOTOR_ID": 0, "AXIS_4_MOTOR_ID": 100, "PICK_DROP_MOTOR_ID": 0 }
            
    if 'Motor_Angle_Offset' in json_data:
        motors_angle_offset = json_data['Motor_Angle_Offset']
    else:
        print("Failed to load Motor_Angle_Offset data from JSON file")
        motors_angle_offset = {"AXIS_2_MOTOR_ID": 220, "BASE_MOTOR_ID": 235, "AXIS_3_MOTOR_ID": 0, "AXIS_5_MOTOR_ID": 0, "AXIS_4_MOTOR_ID": 0, "PICK_DROP_MOTOR_ID": 0}
    
    #robot.adjustAngleOffset(BASE_MOTOR_ID, motors_angle_offset['BASE_MOTOR_ID'])
    #robot.adjustAngleOffset(AXIS_2_MOTOR_ID, motors_angle_offset['AXIS_2_MOTOR_ID'])

    motor_data = {
        'Motor_Angle_Offset':motors_angle_offset,
        'Motor_Offset':motor_offset
        }
    motor_data = load_peg_board_calib_data(json_data, motor_data)
    return motor_data


