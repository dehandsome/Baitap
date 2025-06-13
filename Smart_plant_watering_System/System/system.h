#ifndef SYSTEM_H
#define SYSTEM_H

#define MOI_STURE_MIN_THRESHOLD 30
#define MOI_STURE_MAX_THRESHOLD 60
#define WARTERING_DURATION_MAX 10
#define SENSOR_CHECK_INTERVAL 5
#define LAST_WARTER_TIME 0
#define LAST_SENSOR_CHECK_TIME 0

typedef enum { 
    MODE_AUTO,
    MODE_MANUAL
}Mode;

typedef enum {
    PUMP_OFF,
    PUMP_ON
}PumpStatus;

typedef enum {
LED_NORMAL,
LED_WATERING, 
LED_LOW_MOISTURE_ALERT, 
LED_ERROR
}LEDStatus;

typedef struct 
{
    int moistureMinThreshold;
    int moistureMaxThreshold;
    int wateringDurationMax;
    int sensorCheckInterval;
    Mode currentMode;
    PumpStatus pumpStatus;
    LEDStatus ledStatus;
    int lastWateringTime;
    int lastSensorCheckTime;
    int pumpStartTime;
    int currentTime;
}SystemState;

extern SystemState systemState;

void systemInit();
void updateSystemStatus();
void updateSystemTime();




#endif