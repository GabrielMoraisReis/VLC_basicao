import Adafruit_BBIO.GPIO as GPIO
import time
import binascii

word = "ei"
a = bin(int(binascii.hexlify(word), 16))
count = 2
print("Full:", a)
GPIO.setup("P9_12", GPIO.OUT)
time.sleep(2)
for i in range(5):
        count = 2
        if a[0] == '0':
                time.sleep(4.5)
        elif a[0] == '1':
                GPIO.output("P9_12", GPIO.HIGH)
                time.sleep(1.5)
                GPIO.output("P9_12", GPIO.LOW)
                time.sleep(3)
        while count<len(a):
                print(a[count])
                if(a[count] == '1'):
                        print("Entrou1")
                        GPIO.output("P9_12", GPIO.HIGH)
                        time.sleep(1.5)
                        GPIO.output("P9_12", GPIO.LOW)
                        time.sleep(3)
                elif(a[count]== '0'):
                        print("Entrou2")
                        GPIO.output("P9_12", GPIO.LOW)
                        time.sleep(4.5)
                count = count + 1

