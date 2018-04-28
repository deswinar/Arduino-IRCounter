#include<IRCounter.h>

IRCounter ir(7); // Initialize IR Sensor in pin 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int counter = ir.count(0); // Count when the logic is LOW
  Serial.println(counter);
  if(counter >= 10){
    ir.reset(); // Reset the counter when counter reach 10
  }
}
