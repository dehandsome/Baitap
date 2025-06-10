#include <stdio.h>
#include <stdlib.h>
#include "hvac_system.h"

#include <stdio.h>
#include <stdlib.h>
#include "hvac_system.h"

static void setTemperature(int temperature) {
    printf("Nhiet do duoc cai dat: %d°C.\n", temperature);
}

static void setMode(const char* mode) {
    printf("HVAC đang ở chế độ: %s.\n", mode);
}

// Function to create an HvacSystem instance
HvacSystem* createHvacSystem() {
    HvacSystem* system = (HvacSystem*)malloc(sizeof(HvacSystem));
    system->setTemperature = setTemperature; 
    system->setMode = setMode;               
}