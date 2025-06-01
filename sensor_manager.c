#include "sensor_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Sensor_Manager* created_SensorManagerInstance(){
if(sensor_manager_instance==NULL){
     sensor_manager_instance = (Sensor_Manager*)malloc(sizeof(Sensor_Manager));
     sensor_manager_instance->Nodes=NULL;
     sensor_manager_instance->nodeCount=0;
     printf("Sensor manager created \n");
}
   return sensor_manager_instance ;
}

void add_Sensor(Sensor_Manager*sensor_manager,int id){
    for(int i=0;i<sensor_manager-> nodeCount;i++){
        if(sensor_manager->Nodes[i].id){
            printf(" Sensor ID %d already exists. \n",id);
            return;
        }
    }
    sensor_manager->Nodes =realloc(sensor_manager->Nodes,sizeof(Sensor_Node)*(sensor_manager->nodeCount +1));
    sensor_manager->Nodes[sensor_manager->nodeCount].id  = id;
    sensor_manager->Nodes[sensor_manager->nodeCount].data =0.0f;
    sensor_manager->nodeCount++;
    printf("Added sensor with ID %d. \n", id);
}

void remove_Sensor(Sensor_Manager*sensor_manager,int id ){
    int found=0;
    for(int i=0;i<sensor_manager->nodeCount;i++){
        if(sensor_manager->Nodes[i].id==id){
          found =1 ;
          for(int j=i;j<sensor_manager->nodeCount-1;j++){
            sensor_manager->Nodes[j]=sensor_manager->Nodes[j+1];

          }
          sensor_manager->nodeCount--;
          sensor_manager->Nodes = realloc(sensor_manager->Nodes,sizeof(Sensor_Node)* sensor_manager->nodeCount);
          printf("Removed sensor with ID %d.\n",id);
          break;  
        }
    }
    if(!found){
        printf("Sensor ID %d not found. \n",id);
    }
}

void list_Senssors(Sensor_Manager*sensor_manager){
    printf("Sensor List (%d): \n",sensor_manager->nodeCount);
    for(int i=0;i<sensor_manager->nodeCount;i++){
        printf("ID: %d | Data: %.2f \n",sensor_manager->Nodes[i].id,sensor_manager->Nodes[i].data);
    }
    if(sensor_manager->nodeCount==0){
        printf("[ No semsors found] \n");
    }
}

void collect_SensorData(Sensor_Manager*sensor_manager){
    srand(time(NULL));
    for(int i=0;i<sensor_manager->nodeCount;i++){
        float fakeData=20.0f + (rand()%2000) / 100.0f;
        sensor_manager->Nodes[i].data=fakeData;
    }
    printf("Collected new data from sensors. \n");
}

void uploadSensorData(Sensor_Manager*sensor_manager){
    printf("uploading sensor data to databasse: \n");
    for(int i=0;i<sensor_manager->nodeCount;i++){
        printf(" Sensor ID : %d | Data: %.2f \n ",sensor_manager->Nodes[i].id,sensor_manager->Nodes[i].data);
    }
}

void destroy_SensorManager(){
    if(sensor_manager_instance != NULL){
        free(sensor_manager_instance->Nodes);
        free(sensor_manager_instance);
        sensor_manager_instance=NULL;
        printf("SensorManager destroyed. \n");
    }
}
