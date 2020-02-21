"""
Use python3 to run this script

Author: Harshal Deshpande
"""

import sys
import time
from PyQt4 import QtGui, QtCore
import random

import pandas as pd
import numpy as np

import matplotlib.pyplot as plt
from matplotlib import style
from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt4agg import NavigationToolbar2QT as NavigationToolbar

style.use('ggplot')


class Window(QtGui.QWidget):

    def __init__(self):
        super(Window, self).__init__()

        self.params = ["Temperature", "Light Sensor"]
        self.time_slot = ["00-01","01-02","02-03","03-04","04-05","05-06","06-07","07-08","08-09","09-10","10-11","11-12","12-13","13-14","14-15","15-16","16-17","17-18","18-19","19-20","20-21","21-22","22-23","23-24"]
        
        # print(len(self.time_slot))

        self.setGeometry(600, 100, 800, 600)
        self.setWindowTitle("GUI for CSV")

        self.grid = QtGui.QGridLayout()
        self.setLayout(self.grid)

        self.plot_canvas()
        self.gen_dropdown_list()
        self.home()


        self.show()

    def home(self):
        btn = QtGui.QPushButton("Quit", self)
        btn.clicked.connect(self.exit_application)
        btn.resize(btn.minimumSizeHint())
        btn.move(700, 55)

        # Button to import CSV
        btn2 = QtGui.QPushButton('Import CSV', self)
        btn2.resize(btn2.sizeHint())
        btn2.clicked.connect(self.getCSV)
        self.grid.addWidget(btn2)
        btn2.move(600, 5)

        # Plot Button
        btn1 = QtGui.QPushButton('Plot', self)
        btn1.resize(btn1.sizeHint())
        btn1.clicked.connect(self.plot)
        self.grid.addWidget(btn1)
        btn1.move(405, 5)

    def plot_canvas(self):
        self.figure = plt.figure(figsize=(15, 5))
        self.canvas = FigureCanvas(self.figure)
        self.grid.addWidget(self.canvas, 2, 0, 1, 2)
        self.toolbar = NavigationToolbar(self.canvas,self)
        self.grid.addWidget(self.toolbar,1,0,1,2)

    def getCSV(self):
        filePath = QtGui.QFileDialog.getOpenFileName(self, 'CSV File', '~/Desktop/PyQt4', '*.csv')
        self.csv_data = pd.read_csv(str(filePath))
        self.csv_data["Date"] = pd.to_datetime(self.csv_data["Date"])
        self.csv_data = self.csv_data.set_index("Date")
        self.csv_data['Year'] = self.csv_data.index.year
        self.csv_data['Month'] = self.csv_data.index.month
        self.csv_data['Day'] = self.csv_data.index.day
        # print(self.csv_data)

        self.month_list = self.csv_data["Month"].unique()
        self.year_list = self.csv_data["Year"].unique()
        self.day_list = self.csv_data["Day"].unique()

        # tolist was not working
        self.year_list = [str(x) for x in self.year_list]
        self.month_list = [str(x) for x in self.month_list]
        self.day_list = [str(x) for x in self.day_list]
        # print(self.year_list)
        # print(self.month_list)
        # print(self.day_list)

        self.cb_year.addItems(self.year_list)
        self.cb_month.addItems(self.month_list)
        self.cb_day.addItems(self.day_list)

    def gen_dropdown_list(self):
        self.year_list = []
        self.month_list = []
        self.day_list = []
        self.cb_layout = QtGui.QHBoxLayout()

        # box for year
        self.cb_year = QtGui.QComboBox(self)
        # years = ["2018","2019"]  # should read years from the csv file
        self.cb_year.addItems(self.year_list)
        self.cb_year.move(5, 55)
        self.cb_year.currentIndexChanged.connect(self.selection_change_date)
        self.cb_layout.addWidget(self.cb_year)

        # box for months
        self.cb_month = QtGui.QComboBox(self)
        # months = ["1","2","3","4","5","6","7","8","9","10","11","12"]
        self.cb_month.addItems(self.month_list)
        self.cb_month.move(105, 55)
        self.cb_month.currentIndexChanged.connect(self.selection_change_date)
        self.cb_layout.addWidget(self.cb_month)

        # box for days
        self.cb_day = QtGui.QComboBox(self)
        # days = ["1","2","3","4"]  # should read years from the csv file
        self.cb_day.addItems(self.day_list)
        self.cb_day.move(205, 55)
        self.cb_day.currentIndexChanged.connect(self.selection_change_date)
        self.cb_layout.addWidget(self.cb_day)

        # box for sensor selection
        self.cb_param = QtGui.QComboBox(self)
        self.cb_param.addItems(self.params)
        self.cb_param.move(305, 55)
        self.cb_param.currentIndexChanged.connect(self.selection_change_date)
        self.cb_layout.addWidget(self.cb_param)

        # box for time slot selection
        self.cb_time_slot = QtGui.QComboBox(self)
        self.cb_time_slot.addItems(self.time_slot)
        self.cb_time_slot.move(405, 55)
        self.cb_time_slot.currentIndexChanged.connect(self.plot)
        self.cb_layout.addWidget(self.cb_time_slot)


    def selection_change_date(self, i):
        try:
            current_date = self.cb_year.currentText() + '-' + self.cb_month.currentText() + '-' + self.cb_day.currentText()
            # print(current_date)
            self.current_df = self.csv_data.loc[current_date]

        except KeyError:
            print("Key Error")
            # pass
        except AttributeError:
            print("Att error")
            # pass

    def plot(self):
        try:
            plt.cla()    # clears remaining plots from the canvas
            my_plot = self.figure.add_subplot(111)
            my_plot.clear()

            time_temp = []
            time_light = []
            # time_count = 0

            x_axis = self.current_df["Time"].tolist()
            y_axis_t = self.current_df["Temperature"].tolist()
            y_axis_l = self.current_df["Light Sensor"].tolist()
            print(x_axis)
            # print(y_axis_t)
            
            for time in x_axis:
                if time[:2] == self.cb_time_slot.currentText()[:2]:
                    time_temp.append(y_axis_t[x_axis.index(time)])
                    time_light.append(y_axis_l[x_axis.index(time)])
                    # time_count = time_count + 1
            
            my_plot.legend(loc=0)
            if self.cb_param.currentText() == "Temperature":
                try:
                    temp_label = "Avg. Temp bet " + self.cb_time_slot.currentText() + " is " + str(sum(time_temp)/len(time_temp))
                except ZeroDivisionError:
                    temp_label = "Avg. Temp bet " + self.cb_time_slot.currentText() + " is 0"
                print(temp_label)
                
                my_plot.plot(x_axis, y_axis_t, c='blue', label=str(temp_label))
                my_plot.legend(loc='upper left')
                my_plot.set_title("Temperature Sensor Data")
                # plt.plot(x_axis, y_axis_t, c='blue')
                # plt.show()
                print(y_axis_t)
                self.canvas.draw()
            else:
                try:
                    light_label = "Avg. light intensity " + self.cb_time_slot.currentText() + " is " + str(sum(time_light)/len(time_light))
                except ZeroDivisionError:
                    light_label = "Avg. light intensity " + self.cb_time_slot.currentText() + " is 0"
                print(light_label)

                my_plot.plot(x_axis, y_axis_l, c='red',label=str(light_label))
                my_plot.legend(loc='upper left')
                my_plot.set_title("Light Sensor Data")
                print(y_axis_l)
                self.canvas.draw()
            
        except KeyboardInterrupt:
            print("Cannot Plot!!")

    @staticmethod
    def exit_application():
        print("Hot Damn!!")
        time.sleep(0.1)
        sys.exit()


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    GUI = Window()

    sys.exit(app.exec_())
