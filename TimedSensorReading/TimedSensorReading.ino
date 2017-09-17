const int analogInPin = A0; // input pin for analog sensor (mic or pot)

int sensorValue = 0; // analog value read from analog input

int interval = 2000;   // take a sample every x millis
long lastReading = 0;  // records time of last reading

void setup() {
  
  // start serial comms to log values in serial monitor
  // set bps (bits per sec) to 115200; match it to monitor's baud
  Serial.begin(115200); 
}

void loop() {

  if(millis() - lastReading > interval) {
    
    lastReading = millis(); //record time of the last reading
    
    // analog values represented using 10 bits of data;
    // 10 bits means 2 to the 10th power (2^10 = 1024)
    // val includes zero, so analog range is : 0 to 1023
    sensorValue = analogRead(analogInPin);
    
    // log sensor value to the serial monitor
    Serial.println(sensorValue);

    // DO SOMETHING WITH YOUR READING HERE :
  }
}
