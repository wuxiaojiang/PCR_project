import serial   
ser = serial.Serial()  
ser.baudrate = 9600  
ser.port = 3  
ser.open()
while True:
    t = ser.read(1) 
    print ord(t)
