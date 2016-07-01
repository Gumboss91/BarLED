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
int initSPI();
signed char setRGB(int ledChan, char *input);

// debug funvlion
void printSPIBuff();


int initSPI(){
//Zaehlervariablen	
	int i;

// Init SPI Connection
	wiringPiSetupPhys();
	if( wiringPiSPISetup(spiChan, spiSpeed) == -1){
		printf("Coud not initialise SPI\n");
		return -1;}

// Set Pin State
//	pinMode(12, PWM_OUTPUT);
//	pullUpDnControl(12, PUD_OFF);
//	pwmWrite(12, 

// definieren des Initialvectors
	// Erstes Byte des Buffers 
	spiBuff[0] = 0x96;
	spiBuff[1] = 0xdf;
	spiBuff[2] = 0xff;
	spiBuff[3] = 0xff;

	// Restlicher Buffer
	for(i=4;i<LEN;i++)
		spiBuff[i] = 0xff;

	return;
}

signed char setRGB(int ledChan, char *input){
//Eingabepruefung
	if(ledChan > 4)
		return -1;
	// Hex Input convert to RGB Values
	int hexInValue = (int) strtol(input, NULL, 0);

	unsigned int b = 257*(hexInValue & 0xff);
	unsigned int g = 257*((hexInValue >> 8 ) & 0xff);
	unsigned int r = 257*((hexInValue >> 16) & 0xff);
	
	
	if(r > 65535 || g > 65535 || b > 65535)
		return -2;

//Setzten der Bufferbits fuer den ausgewäten Channel
	switch(ledChan){
		case 1:	spiBuff[27] = r;
						spiBuff[26] = r >> 8;
						spiBuff[25] = g;
						spiBuff[24] = g >> 8;
						spiBuff[23] = b;
						spiBuff[22] = b >> 8;
						break;
	
		case 2:	spiBuff[21] = r;
						spiBuff[20] = r >> 8;
						spiBuff[19] = g;
						spiBuff[18] = g >> 8;
						spiBuff[17] = b;
						spiBuff[16] = b >> 8;
						break;
		
		case 3:	spiBuff[15] = r;
						spiBuff[14] = r >> 8;
						spiBuff[13] = g;
						spiBuff[12] = g >> 8;
						spiBuff[11] = b;
						spiBuff[10] = b >> 8;
						break;
	
		case 4:	spiBuff[9] = r;
						spiBuff[8] = r >> 8;
						spiBuff[7] = g;
						spiBuff[6] = g >> 8;
						spiBuff[5] = b;
						spiBuff[4] = b >> 8;
						break;
		default:	return -1; break;
	}
	
// Send Buffer over SPI
	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		printf("Error while Sending\n");

	return 0;
}

void printSPIBuff(){
	int i=0;
	printf("\nInit: %x%x\n",spiBuff[0],spiBuff[1]);
	for(i=2;i<LEN;i++)
		printf("Buffer:%i %x\n",i,spiBuff[i]);
	return;
}
