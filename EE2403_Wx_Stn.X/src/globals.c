<<<<<<< HEAD



#include "../inc/globals.h"


//DWORD_VAL Flags;
_UBUFFER UARTBUFFER;

void InitGlobals(void)
{
//    Flags.Val = 0;
    UARTBUFFER = FREE;

    return;
}
=======
#include "../inc/globals.h"





int ADRaw;
double ADValue,ADAverage,ADTest;
//char U1RXDat[80];
BYTE_VAL Flags;
void InitGlobals(void)
{
    ADRaw = 0;
    ADValue = 0.0;
    ADTest = 0.0;
    //memset(U1RXDat, '\0', sizeof(U1RXDat));
    Flags.Val = 0;

    return;
}
>>>>>>> 25b9476703b708b4a18d91082ed150be80f59191
