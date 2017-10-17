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
void setup() {
  // put your setup code here, to run once:
pinMode(A2, OUTPUT); //trigger pin
  pinMode(A3, INPUT); //echo pin
  Serial.begin(9600); // initialize serial communication:
}

void loop() {
  // put your main code here, to run repeatedly:
int distance = getDistance(A2, A3, "cm");
  Serial.print(distance);
  Serial.println(" centimeters");
}
