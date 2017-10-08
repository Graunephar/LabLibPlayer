/****************************************************
"Lab Lib" Music player extension by Graunephar

                       -s`
                     -sdd`
                   -ydddd`
                 -ydddddd`
               :ydddddddo
             :ydddddddo`
           :yddddddd+`   yddddd/           :dddddh
         /hddddddd+`     +dddddh-         .hddddds
       /hddddddh+`       `ydddddds:`   `-oddddddh`
    `/hddddddh+`          `oddddddddddddddddddds`
  `/hddddddh/`              -sddddddddddddddds-
`+hddddddh/                   `:oydddddddyo/`

// It's not a dick
****************************************************/
#include <SD.h>
#include "Adafruit_VS1053.h"


class LL_Player {

  Adafruit_VS1053_FilePlayer _musicPlayer;
  int _baudrate;
  String _currentGenre;
  int _currentTrackNumber;


public:
  //Setup methods
  LL_Player(int baudrate);
  void printDirectory(File dir, int numTabs); //List all stuff on SD card
  int begin();

  //Custom play methods for course
  void setGenre(String genre); //Tell which grenre we want to play
  void continousPlay(); //Play contrinous in background from one genre
  void updateTrackPlaying();

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


private:
  String getNextTrackName();

};
