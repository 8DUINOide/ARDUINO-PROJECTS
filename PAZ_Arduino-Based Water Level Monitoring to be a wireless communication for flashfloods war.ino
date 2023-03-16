//======================================================================================
//Filename : PAZ_Arduino-Based Water Level Monitoring to be a wireless communication for flashfloods warning system.ino
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number:4
//Description :An arduino code that can detect water in a certain level, and will display the level of water in LCD Display. And also the lights will on depending to the level of the water being detected.
//Last modified: March 16, 2023
//======================================================================================

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LED_Y 8 //define yellow LED pin
#define LED_G 9 //define green LED
#define LED_R 10 //define red LED
#define BUZZER 2 //buzzer pin

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.print("Hello, world!");
   pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
}
void loop() {
  int value = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("   ");
  Serial.println(value);

  lcd.setCursor(0, 1);
  lcd.print("W Level :");

  if (value == 0) {
    lcd.print("Empty ");
  } else if (value > 50 && value < 290) {
    lcd.print("LOW   ");
    digitalWrite(LED_Y, HIGH);
    delay(300);
     digitalWrite(LED_G, LOW);
    delay(300);
     digitalWrite(LED_R, LOW);
    delay(300);
  } else if (value > 291 && value < 350) {
    lcd.print("Medium");
    digitalWrite(LED_Y, LOW);
    delay(300);
     digitalWrite(LED_G, HIGH);
    delay(300);
     digitalWrite(LED_R, LOW);
    delay(300);
  } else if (value > 351){
    lcd.print("HIGH  ");
    digitalWrite(LED_Y, LOW);
    delay(300);
     digitalWrite(LED_G, LOW);
    delay(300);
     digitalWrite(LED_R, HIGH);
    delay(300);
    tone(BUZZER, 300);
    delay(1000);
    noTone(BUZZER);
  }
}
