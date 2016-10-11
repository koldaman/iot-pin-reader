#include "Arduino.h"

#include <PinReader.h>

PinReader pinReader(4); // D2

void switchPin(uint8_t pin, boolean state) {
   Serial.println("Switching state");
   digitalWrite(pin, state);     // set pin to the opposite state
}

void pinCallback(int oldValue, int newValue) {
   Serial.print("Pin D2 changed from ");
   Serial.print(oldValue);
   Serial.print(" to ");
   Serial.println(newValue);
   digitalWrite(0, newValue);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //set led pin as output
  pinMode(0, OUTPUT);

  pinReader.init();
  pinReader.setCallback(pinCallback);
}

void loop() {

}
