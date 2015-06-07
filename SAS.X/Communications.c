
#include "Communications.h"

bool pendingSend=false;
void updateComms() {
    checkCommDirection();
    if (receiveData()) {
        talkTime = 0;
        pendingSend = true;
    }
    if (pendingSend && talkTime > 500) {
        RS485_1_Port = TALK;
        talkTime = 0;
        prepAndSendData();
        pendingSend = false;
    }
}

void prepAndSendData() {
    static int sender;
    ToSend(RESPONSE_ADDRESS, SAS_ADDRESS);
    ToSend(THROTTLE1_SAS, throttle1);
    ToSend(THROTTLE2_SAS, throttle2);
    ToSend(BRAKE_SAS, brake);
    ToSend(WHEELSPEED1_SAS, sender++);
    ToSend(WHEELSPEED2_SAS, sender++);
    ToSend(WHEELSPEED3_SAS, sender++);
    ToSend(WHEELSPEED4_SAS, sender++);
    //    ToSend(8, sender++);
    //    ToSend(9, sender++);
    //    ToSend(10, sender++);
    //    ToSend(11, sender++);
    //    ToSend(12, sender++);
    //    ToSend(13, sender++);
    sendData(ECU_ADDRESS);
    talkTime = 0;
}

void checkCommDirection() {
    //you have finished send and time has elapsed.. start listen
    if (Transmit_stall && (talkTime > 500) && (RS485_1_Port == TALK)) {
        RS485_1_Port = LISTEN;
    }
}