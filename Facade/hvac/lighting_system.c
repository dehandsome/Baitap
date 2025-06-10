#include<stdio.h>
#include<stdlib.h>
#include"smart_home_facade.h"
#include"lighting_system.h"

static void turnOn() {
    printf(" Den da duoc bat.\n");
  }
static void turnOff(){
    printf("Den da duoc tat.\n");
  }
static void setBrightness(int level){
    printf("Den duoc cai dat voi muc sang %d.\n",level);
}
LightingSystem * createLightingSystem(){
    LightingSystem *system = (LightingSystem*)malloc(sizeof(LightingSystem));
    system->turnOn=turnOn;
    system->turnOff=turnOff;
    system->setBrightness=setBrightness;
    return system;
}