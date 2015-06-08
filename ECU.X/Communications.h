/* 
 * File:   Communications.h
 * Author: User
 *
 * Created on May 31, 2015, 3:26 PM
 */

#ifndef COMMUNICATIONS_H
#define	COMMUNICATIONS_H

#ifdef	__cplusplus
extern "C" {
#endif


    //COMMUNICATIONS METHODS
    void updateComms();

    enum bus1CommState {
        SAS_UPDATE = 0, DDS_UPDATE = 1, PDU_UPDATE = 2, CHECK_STATE1 = 3, ERROR_STATE1 = 4, NUM_STATES1 = 5
    };
    enum bus1CommState commsBus1State = SAS_UPDATE;
    void checkCommDirection();
    void bus1Update();
    void resetCommTimers();
    void RS485_Direction1(int T_L);
    void sendErrorCode();

    enum bus2CommState {
        MCS_UPDATE = 0, BMM_UPDATE = 1, CHECK_STATE2 = 2, ERROR_STATE2 = 3, NUM_STATES2 = 4
    };
    enum bus2CommState commsBus2State = MCS_UPDATE;
    void checkCommDirection1();
    void bus2Update();
    void resetCommTimers2();
    void RS485_Direction2(int T_L);
    void sendErrorCode2();



    //SAS
    extern bool receiveCommSAS();
    extern bool requestSASData();
    extern bool readyToSendSAS;
    extern bool SAS_COMMS_ERROR;

    //

    extern bool requestBMMData();
    extern bool receiveCommBMM();
    extern bool readyToSendBMM;
    extern bool BMM_COMMS_ERROR;
    //
    extern bool requestMCSData();
    extern bool receiveCommMCS();
    extern bool readyToSendMCS;
    extern bool MCS_COMMS_ERROR;
    //

    extern bool requestDDSData();
    extern bool receiveCommDDS();
    extern bool readyToSendDDS;
    extern bool DDS_COMMS_ERROR;
    //


    extern bool requestPDUData();
    extern bool receiveCommPDU();
    extern bool readyToSendPDU;
    extern bool PDU_COMMS_ERROR;
    //HORN METHOD
    extern void RTD(int lenth);

    //FAST TRANSFER / UART STUFF
    extern void sendData(unsigned char whereToSend);
    extern bool receiveData();
    extern void ToSend(const unsigned char where, const unsigned int what);
    extern volatile int receiveArray[20];
    extern volatile bool Transmit_stall;
    extern volatile unsigned int talkTime;

    extern void sendData1(unsigned char whereToSend);
    extern bool receiveData1();
    extern void ToSend1(const unsigned char where, const unsigned int what);
    extern volatile int receiveArray1[20];
    extern volatile bool Transmit_stall1;
    extern volatile unsigned int talkTime1;

    extern void sendData2(unsigned char whereToSend);
    extern bool receiveData2();
    extern void ToSend2(const unsigned char where, const unsigned int what);
    extern volatile int receiveArray2[20];
    extern volatile bool Transmit_stall2;
    extern volatile unsigned int talkTime2;

    extern void sendData3(unsigned char whereToSend);
    extern bool receiveData3();
    extern void ToSend3(const unsigned char where, const unsigned int what);
    extern volatile int receiveArray3[20];
    extern volatile bool Transmit_stall3;
    extern volatile unsigned int talkTime3;










#ifdef	__cplusplus
}
#endif

#endif	/* COMMUNICATIONS_H */

