
/*

  { Project 1 }
  {   Part 2  }

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

//including important libraries
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
  WbDeviceTag distance_sensor_0; //declared device tag variables 
  WbDeviceTag distance_sensor_1; //declared device tag variables 
  WbDeviceTag distance_sensor_2; //declared device tag variables 
  WbDeviceTag distance_sensor_3; //declared device tag variables 
  WbDeviceTag distance_sensor_4; //declared device tag variables 
  WbDeviceTag distance_sensor_5; //declared device tag variables 
  WbDeviceTag distance_sensor_6; //declared device tag variables 
  WbDeviceTag distance_sensor_7; //declared device tag variables 
  
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
  wb_differential_wheels_enable_encoders(TIME_STEP*4);
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
    // If sensor_value 0,1,6,7 exceeds 500 and sensor_value 5 is less than 500then robot should turn right
    if (((sensors_value_0>=500)||(sensors_value_1>=500)||(sensors_value_6>=500)||(sensors_value_7>=500)) && (sensors_value_5<=500)) { // 1 right
      
      wb_differential_wheels_set_speed(100,-100);
      wb_robot_step(TIME_STEP);
      printf("1 Right Turn for wall detection\n");
      printf("sensors_value_5: %g m.\n",sensors_value_5);
    }
    
    // If sensor_value 0,1,6,7 exceeds 500 and sensor_value 5 is greater than 500 then robot should turn right
    else if (((sensors_value_0>=500)||(sensors_value_1>=500)||(sensors_value_6>=500)||(sensors_value_7>=500)) && (sensors_value_5>=500)) { // 2 right
      
      wb_differential_wheels_set_speed(100,-100);
      wb_robot_step(TIME_STEP);
      printf("2 Right Turn\n");
      printf("sensors_value_5: %g m.\n",sensors_value_5);
    }
    
    // If value of all the sensors 0,1,6,7 reduces from 500 but sensor 5 have value greater than 500 but less than 550, then robot should go straight
    else if ((((sensors_value_0<=500)||(sensors_value_1<=500))&&((sensors_value_6<=500)||(sensors_value_7<=500))) && (550>sensors_value_5 && sensors_value_5>500)){ // 3 Straight
      
      printf("3 Straight\n");
      printf("sensors_value_5: %g m.\n",sensors_value_5);
      wb_differential_wheels_set_speed(200,200);
      wb_robot_step(TIME_STEP);
    }
    
    // If value of all the sensors 0,1,6,7 reduces from 500 but sensor 5 have value greater than 400 but less than 500, then robot should turn left
    else if ((((sensors_value_0<=500)||(sensors_value_1<=500))&&((sensors_value_6<=500)||(sensors_value_7<=500))) && (500>sensors_value_5 && sensors_value_5>400)){ // 4 Left
      
      printf("4 Slight Left\n");
      wb_differential_wheels_set_speed(-10,40);
      wb_robot_step(TIME_STEP);
    }
    
    // If value of all the sensors 0,1,6,7 reduces from 500 but sensor 5 have value greater than 550 but less than 600, then robot should turn right
    else if ((((sensors_value_0<=500)||(sensors_value_1<=500))&&((sensors_value_6<=500)||(sensors_value_7<=500))) && (600>sensors_value_5 && sensors_value_5>550)){ // 5 Right
      
      printf("5 Slight Right\n");
      printf("sensors_value_5: %g m.\n",sensors_value_5);
      wb_differential_wheels_set_speed(40,-10);
      wb_robot_step(TIME_STEP);
    }
    
    // If none of the above mentioned if conditions are executed that means there is no wall so robot should move forward
    else {                                                       // 6
      
      printf("6 Move Forward\n");
      printf("sensors_value_5: %g m.\n",sensors_value_5);
      wb_differential_wheels_set_speed(200,200);
      wb_robot_step(TIME_STEP);
    }
    
 } // for loop
 
  return 0;
  
}/* int main ... */

