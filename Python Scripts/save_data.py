import serial

import datetime

import os,sys
import pandas as pd
import numpy as np

def main():
    try:
        ser = serial.Serial('COM6',115200,timeout=1)
        print("COM6")
    except:
        try:
            ser = serial.Serial('COM12',115200,timeout=1)
            print("USB12")
        except:
            try:
                ser = serial.Serial('COM11',115200,timeout=1)
                print("com11")
            except:
                ser = serial.Serial('COM7',115200,timeout=1)
                print("COM7")
        
    global serial_data

    global prev_csv

    print("bef loop")
    while ser.is_open:
        line = ser.readline().decode("ascii")
        new_data = line.strip().split(':')
        now = datetime.datetime.now()

        # temp_data = {'Temperature':[],'Light Sensor':[],"Year":[],"Month":[],"Day":[],"Time":[]}

        if (new_data[0] == '@'):
            ser.write(b'!')
            # serial_data['Temperature'].append(new_data[1])
            # serial_data['Light Sensor'].append(0)
            # serial_data['Year'].append(datetime.date.today().year)
            # serial_data['Month'].append(datetime.date.today().month)
            # serial_data['Day'].append(datetime.date.today().day)
            # serial_data["Time"].append(now.strftime("%H:%M:%S"))
            # temp_data = {'Temperature':[float(new_data[1])],'Light Sensor':[float(new_data[2])],"Year":[datetime.date.today().year],"Month":[datetime.date.today().month],"Day":[datetime.date.today().day],"Time":[now.strftime("%H:%M:%S")]}
            temp_data = {'Temperature':[float(new_data[1])],'Light Sensor':[float(new_data[2])],"Date":[str(datetime.datetime.now())[:10]],"Time":[now.strftime("%H:%M:%S")]}

            temp_frame = pd.DataFrame(temp_data)
            # print("done with temp frame")
            final_data = pd.concat([prev_csv,temp_frame],sort=False)
            final_data.to_csv(csv_path,index=False)
            prev_csv = final_data

            # print(serial_data)    

if __name__ == "__main__":
    try:
        path = r"E:/ESD/LAB1/Python_Codes"
        csv_path = os.path.join(path,r"noobs_10sec.csv")
        serial_data = {'Temperature':[],'Light Sensor':[],"Date":[],"Time":[]}
        
        try:
            prev_csv = pd.read_csv(csv_path)
        except:
            prev_csv = pd.DataFrame(serial_data)

        main()
    
    except serial.serialutil.SerialException:
        current_data = pd.DataFrame(serial_data)
        final_data = pd.concat([prev_csv,current_data],sort=False)
        final_data.to_csv(csv_path, index=False)
        # print(final_data)
        # print(current_data)
        print("SERIAL CLOSED!!!")

    except KeyboardInterrupt:
        current_data = pd.DataFrame(serial_data)
        final_data = pd.concat([prev_csv,current_data],sort=False)
        final_data.to_csv(csv_path, index=False)
        print("Interruption from keyboard....")
    
    except:
        current_data = pd.DataFrame(serial_data)
        final_data = pd.concat([prev_csv,current_data],sort=False)
        final_data.to_csv(csv_path, index=False)
        print("Major Exception...")