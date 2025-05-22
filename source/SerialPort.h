#ifndef _SERIAL_PORT_H_
#define _SERIAL_PORT_H_

/*Defines*/

/*Typedefs, enums and structure definitions*/

/*Public function prototypes*/

uint32_t SerialPortSendBytes(uint8_t *pBuf, uint32_t numBytes);
uint32_t SerialPortGetBytes(uint8_t *pBuf, uint32_t numBytes);
#endif