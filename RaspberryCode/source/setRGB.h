//Header  setRGB.h

//Include Standart Libs
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

// Wiring PI Includes
#include <wiringPi.h>
#include <wiringPiSPI.h>

// SPI Definitions
#define LEN 28
int spiChan = 1;
int spiSpeed = 1000000;

// Buffer for SPI communication
unsigned char spiBuff[LEN];

// function declaration
void initSPIBuff();
signed char setRGB(int ledChan, int r, int g, int b);

// debug funvlion
void printSPIBuff();




