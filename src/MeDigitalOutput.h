/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * \class   MeDigitalOutput
 * \brief   Driver for Me-Light Sensor module.
 * @file    MeDigitalOutput.h
 * @author  MakeBlock
 * @version V1.0.2
 * @date    2015/11/09
 * @brief   Header file for Me-Light Sensor.cpp
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
 *
 * \par Method List:
 *
 *    1. void    MeDigitalOutput::setpin(uint8_t ledPin, uint8_t sensorPin)
 *    2. int16_t MeDigitalOutput::read()
 *    3. void    MeDigitalOutput::lightOn()
 *    4. void    MeDigitalOutput::lightOff()
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/07/24     1.0.0            Rebuild the old lib.
 * Rafael Lee       2015/09/02     1.0.1            Added function setpin and some comments.
 * Mark Yan         2015/11/09     1.0.2            fix some comments error.
 * </pre>
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MeDigitalOutput_H
#define MeDigitalOutput_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "MeConfig.h"

#ifdef ME_PORT_DEFINED
#include "MePort.h"
#endif // ME_PORT_DEFINED

/**
 * Class: MeDigitalOutput
 * \par Description
 * Declaration of Class MeDigitalOutput.
 */
#ifndef ME_PORT_DEFINED
class MeDigitalOutput
#else // !ME_PORT_DEFINED
class MeDigitalOutput : public MePort
#endif // !ME_PORT_DEFINED
{
public:
#ifdef ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the light sensor to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  MeDigitalOutput(void);

/**
 * Alternate Constructor which can call your own function to map the light sensor to arduino port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  MeDigitalOutput(uint8_t port);
#else // ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the light sensor to arduino port
 * \param[in]
 *   ledPin - arduino port for led input
 * \param[in]
 *   sensorPin - arduino port for sensor data read
 */
  MeDigitalOutput(uint8_t ledPin);
#endif  // ME_PORT_DEFINED
/**
 * \par Function
 *    setpin
 * \par Description
 *    Set I2C data pin, clock pin and clear display. \n
 *    dataPin - the DATA pin for Seven-Segment LED module. \n
 *    clkPin  - the CLK pin for Seven-Segment LED module.
 * \param[in]
 *    ledPin - Which pin on board that LEDpin is connecting to.
 * \param[in]
 *    sensorPin - Which pin on board that sensorPin is connecting to.
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    Set global variable _KeyPin and s2
 */
  void setpin(uint8_t ledPin);

/**
 * \par Function
 *    lightOn
 * \par Description
 *    Turn on the LED on the light sensor.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 */
  void on(void);

/**
 * \par Function
 *    lightOff
 * \par Description
 *    Turn off the LED on the light sensor.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 */
  void off(void);
private:
  uint8_t _ledPin;
};

#endif // MeDigitalOutput_H
