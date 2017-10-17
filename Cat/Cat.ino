#include <Servo.h> // Including servo library
Servo tail;// attach tail servo
Servo paw;// attach paw servo
void setup() {
pinMode(A2, OUTPUT); // trigger pin
pinMode(A3, INPUT); // echo pin
Serial.begin(9600);
pinMode(A0, OUTPUT); // light
pinMode(A1, OUTPUT); // light
  paw.attach(10);// attaching servo  
  tail.attach(5); // THIS IS SCREWING IT UP!!!
}

void loop() {
  // put your main code here, to run repeatedly:
 int distance = getDistance(A2, A3, "cm"); // finding distance of ultrasonic
  Serial.print(distance); // Printing value of ultrasonic
  Serial.println(" centimeters"); // Printing centimeters after value of ultrasonic
  
  if (distance < 30){
   int randomnumber = random(1, 3); // Picking random number
   digitalWrite(A0, HIGH); // Turning on light
   digitalWrite(A1, HIGH); // Turning on other light
   delay(1000);
    if (randomnumber == 1){
      tail.write(80);// wags tail
      delay(500);
      tail.write(170); // wags tail
      } else if (randomnumber == 2){
        paw.write(80); // moves paw
        delay(500);
        paw.write(170); // moves paw
        }
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      
    }
}
