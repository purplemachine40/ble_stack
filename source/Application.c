/*
   File Description:
*/

#include "Common.h"

#include "BleInterface.h"

/*Local Defines*/

/*Typedefs, enums and structures*/

/*Static variables*/

/*Static function prototypes*/

static void StartAdvResp(uint8_t isSuccess);
static void WriteAttributeResp(uint8_t isSuccess);

static const TS_BLE_APP_CALLBACKS bleAppCallbacks =
{
   .pStartAdvResp = StartAdvResp,
   .pWriteAttributeResp = WriteAttributeResp
};


/*Functions*/

/**
 * @brief - Init application.
 * @param void -
 * @return void
 */
void InitApplication(void)
{
   SetBleAppCallbacks(&bleAppCallbacks);
}/*END FUNCTION InitApplication()*/


/**
 * @brief - Update the application.
 * @param void -
 * @return void
 */
void UpdateApplication(void)
{
   /*Example initiating Start Advertising.*/

   StartBleAdv();
}/*END FUNCTION UpdateApplication()*/


/**
 * @brief - Response for Start Advertising.
 * @param isSuccess - TRUE on success, FALSE otherwise.
 * @return void
 */
static  void StartAdvResp(uint8_t isSuccess)
{
   /*Received response from the Start Advertising command.*/
}/*END FUNCTION StartAdvResp()*/


/**
 * @brief - Response for Write Attribute.
 * @param isSuccess - TRUE on success, FALSE otherwise.
 * @return void
 */
static  void WriteAttributeResp(uint8_t isSuccess)
{
   /*Received response from the Write Attribute command.*/
}/*END FUNCTION WriteAttributeResp()*/
