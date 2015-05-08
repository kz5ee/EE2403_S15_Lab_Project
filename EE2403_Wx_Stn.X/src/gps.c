#include <stdio.h>
#include <Generic.h>
#include <stddef.h>
#include <stdlib.h>
#include <libpic30.h>
#include <string.h>

#include "../inc/globals.h"
#include "../inc/buffers.h"
#include "../inc/gps.h"


char NMEACSV[80] = "\0";
char *token[15];

float Timestamp, Latitude, Longitude, HDOP, Altitude, GEOID, LatMin, LonMin;
int Quality, NumSats, LatDeg, LonDeg;
char LatHemi, LonHemi, AUnits, GUnits;
char strchecksum[3], LatStr[13], LonStr[13];
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


	return;	
}

void ParseDegMin(double Lat, double Lon)
{
   int i= 0, j =0, size;
    char ladeg[3], lodeg[3], lamin[10], lomin[10];
    
    dtoa(Lat, LatStr);
    dtoa(Lon, LonStr);
    
    size = sizeof(LatStr);
    
    for(i=0; i<sizeof(LatStr); i++)
    {
        if(i < 2)
        {
            ladeg[i] = LatStr[i];
        }
        if(i == 1)
        {
            ladeg[(i + 1)] = '\0';
        }
        if((i >= 1) && (LatStr[i + 1] != EOF))
        {
            lamin[j++] = LatStr[i + 1];
        }
        if(i == (sizeof(LatStr) -1))
        {
            lamin[j] = '\0';
        }
    }
    
    LatDeg = atoi(ladeg);
    LatMin = atof(lamin);

    for(i=0; i<sizeof(LonStr); i++)
    {
        if(i < 2)
        {
            lodeg[i] = LonStr[i];
        }
        if(i == 1)
        {
            lodeg[(i + 1)] = '\0';
        }
        if((i >= 1) && (LonStr[i + 1] != EOF))
        {
            lomin[j++] = LonStr[i + 1];
        }
        if(i == (sizeof(LonStr) -1))
        {
            lomin[j] = '\0';
        }
    }

    LonDeg = atoi(lodeg);
    LonMin = atof(lomin);



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

void SuppressGPS(void)
{
    char KillGSV[31], KillGLL[31], KillGSA[31], KillRMC[31];
    /*
     * We only want GGA
     * Suppress GSV, GLL, GSA, RMC, and VTG
     */
    printf("$PUBX,40,GSV,0,0,0,0,0,0*59\r\n");
    printf("$PUBX,40,GLL,0,0,0,0,0,0*5C\r\n");
    printf("$PUBX,40,GSA,0,0,0,0,0,0*4E\r\n");
    printf("$PUBX,40,RMC,0,0,0,0,0,0*47\r\n");
    printf("$PUBX,40,VTG,0,0,0,0,0,0*5E\r\n");

    
}
    