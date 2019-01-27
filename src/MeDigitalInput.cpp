/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * \class   MeDigitalInput
 * \brief   Driver for Me digitalinput module.
 * @file    MeDigitalInput.cpp
 * @author  MakeBlock
 * @version V1.0.1
 * @date    2015/09/08
 * @brief   Driver for Me digitalinput module.
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
 *    1. void     MeDigitalInput::setpin(uint8_t digitalinputPin); 
 *    2. uint16_t MeDigitalInput::read(void); 
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/07/24     1.0.0            Rebuild the old lib.
 * Rafael Lee       2015/09/08     1.0.1            Added some comments and macros.
 * </pre>
 *
 * @example DigitalInputTest.ino
 */
/* Includes ------------------------------------------------------------------*/
#include "MeDigitalInput.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
#ifdef ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Me digitalinput device to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
MeDigitalInput::MeDigitalInput(void) : MePort(0)
{

}

/**
 * Alternate Constructor which can call your own function to map the Me digitalinput device to arduino port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
MeDigitalInput::MeDigitalInput(uint8_t port) : MePort(port)
{

}
#else // ME_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Me digitalinput device to arduino port
 * \param[in]
 *   digitalinputPin - arduino port for digitalinput output port
 */
MeDigitalInput::MeDigitalInput(uint8_t digitalinputPin)
{
  _digitalinputPin = digitalinputPin;
  pinMode(_digitalinputPin, INPUT);
}
#endif // ME_PORT_DEFINED 
/**
 * \par Function
 *    setpin
 * \par Description
 *    Reset the digitalinput device available PIN by its arduino port.
 * \param[in]
 *   digitalinputPin - arduino port for digitalinput output port
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
void MeDigitalInput::setpin(uint8_t digitalinputPin)
{
  _digitalinputPin = digitalinputPin;
  pinMode(_digitalinputPin, INPUT);
#ifdef ME_PORT_DEFINED
  _pin[OFFSET_0] = digitalinputPin;
#endif // ME_PORT_DEFINED
}

/**
 * \par Function
 *    read()
 * \par Description
 *    Read DAC value of Me digitalinput module.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \par Return
 *    The value of digitalinput device(0-1024)
 * \par Others
 *    None
 */
uint16_t MeDigitalInput::read(void)
{
#ifdef ME_PORT_DEFINED
  return(MePort::dRead(INPUT, OFFSET_0) );
#else // ME_PORT_DEFINED
  return digitalRead(_digitalinputPin);
#endif // ME_PORT_DEFINED
}
