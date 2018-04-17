#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial  BTSerial(2, 3); //TX RX
//initializing Servo object
Servo servo2;

const int sensorPin = A0; //light sensor
const int servoPin = 10; //Servo motor(white wire)
const int lightPin = 9; 

int threshold = 200;

void push(){
    servo2.write(-65);
    delay(300);
    servo2.write(65);
}

void setup() {
  BTSerial.begin(9600); 
  Serial.begin(9600); 
  servo2.attach(servoPin); 
  
  pinMode(lightPin, OUTPUT); //defining LED pin as output
}

int alreadyPushed = 0;
void loop() {
  int val = analogRead(sensorPin); //read light sensor data
  Serial.println(val); //print to serial monitor
  
  if(val < threshold) { 
    //digitalWrite(lightPin, HIGH);
    BTSerial.print("H");
    if (alreadyPushed == 0)
    {
      push();
      alreadyPushed = 1;
    }
  }
  else {
    //digitalWrite(ledPin, LOW);
    BTSerial.print("L");
    Serial.println("L");
    servo2.write(65);
    if (alreadyPushed == 1)
    {
      push();
    }
    alreadyPushed = 0;
  }
  delay(100);
}


