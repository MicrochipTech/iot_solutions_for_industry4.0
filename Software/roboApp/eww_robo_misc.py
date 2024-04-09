import ntplib
import time
import subprocess
import cv2



ntp_server = ['de.pool.ntp.org',
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

def get_ntp_time(time_server, update_system_time):
    g_time = None
    client = ntplib.NTPClient()
    for host in time_server:
        try:
            print('Getting time from',host)
            response = client.request(host, version=3)
            g_time = time.gmtime(response.tx_time)
            break
        except Exception as e:
            print("Failed to get time :",e)
            pass
        
    if g_time:
        date_time = str(g_time.tm_year)+"-"+str(g_time.tm_mon)+"-"+str(g_time.tm_mday)+' '+str(g_time.tm_hour)+":"+str(g_time.tm_min)+":"+str(g_time.tm_sec)
        print(date_time)
        if update_system_time:
            cmd = 'date -s '+'"'+date_time+'"'
            p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
            p_status = p.wait()
    else:
        date_time = None
    return date_time

    
def enable_ap_mode():
    output = subprocess.check_output('iw phy0 interface add p2p0 type station', shell=True)
    print(output)
    time.sleep(2)
    output = subprocess.check_output('hostapd /etc/hostapd.conf -B &', shell=True)
    print(output)
    time.sleep(2)
    output = subprocess.check_output('ifconfig p2p0 192.168.0.1', shell=True)
    print(output)
    time.sleep(2)
    output = subprocess.check_output('/etc/init.d/S80dhcp-server start', shell=True)
    print(output)
    time.sleep(2)
    
def get_ip():
    ip = None
    ip_str=b'ip_address='
    ip_len = 16
    output = subprocess.check_output('wpa_cli status', shell=True)
    t1 = output.find(ip_str)
    if t1 > 30:
        t1 += len(ip_str)
        t2 = output[t1:t1+ip_len]
        t3 = t2.find(b'\n')
        ip = output[t1:t1+t3]
    return ip    


def find_wbz_port():
    args = {'/dev/ttyACM0':"udevadm info -q property --export -n /dev/ttyACM0 | grep DEVLINKS",
            '/dev/ttyACM1':"udevadm info -q property --export -n /dev/ttyACM1 | grep DEVLINKS",
            '/dev/ttyACM2':"udevadm info -q property --export -n /dev/ttyACM2 | grep DEVLINKS",
            '/dev/ttyACM3':"udevadm info -q property --export -n /dev/ttyACM3 | grep DEVLINKS"}
    for arg in args:
        try:
            output = subprocess.check_output(args[arg], shell=True)
        except:
            output = ''
            pass
        if output.find(b'Microchip_Technology_Inc._MCP2200_USB_Serial_Port_Emulator_') != -1:
            return arg
    return None
    
