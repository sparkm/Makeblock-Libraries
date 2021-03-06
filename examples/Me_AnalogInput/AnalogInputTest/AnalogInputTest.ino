/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    AnalogInputTest.ino
 * @author  MakeBlock
 * @version V1.0.1
 * @date    2015/09/10
 * @brief   Description: this file is sample program for AnalogInput module.
 *
 * Function List:
 * 1. uint16_t MeAnalogInput::read(); 
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
MeAnalogInput myAnalogInput(PORT_8);

/* Private functions ---------------------------------------------------------*/
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("value=");
  Serial.println(myAnalogInput.read() );
  delay(100);
}
