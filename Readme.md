
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

1. Press the "Clone or download" button above and download a .zip archive with these files,
1. Copy the files from the directory "SD card files" to the root of a micro SD card
9. Install the shield on top of your Uno or Leonardo
2. Place the SD card in the shield.
5. Open the .ino file in one of the example folders and upload the code to your Arduino.
9. Plug in headphones or speakers and enjoy the sweet music :)


## Documentation of methods

## Constructor
```c++
LL_Player(int baudrate);
```
Constructor, makes a new LL player object

**Parameters**
int baudrate: The baudrate that the LL_Player will use to write error messages and stuff

**Returns:**
A new LL_Player object

**Example:**
```c++
//Make new LL_Player with a baudrate of 9600
LL_Player llplayer = LL_Player(9600);
```


## Starts the LL Player

```c++
int begin();

```

**Returns:**
0: If something is wrong,
1: If everything seems correct

**Notes**
Should be called before trying to do anything else


## Start Continous Play

Starts playing music from a subfolder (genre). Continous to play the music as long as updateTrackPlaying is called regularly. When all files in folder is played it will start over.

```c++
void startContinousPlay(String genre)
```

**Parameters**
A string representing a genre. The string should match a folder with mp3 files on the SD card. The name is case sensitive.


**Example:**

```c++
LL_Player llplayer = LL_Player(9600);
llplayer.startContinousPlay("dubstep");
```

## Update track playing
Checks if no track is playing. If there is no track it plays the next one int he genre folder. Called often to ensure a track is playing.  

```c++
void updateTrackPlaying();
```

**Notes**
__SHOULD__ be called ALL the time. No call = no music  


## Skip track

Plays the next track in the genre folder. Plays the first track if there are no tracks left.


```c++
void skipToNextTrackInGenre()
```


## Skip to specific track

Plays a specific track in a genre, if it exists

```c++
void skipToTrackNr(int tracknumber);
```

**Parameters**
An integer with a number between 1 and the number of files in the genre folder.

**Example:**
```c++
llplayer.skipToTrackNr(99);

```

**Notes**
 If number does not exist it writes out an error message to the serial monitor and does nothing. This could probably be done in a more clever way... Meh...

 ## Print all files on SD card

 Does what the name says. Makes debugging easier.

 ```c++
 void printAllFilesOnSDCard();
 ```

**Notes**
The SD cards is formatet with a Fat32 filesystem which means filenames can not be longer that 8 characters. If you need to use this function that is probably the error.  

## Get Name Of Current Track

Gets the name of the track that isn playing

```c++
String getCurrentTrackName()
```

**Returns:**
A String with the name of the track that is playing

**Example:**
```c++
String name = llplayer.getCurrentTrackName();
```


## Check if music is playing

```c++
boolean isPlayingMusic()
```

**Returns:**
A boolean
false: if music is not playing
true: if music is playing

**Example:**

```c++
if(llplayer.isPlayingMusic()) //Do stuff
```
**Notes**



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
