//======================================================================================
//Filename : PAZ_Fire and Gas Alarm System.ino
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number:3
//Description :This project can detect fire and gas and then the buzzer activates. There is a text to be display in LCD when there is a fire or gas detected.
//Last modified: March 16, 2023
//======================================================================================

const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 8;
const int BUZZER_PIN = 5;
int gasPin = A0;
int flamePin = 2;
// Your threshold value
int gasSensorThres = 400;
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <ezButton.h>
ezButton toggleSwitch(7);  // create ezButton object that attach to pin 7;



void setup() {
  pinMode(LED1, OUTPUT);  
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
 pinMode(BUZZER_PIN, OUTPUT); 
  pinMode(gasPin, INPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
  // initialize the LCD
  lcd.init     ();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.print("Hello, world!");
   toggleSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
  
   
}

void loop() {

   toggleSwitch.loop(); // MUST call the loop() function first
     
  int state = toggleSwitch.getState();
 if (state == LOW){ // Morning
    Serial.println("The switch: ON");
      int gasSensor = analogRead(gasPin);
  int flameSensor = digitalRead(flamePin);
  
  if  (flameSensor==LOW){ // HIGH MEANS NO FLAME
    Serial.println("Fire Detected");
    lcd.setCursor(2, 0);
     lcd.print("Fire Detected");
     delay(1000);
    lcd.setCursor(3, 1);
    lcd.print("Take Action!");
    delay(3000);
    lcd.clear();
    digitalWrite(LED1, LOW); // Fire is Detected
    digitalWrite(LED2, HIGH);
     digitalWrite(LED3, LOW);
   digitalWrite(BUZZER_PIN,HIGH);
   
  }
   else if (gasSensor > gasSensorThres) //Gas Detected
  {
    Serial.println("Gas Detected");
    lcd.setCursor(2, 0);
 lcd.print("Gas Detected");
  lcd.setCursor(2, 1);
   delay(500);
 lcd.print("Take Action!");         
  delay(1000);
  lcd.clear();       
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(BUZZER_PIN,HIGH);
  }
 
    
  
  else     // No Gas and Fire Detected
  {
    Serial.println("No Gas and Fire Detected");
      lcd.setCursor(0, 0);
     lcd.print("No Gas  Detected");
     delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("No Fire Detected");
    delay(3000);
    lcd.clear();
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);                          
    digitalWrite(LED3, LOW);  
    digitalWrite(BUZZER_PIN,LOW);  
  }
   
 }
  if(state == HIGH){        // Evening
    Serial.println("The switch: OFF");
    int gasSensor = analogRead(gasPin);
  int flameSensor = digitalRead(flamePin);
    if  (flameSensor==LOW){ // HIGH MEANS NO FLAME
    Serial.println("No Gas and Fire Detected");
      lcd.setCursor(0, 0);
     lcd.print("No Gas  Detected");
     delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("No Fire Detected");
    delay(3000);
    lcd.clear();
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);                          
    digitalWrite(LED3, LOW);  
    digitalWrite(BUZZER_PIN,LOW);  
   
  }
   else if (gasSensor > gasSensorThres) //Gas Detected
  {
    Serial.println("Gas Detected");
    lcd.setCursor(2, 0);
 lcd.print("Gas Detected");
  lcd.setCursor(2, 1);
   delay(500);
 lcd.print("Take Action!");         
  delay(1000);
  lcd.clear();       
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(BUZZER_PIN,HIGH);
  }
 
    
  
  else     // No Gas and Fire Detected
  {
    Serial.println("No Gas and Fire Detected");
      lcd.setCursor(0, 0);
     lcd.print("No Gas  Detected");
     delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("No Fire Detected");
    delay(3000);
    lcd.clear();
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);                          
    digitalWrite(LED3, LOW);  
    digitalWrite(BUZZER_PIN,LOW);  
  }
   
}
}
