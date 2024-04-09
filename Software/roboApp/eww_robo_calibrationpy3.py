import piarm
from eww_robo import *
import logging
import time
import json



def help_func():
    print("Robotic Arm Calibration Help Menu\n")
    print("\t -h or help     : for help menu")
    print("\t exit           : exit from calibration routine")
    print("\t save           : save the paramenters to eww_robo_calib.json file")
    print("\t torque         : set - to set the the torque")
    print("\t                  clear - to clear the torque")
    print("\t play           : enter peg name to go that location eg: play c3")
    print("\t read           : ")
    print("\t save           : ")
    print("\t calib          : ")
    print("\t offset calib   : ")
    print("\t ")
    print("")


    
def save_json_file(motor_data):
    if motor_data == None:
        print("use read command to get the data")
        return None
    json_motor_data = json.dumps(motor_data, indent=4, sort_keys=True)
    with open('eww_robo_calib.json', 'w') as j_file:
        j_file.write(json_motor_data)
        j_file.close

def check_a1_motor_values(robot, motor_offset):
    status = True
    msg = ''
    set_torque_all_motor(robot)
    time_val = motor_control["rotate_motor"]["BASE_MOTOR_ID"](robot,120, motor_offset, 0)
    time.sleep(1.0+time_val/1000)
    time_val = motor_control["rotate_motor"]["BASE_MOTOR_ID"](robot,0, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, BASE_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate (y/n): ")
    if check == 'y':
        if cp > 10 and cp < 950:
            print("Position ok for angle 0")
        else:
            status = False
            msg += "Motor position is not within range for angel 0\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")
    
    time_val = motor_control["rotate_motor"]["BASE_MOTOR_ID"](robot,180, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, BASE_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate (y/n): ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 180")
        else:
            status = False
            msg += "Motor position is not within range for angel 180\r\n"
            print("Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")
    time_val = motor_control["rotate_motor"]["BASE_MOTOR_ID"](robot,90, motor_offset, 0)
    time.sleep(time_val/1000)
    if not status:
        print("Error",msg)
    else:
        print("Base motor parameters are within range")
    return status


def check_a2_motor_values(robot, motor_offset):
    status = True
    msg = ''
    set_torque_all_motor(robot)
    time_val = motor_control["rotate_motor"]["AXIS_2_MOTOR_ID"](robot,125, motor_offset, 0)
    time.sleep(1.0+time_val/1000)
    time_val = motor_control["rotate_motor"]["AXIS_2_MOTOR_ID"](robot,70, motor_offset, 0)
    time.sleep(1.0+time_val/1000)
    cp = read_motorPosition(robot, BASE_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate (y/n): ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 70")
        else:
            status = False
            msg += "Motor position is not within range for angel 70\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")

    time_val = motor_control["rotate_motor"]["AXIS_2_MOTOR_ID"](robot,180, motor_offset, 0)
    time.sleep(1.0+time_val/1000)
    cp = read_motorPosition(robot, AXIS_2_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate (y/n): ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 180")
        else:
            status = False
            msg += "Motor position is not within range for angel 180\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")
    time_val = motor_control["rotate_motor"]["AXIS_2_MOTOR_ID"](robot,90, motor_offset, 0)
    time.sleep(time_val/1000)
    if not status:
        print("Error",msg)
    else:
        print("Axis2 motor parameters are within range")
    return status
    
def check_a3_motor_values(robot, motor_offset):
    status = True
    msg = ''
    set_torque_all_motor(robot)
    time_val = motor_control["rotate_motor"]["AXIS_3_MOTOR_ID"](robot,150, motor_offset, 0)
    time.sleep(1.0+time_val/1000)
    time_val = motor_control["rotate_motor"]["AXIS_3_MOTOR_ID"](robot,90, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, AXIS_3_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate: ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 90")
        else:
            status = False
            msg += "Motor position is not within range for angel 90\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")
    
    time_val = motor_control["rotate_motor"]["AXIS_3_MOTOR_ID"](robot,180, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, AXIS_3_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate: ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 210")
        else:
            status = False
            msg += "Motor position is not within range for angel 210\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")

    time_val = motor_control["rotate_motor"]["AXIS_3_MOTOR_ID"](robot,90, motor_offset, 0)
    time.sleep(time_val/1000)
    if not status:
        print("Error",msg)
    else:
        print("Axis3 motor parameters are within range")
    return status

def check_a4_motor_values(robot, motor_offset):
    status = True
    msg = ''
    set_torque_all_motor(robot)
    time_val = motor_control["rotate_motor"]["AXIS_4_MOTOR_ID"](robot,135, motor_offset, 0)
    time.sleep(1.0+time_val/1000)
    time_val = motor_control["rotate_motor"]["AXIS_4_MOTOR_ID"](robot,90, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, AXIS_4_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate: ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 90")
        else:
            status = False
            msg += "Motor position is not within range for angel 90\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")    
    time_val = motor_control["rotate_motor"]["AXIS_4_MOTOR_ID"](robot,180, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, AXIS_4_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate: ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 180")
        else:
            status = False
            msg += "Motor position is not within range for angel 180\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")

    time_val = motor_control["rotate_motor"]["AXIS_4_MOTOR_ID"](robot,90, motor_offset, 0)
    time.sleep(time_val/1000)
    if not status:
        print("Error",msg)
    else:
        print("Axis2 motor parameters are within range")
    return status
    

def check_a5_motor_values(robot, motor_offset):
    status = True
    msg = ''
    set_torque_all_motor(robot)
    time_val = motor_control["rotate_motor"]["AXIS_5_MOTOR_ID"](robot,120, motor_offset, 0)
    time.sleep(1.0+time_val/1000)
    time_val = motor_control["rotate_motor"]["AXIS_5_MOTOR_ID"](robot,10, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, AXIS_5_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate: ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 10")
        else:
            status = False
            msg += "Motor position is not within range for angel 10\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")
    
    time_val = motor_control["rotate_motor"]["AXIS_5_MOTOR_ID"](robot,180, motor_offset, 0)
    time.sleep(1.0 + time_val/1000)
    cp = read_motorPosition(robot, AXIS_5_MOTOR_ID)
    print("Current Position :",cp)
    check = input("Did motor rotate: ")
    if check == 'y':
        if cp > 100 and cp < 900:
            print("Position ok for angle 180")
        else:
            status = False
            msg += "Motor position is not within range for angel 180\r\n"
            print("Error: Do motor angle offset calibration")
    else:
        status = False
        msg += "Check motor connection\r\n"
        print("Check motor connection")
    time_val = motor_control["rotate_motor"]["AXIS_5_MOTOR_ID"](robot,90, motor_offset, 0)
    time.sleep(time_val/1000)
    if not status:
        print("Error",msg)
    else:
        print("Axis2 motor parameters are within range")
    return status

def pick_peg(robot, motor_offset, motor_angles, test):
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

##    for i in range(1,50):
##        time.sleep(0.5)
##        rotate_arm(robot, motor_offset, motor_angles["AXIS_5_MOTOR_ID"]+random.randint(-4,4), "AXIS_5_MOTOR_ID")
##        rotate_arm(robot, motor_offset, motor_angles["AXIS_4_MOTOR_ID"]+random.randint(-3,3), "AXIS_4_MOTOR_ID")
##        rotate_arm(robot, motor_offset, motor_angles["AXIS_2_MOTOR_ID"]+random.randint(0,1), "AXIS_2_MOTOR_ID")
    
    if not test:
        print("Picking..")
        v_init = read_motorVoltage(robot, PICK_DROP_MOTOR_ID)
        pick_flag = False
        while (pick_flag == False):
            (status, time_val) = rotate_a6_finger_motor(robot, PICK+55, motor_offset, 100)
            print("CP :",get_a6_finger_motor(robot, motor_offset))
            v_pick = read_motorVoltage(robot, PICK_DROP_MOTOR_ID)
            print('v_init :',v_init, '  v_pick : ',v_pick, 'V_DIFF', v_init-v_pick)
            if status and (v_pick < (v_init - V_DIFF)): #or (v_init > 7.0 and v_pick <6.90)
                print('picked')
                (status, time_val) = rotate_a6_finger_motor(robot, PICK, motor_offset, 100)
                new_angle = 70
                rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")
                pick_flag = True
            else:
                print('not picked.. retrying')
                (status, time_val) = rotate_a6_finger_motor(robot, PLACE-50, motor_offset, 100)
                new_angle = 70
                rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")
                v_init = read_motorVoltage(robot, PICK_DROP_MOTOR_ID)
                rotate_arm(robot, motor_offset, motor_angles["AXIS_5_MOTOR_ID"]+random.randint(-5,5), "AXIS_5_MOTOR_ID")
                rotate_arm(robot, motor_offset, motor_angles["AXIS_4_MOTOR_ID"]+random.randint(-3,3), "AXIS_4_MOTOR_ID")
                rotate_arm(robot, motor_offset, motor_angles["AXIS_2_MOTOR_ID"]+random.randint(0,1), "AXIS_2_MOTOR_ID")

def place_peg(robot, motor_offset, motor_angles):
    TOLERANCE = 2
    
    rotate_arm(robot, motor_offset, motor_angles["BASE_MOTOR_ID"], "BASE_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_5_MOTOR_ID"], "AXIS_5_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_3_MOTOR_ID"], "AXIS_3_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_4_MOTOR_ID"] + 2, "AXIS_4_MOTOR_ID")

    rotate_arm(robot, motor_offset, motor_angles["AXIS_2_MOTOR_ID"] - 2, "AXIS_2_MOTOR_ID")
    (status, time_val) = rotate_a6_finger_motor(robot, PLACE, motor_offset, 10)
    time.sleep(ADD_TIME + float(time_val)/1000)
    new_angle = 70
    rotate_arm(robot, motor_offset, new_angle, "AXIS_2_MOTOR_ID")


