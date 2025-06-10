#ifndef SECURITY_SYSTEM_H
#define SECURITY_SYSTEM_H

#include"smart_home_facade.h"

typedef struct 
{
    void (*activateAlarm)(void);
    void (*deactivateAlarm)(void);
    void (*monitorSensors)(void);
}SecuritySystem;

SecuritySystem *createSecuritySystem();
#endif