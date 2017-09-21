const int ledPin = 11;

int brightness = 0;
int ledDirection = 1;

void setup() {
  //set up   
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // apply brightness to LED
  analogWrite(ledPin,brightness);

  // increase brightness by adding direction
  brightness = brightness + ledDirection;

  // condition
  if(brightness == 0 || brightness == 255){
    
    // invert direction
    ledDirection = -ledDirection;
  }

  // wait for 10 miliseconds
  delay(10);
  
}
