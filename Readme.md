
This code is made to be included in ["LabLib"](https://github.com/LabToolsAU/LabLib) a repository with code intended to help first year IT students and the newest version can properbly be found there. This repo is only for my personal reference.

# Lab Lib player

##About this library
LabLib Player is a wrapper class for the [Adafruit_VS1053_FilePlayer](https://github.com/adafruit/Adafruit_VS1053_Library). It is made for the course Skitsering og Fysisk PrototypeDesign" at Aarhus University.

It configures the arduinos pins to only use the ["Music maker edition"](https://www.adafruit.com/product/1788) of the board and hides a lot of funvtions that are not needed.

Internally it uses an extended version of the Adafruit_VS1053 library. Where some of the functions is borrowed from [SFEMP3 Library](https://github.com/madsci1016/Sparkfun-MP3-Player-Shield-Arduino-Library)

All the music files in this library is prices of tracks downloaded at [Free Music Archive](http://freemusicarchive.org)

##Setup
In order to make the setup as easy as all the required .cpp and .h files (including the Adafruit_VS1053_FilePlayer) is placed along side the exampel .ino files. This also means that no libraries needs to be installed in order to use the code in the Arduino IDE.

** Follow the steps below to get the example code running **

4. Press the "Clone or download" button above and download a .zip archive with these files,
1. Copy the files from the directory "SD card files" to the root of a micro SD card
9. Install the shield on top of your Uno or Leonardo
2. Place the SD card in the shield.
5. Open the .ino file in one of the example folders and upload the code to your Arduino.
9. Plug in headphones or speakers and enjoy the sweet music :)


##Documentation of methods

##Constructor
'''c++
LL_Player(int baudrate);
'''
Constructor, makes a new LL player object

**Parameters**
int baudrate: The baudrate that the LL_Player will use to write error messages and stuff

**Returns:**
A new LL_Player object

**Example:**
'''c++
//Make new LL_Player with a baudrate of 9600
LL_Player musicPlayer = LL_Player(9600);
'''


'''c++

'''

**Parameters**

**Returns:**

**Example:**
'''c++
'''
**Notes**

int begin();

//Custom play methods for course
void startContinousPlay(String genre); //Play contrinous in background from one genre
void updateTrackPlaying();
void skipToNextTrackInGenre();
void skipToTrackNr(int tracknumber);


//Debugging
void printAllFilesOnSDCard();

//Callback method for Adafruits class
boolean useInterrupt(uint8_t type);
File getCurrentTrack();
boolean isPlayingMusic();
void feedBuffer(void);
boolean startPlayingFile(const char *trackname);
boolean playFullFile(const char *trackname);
void stopPlaying(void);
boolean paused(void);
boolean stopped(void);
void pausePlaying();
void resumePlaying();
void setVolume(uint8_t left, uint8_t right);
boolean playFullFile(char *trackname);

//Callback for frederiks extensions of Adafruit class
void setBassFrequency(uint16_t frequency);
void setBassAmplitude(uint16_t amplitude);
void setTrebleFrequency(uint8_t frequency);
void setTrebleAmplitude(uint8_t amplitude);
