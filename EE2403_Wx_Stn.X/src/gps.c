#include <stdio.h>
#include <Generic.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/globals.h"
#include "../inc/buffers.h"
#include "../inc/gps.h"


char NMEACSV[80] = "\0";
char *token[15];

float Timestamp, Latitude, Longitude, HDOP, Altitude, GEOID, LatMin, LonMin;
int Quality, NumSats, LatDeg, LonDeg;
char LatHemi, LonHemi, AUnits, GUnits;
char strchecksum[3];
volatile UINT16 GPSIndex;
S16 TempChar;

UINT8 TokenizeGpsSentence(char *NMEASentence, char **tok)
{
    UINT8 RetVal, index, length;

	length = strlen(NMEASentence);
	RetVal = 0;
	if (length > 2)
	{
		tok[0] = NMEASentence + 2;
		RetVal = 1;
		for (index = 2; index < length; index++)
		{
			if (NMEASentence[index] == ',' || NMEASentence[index] == '*')
			{						// If we find a delimiter, end this token string
				// and point to the beginning of the next one,
				// even if this points to another delimiter or the NULL terminator!!
				tok[RetVal++] = &NMEASentence[index + 1];
				NMEASentence[index] = 0;	// This delimiter is now NULL terminator for the previous token.
			}

			// in the unlikely case that there is no data between the final delimiter
			// and the NULL terminator, the final entry will point to the NULL terminator
			// thus yielding a legal, empty string.
		}
	}

	tok[RetVal] = NULL;				// Mark the end.
	return RetVal;
}

void ParseGGA(char **toks)
{
    int	TokenIndex;

	//	RetVal = SID_GPGGA;
	//	strtok(instr,",\r\n");			// Skip the sentence type
	//	nxprintf("-");
	TokenIndex = 1;
	if (sscanf(toks[TokenIndex++],"%f",&Timestamp) != 1) Timestamp = 0.0;			// Time
	if (sscanf(toks[TokenIndex++],"%f",&Latitude) != 1) Latitude = 0.0;				// Lat
	if (sscanf(toks[TokenIndex++],"%c",&LatHemi) != 1) LatHemi = ' ';	// Lat Hemisphere (N/S)
	if (sscanf(toks[TokenIndex++],"%f",&Longitude) != 1) Longitude = 0.0;				// Lon
	if (sscanf(toks[TokenIndex++],"%c",&LonHemi) != 1) LonHemi = ' ';	// Lon Hemisphere (E/W)
	if (sscanf(toks[TokenIndex++],"%d",&Quality) != 1) Quality = 0;			// Status 1-8
	if (sscanf(toks[TokenIndex++],"%d",&NumSats) != 1) NumSats = 0;				// Satellites in use
	if (sscanf(toks[TokenIndex++],"%f",&HDOP) != 1) HDOP = 0.0;			// HDOP
	if (sscanf(toks[TokenIndex++],"%f",&Altitude) != 1) Altitude = 0.0;				// Altitude
	if (sscanf(toks[TokenIndex++],"%c",&AUnits) != 1) AUnits = 0.0;			// Altitude (m)
	if (sscanf(toks[TokenIndex++],"%f",&GEOID) != 1) GEOID = 0.0;			// Height of geoid
	if (sscanf(toks[TokenIndex++],"%c",&GUnits) != 1) GUnits = 0.0;			// geoid units (m)


	return;	// Returns Sentence Type (SID_) or -1 if not valid.
}

void ParseDegMin(double LatLong)
{

    return;
}

void PullGPSSentence(char *NMEASentence)
{
    int i = 0, j = 0;
    char Sentence[80], Temp;

    do
    {
        Temp = GetGPSChar;

        if(Temp == '$')
        { i++; }
        
        if(Temp != EOF)
        {
        
            if((Temp != '$') && (Temp != '*'))
            {
                Sentence[i++] = (char)Temp;
            }
            if(Temp == '*')
            {
                GETCHECKSUM = 1;  //We've reached the checksum part of the sentence
                Sentence[i] = '\0';
            }
            if((GETCHECKSUM == 1) && (j < 3))
            {
                strchecksum[j++] = (char)Temp;
            }
            if(j == 3)
            { 
                strchecksum[j] = '\0'; //Null terminate the checksum string
                GETCHECKSUM = 0;
            }    
        }

    }while((Temp != '$') || (Temp != EOF));
    
    if(strlen(Sentence) > 1)
    { strcpy(NMEASentence, Sentence); }

    return;
}   
    