#ifndef SMART_HOME_FACADE_H
#define SMART_HOME_FACADE_H

#include "../lighting/lighting_system.h"
#include"../hvac/hvac_system.h"
#include"../security/security_system.h"
typedef struct 
{
    LightingSystem* lighting;
    HvacSystem* hvac;
    SecuritySystem*security;
}SmartHomeFacade;

SmartHomeFacade* createSmartHomeFacade();

void setactiveMorring(SmartHomeFacade*facade);
void setMovieNightScene(SmartHomeFacade* facade);



#endif