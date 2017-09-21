const int analogInPin = A0;  // input pin for analog sensor (mic or pot)
const int analogOutPin = 13; // output pin for LED (using PWM)

int sensorValue = 0; // analog value read from analog input
int outputValue = 0; // value output as PWM (analog out)

void setup() {
  
  // start serial comms to log values in serial monitor
  // set bps (bits per sec) to 115200; match it to monitor's baud
  Serial.begin(9600); 
}

void loop() {
  
  // read analog input pin and save value
  sensorValue = analogRead(analogInPin);

  // map fn translates one range of numbers to another
  // analog values represented using 10 bits of data;
  // 10 bits means 2 to the 10th power (2^10 = 1024)
  // val includes zero, so analog range is : 0 to 1023
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  // log output value to the serial monitor
  Serial.println(outputValue);

  // write output value to output pin (analog out)
  analogWrite(analogOutPin, outputValue);

  // short pause for analog-to-digital converter to recover
  delay(10);
}
