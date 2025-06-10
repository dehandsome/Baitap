#include<stdio.h>
#include<stdlib.h>
#include"../security/security_system.h"
static void activateAlarm(){
    printf("Chuong bao dong da bat.\n");
}
static void deactivateAlarm(){
    printf("Chuong bao dong da tat.\n");
}
static void monitorSensors(){
    printf("Phat hien chuyen dong,\n");
}
SecuritySystem *createSecuritySystem(){
    SecuritySystem * system = (SecuritySystem*)malloc(sizeof(SecuritySystem));
    system->activateAlarm=activateAlarm;
    system->deactivateAlarm=deactivateAlarm;
    system->monitorSensors=monitorSensors;
    return system;
}