#include <ezButton.h>
ezButton toggleSwitch(8);  // create ezButton object that attach to pin 7;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set th'\e LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 7;
const int echoPin = 6;
long duration;
int Cm,Inch;
void setup() {
 toggleSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
 // initialize the LCD
  lcd.init();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.print("Hello, world!");
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
  toggleSwitch.loop(); // MUST call the loop() function first
     
  int state = toggleSwitch.getState();
 if (state == HIGH){ // For inches
    Serial.println("The switch: OFF");
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
    Inch = duration*0.0133/2;
  lcd.setCursor(0,1);
  lcd.print("Distance:");
  Serial.println("Inch");
  lcd.print(Inch);
  lcd.print("  inch");
    delay(10);
    lcd.setCursor(0,0);
  lcd.print("Grp2:Math Device");
 }
     if(state == LOW){        // For centimeter
    Serial.println("The switch: ON");
   
     digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Cm= duration*0.034/2;
  lcd.setCursor(0,1); 
  lcd.print("Distance: "); 
  lcd.print(Cm);
  lcd.print("  cm");
  delay(10);
    lcd.setCursor(0,0);
  lcd.print("Grp2:Math Device");
  
     }
}
 
