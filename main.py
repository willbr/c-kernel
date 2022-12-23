from ctypes import *

dll = WinDLL('./lib-hello.dll')
dll.say_hello()

