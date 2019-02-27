rapi.py goes to the raspberry pi, this should be the only file you need as it serve as the communication gateway from GUI to the platform.
master.ino is the one goes to Arduino Nano.
slave.ino is the one goes to the Protoneer Shield.

controllerArduino.ino is not needed if you are using Nano + Shield (instead of just shield), but I still have it there just in case we decide to reduce the number of microcontroller.
