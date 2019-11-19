#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(10, 9); // SS_PIN 10, RST_PIN 9

int lock = 6;
int serrure = 3 //(pour gérer une gache éléctrique)

void setup() 
{
  pinMode(lock, OUTPUT);
  pinMode (serrure, OUTPUT);
 
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init(); 

  Serial.println("Test acces via TAG RFID\n");
}

void loop()
{
  if(mfrc522.PICC_IsNewCardPresent() == 0) return;
  if(mfrc522.PICC_ReadCardSerial() == 0) return;
  
  Serial.print("UID de tag :");
  String tag= "";
  byte caractere;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     tag.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     tag.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  tag.toUpperCase();
  
  if (tag.substring(1) == "06 62 20 02"){ // En fonction de la réponse
    digitalWrite(lock, HIGH);
    Serial.println("TAG verifie - Acces Autorise !\n");
    delay(3000);
    digitalWrite(lock, LOW);
    digitalWrite(serrure, LOW) 
  }  
  else {
    Serial.println("TAG inconnu - Acces refuse !!!\n");
    for (int i = 1; i < 5 ; i++) {
      digitalWrite(lock, HIGH);
      delay(200);
      digitalWrite(lock, LOW);
      delay(200);
    }
  }
  delay(1000);
}
