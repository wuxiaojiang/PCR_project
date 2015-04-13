#!/usr/bin/python
#-*-coding:utf-8-*-
#-------------------------------------
#程序名：服务器模块
#作 者：吴晓疆
#日 期：2015/4/4
#--------------------------------------
import socket
import time
#import gpio_tools
class pcr_control_server():
    def _init_(self):
        pass
    def build_udp(self,host,port):
        sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        self.host = host
        self.port = port
        sock.bind((host,port))
        return sock
    def run_udp(self,sock):
        #gpio_11 = gpio_tools.gpio()
        #gpio_11.init_gpio(11,1)
        while True:
            print 'waiting for connection......'
            try:
                msg,add = sock.recvfrom(8192)
                print 'got data from %s at %s'%(str(add),time.strftime('time : %H:%M:%S',time.localtime(time.time())))
                print msg
                if msg == 'stop':
                    message = 'PCR stopped'
                    sock.sendto(message,add)
                    #gpio_11.gpio_low(11)
                    sys.exit(1)
                elif msg == 'run':
                    message = 'pcr started'
                    #gpio_11.gpio_high(11)
                    sock.sendto(message,add)
                elif msg == 'test':
                    message = 'socket is good'
                    sock.sendto(message,add)
<<<<<<< HEAD
                elif msg == 'pause':
                    message = 'pcr pause'
                    gpio_11.gpio_low(11)
                    sock.sendto(message,add)
                elif msg = 'save':
                    message = 'saving'
                    sock.sendto(message,add)
=======
>>>>>>> parent of 6971bb3... holmes
                print '------------------------------------------------------'
            except(IOError):
                print 'socket error'
                sys.exit(1)
