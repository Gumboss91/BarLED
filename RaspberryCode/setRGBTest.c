#include "setRGB.h"

int main(int argc, char *argv[]) {
	
	initSPI();
	setRGB(1, 1000, 1000, 1000);
	printSPIBuff();
	return 0;
}

