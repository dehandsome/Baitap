#include <stdio.h>
#include "sensor.h"
#include"../System/system.h"
SensorData sensorData;

void sensorInit() {
    sensorData.soilMoisture = SOIL_MOISTURE_INIT ;
    sensorData.temperature = TEMPERATURE_INIT;
}

void readSensors() {
    // simulate
    printf("Reading sensors...\n");
    if (sensorData.soilMoisture < 20) {
        sensorData.soilMoisture += 1;  // tang len neu nho hon 20
    } else if (sensorData.soilMoisture > 75) {
        sensorData.soilMoisture -= 1;  // giam neu lon hon 75 
    }
    sensorData.temperature += (rand() % 3 - 1);
    systemState.lastSensorCheckTime = systemState.currentTime;
    printf("Soil Moisture: %d%%, Temp: %d°C\n", sensorData.soilMoisture, sensorData.temperature);
}