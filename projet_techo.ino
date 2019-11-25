#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
MFRC522 mfrc522(10, 9); // SS_PIN 10, RST_PIN 9

const int buzzer = 8;
const int led = 6;
const int green = 7;
const int red = 2;

void setup() 
{
  lcd.begin();
  pinMode(buzzer, OUTPUT); // Pour le buzzer
  pinMode(led, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
 
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  lcd.clear();  
  lcd.setCursor(4, 0);
  lcd.print("Presentez");
  lcd.setCursor(3, 1);
  lcd.print("votre carte");

}

void loop()
{  
  if(mfrc522.PICC_IsNewCardPresent() == 0) return;
  if(mfrc522.PICC_ReadCardSerial() == 0) return;
  
  String tag= "";
  byte caractere;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     tag.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
     tag.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  tag.toUpperCase();
  
  lcd.clear();  
  lcd.setCursor(4, 0);
  lcd.print("Tag scan :");
  lcd.setCursor(2, 1);
  lcd.print(tag);
  Serial.println(tag);

  digitalWrite(green, LOW);
//  digitalWrite(red, LOW);
  tone(buzzer, 1500);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  lcd.clear();  
  //digitalWrite(buzzer, LOW);
  noTone(buzzer);
  lcd.setCursor(4, 0);
  lcd.print("Presentez");
  lcd.setCursor(3, 1);
  lcd.print("votre carte");

}
