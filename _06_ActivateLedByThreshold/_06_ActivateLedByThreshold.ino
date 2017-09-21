const int analogInPin = A0;  // input pin for analog sensor (mic or pot)
const int analogOutPin = 13; // output pin for LED (using PWM)

int sensorValue = 0; // analog value read from analog input

int threshold = 800;  // analog threshold to reach, turns on led 
int brightness = 200; // analog pwm value (brightness) for led when on

void setup() {
  
  // start serial comms to log values in serial monitor
  // set bps (bits per sec) to 115200; match it to monitor's baud
  Serial.begin(115200); 
}

void loop() {

  // analog values represented using 10 bits of data;
  // 10 bits means 2 to the 10th power (2^10 = 1024)
  // val includes zero, so analog range is : 0 to 1023
  sensorValue = analogRead(analogInPin);

  // log sensor value to the serial monitor
  Serial.println(sensorValue);

  if(sensorValue > threshold) {
    // write output value to output pin (analog out)
    analogWrite(analogOutPin, brightness); //set
  } else {
    analogWrite(analogOutPin, 0);
  }


  // short pause for analog-to-digital converter to recover
  delay(10);
}
