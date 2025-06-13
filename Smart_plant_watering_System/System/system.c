#include <stdio.h>
#include "system.h"

SystemState systemState;
void systemInit() {
    systemState.moistureMinThreshold = MOI_STURE_MIN_THRESHOLD  ;
    systemState.moistureMaxThreshold = MOI_STURE_MAX_THRESHOLD ;
    systemState.wateringDurationMax = WARTERING_DURATION_MAX ;
    systemState.sensorCheckInterval = SENSOR_CHECK_INTERVAL  ;
    systemState.currentMode = MODE_AUTO;
    systemState.pumpStatus = PUMP_OFF;
    systemState.ledStatus = LED_NORMAL;
    systemState.lastWateringTime = LAST_WARTER_TIME ;
    systemState.lastSensorCheckTime = LAST_SENSOR_CHECK_TIME ;
    systemState.pumpStartTime = 0;
    systemState.currentTime = 0;
}
void updateSystemStatus() {
    printf("Mode: %s\n", systemState.currentMode == MODE_AUTO ? "AUTO" : "MANUAL");
    printf("Pump: %s\n", systemState.pumpStatus == PUMP_ON ? "ON" : "OFF");
    printf("LED Status: %d\n", systemState.ledStatus);
}
void updateSystemTime() {
    systemState.currentTime++;
}