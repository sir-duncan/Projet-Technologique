#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Wire.h>

void setup() {
  Serial.begin (9600);

  while(!Serial); // Waiting for Serial connection

  Serial.println("\nScanning for I2C device...");
  byte count = 0;
 
  Wire.begin();
  for (byte i = 1; i < 120; i++) {
    Wire.beginTransmission(i);
    if(Wire.endTransmission() == 0){
      Serial.print("Found address: ");
      Serial.print(i, DEC);
      Serial.print(" (0x");
      Serial.print(i, HEX);
      Serial.println(")");
      count++;
    }
  }
  Serial.println ("Done.");
}

void loop() {}
