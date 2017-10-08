#include "Extended_Adafruit_Player.h"


void Extended_Adafruit_Player::setBassAmplitude(uint16_t amplitude) {
  union sci_bass_m sci_base_value;

  if(amplitude < 0)
  {
      amplitude = 0;
  }
  else if(amplitude > 15)
  {
      amplitude = 15;
  }
  sci_base_value.word = sciRead(VS1053_REG_BASS);
  sci_base_value.nibble.Bass_Amplitude = amplitude;
  writeRegister(SCI_BASS, sci_base_value.word);

}

void Extended_Adafruit_Player::setBassFrequency(uint16_t frequency) {
  union sci_bass_m sci_base_value;


  if(frequency < 2)
  {
      frequency = 2;
  }
  else if(frequency > 15)
  {
      frequency = 15;
  }

  sci_base_value.word = sciRead(VS1053_REG_BASS);
  sci_base_value.nibble.Bass_Freqlimt = frequency;
  writeRegister(SCI_BASS, sci_base_value.word);
}

void Extended_Adafruit_Player::setTrebleAmplitude(uint8_t amplitude) {
  union sci_bass_m sci_base_value;
  if(amplitude < -8)
  {
      amplitude = -8;
  }
  else if(amplitude > 7)
  {
      amplitude = 7;
  }
  sci_base_value.word = sciRead(VS1053_REG_BASS);
  sci_base_value.nibble.Treble_Amplitude = amplitude;
  writeRegister(SCI_BASS, sci_base_value.word);
}

void Extended_Adafruit_Player::setTrebleFrequency(uint8_t frequency) {
  union sci_bass_m sci_base_value;
  if(frequency < 1)
  {
      frequency = 1;
  }
  else if(frequency > 15)
  {
      frequency = 15;
  }
  sci_base_value.word = sciRead(VS1053_REG_BASS);
  sci_base_value.nibble.Treble_Freqlimt = frequency;
  writeRegister(SCI_BASS, sci_base_value.word);
}

void Extended_Adafruit_Player::writeRegister(uint8_t addressbyte, uint16_t data) {
  union twobyte val;
  val.word = data;
  noInterrupts();
  writeRegister(addressbyte, val.byte[1], val.byte[0]);
  interrupts();
}

void Extended_Adafruit_Player::writeRegister(uint8_t addressbyte, uint8_t high, uint8_t low) {

  #ifdef SPI_HAS_TRANSACTION
  if (useHardwareSPI) SPI.beginTransaction(VS1053_CONTROL_SPI_SETTING);
  #endif
  digitalWrite(_cs, LOW);
  spiwrite(VS1053_SCI_WRITE);
  spiwrite(addressbyte);
  spiwrite(high);
  spiwrite(low);
  digitalWrite(_cs, HIGH);
  #ifdef SPI_HAS_TRANSACTION
  if (useHardwareSPI) SPI.endTransaction();
  #endif

}
