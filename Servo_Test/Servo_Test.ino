#include <Servo.h>
Servo tail; // declaring servo
Servo paw;// declaring servo
void setup() {
 tail.attach(5); // attaching servo
  paw.attach(10);// attaching servo
  }
  void loop() {
     tail.write(80);//moving servo
    delay(1000);
    tail.write(170);
    delay(1000);
    paw.write(80); // moving servo
       delay(1000);
       paw.write(170); // moving servo
    }
