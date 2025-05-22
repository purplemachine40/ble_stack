/*
   File Description:
*/

#include "Common.h"
#include "BleInterface.h"
#include <string.h>

/*Local Defines*/

/*Typedefs, enums and structures*/

/*Static variables*/

static TS_PACKET_TRANSLATOR_CALLBACKS packetTransCallbacks;
static TS_BLE_APP_CALLBACKS bleAppCallbacks;

/*Static function prototypes*/

/*Functions*/

/**
 * @brief - Sets the callbacks to invoke for packet translation.
 * @param *pCallbacks - Pointer to callback structure TS_PACKET_TRANSLATOR_CALLBACKS.
 * @return void
 */
void SetPacketTransCallbacks(const TS_PACKET_TRANSLATOR_CALLBACKS *pCallbacks)
{
   memcpy(&packetTransCallbacks, pCallbacks, sizeof(packetTransCallbacks));
}/*END FUNCTION SetPacketTransCallbacks()*/


/**
 * @brief - Sets the callbacks to invoke into the application.
 * @param *pCallbacks - Pointer to callback structure TS_BLE_APP_CALLBACKS.
 * @return void
 */
void SetBleAppCallbacks(const TS_BLE_APP_CALLBACKS *pCallbacks)
{
   memcpy(&bleAppCallbacks, pCallbacks, sizeof(bleAppCallbacks));
}/*END FUNCTION SetBleAppCallbacks()*/


/**
 * @brief - Invokes the callback to start advertising.
 * @param void -
 * @return void
 */
void StartBleAdv(void)
{
   packetTransCallbacks.pStartAdv();
}/*END FUNCTION StartBleAdv()*/


/**
 * @brief - Invokes the callback to write an attribute.
 * @param *pAttrData - Attribute data.
 * @return void
 */
void WriteBleAttribute(TS_BLE_ATTRIBUTE_DATA *pAttrData)
{
   packetTransCallbacks.pWriteAttribute(pAttrData);
}/*END FUNCTION WriteBleAttribute()*/


/**
 * @brief - Packet translator calls this function to post a response to a command.
 * @param respId - Response ID as defined in TE_PACKET_TRANSLATOR_RESP_ID.
 * @param isSuccess - TRUE if the operation succeeded, FALSE otherwise.
 * @return void
 */
void PostBleResp(TE_PACKET_TRANSLATOR_RESP_ID respId, uint8_t isSuccess)
{
   switch(respId)
   {
      case ptri_START_ADV:
      {
         bleAppCallbacks.pStartAdvResp(isSuccess);
      }
      break;
      case ptri_WRITE_ATTRIBUTE:
      {
         bleAppCallbacks.pWriteAttributeResp(isSuccess);
      }
      break;
      default:
      {
         /*Error*/
      }
   }
}/*END FUNCTION PostBleResp()*/
