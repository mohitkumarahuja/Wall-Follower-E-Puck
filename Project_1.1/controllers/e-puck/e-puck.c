
/*

  { Project 1 }
  {   Part 1  }

Code submitted by:
Team members:

1.> Mohit Kumar Ahuja
2.> Marc Blanchon


Course 	: MSCV
Subject : Autonomous Robotics




Code submitted to: 

Prof. Xevi Cufí   
University of GIRONA

*/



// including important libraries
#include <webots/robot.h>
#include <webots/differential_wheels.h>
#include <webots/distance_sensor.h>
#include <webots/led.h>
#include <stdio.h>
#define TIME_STEP 64 /* ms */
#define WHEEL_RADIUS 0.0205 /* m */
#define AXLE_LENGTH 0.052 /* m */
#define ENCODER_RESOLUTION 159.23 /* pulses per revolution  */
#define RANGE (1024 / 2)

int main(int argc, char *argv[]) {
  //* define variables */
  WbDeviceTag distance_sensor_0; // declared device tag variables for storing robot sensor values
  WbDeviceTag distance_sensor_1; // declared device tag variables for storing robot sensor values
  WbDeviceTag distance_sensor_2; // declared device tag variables for storing robot sensor values
  WbDeviceTag distance_sensor_3; // declared device tag variables for storing robot sensor values
  WbDeviceTag distance_sensor_4; // declared device tag variables for storing robot sensor values
  WbDeviceTag distance_sensor_5; // declared device tag variables for storing robot sensor values
  WbDeviceTag distance_sensor_6; // declared device tag variables for storing robot sensor values
  WbDeviceTag distance_sensor_7; // declared device tag variables for storing robot sensor values
  
  double sensors_value_0; // assigning sensor values a data type.
  double sensors_value_1; // assigning sensor values a data type.
  double sensors_value_2; // assigning sensor values a data type.
  double sensors_value_3; // assigning sensor values a data type.
  double sensors_value_4; // assigning sensor values a data type.
  double sensors_value_5; // assigning sensor values a data type.
  double sensors_value_6; // assigning sensor values a data type.
  double sensors_value_7; // assigning sensor values a data type.
  
  /* initialize Webots */
  wb_robot_init();
  wb_differential_wheels_enable_encoders(TIME_STEP*4); //enabling encoders
  distance_sensor_0 = wb_robot_get_device("ps0"); //get distance sensors
  distance_sensor_1 = wb_robot_get_device("ps1"); //get distance sensors
  distance_sensor_2 = wb_robot_get_device("ps2"); //get distance sensors
  distance_sensor_3 = wb_robot_get_device("ps3"); //get distance sensors
  distance_sensor_4 = wb_robot_get_device("ps4"); //get distance sensors
  distance_sensor_5 = wb_robot_get_device("ps5"); //get distance sensors
  distance_sensor_6 = wb_robot_get_device("ps6"); //get distance sensors
  distance_sensor_7 = wb_robot_get_device("ps7"); //get distance sensors
  
  wb_distance_sensor_enable(distance_sensor_0,TIME_STEP*4); //enabling distance sensors
  wb_distance_sensor_enable(distance_sensor_1,TIME_STEP*4); //enabling distance sensors
  wb_distance_sensor_enable(distance_sensor_2,TIME_STEP*4); //enabling distance sensors
  wb_distance_sensor_enable(distance_sensor_3,TIME_STEP*4); //enabling distance sensors
  wb_distance_sensor_enable(distance_sensor_4,TIME_STEP*4); //enabling distance sensors
  wb_distance_sensor_enable(distance_sensor_5,TIME_STEP*4); //enabling distance sensors
  wb_distance_sensor_enable(distance_sensor_6,TIME_STEP*4); //enabling distance sensors
  wb_distance_sensor_enable(distance_sensor_7,TIME_STEP*4); //enabling distance sensors
  
  /* infinite for loop */
  for (;;) {
    
    /* get sensors values */
    sensors_value_0 = wb_distance_sensor_get_value(distance_sensor_0); //getting values from those distance sensors
    sensors_value_1 = wb_distance_sensor_get_value(distance_sensor_1); //getting values from those distance sensors
    sensors_value_2 = wb_distance_sensor_get_value(distance_sensor_2); //getting values from those distance sensors
    sensors_value_3 = wb_distance_sensor_get_value(distance_sensor_3); //getting values from those distance sensors
    sensors_value_4 = wb_distance_sensor_get_value(distance_sensor_4); //getting values from those distance sensors
    sensors_value_5 = wb_distance_sensor_get_value(distance_sensor_5); //getting values from those distance sensors
    sensors_value_6 = wb_distance_sensor_get_value(distance_sensor_6); //getting values from those distance sensors
    sensors_value_7 = wb_distance_sensor_get_value(distance_sensor_7); //getting values from those distance sensors
    
    /* bahaviours and speed values*/
    // If any one of the sensors 0,1,6,7 detect wall at 2 cm ie sensor_value>400 it will stop
    if ((sensors_value_0>=440)||(sensors_value_1>=440)||(sensors_value_6>=440)||(sensors_value_7>=440)) { // 1
      wb_differential_wheels_set_speed(0,0);
      wb_robot_step(TIME_STEP*10000);
      printf("Stop\n");
      printf("sensors values: %g %g %g %g  \n",sensors_value_0, sensors_value_1, sensors_value_6, sensors_value_7);
      break; // exit for loop
    }
    else { //2     // Otherwise if nothing is detected it should move forward.
      printf("7 Move Forward\n");
      printf("sensors values: %g %g %g %g  \n",sensors_value_0, sensors_value_1, sensors_value_6, sensors_value_7);
      wb_differential_wheels_set_speed(200,200);
      wb_robot_step(TIME_STEP);
    }
 } // for loop
  return 0;
}/* int main ... */

