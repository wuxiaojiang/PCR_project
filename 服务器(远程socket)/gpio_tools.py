#!/usr/bin/python
#-*-coding:utf-8-*-
#-----------------------------------
#程序名：远程服务器gpio接口
#作 者：吴晓疆
#日 期：2015/4/7
#-----------------------------------
import RPi.GPIO as GPIO
class gpio():
    def _init_(self):
        pass
    def init_gpio(self,num,flag):
        self.num=num
        GPIO.setmode(GPIO.BOARD)
        if flag == 1:
            GPIO.setup(num,GPIO.OUT)
        elif flag == 0:
            GPIO.setup(num,GPIO.IN)
    def gpio_high(self,num):
        GPIO.output(num,True)
    def gpio_low(self,num):
        GPIO.output(num,False)
            
