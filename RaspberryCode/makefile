all: setRGBTest.o BarLEDServer.o
 
setRGBTest.o: setRGBTest.c
	gcc setRGBTest.c -o setRGBTest -lwiringPi

BarLEDServer.o: BarLEDServer.c
	gcc BarLEDServer.c -o BarLEDServer -lpthread -lwiringPi
