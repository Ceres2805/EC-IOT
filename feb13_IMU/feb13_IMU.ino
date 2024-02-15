#include "Wire.h"
#include <MPU6050_light.h>


MPU6050 mpu(Wire);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();


   byte status = mpu.begin();
  Serial.println("MPU6050 status: ");
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
 
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");


}


void loop() {
  // put your main code here, to run repeatedly:
  mpu.update();
 
  float beta=mpu.getAngleX();
  float theta=mpu.getAngleY();
  float alpha=mpu.getAngleZ();


  Serial.print("X : ");
  Serial.print(beta);
  Serial.print("\tY : ");
  Serial.print(theta);
  Serial.print("\tZ : ");
  Serial.println(alpha);
 


}