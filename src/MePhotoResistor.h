/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * \class   MePhotoResistor
 * \brief   Driver for Me photoresistor module.
 * @file    MePhotoResistor.h
 * @author  MakeBlock
 * @version V1.0.1
 * @date    2015/09/09
 * @brief   Header for MePhotoResistor.cpp.
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
 *    1. void     MePhotoResistor::setpin(uint8_t photoresistorPin); 
 *    2. uint16_t MePhotoResistor::read(void); 
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/07/24     1.0.0            Rebuild the old lib.
 * Rafael Lee       2015/09/09     1.0.1            Added some private variables and methods.
 * </pre>
 */

#ifndef MePhotoResistor_H
#define MePhotoResistor_H

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "MeConfig.h"

#ifdef ME_PORT_DEFINED
#include "MePort.h"
#endif // ME_PORT_DEFINED

/**
 * Class: MePhotoResistor
 * \par Description
 * Declaration of Class MePhotoResistor.
 */
#ifndef ME_PORT_DEFINED
class MePhotoResistor
#else // !ME_PORT_DEFINED
class MePhotoResistor : public MePort
#endif  // !ME_PORT_DEFINED
{
public:
#ifdef ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Me photoresistor device to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  MePhotoResistor(void);

/**
 * Alternate Constructor which can call your own function to map the Me photoresistor device to arduino port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  MePhotoResistor(uint8_t port);
#else // ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Me photoresistor device to arduino port
 * \param[in]
 *   photoresistorPin - arduino port for photoresistor output port
 */
  MePhotoResistor(uint8_t photoresistorPin);
#endif // ME_PORT_DEFINED
/**
 * \par Function
 *    setpin
 * \par Description
 *    Reset the photoresistor device available PIN by its arduino port.
 * \param[in]
 *   photoresistorPin - arduino port for photoresistor output port
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
  void setpin(uint8_t photoresistorPin);

/**
 * \par Function
 *    read()
 * \par Description
 *    Read DAC value of Me photoresistor module.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \par Return
 *    The value of photoresistor device(0-1024)
 * \par Others
 *    None
 */
  uint16_t read(void);
private:
  volatile uint8_t _photoresistorPin;
};
#endif // MePhotoResistor_H
