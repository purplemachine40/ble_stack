/*
   File Description:
*/

#include "Common.h"

#include "Application.h"
#include "NordicPacketTranslator.h"
#include "SerialPort.h"

/*Local Defines*/

/*Typedefs, enums and structures*/

/*Static variables*/

/*Static function prototypes*/

static const TS_NORDIC_PT_SETUP nordicPtSetup =
{
   .pSendBytes = SerialPortSendBytes,
   .pGetBytes = SerialPortGetBytes
};

/*Functions*/

int main(int argc, char *arg[])
{
   InitNordicPacketTranslator(&nordicPtSetup);
   InitApplication();

   while(TRUE)
   {
      UpdateApplication();
      UpdateNordicPacketTranslator();
   }
}