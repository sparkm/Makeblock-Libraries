/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    InfraredReceiverTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/01
 * @brief   Description: this file is sample code for Me Infrared Receiver device.
 *
 * Function List:
 * 1. void MeInfraredReceiver::begin(void)
 * 2. int16_t MeInfraredReceiver::read(void)
 * 3. int16_t MeInfraredReceiver::available(void)
 * 4. bool MeInfraredReceiver::buttonState(void)
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2015/09/01    1.0.0          rebuild the old lib
 * </pre>
 */
#include "MeShield.h"

MeIR irDecode(PORT_10);

void setup()
{
  Serial.begin(9600);
  irDecode.begin();
  Serial.println("InfraredReceiverDecode Start!");
}

void loop()
{
  char read = irDecode.getCode();
  if (read) {
    Serial.print("read: ");
    Serial.println(read, HEX);
  }

  if (read == 'A') {
    irDecode.end();
  }
}

