#!/usr/bin/python
#-*-coding:utf-8-*-
#--------------------------------------------------
#程序名：测试用客户端
#作 者：吴晓疆
#日 期：2015/4/5
#--------------------------------------------------
import socket
import time
host = '192.168.1.104'
port = 1080
def s_and_r(host,port,message):
    s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    try:
        s.connect((host,port))
        print '---------------------------------------'
        print 'try to connection %s at %d'%(host,port)
        s.send(message)
        print 'request:%s'%message
        msg,add = s.recvfrom(8192)
        print 'answer:%s'%msg
        print '---------------------------------------'
    except(IOError):
        print 'error'
        pass

if __name__ == '__main__':
    s_and_r(host,port,'run')
    time.sleep(3)
    s_and_r(host,port,'stop')
