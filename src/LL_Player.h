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


public:
  LL_Player(int baudrate);
  //void printDirectory(File dir, int numTabs);
  int returnNumber();
  void printDirectory(File dir, int numTabs);
  int begin();

};
