#ifndef SMOKE_SENSOR_H
#define SMOKE_SENSOR_H

#include "../publisher.h"

typedef struct 
{
    Publisher base;
    int smokeDetected; // 1= co khoi,0=kkhong co khoi
}SmokeSensor;

void smokeSensorInit(SmokeSensor* sensor);
void smokeSensorTrigger(SmokeSensor* sensor, int detected);


#endif 