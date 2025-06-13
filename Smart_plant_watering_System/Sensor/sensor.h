#ifndef SENSOR_H
#define SENSOR_H

#define SOIL_MOISTURE_INIT 50
#define TEMPERATURE_INIT 25
typedef struct {
    int soilMoisture;
    int temperature;
} SensorData;

extern SensorData sensorData;

void sensorInit();
void readSensors();

#endif