def cmd_app(robot):
    exit_flag = False
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
    
    rotate_arm(robot, motor_offset, 90, "AXIS_2_MOTOR_ID")
    rotate_arm(robot, motor_offset, 90, "AXIS_3_MOTOR_ID")
    rotate_arm(robot, motor_offset, 90, "AXIS_4_MOTOR_ID")
    rotate_arm(robot, motor_offset, 90, "BASE_MOTOR_ID")
    rotate_arm(robot, motor_offset, 90, "AXIS_5_MOTOR_ID")

    while exit_flag == False:
        input_str = input("$>> ")
        input_str = input_str.upper()   # to accept both lower and upper case
        if input_str == 'HELP' or input_str == '-H':
            help_func()
        if input_str == '':
            time.sleep(0.1)
        elif input_str == 'EXIT':
            exit_flag = True
##        elif input_str == 'CAM':
##            motor_offset = calibrate_all_motor(robot)
        elif input_str == 'SAVE':
            save_json_file(motor_data)
        elif input_str[0:6] == 'TORQUE':
            input_str_split = None
            input_str_split = input_str.split(' ')
            if input_str_split[0] == 'TORQUE' and input_str_split[1] == 'SET':
                set_torque_all_motor(robot)
                print('TORQUE CLEARED')
            elif input_str_split[0] == 'TORQUE' and input_str_split[1] == 'CLEAR':
                clear_torque_all_motor(robot)
                print('TORQUE CLEARED')
            else:
                print('unknown command')
        elif input_str[0:4] == 'TEST':
            input_str_split = input_str.split(' ')
            if input_str_split[0] == 'TEST':
                try:
                    if peg_board.index(input_str_split[1]) >= 0 :
                        print("Moving to Motor angles for "+input_str_split[1]+" location")
                        #set_arm_motor_angles(robot, motor_offset, motor_data[input_str_split[1]])
                        pick_peg(robot, motor_offset, motor_data[input_str_split[1]],True)
                    else:
                        print("Unknown Error:",input_str)
                except Exception as e:
                    print("unknow command",e)
                    pass
        elif input_str[0:4] == 'PICK':
            input_str_split = input_str.split(' ')
            if input_str_split[0] == 'PICK':
                try:
                    if peg_board.index(input_str_split[1]) >= 0 :
                        print("Moving to Motor angles for "+input_str_split[1]+" location")
                        #set_arm_motor_angles(robot, motor_offset, motor_data[input_str_split[1]])
                        pick_peg(robot, motor_offset, motor_data[input_str_split[1]],False)
                    else:
                        print("Unknown Error:",input_str)
                except Exception as e:
                    print("unknow command",e)
                    pass
        elif input_str[0:5] == 'PLACE':
            print('place')
            input_str_split = input_str.split(' ')
            if input_str_split[0] == 'PLACE':
                try:
                    if peg_board.index(input_str_split[1]) >= 0 :
                        print("Moving to Motor angles for "+input_str_split[1]+" location")
                        #set_arm_motor_angles(robot, motor_offset, motor_data[input_str_split[1]])
                        place_peg(robot, motor_offset, motor_data[input_str_split[1]])
                    else:
                        print("Unknown Error:",input_str)
                except Exception as e:
                    print("unknow command",e)
                    pass
        elif input_str == 'READ':
            motor_data = read_json_file(motor_data)
        elif input_str == 'PRINT':
            json_motor_data = json.dumps(motor_data, indent=4, sort_keys=True)
            print(json_motor_data)
        elif input_str[0:5] == 'CALIB':
            input_str_split = None
            input_str_split = input_str.split(' ')
            if input_str_split[0] == 'CALIB':
                try:
                    if peg_board.index(input_str_split[1]) >= 0:
                        print("Getting Motor angles for "+input_str_split[1]+" location")
                        motor_data[input_str_split[1]] = get_arm_motor_angles(robot, motor_offset)
                        print("Received motor angles")
                        set_arm_motor_angles(robot, motor_offset, motor_data[input_str_split[1]])
                        print("Setting to location")
                        check = input("Press any key to continue:")
                        clear_torque_all_motor(robot)
                    else:
                        print("Unknown Error:",input_str)
                except:
                    print("unknow command")
                    pass
        elif input_str == 'OFFSET CALIB':
            clear_torque_all_motor(robot)
            input("Keep all the motors  in 90 degree and press any key")
            set_torque_all_motor(robot)
            time.sleep(5)
            for motor in motors:
                motor_offset[motor] = int(round((read_motorPosition(robot, motors.get(motor)) - (90*4.23)),0))
                print(motor, ' -- > ', motor_offset[motor])
                time.sleep(1)
        elif input_str == 'CHECK A1':
            status = check_a1_motor_values(robot,motor_offset)
            if not status:
                print("Error: Do motor angle offset calibration and perform Offset calib again")
        elif input_str == 'CHECK A2':
            status = check_a2_motor_values(robot,motor_offset)
            if not status:
                print("Error: Do motor angle offset calibration and perform Offset calib again")
        elif input_str == 'CHECK A3':
            status = check_a3_motor_values(robot,motor_offset)
            if not status:
                print("Error: Do motor angle offset calibration and perform Offset calib again")
        elif input_str == 'CHECK A4':
            status = check_a4_motor_values(robot,motor_offset)
            if not status:
                print("Error: Do motor angle offset calibration and perform Offset calib again")
        elif input_str == 'CHECK A5':
            status = check_a5_motor_values(robot,motor_offset)
            if not status:
                print("Error: Do motor angle offset calibration and perform Offset calib again")
        else:
            print("unknow command")
    return (motor_data, motor_offset)

if __name__ == "__main__":
    logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.WARNING)
    #logging.getLogger().setLevel(logging.DEBUG)
    robot = piarm.PiArm()
    robot.connect("COM8")
    #robot.connect("/dev/ttyUSB0")
                    
    #motor_offset = calibrate_all_motor(robot)        
    (motor_data, motor_offset) = cmd_app(robot)

        

