#include <Arduino.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
//Hello
// put function declarations here:
int myFunction(int, int);

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;


/*Measuring Voltage*/
/*float Voltage;
void battery_voltage(void) {
  Voltage=(float)analogRead(13)/28 (Interchangeable 62 and 28[28 not tested]); 
}*/

void setup() {
  /*LEDs*/
  /*pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  delay(4000);
  digitalWrite(5, LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH); */

  /*Measuring Voltage*/
  /*Serial.begin(57600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);*/

  /*Measuring angles with Gyro*/
  Serial.begin(57600);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  /*Measuring Voltage*/
  /*battery_voltage();
  Serial.print(Voltage);
  Serial.println("V");
  delay(50);*/

  /*Measuring angles via gyroscope*/
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255); 
  data.Z = map(az, -17000, 17000, 0, 255);  // Y axis data
  delay(500);
  Serial.print("Axis X = ");
  Serial.print(data.X);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.print(data.Y);
  Serial.print("  ");
  Serial.print("Axis Z  = ");
  Serial.println(data.Z);
}


