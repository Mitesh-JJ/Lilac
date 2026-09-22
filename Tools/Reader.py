import serial
import time

SRC       = "/dev/ttyUSB0"
BAUD_RATE = 9600

source = serial.Serial(port = SRC, baudrate = BAUD_RATE, timeout = 0.5)
time.sleep(3) # Remote resync pause

while True:
    data = source.read(5)
    if data:
        print(data[0], data[1], data[2], data[3], data[4])
