#include "subscribers/alarm_system_controller.h"
#include <stdio.h>

void alarmSystemUpdate(Subscriber* self, Publisher* context, const char* eventInfo){
      (void)self; (void)context;
       printf("[AlarmSystem] Alarm: %s\n", eventInfo);
}
void alarmSystemControllerInit(AlarmSystemController* controller){
    controller->base.update = alarmSystemUpdate;
    controller->base.data = NULL;
}