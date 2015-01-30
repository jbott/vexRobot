/****************************************************************
 * vexRemote.h
 * Used to add remote control to the vexDuino project
 *
 * Author: Jan 2015 - John Ott
****************************************************************/

#ifndef VexRemote_H
#define VexRemote_H

#include <Arduino.h>
#include "ServoDecode.h"

#define DEADZONE_DEFAULT 30

class vexRemote
{
    public:
        vexRemote();
        void setup();
        char* PrintStatus();
        int GetChannel(int chan);
        int GetChannelRaw(int chan);
        void SetDeadzone(int deadzone);
    private:
        int m_deadzone;
};

#endif
