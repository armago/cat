int getDistance(int trig, int echo, int unit) {

  long duration;
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);



  if (unit == "in") {
    return duration / 74 / 2;
  }

  else if (unit == "cm") {
    return duration / 29 / 2; 
  }

  else {
    return duration;
  }
  
  
}
#include <Servo.h>
Servo myservo;
Servo myservoo;

/*This example sets a variable as the distance reading and then
prints it to the serial monitor every second.
*/
void setup() {
  pinMode(7, OUTPUT); //trigger pin
  pinMode(6, INPUT); //echo pin
  Serial.begin(9600); // initialize serial communication:
  myservo.attach(9);
  myservoo.attach(10);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  /* initializes variable distance and sets it to the ultrasonic
  value */ 

  String motors = ["myservo"];
  int distance = getDistance(7, 6, "cm");
  Serial.print(distance);
  Serial.println(" centimeters");
  if (distance < 30) {
    myservo.write(90);
    myservoo.write(90);
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
delay(1000);
myservo.write(180);
myservoo.write(180);
delay(1000);
digitalWrite(13, LOW);
digitalWrite(12, LOW);
  
    }
}
