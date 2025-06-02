<<<<<<< HEAD
#include"sensor_manager.h"
int main(){
     Sensor_Manager* sensor_manager =created_SensorManagerInstance();
      add_Sensor(sensor_manager,101);
      add_Sensor(sensor_manager,102);
      add_Sensor(sensor_manager,103);

      list_Senssors(sensor_manager);
      collect_SensorData(sensor_manager);
      upload_SensorData(sensor_manager);
      remove_Sensor(sensor_manager,102);
      list_Senssors(sensor_manager);
      destroy_SensorManager();
      return 0 ;
=======
#include"sensor_manager.h"
int main(){
     Sensor_Manager* sensor_manager =created_SensorManagerInstance();
      add_Sensor(sensor_manager,101);
      add_Sensor(sensor_manager,102);
      add_Sensor(sensor_manager,103);

      list_Senssors(sensor_manager);
      collect_SensorData(sensor_manager);
      upload_SensorData(sensor_manager);
      remove_Sensor(sensor_manager,102);
      list_Senssors(sensor_manager);
      destroy_SensorManager();
      return 0 ;
>>>>>>> 04db0b39fbbafbe5b55c0d742a7e5dd09ec37aa1
}