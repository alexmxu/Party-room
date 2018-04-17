#include <SoftwareSerial.h>
#include <Servo.h>

//initializing Servo object
Servo servo1;

SoftwareSerial  BTSerial(2, 3); //TX RX
int servoPin = 10;
void setup() {
  BTSerial.begin(9600); //begin bluetooth communication
  Serial.begin(9600); //begin serial communication
  servo1.attach(servoPin);
}

void loop() {
  if (BTSerial.available()) {
    char inChar = (char) BTSerial.read(); //reads single character at a time
    if(inChar == 'L') {
      servo1.write(90);
    }
    else if(inChar == 'H') {
      servo1.write(0);
    }
    Serial.println(inChar);
  }
}
