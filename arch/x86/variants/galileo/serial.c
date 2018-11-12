#include <pip/api.h>
#include "galileo-support.h"
#define SERIAL_PORT 0x3f8



void Pip_Debug_Putc(char c)
{
    initGalileoSerial(DEBUG_SERIAL);
    galileoSerialPrintc(c);
}
