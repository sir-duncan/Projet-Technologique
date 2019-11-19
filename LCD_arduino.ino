#include <LiquidCrystal.h>

const int LED = 6;
//LiquidCrystal lcd(2, 3, 5, 6, 7, 8);
void setup() {
  pinMode(LED, OUTPUT);
  //lcd.begin(16, 2);
  //lcd.print("Projet Techno");
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);
}
