
// Global variable
int animal;


void setup() {
  // whatever is in here will run once
  
  Serial.begin(9600);

  animal = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(animal);
  animal = animal + 1;

  delay(1000);

}
