
from sense_hat import SenseHat
import math
import serial


sense = SenseHat()
humidity = sense.get_humidity()
temp = sense.get_temperature()-10
pressure = sense.get_pressure()/1000
altitude = 44330*(1-pow(pressure/1000, 1/525.55))
ser = serial.Serial('/dev/ttyUSB0', 9600)
f = open("rezultate.txt","w+")


while True:
    data = raw_input('Show: ')

    if data == 'H' or data == 'h':
        print("Umiditate: %s %%rH" % humidity)
        f.write("Umiditate: %s %%rH" % humidity)
    if data == 'T' or data == 't':
        print("Temperatura: %s C" % temp)
        f.write("Temperatura: %s C" % temp)
    if data == 'P' or data == 'p':
        print("Pressure: %s Bars" % pressure)
        f.write("Pressure: %s Bars" % pressure)
    if data == 'E' or data == 'e':
        print("Altitude: %s Meters" % altitude)
        f.write("Altitude: %s Meters" % altitude)
    if(data == 'Q' or data == 'q'):
        ser.write('Q')
    if(data == 'W' or data == 'w'):
        ser.write('W')
    if(data == 'S' or data == 's'):
        ser.write('S')
    if(data == 'A' or data == 'a'):
        ser.write('A')
    if(data == 'D' or data == 'd'):
        ser.write('D')
    if(data == 'C' or data == 'c'):
        ser.write('C')
        read_ser=ser.readline();
        print(read_ser);
        f.write("s%" % read_ser);
    if(data == 'M' or data == 'm'):
        ser.write('M')
        read_ser=ser.readline();
        print(read_ser);
        f.write("s%" % read_ser);
    if(data == 'X' or data == 'x'):
        ser.write('X')
    if(data == 'Y' or data == 'y'):
        f.close()
