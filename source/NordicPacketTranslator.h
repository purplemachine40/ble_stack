#ifndef _NORDIC_PACKET_TRANSLATOR_H_
#define _NORDIC_PACKET_TRANSLATOR_H_

#include "Common.h"

/*Defines*/

/*Typedefs, enums and structure definitions*/

typedef struct _TS_NORDIC_PT_SETUP
{
    uint32_t (*pSendBytes)(uint8_t *pBuf, uint32_t numBytes);
    uint32_t (*pGetBytes)(uint8_t *pBuf, uint32_t numBytes);
}TS_NORDIC_PT_SETUP;

/*Public function prototypes*/

void InitNordicPacketTranslator(const TS_NORDIC_PT_SETUP *pSetup);
void UpdateNordicPacketTranslator(void);
#endif