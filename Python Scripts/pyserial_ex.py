import serial

import os
import pandas as pd
import numpy as np

def main():
    # ser = serial.Serial('/dev/ttyUSB0',115200,timeout=1) 
    try:
        ser = serial.Serial('COM6',115200,timeout=1)
        print("COM6")
    except:
        try:
            ser = serial.Serial('COM4',115200,timeout=1)
            print("USB4")
        except:
            try:
                ser = serial.Serial('COM7',115200,timeout=1)
                print("com7")
            except:
                ser = serial.Serial('COM3',115200,timeout=1)
                print("COM3")
        

    global fdf
    count = 0
    print("bef loop")
    while ser.is_open:
        line = ser.readline().decode("ascii")
        new_data = line.strip().split(':')
        # line = line[1:]
        # print(new_data)
        if (new_data[0] == '@'):
            fdf.loc[count] = [line]
            count = count + 1
        # print(fdf)

if __name__ == "__main__":
    try:
        path = r"E:/ESD/LAB1/Python_Codes"
        csv_path = os.path.join(path,r"noobs1.csv")

        serial_data = {'Data':["Dummy"]}
        fdf = pd.DataFrame(serial_data)
        main()
    except serial.serialutil.SerialException:
        print(fdf)
        fdf.to_csv(csv_path)
        print("SERIAL CLOSED!!!")
    except KeyboardInterrupt:
        print(fdf)
        fdf.to_csv(csv_path)
        print("Interruption from keyboard....")