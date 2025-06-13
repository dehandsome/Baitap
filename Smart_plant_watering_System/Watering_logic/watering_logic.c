#include <stdio.h>
#include "watering_logic.h"
#include "../Sensor/sensor.h"
#include "../System/system.h"
#include "../Actuators/actuator.h"

void wateringLogicInit() {
    
}

void processWateringLogic() {
    if (systemState.currentMode == MODE_AUTO) {
        // Nếu bơm đang TẮT, kiểm tra điều kiện để BẬT
        if (systemState.pumpStatus == PUMP_OFF) {
            if (sensorData.soilMoisture < systemState.moistureMinThreshold) {
                if ((systemState.currentTime - systemState.lastWateringTime) >= systemState.sensorCheckInterval) {
                    turnPumpOn();
                    systemState.pumpStartTime = systemState.currentTime;
                    printf("Bơm được BẬT (độ ẩm thấp và đã hết thời gian chờ giữa hai lần tưới)\n");
                }
            }
        }

        // Nếu bơm đang BẬT, kiểm tra điều kiện để TẮT
        if (systemState.pumpStatus == PUMP_ON) {
            if (sensorData.soilMoisture >= systemState.moistureMaxThreshold) {
                turnPumpOff();
                systemState.lastWateringTime = systemState.currentTime;
                printf("Bơm TẮT do đạt ngưỡng độ ẩm tối đa\n");
            } else if ((systemState.currentTime - systemState.pumpStartTime) >= systemState.wateringDurationMax) {
                turnPumpOff();
                systemState.lastWateringTime = systemState.currentTime;
                printf("Bơm TẮT do đã tưới đủ thời gian tối đa\n");
            }
        }
    }
}

