#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(3, 0);
  lcd.print("Presentez");
  lcd.setCursor(2, 1);
  lcd.print("votre carte");
}
