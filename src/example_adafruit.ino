/***************************************************
  This is an example for the Adafruit VS1053 Codec Breakout

  Designed specifically to work with the Adafruit VS1053 Codec Breakout
  ----> https://www.adafruit.com/products/1381

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// include SPI, MP3 and SD libraries
#include "LL_Player.h"


#define BAUDRATE 9600 // The baudrate used by llplayer to send error messeges
LL_Player llplayer = LL_Player(BAUDRATE);

void setup() {

  Serial.begin(BAUDRATE); // we want to use the same baud rate as ll player so we can outout to the same console

  while (!Serial) {
  ; // wait for serial port to connect. Needed for native USB port only
  }

  setupLLPlayer();

  llplayer.startContinousPlay("dakkeduk"); // SHOULD ONLY BE DONE ONCE OR WHEN CHANGING GENRE
}


void loop() {

delay(10);
 /*
 * PRO TIP: Use millis not delays in your code
 * Otherwise continous track update will not happen ;) */

 llplayer.updateTrackPlaying(); //should be called continbously in order to guarante continous play.



/*
  // Play one file, don't return until complete
  Serial.println(F("Playing track 001"));
  llplayer.playFullFile("track001.mp3");
  // Play another file in the background, REQUIRES interrupts!
  Serial.println(F("Playing track 002"));
  llplayer.startPlayingFile("track002.mp3");
  Serial.print("IS PLAYING: ");
  Serial.println(llplayer.isPlayingMusic());
  delay(10000);
  llplayer.pausePlaying();
  Serial.print("PAUSED STATUS: ");
  Serial.println(llplayer.paused());
  delay(5000);
  llplayer.resumePlaying();
*/

}

void setupLLPlayer() {
  if(!llplayer.begin()) {
    ; //The Adafruit VS1053 shield is not configured correctly. Halt here.
    while(1);
  };
}


/// File listing helper
