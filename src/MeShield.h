/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * \brief   Driver for Shield Board.
 * \file    MeShield.h
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/01
 * @brief   Driver for Shield Board.
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
 * This file is Hardware adaptation layer between Shiled board
 * and all MakeBlock drives
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/09/01     1.0.0            Rebuild the old lib.
 * </pre>
 */
#ifndef MeShield_H
#define MeShield_H

#include <Arduino.h>
#include "MeConfig.h"

/* Supported Modules drive needs to be added here */
#include "MeUltrasonicSensor.h"
#include "MeDCMotor.h"
#include "MeRGBLed.h"
#include "MePotentiometer.h"
#include "MeLineFollower.h"
#include "MeSerial.h"
#include "MeBluetooth.h"
#include "MeWifi.h"
#include "MeGyro.h"
#include "MeIR.h"
#include "MeUSBHost.h"


/*********************  Shield Board GPIO Map *********************************/
MePort_Sig mePort[PORT_MAX] =
{
  {NC, NC, NC}, 
  { 2,  4,  5}, { 7,  8,  6}, {12, 13, NC}, { 3, NC, NC}, 
  { 9, NC, NC}, {10, NC, NC}, {11, NC, NC}, {A0, NC, NC}, 
  {A1, NC, NC}, {A2, NC, NC}, {A3, NC, NC}, {A4, NC, NC}, 
  {A5, NC, NC}, {NC, NC, NC}, {NC, NC, NC}, {NC, NC, NC},
};

#define buzzerOn()  pinMode(SCL,OUTPUT),digitalWrite(SCL, HIGH)
#define buzzerOff() pinMode(SCL,OUTPUT),digitalWrite(SCL, LOW)

#endif // MeShield_H

