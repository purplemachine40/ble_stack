/*
   File Description:
*/

#include "Common.h"

#include "SerialPort.h"
#include <string.h>

/*Local Defines*/

/*Typedefs, enums and structures*/

/*Static variables*/

/*Static function prototypes*/

/*Functions*/

/**
 * @brief - Sends bytes out of the serial port.
 * @param *pBuf - Pointer to data buffer to send.
 * @param numBytes - Number of bytes in pBuf.
 * @return uint32_t - Number of bytes sent.
 */
uint32_t SerialPortSendBytes(uint8_t *pBuf, uint32_t numBytes)
{
   /*Send bytes out of the serial port.*/

   return numBytes;
}/*END FUNCTION SerialPortSendBytes()*/


/**
 * @brief - Returns bytes received from the serial port.
 * @param *pBuf - Pointer to the buffer to receive the bytes.
 * @param numBytes - Max number of bytes to copy to pBuf.
 * @return uint32_t - Number of bytes copied to pBuf.
 */
uint32_t SerialPortGetBytes(uint8_t *pBuf, uint32_t numBytes)
{
   /*If there are received bytes, provide them.*/

   return numBytes;
}/*END FUNCTION SerialPortGetBytes()*/
