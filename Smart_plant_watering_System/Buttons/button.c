#include <stdio.h>
#include "button.h"
#include "../System/system.h"
#include "../Actuators/actuator.h"

void buttonInit() {
}

void readButtons() {
    
    static int counter = 0;
    counter++;
    if (counter % 10 == 0) {
        if (systemState.currentMode == MODE_AUTO) {
            systemState.currentMode = MODE_MANUAL;
            turnPumpOff();
        } else {
            systemState.currentMode = MODE_AUTO;
        }
        printf("Button: Toggled mode\n");
    }
}