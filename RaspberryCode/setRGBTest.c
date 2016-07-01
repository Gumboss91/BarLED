#include "setRGB.h"

int main(int argc, char *argv[]) {
	
	initSPI();
	
	setRGB(1,argv[1]);
//	printSPIBuff();
	return 0;
}

