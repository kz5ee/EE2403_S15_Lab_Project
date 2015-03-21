


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/buffers.h"
#include "../inc/globals.h"


UINT8 Uart2RingBuffer[TPBUFMAXSIZE];
UINT8 Uart3RingBuffer[GPSBUFMAXSIZE];//Max length of NEMA sentence is 80 and the max STX is 154
UINT8 Uart4RingBuffer[MAXRINGBUFSIZE];

//UINT8 UartRingBuffer[3][];

UINT16 HIndex[3] = 0,TIndex[3] = 0;//Internal Indexes

/// @fn void RngAdd(U8 NewData)
/// @author Jonathan Streeter
/// @date 1/20/2014
/// @brief Adds to the Buffer and moves the Head and Tail
/// @details Adds a new data byte from the UART interrupt to the Ring Buffer and
///	moves the Head and Tail buffer. This is the ONLY function that
///	moves the Head Pointer
///
/// @param NewData Data to be inserted into the RngBuffer
/// @return void
////////////////////////////////////////////////////////////////////////////////
void RngAdd(UINT8 NewData)
{
    switch (UARTBUFFER)
    {
        case PRESSTEMP:

            break;

        case GPS:

            break;

        case FREE:

            break;

        default:
            break;
    }
    if(U2RXBUFF == 1)
    {
        Uart2RingBuffer[U2HIndex] = NewData;//Shove data in
        U2HIndex =(U2HIndex + 1) % TPBUFMAXSIZE;//Advance and check overflow
        if(U2HIndex == U2TIndex)//Check if they have looped back on eachother
          U2TIndex =(U2TIndex + 1) % MAXRINGBUFSIZE;//If so andvance the TP
    }
    if(U3RXBUFF == 1)
    {
        Uart3RingBuffer[U3HIndex] = NewData;//Shove data in
        U3HIndex =(U3HIndex + 1) % TPBUFMAXSIZE;//Advance and check overflow
        if(U3HIndex == U3TIndex)//Check if they have looped back on eachother
          U3TIndex =(U3TIndex + 1) % MAXRINGBUFSIZE;//If so andvance the TP
    }
    if(U4RXBUFF == 1)
    {
        Uart4RingBuffer[U4HIndex] = NewData;//Shove data in
        U4HIndex =(U4HIndex + 1) % TPBUFMAXSIZE;//Advance and check overflow
        if(U4HIndex == U4TIndex)//Check if they have looped back on eachother
          U4TIndex =(U4TIndex + 1) % MAXRINGBUFSIZE;//If so andvance the TP
    }

return;
}

/// @fn S16 RngGet(U8 *LocalTailIndex)
/// @author Jonathan Streeter
/// @date 1/21/2014
/// @brief Adds to the Buffer and moves the Head and Tail
/// @details Get the next char from the ring buffer using the Local Tail Index that you pass it.
///	If the return is > 0xFF then the Tail is at the Head. The Tail index is moved to
///	the next char
/// @param LocalTailIndex
/// @return char that it pulled. EOF if the Head matches the tail
////////////////////////////////////////////////////////////////////////////////
//S16 RngGet(UINT16 *LocalTailIndex)
//{
//S16 RTV = EOF;
//
//    if(*LocalTailIndex != HIndex)//Not Matching
//    {
//        RTV = UartRingBuffer[ *LocalTailIndex ];//Grab data
//        *LocalTailIndex =(*LocalTailIndex + 1) % MAXRINGBUFSIZE;//increment and check for overflow
//    }
//
//    return(RTV);//Will be 0xFFFF if no new char was aquired
//}

/// @fn U8 RngDataUsed(U8* LocalTailIndexPeek)
/// @author Jonathan Streeter
/// @date 1/21/2014
/// @brief Using local TailIndex return howmany bytes ahead the Head is.
/// @details Using local TailIndex return howmany bytes ahead the Head is.
///
/// @param LocalTailIndexPeek The index that is passed in
/// @return Number of bytes left in Buffer
////////////////////////////////////////////////////////////////////////////////

//UINT16 RngDataUsed(UINT16* LocalTailIndexPeek)
//{
//    UINT16 DataLeft = 0;
//    UINT16 Temp = HIndex;
//
//    if(Temp < *LocalTailIndexPeek)
//    Temp += MAXRINGBUFSIZE;
//
//    DataLeft = (UINT16) (Temp - *LocalTailIndexPeek);
//
//    return(DataLeft);
//}