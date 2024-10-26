#include <Arduino.h>
//Hello
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);

  delay(4000);

  digitalWrite(5, LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}


