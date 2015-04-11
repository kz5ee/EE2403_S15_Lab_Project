
int ADRaw;
char U1RXDat[80];
void InitGlobals(void)
{
    ADRaw = 0;
    memset(U1RXDat, '\0', sizeof(U1RXDat));

    return;
}
