#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#define Buzzer 23

#define I2C_ADDR 0x27
#define totalRows 2
#define totalColumns 16

LiquidCrystal_I2C lcd(I2C_ADDR, totalColumns, totalRows);
#define TRIGGER_PIN 16
#define ECHO_PIN 17


NewPing sonar(TRIGGER_PIN, ECHO_PIN);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  Serial.println("Hello Buzz!");
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  unsigned int distance = sonar.ping_cm();
if(distance<=20){
   
  Serial.print("UZAKLIK= ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("UZAKLIK= ");
  lcd.print(distance);
  lcd.print(" cm");
 
  delay(50);
  tone(Buzzer,493);
  delay(50);
  noTone(Buzzer);
  delay(500);
  lcd.clear();
  
}
else if(20<distance && distance<40){
  
  Serial.print("UZAKLIK= ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("UZAKLIK= ");
  lcd.print(distance);
  lcd.print(" cm");
  
  delay(200);
  tone(Buzzer,493);
  delay(200);
  noTone(Buzzer);
  delay(500);
  lcd.clear();
  
}
else{
  unsigned int distance = sonar.ping_cm();
  Serial.print("UZAKLIK= ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("UZAKLIK= ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(500);
  lcd.clear();

} 
}
