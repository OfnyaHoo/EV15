/* 
 * File:   debug.h
 * Author: User
 *
 * Created on June 8, 2015, 7:10 PM
 */

#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdbool.h>

#define NO_DEBUG            0
#define THROTTLE_BRAKE      1
#define BATTERY_DEBUG_VOLTS 2
#define BATTERY_DEBUG_TEMPS 3
#define BATTERY_DEBUG_POWER 4
#define MAX_DEBUG_STATES    4
    extern unsigned int throttle1, throttle2, brake;
    extern void handleDebugRequests();
    extern volatile unsigned int DebugTimer;
    extern void Send_put2(unsigned char _data);
    extern void sendData2(unsigned char whereToSend);
    extern bool receiveData2();
    extern void ToSend2(const unsigned char where, const unsigned int what);



#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */
