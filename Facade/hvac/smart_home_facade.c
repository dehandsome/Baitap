#include<stdio.h>
#include<stdlib.h>
#include"smart_home_facade.h"

SmartHomeFacade* createSmartHomeFacade(){
    SmartHomeFacade *facade = (SmartHomeFacade*)malloc(sizeof(SmartHomeFacade));
    facade->lighting= createLightingSystem ;
    facade->lighting=createHvacSystem;
    facade->security=createSecuritySystem;
    return facade;
}
void setactiveMorring(SmartHomeFacade*facade){
    facade->lighting->turnOff();
    facade->hvac->setTemperature(25);
    facade->hvac->setMode("tat");
    facade->security->deactivateAlarm();
    facade->security->monitorSensors();
    printf("Xin chao buoi sang.\n");
}
void setMovieNightScene(SmartHomeFacade* facade){
    facade->lighting->setBrightness(30);
    facade->hvac->setTemperature(23);
    facade->hvac->setMode("cool");
    facade->security->activateAlarm();
    facade->security->monitorSensors();
    printf("Chuc ban xem phim vui ve.\n");
}
