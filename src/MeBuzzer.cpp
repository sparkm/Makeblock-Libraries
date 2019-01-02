/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * \class   MeBuzzer
 * \brief   Driver for Me Buzzer module.
 * @file    MeBuzzer.cpp
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/11/09
 * @brief   Driver for Me Buzzer module.
 *
 * \par Copyright
 * This software is Copyright (C), 2012-2016, MakeBlock. Use is subject to license \n
 * conditions. The main licensing options available are GPL V2 or Commercial: \n
 *
 * \par Open Source Licensing GPL V2
 * This is the appropriate option if you want to share the source code of your \n
 * application with everyone you distribute it to, and you also want to give them \n
 * the right to share who uses it. If you wish to use this software under Open \n
 * Source Licensing, you must contribute all your source code to the open source \n
 * community in accordance with the GPL Version 2 when your application is \n
 * distributed. See http://www.gnu.org/copyleft/gpl.html
 *
 * \par Description
 * This file is a drive for Me Buzzer device, The Me Buzzer inherited the 
 * MeSerial class from SoftwareSerial.
 *
 * \par Method List:
 *
 *    1. void MeBuzzer::setpin(int pin);
 *	  2. void MeBuzzer::tone(int pin, uint16_t frequency, uint32_t duration);
 *	  3. void MeBuzzer::tone(uint16_t frequency, uint32_t duration)
 *	  4. void MeBuzzer::noTone(int pin);
 *	  5. void MeBuzzer::noTone();
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * forfish         2015/11/09     1.0.0            Add description
 * </pre>
 *
 * @example BuzzerTest.ino
 * @example MbotBuzzerTest.ino
 * @example MbotBuzzerTest2.ino
 */
#include "MeBuzzer.h"
#include <avr/wdt.h>

#ifdef ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Buzzer to arduino port,
 * Buzzer pins are used and initialized here.
 * \param[in]
 *   None
 */
MeBuzzer::MeBuzzer()
{
}

/**
 * Alternate Constructor which can call your own function to map the Buzzer to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
MeBuzzer::MeBuzzer(uint8_t port):MePort(port)
{
}

#else // ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Buzzer to arduino port,
 * \param[in]
 *   switchPin - arduino port for buzzer detect pin.
 */
MeBuzzer::MeBuzzer(int pin)
{
  _pin[OFFSET_0] = pin;
}
#endif // ME_PORT_DEFINED

/**
 * \par Function
 *    setpin
 * \par Description
 *    Reset the buzzer available pin by its arduino port.
 * \param[in]
 *    pin - arduino port for buzzer detect pin.
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
void MeBuzzer::setpin(int pin)
{
  _pin[OFFSET_0] = pin;
}

/**
 * \par Function
 *    tone
 * \par Description
 *    Playing the tones.
 * \param[in]
 *    pin - Which pin on board that buzzer is connecting to.
 * \param[in]
 *    frequency - The speed of buzzer's tone play.
 * \param[in]
 *    duration - Time of a tone play.
 * \par Output
 *    None
 * \Return
 *    None.
 * \par Others
 *    Frequency (in hertz) and duration (in milliseconds).
 */
void MeBuzzer::tone(int pin, uint16_t frequency, uint32_t duration)
{
  _pin[OFFSET_0] = pin;
  int period = 1000000L / frequency;
  int pulse = period / 2;
  pinMode(_pin[OFFSET_0], OUTPUT);
  for (long i = 0; i < duration * 1000L; i += period) 
  {
    digitalWrite(_pin[OFFSET_0], HIGH);
    delayMicroseconds(pulse);
    digitalWrite(_pin[OFFSET_0], LOW);
    delayMicroseconds(pulse);
    wdt_reset();
  }
}

/**
 * \par Function
 *    tone
 * \par Description
 *    Playing the tones.
 * \param[in]
 *    frequency - The speed of buzzer's tone play.
 * \param[in]
 *    duration - Time of a tone play.
 * \par Output
 *    None
 * \Return
 *    None.
 * \par Others
 *    Frequency (in hertz) and duration (in milliseconds).
 */
void MeBuzzer::tone(uint16_t frequency, uint32_t duration)
{
  int period = 1000000L / frequency;
  int pulse = period / 2;
  pinMode(_pin[OFFSET_0], OUTPUT);
  for (long i = 0; i < duration * 1000L; i += period) 
  {
    digitalWrite(_pin[OFFSET_0], HIGH);
    delayMicroseconds(pulse);
    digitalWrite(_pin[OFFSET_0], LOW);
    delayMicroseconds(pulse);
    wdt_reset();
  }
}

/**
 * \par Function
 *    noTone
 * \par Description
 *    Do not playing the tones.
 * \param[in]
 *    pin - Which pin on board that buzzer is connecting to.
 * \par Output
 *    None
 * \Return
 *    None.
 * \par Others
 *    None
 */
void MeBuzzer::noTone(int pin)
{
  _pin[OFFSET_0] = pin;
  pinMode(_pin[OFFSET_0], OUTPUT);
  digitalWrite(_pin[OFFSET_0], LOW);
}

/**
 * \par Function
 *    noTone
 * \par Description
 *    Do not playing the tones.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \Return
 *    None.
 * \par Others
 *    None
 */
void MeBuzzer::noTone()
{
  pinMode(_pin[OFFSET_0], OUTPUT);
  digitalWrite(_pin[OFFSET_0], LOW);
}
