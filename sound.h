//constant definition
#define SAMPLERATE 16000

//struct /union definition
typedef struct{
	char chunkID[4];	//"RIFF"
	unsigned int chunkSize;	//4 bytes
	char format[4];		//"WAVE"
	char subchunk1ID[4];	//"fat"
	unsigned int subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char subchunk2ID[4];
	unsigned int subchunk2Size;
}WAVHeader;
//Function prototypes
void dispWAVHeader(char filename[]);
void dispWAVData(char filename[]);
void printID(char []);
