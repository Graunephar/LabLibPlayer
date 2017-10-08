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
#define DELAY 60000 // If you choose new genres to wuickly things will crash

LL_Player llplayer = LL_Player(BAUDRATE);

unsigned long timestamp = millis();

String genres[] = {"jazz", "dakkeduk", "hip-hop"};
const int nrOfGenres = 3; //The number of genres in playlist

void setup() {

  Serial.begin(BAUDRATE); // we want to use the same baud rate as ll player so we can outout to the same console

  while (!Serial) {
  ; // wait for serial port to connect. Needed for native USB port only
  }

  randomGenrePicker();
  setupLLPlayer();

  llplayer.startContinousPlay("hip-hop"); // Start playing from new genre

}


void loop() {

delay(10);
 /*
 * PRO TIP: Use millis not delays in your code
 * Otherwise continous track update will not happen ;) */

 llplayer.updateTrackPlaying(); //should be called continbously in order to guarante continous play.

 //Changing genre after 60 seconds
 if(millis() > timestamp + DELAY) {
   String newgenre = randomGenrePicker();
   llplayer.startContinousPlay(newgenre); // Start playing from new genre
   timestamp = millis();
}

}

//Pick a random genre from an array of genres
String randomGenrePicker() {
  int rando = random(0, nrOfGenres + 1); //Generate random nr netween 0 and the size of the playlist
  Serial.print("New Genre picked: ");
  Serial.println(genres[rando]);
  return genres[rando];
}

void setupLLPlayer() {
  if(!llplayer.begin()) {
    ; //The Adafruit VS1053 shield is not configured correctly. Halt here.
    while(1);
  };
}


/// File listing helper
