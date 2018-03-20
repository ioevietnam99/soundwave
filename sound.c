#include "sound.h"
#include <stdio.h>
#include <math.h>
//function definition of printID()
void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);

	printf("\n");
}

//function definition of disWAVData()
void dispWAVData(char filename[]){
	int i,j;	//loop counters
	FILE *fp;	//File handler to open the file "test.wav"
	double rms[80], sum;		//80 pieces of RMS value
	short samples[SAMPLERATE];	//totally 16000 samples in 1 sec
	WAVHeader mh;		//just used tokip over te header of a file

	fp = fopen(filename, "r");

	if(fp == NULL){	//if fopen fails
		printf("Error when open the file!\n");
		return;
	}
	fread(&mh, sizeof(mh), 1, fp);	//Skip over the header of a wave file
	fread(samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	for(i=0; i<80; i++){
		for(j=0, sum=0.0; j<SAMPLERATE/80; j++){
			sum += samples[j+i*200]*samples[j+i*200];
		}
		rms[i] = sqrt(sum/200);
		printf("rms[%d]: %10.4f\n", i, rms[i]);
	}
}

//function definition of dispWAVHeader()
void dispWAVHeader(char filename[]){
	FILE *fp;
	WAVHeader mh;	//an instance of WAVHeader struct

	//open the test.wav file for reading
	fp = fopen(filename, "r");
	if(fp == NULL){	//if  fopen fails
		printf("Error when open the file \n");
		return;	//close the opened file
	}
	fread(&mh, sizeof(mh), 1, fp);
	fclose(fp);	//close the opened file
	printf("Chunk ID: ");
	printID(mh.chunkID);
	printf(" chunk size: %d\n", mh.chunkSize);
	printf("Format: ");
	printID(mh.format);
	printf(" subchunk 1 ID: ");
	printID(mh.subchunk1ID);
	printf(" subchunk 1 size: %d\n", mh.subchunk1Size);
	printf(" audio format: %d\n", mh.audioFormat);
	printf(" num channels: %d\n", mh.numChannels);
	printf(" sample rate: %d\n", mh.sampleRate);
	printf(" byte rate: %d\n", mh.byteRate);
	printf(" block align: %d\n", mh.blockAlign);
	printf(" bits per sample: %d\n", mh.bitsPerSample);
	printf(" subchunk 2 ID: ");
	printID(mh.subchunk2ID);
	printf(" subchunk 2 size: %d\n", mh.subchunk2Size);
}
