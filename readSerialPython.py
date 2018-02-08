#!/usr/bin/env python
import serial, io

outfile='/tmp/02272017Rand.txt'

ser = serial.Serial(
		port='/dev/ttyACM0',
		baudrate=115200,
)

sio = io.TextIOWrapper(
		io.BufferedRWPair(ser, ser, 1),
		encoding='ascii', newline='\r'
)

with open(outfile, 'a') as f:
	while ser.isOpen():
		datastring = sio.readline()
		f.write(datastring)
		f.flush()

ser.close()
