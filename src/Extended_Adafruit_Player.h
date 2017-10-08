#include "Adafruit_VS1053.h"



#define SCI_BASS 0x02
#define VS1053_CONTROL_SPI_SETTING  SPISettings(250000,  MSBFIRST, SPI_MODE0)
#define VS1053_DATA_SPI_SETTING     SPISettings(8000000, MSBFIRST, SPI_MODE0)

class Extended_Adafruit_Player : public Adafruit_VS1053_FilePlayer{

  union sci_bass_m {

    /**
     * \brief whole word value
     *
     * allows access and handeling of whole uint16_t (aka word) value
     */
      uint16_t word;

    /**
     * \brief individual Nibbles
     *
     * allows access and handeling of individual nibble values
     */
      struct {
        uint8_t  Bass_Freqlimt    : 4; // 0..3
        uint8_t  Bass_Amplitude   : 4; // 4..7
        uint8_t  Treble_Freqlimt  : 4; // 8..11
         int8_t  Treble_Amplitude : 4; // 12..15
      }nibble;
    } ;

    /**
     * \brief A handler for accessing bytes of a word.
     *
     * Often individual bytes of a word are handled by bit shifting e.g.
     * \code
     * Mp3WriteRegister(SCI_MODE, ((MP3SCI_MODE >> 8) & 0xFF), (MP3SCI_MODE & 0xFF) );
     * \endcode
     * This may lead to excessive shifts and worse; signed carries of the second shift,
     * If the casting is not correct.
     * This union allows a more efficient and simpler method to directly access the
     * individual bytes of the word.
     * And is convienent for handeling Endian issues. Where byte[0..1] can be
     * assigned specific endian and the word (aka uint16_t) can be used.
     */

    union twobyte {

    /**
     * \brief whole word value
     *
     * allows access and handeling of whole uint16_t (aka word) value
     */
      uint16_t word;

    /**
     * \brief individual bytes
     *
     * allows access and handeling of individual uint8_t (aka bytes),
     * either MSB or LSB byte of word
     */
      uint8_t  byte[2];
    } ;

public:
  void setBassFrequency(uint16_t frequency);
  void setBassAmplitude(uint16_t amplitude);
  void setTrebleFrequency(uint8_t frequency);
  void setTrebleAmplitude(uint8_t amplitude);

  void writeRegister(uint8_t addressbyte, uint16_t data);
  void writeRegister(uint8_t addressbyte, uint8_t high, uint8_t low);


};
