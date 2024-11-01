#include <Arduino.h>
#include <Wire.h>
//Hello
// put function declarations here:
int myFunction(int, int);

float RateRoll, RatePitch, RateYaw;
void gyro_signals(void){
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();

  Wire.beginTransmission(0x68);
  Wire.write(0x1B); 
  Wire.write(0x8); 
  Wire.endTransmission();

  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);

  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();

  RateRoll = float(GyroX / 65.5);
  RatePitch = float(GyroY / 65.5);
  RateYaw = float(GyroZ / 65.5);
}

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
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
}

void loop() {
  /*Measuring Voltage*/
  /*battery_voltage();
  Serial.print(Voltage);
  Serial.println("V");
  delay(50);*/

  gyro_signals();
  Serial.print("Roll rate [°/s]= ");
  Serial.print(RateRoll);
  Serial.print(" Pitch Rate [°/s]= ");
  Serial.print(RatePitch);
  Serial.print("Yaw rate [°/s]= ");
  Serial.print(RateYaw);
  delay(50);
}


