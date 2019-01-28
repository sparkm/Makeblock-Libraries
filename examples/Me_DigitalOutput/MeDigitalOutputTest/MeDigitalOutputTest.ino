/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    MeLightSensorTest.ino
 * @author  MakeBlock
 * @version V1.0.1
 * @date    2015/09/10
 * @brief   Description: this file is sample program for Me Light Sensor module.
 *
 * Function List:
 *    1. int16_t MeLightSensor::read();
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/07/24     1.0.0            Rebuild the old lib.
 * Rafael Lee       2015/09/10     1.0.1            Added some comments and macros.
 * </pre>
 */

/* Includes ------------------------------------------------------------------*/
#include "MeShield.h"

/* Private variables ---------------------------------------------------------*/
MeDigitalOutput laser(PORT_4);

/* Private functions ---------------------------------------------------------*/
/**
 * \par Function
 *    setup
 * \par Description
 *    Run once, initialize serial port.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \return
 *    None.
 * \par Others
 *    None
 */
void setup()
{
}

/**
 * \par Function
 *    loop
 * \par Description
 *    Run continuously, print if light sensor's DAC value.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \return
 *    None.
 * \par Others
 *    None
 */
void loop()
{
  laser.on();

  // wait 100 milliseconds before the next loop
  delay(100);

  laser.off();

  // wait 100 milliseconds before the next loop
  delay(100);
}

