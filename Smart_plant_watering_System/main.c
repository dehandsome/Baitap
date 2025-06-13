#include "System/system.h"
#include "Sensor/sensor.h"
#include "Actuators/actuator.h"
#include "Buttons/button.h"
#include "Watering_logic/watering_logic.h"

int main() {
    systemInit();
    sensorInit();
    actuatorInit();
    buttonInit();
    wateringLogicInit();

    while (1) {
        readButtons();
        readSensors();
        processWateringLogic();
        updateActuatorStatus();
        updateSystemStatus();
    }
    return 0;
}