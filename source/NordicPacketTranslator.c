/*
   File Description: This file translates commands received from the BleInterface (via callbacks) and
                     sends commands to the external BLE module in (fictitious) Nordic protocol.
*/

#include "Common.h"

#include "BleInterface.h"
#include "NordicPacketTranslator.h"
#include <string.h>

/*Local Defines*/

#define SIZE_NORDIC_RCV_BUF 64

/*Typedefs, enums and structures*/

/*Static variables*/

static TS_NORDIC_PT_SETUP nordicPtSetup;

/*Static function prototypes*/

static void StartAdv(void);
static void WriteAttribute(TS_BLE_ATTRIBUTE_DATA *pAttrData);

TS_PACKET_TRANSLATOR_CALLBACKS ptCallbacks =
{
   .pStartAdv = StartAdv,
   .pWriteAttribute = WriteAttribute
};

/*Functions*/

/**
 * @brief - Initializes the Nordic Packet Translator.
 * @param *pSetup - Pointer to the TS_NORDIC_PT_SETUP structure.
 * @return void
 */
void InitNordicPacketTranslator(const TS_NORDIC_PT_SETUP *pSetup)
{
   memcpy(&nordicPtSetup, pSetup, sizeof(nordicPtSetup));
   SetPacketTransCallbacks(&ptCallbacks);
}/*END FUNCTION InitNordicPacketTranslator()*/

/**
 * @brief - Updates the packet translator.
 * @param void -
 * @return void
 */
void UpdateNordicPacketTranslator(void)
{
   uint8_t rcvBuf[SIZE_NORDIC_RCV_BUF];
   uint8_t bytesRcvd;
   uint8_t respSuccess = TRUE;

   bytesRcvd = nordicPtSetup.pGetBytes(rcvBuf, SIZE_NORDIC_RCV_BUF);

   if(bytesRcvd)
   {
      /*...additional code to parse the packet/determine what it is.  Assume
      Assume it's a Start Advertising command response.*/

      PostBleResp(ptri_START_ADV, respSuccess);
   }
}/*END FUNCTION UpdateNordicPacketTranslator()*/

/**
 * @brief - Sends the start advertising command.
 * @param void -
 * @return void
 */
static void StartAdv(void)
{
   uint8_t startAdvCmd[] = "AT:START_ADV";
   nordicPtSetup.pSendBytes(startAdvCmd, sizeof(startAdvCmd));
}/*END FUNCTION StartAdv()*/

/**
 * @brief - Sends the Write Attribute command.
 * @param *pAttrData - Attribute data to write.
 * @return void
 */
static void WriteAttribute(TS_BLE_ATTRIBUTE_DATA *pAttrData)
{
   uint8_t writeAttrCmd[] = "AT:WRITE_ATTRIBUTE-";
   uint8_t attrData[sizeof(TS_BLE_ATTRIBUTE_DATA)];
   nordicPtSetup.pSendBytes(writeAttrCmd, sizeof(writeAttrCmd));

   memcpy(attrData, (uint8_t*)pAttrData, sizeof(TS_BLE_ATTRIBUTE_DATA));
   nordicPtSetup.pSendBytes(attrData, sizeof(attrData));
}/*END FUNCTION WriteAttribute()*/
