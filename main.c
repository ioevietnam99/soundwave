//this file contains the main function of our project

#include <stdio.h>
#include "sound.h"

int main(void){
	while(1){	//loop forever
		//run system command "arecord" to record 1 sec of wav
		system("arecord -r16000 -c1 -f S16_LE -d1 test.wav");
		//display WAV header
		dispWAVHeader("test.wav");
		//display WAV header strength as decibel values	
		break;	//loop runs just once
	}
	return 0;
}
