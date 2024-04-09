import serial
import threading
import json

#class SerialPortHandlerError(Exception):
    #console_print (ERROR_LOG, "Error in Serialport")
    #pass

def extract_json_data(input_string):
    parsed_json = None
    incomplete_string = ''
    try:
        # Find the start and end indices of the JSON string
        start_index = input_string.find('{')
        end_index = input_string.rfind('}')
        if(len(input_string) == 0):
            parsed_json = None
            incomplete_string = ''
            #print("test0:",incomplete_string)
        elif ((start_index != -1) and (end_index != -1)):
            json_string = input_string[start_index:end_index + 1]
            if(len(input_string) >  end_index + 1):
                incomplete_string = input_string[end_index + 1: ]
            #print("test1:",incomplete_string)
            parsed_json = json.loads(json_string)
        elif start_index != -1 and end_index == -1:
            incomplete_string = input_string[start_index:]
            #print("test2:",incomplete_string)
        elif start_index == -1:
            incomplete_string = input_string
            #print("test3:",incomplete_string)
    except json.JSONDecodeError as e:
        parsed_json = None
        #print("Json Exception:", e)
        #print("test4:",incomplete_string)
        pass
    except Exception as e:
        print("Exception:", e)
        pass
    finally:
        #print("json data:", parsed_json)
        #print("incomplete_string:", incomplete_string)
        return (parsed_json, incomplete_string)

class  SerialPortHandler(object):
    def __init__(self, commPort, baudrate = 115200, timeout= 0.5):
        self.alive = False
        self.serial_comm = None
        self.commPort = commPort
        self.baudrate = baudrate
        self.timeout = timeout
        self._rxData = None
        self._rxStr = ''
        self._rxLock = threading.Lock()
        self.rxThread = None
    def connect(self):
        try:
            self.serial_comm = serial.Serial(port = self.commPort, baudrate=self.baudrate, timeout=self.timeout)
            self.alive = True
            self.rxThread = threading.Thread(target=self._readLoop)
            self.rxThread.daemon = True
            self.rxThread.start()
            print("connected to : " +self.serial_comm.name)
            return True
        except serial.SerialException as err:
            print("Port Error: Couldn't Open Port.. : "+str(err))
            pass
            return False
    def _readLoop(self):
        #internal Function: Donot call it from the Application script
        try:
            while self.alive:
                data = self.serial_comm.read(100).decode()
                if data != '':
                    with self._rxLock:
                        self._rxStr = self._rxStr + data
                        (temp_data,self._rxStr) = extract_json_data(self._rxStr)
                        if temp_data != None:
                            self._rxData = temp_data
                            #print("Data Updated:", self._rxData)
                        #self._rxData.append(data)
                        #self._rxStr = self._rxStr + ''.join(str(data))
        except serial.SerialException as err:
            self.alive = False
            try:
                self.serial_comm.close()
            except Exception:
                pass
    def get_read_data(self):
        if self.alive is True:
            with self._rxLock:
                temp_jsonData = self._rxData
                self._rxData = None
            return temp_jsonData
        else:
            print("Comport Not Alive: "+self.serial_comm.name)
            return None
    def write_data(self, send_serial_data):
        if self.alive is True:
            return self.serial_comm.write(send_serial_data)
            #return self.serial_comm.write(bytes(send_serial_data, 'utf-8'))
    def disconnect(self):
        self.alive = False
        self.rxThread.join()
        self.serial_comm.close()
        print('Closing Comport :'+self.serial_comm.name)
    def __del__(self):
        print('Exiting SerialPortHandler - Closing Comport :'+self.serial_comm.name)
        try:
            self.disconnect()
        except Exception:
            pass
