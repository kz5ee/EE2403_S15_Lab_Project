#include "../inc/globals.h"





int ADRaw;
double ADValue,ADAverage;
//char U1RXDat[80];
BYTE_VAL Flags;
void InitGlobals(void)
{
    ADRaw = 0;
    ADValue = 0.0;
    //memset(U1RXDat, '\0', sizeof(U1RXDat));
    Flags.Val = 0;

    return;
}
