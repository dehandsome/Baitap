#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include<stdlib.h>

typedef struct 
{
    int id;
    float data;
}Sensor_Node;

typedef struct 
{
    Sensor_Node * Nodes;
    int nodeCount;

}Sensor_Manager;

static Sensor_Manager* sensor_manager_instance = NULL;

Sensor_Manager* created_SensorManagerInstance();

void add_Sensor(Sensor_Manager*sensor_manager,int id);
void remove_Sensor(Sensor_Manager*sensor_manager,int id );
void list_Senssors(Sensor_Manager*sensor_manager);

void collect_SensorData(Sensor_Manager*sensor_manager);
void upload_SensorData(Sensor_Manager*Sensor_manager);

void destroy_SensorManager();

#endif
