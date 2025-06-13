#include <stdio.h>
#include "actuator.h"
#include "../System/system.h"

void actuatorInit() {
    systemState.pumpStatus = PUMP_OFF;
    systemState.ledStatus = LED_NORMAL;
}

void turnPumpOn() {
    systemState.pumpStatus = PUMP_ON;
    systemState.ledStatus = LED_WATERING;
    printf("Pump ON\n");
}

void turnPumpOff() {
    systemState.pumpStatus = PUMP_OFF;
    systemState.ledStatus = LED_NORMAL;
    printf("Pump OFF\n");
}

void updateActuatorStatus() {
    if (systemState.pumpStatus == PUMP_ON) {
        printf("Actuator: Pump is running\n");
    }
}