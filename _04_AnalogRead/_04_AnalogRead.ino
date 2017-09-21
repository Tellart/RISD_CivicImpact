/*
Potentiometer (AnalogRead)
by Epic
*/

int potentiometer = 0;

void setup() {
  // we'll use serial to monitor the values
  Serial.begin(9600);  
}

void loop() {
  // use analogRead() to get current value
  potentiometer = analogRead(0);

  Serial.println(potentiometer);

  delay(10);
}
