from ctypes import *

dll = WinDLL('./lib-hello.dll')
dll.say_hello()

n = dll.double_int(9)
print(n)

dll.double_float.argtypes = [c_float]
dll.double_float.restype = c_float

f = dll.double_float(3.14)
print(f"{f:0.2f}")
