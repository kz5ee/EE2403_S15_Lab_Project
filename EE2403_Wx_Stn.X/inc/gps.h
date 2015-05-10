/* 
 * File:   gps.h
 * Author: Mike
 *
 * Created on May 7, 2015, 11:11 AM
 */

#ifndef GPS_H
#define	GPS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Generic.h>
#include "types.h"
#include "globals.h"

#define GetGPSChar    RngGet(&GPSIndex)

    extern char NMEACSV[80];
    extern char *token[15];

    extern double Timestamp, Latitude, Longitude, HDOP, Altitude, GEOID, LatMin, LonMin;
    extern int Quality, NumSats, LatDeg, LonDeg;
    extern char LatHemi, LonHemi, AUnits, GUnits;
    extern volatile UINT16 GPSIndex;
    extern S16 TempChar;


    extern UINT8 TokenizeGpsSentence(char *, char **);
    extern void ParseGGA(char **);
    extern void ParseDegMin(double, double);
    extern void PullGPSSentence(char *);
    extern void SuppressGPS(void);
    extern double DegMinToDeg(double);





#ifdef	__cplusplus
}
#endif

#endif	/* GPS_H */

