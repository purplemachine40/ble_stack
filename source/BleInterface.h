#ifndef _BLE_INTERFACE_H_
#define _BLE_INTERFACE_H_

/*Defines*/

/*Typedefs, enums and structure definitions*/

typedef enum _TE_PACKET_TRANSLATOR_RESP_ID
{
    ptri_START_ADV,
    ptri_WRITE_ATTRIBUTE,
    ptri_TOTAL_PT_RESPONSE_IDS
}TE_PACKET_TRANSLATOR_RESP_ID;

typedef struct _TS_BLE_ATTRIBUTE_DATA
{
    uint8_t *pData;
    uint16_t startPos;
    uint16_t dataLen;
    uint16_t connectionHandle;
    uint16_t attributeHandle;
}TS_BLE_ATTRIBUTE_DATA;

typedef struct _TS_PACKET_TRANSLATOR_CALLBACKS
{
    void (*pStartAdv)(void);
    void (*pWriteAttribute)(TS_BLE_ATTRIBUTE_DATA *pAttrData);
}TS_PACKET_TRANSLATOR_CALLBACKS;

typedef struct _TS_BLE_APP_CALLBACKS
{
    void (*pStartAdvResp)(uint8_t isSuccess);
    void (*pWriteAttributeResp)(uint8_t isSuccess);
}TS_BLE_APP_CALLBACKS;

/*Public function prototypes*/

void SetPacketTransCallbacks(const TS_PACKET_TRANSLATOR_CALLBACKS *pCallbacks);
void SetBleAppCallbacks(const TS_BLE_APP_CALLBACKS *pCallbacks);
void StartBleAdv(void);
void WriteBleAttribute(TS_BLE_ATTRIBUTE_DATA *pAttrData);
void PostBleResp(TE_PACKET_TRANSLATOR_RESP_ID respId, uint8_t isSuccess);

#endif