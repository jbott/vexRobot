/****************************************************************
 * vexRemote.cpp
 * Used to add remote control to the vexDuino project
 *
 * Author: Jan 2015 - John Ott
****************************************************************/

#include "vexRemote.h"

vexRemote::vexRemote() {
    m_deadzone = DEADZONE_DEFAULT;
}

void vexRemote::setup() {
    ServoDecode.begin();
}

char * vexRemote::PrintStatus()
{
    static char * remote_state_strings[] = {
        "NOT_SYNCED",
        "ACQUIRING",
        "READY",
        "FAILSAFE"
    };
    return remote_state_strings[ServoDecode.getState()];
}

int vexRemote::GetChannel(int chan)
{
    // GetChannelRaw may return from 1000 to 2000, but rarely reaches the limits.
    // Constrain it to a limit of +/- 400 instead to get a more valid range
    return map(constrain(GetChannelRaw(chan), 1100, 1900), 1100, 1900, -255, 255);
}

int vexRemote::GetChannelRaw(int chan)
{
    return ServoDecode.GetChannelPulseWidth(chan);
}

void vexRemote::SetDeadzone(int deadzone)
{
    m_deadzone = constrain(deadzone, 0, 255);
}