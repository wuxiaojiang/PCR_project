#!/usr/bin/python
#-*-coding:utf-8-*-
#---------------------------------------
#程序名：GPIO_NOKIA5110驱动
#作 者：吴晓疆
#日期：2015/4/4
#---------------------------------------
import RPi.GPIO as GPIO
import time
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
RST  = 11
DC   = 12
SDIN = 13
SCLK = 15
E_PULSE = 0.00005
E_DELAY = 0.00005
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class 5110():
    def _init_(self):
        pass
    
