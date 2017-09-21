/*
  SD card datalogger

  This example shows how to log data from three analog sensors
  to an SD card using the SD library.

  The circuit:
   analog sensors on analog ins 0, 1, and 2
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created  24 Nov 2010
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>
#define PIN_GATE_IN 2
#define IRQ_GATE_IN  0
#define PIN_LED_OUT 13
#define PIN_ANALOG_IN A0

//Important! chip select is 10 for Arduino Uno!
const int chipSelect = 10;


//This is for the Sparkfun Sound Detector
void soundISR()
{
  int pin_val;

  pin_val = digitalRead(PIN_GATE_IN);
  digitalWrite(PIN_LED_OUT, pin_val);
}
////////////////////////////////////////

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop() {

  int value;

  // Check the envelope input (It should be connected to A0)
  value = analogRead(PIN_ANALOG_IN);

  // pause for 1 second
  delay(5000);

  
  // make a string for assembling the data to log:
  String dataStringLow = "";
  String dataStringMod = "";
  String dataStringHigh = "";

  
  // read three sensors and append to the string:
  int analogPin = 0;

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("DATALOG2.txt", FILE_WRITE);
  
  int sensor = analogRead(analogPin);
  if (value <= 10) {
    //Append Sensor Value to dataStringMod Variable

    dataStringLow += String(sensor) ;
  }
  else if ((value > 10) && ( value <= 30) ) {

    //Append Sensor Value to dataStringMod Variable
    dataStringMod += String(sensor) ;
  }
  else if (value > 30) {

    //Append Sensor Value to dataStringHigh Variable
    dataStringHigh += String(sensor) ;
  }


  // if the file is available, write to it:
  if (dataFile) {
    if (value <= 10) {
      dataFile.println("Low," + dataStringLow);
      Serial.println("Low," + dataStringLow);

    }
    else if ((value > 10) && ( value <= 30) ) {
      dataFile.println("Medium," + dataStringMod);
      Serial.println("Medium," + dataStringMod);

    }
    else if (value > 30) {
      dataFile.println("High," + dataStringHigh);
      Serial.println("High," + dataStringHigh);
    }

    dataFile.close();

  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening DATALOG2.txt");
  }
}









