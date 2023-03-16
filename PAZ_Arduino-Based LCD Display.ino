
//======================================================================================
//Filename : PAZ_Arduino-Based LCD Display.ino
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number:7
//Description :An arduino code that can be used to display tect in LCD Display
//Last modified: March 16, 2023
//======================================================================================


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.print("Hello, world!");
}

void loop()
{
  // Do nothing here...
 lcd.clear();
 lcd.setCursor(3,0);
 lcd.print("Capstone E");
 delay(3000);
lcd.clear();
lcd.print("My Capstone");
delay(1000);
lcd.clear();
 lcd.print("Project entitled");
 delay(1000);
lcd.clear();
lcd.print("'Fire Alarm");
delay(1000);
lcd.clear();
 lcd.print("System with GSM-");
 delay(1000);
lcd.clear();
lcd.print("Based Monitoring");
delay(1000);
lcd.clear();
 lcd.print("Scheme'");
 delay(1000);
 lcd.clear();
lcd.setCursor(3,0);
 lcd.print("Thank You!");
 delay(3000);
lcd.clear();
 
}
