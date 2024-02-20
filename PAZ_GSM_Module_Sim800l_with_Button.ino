//======================================================================================
//Filename : PAZ_GSM Module Sim800l with Button.ino
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Description :This project will work by pressing the yellow button calls a pre-set SIM number, while the blue button shares the exact location via a Google Maps link. 
//Last modified: February 20, 2024
//======================================================================================

#include <SoftwareSerial.h>

int callButton = 6;
int messageButton = 7;
int callState = 0;
int messageState = 0;

// Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); // SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup() {
  pinMode(callButton, INPUT);
  pinMode(messageButton, INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Press the (Yellow Button) to send a Call");
  Serial.println("Press the (Blue Button) to send a Message");
}

void loop() {
  callState = digitalRead(callButton);
  messageState = digitalRead(messageButton);

  if (callState == HIGH) {
    Serial.println("Sending a Call");
    sendCall();
  } 
  if (messageState == HIGH) {
    Serial.println("Sending a Message");
    sendSMS();
  } 

  delay(100);
}

void sendCall() {
  Serial.println("Initializing Call...");
  mySerial.println("AT");
  updateSerial();

  mySerial.println("ATD+63xxxxxxxxxx;"); // Change ZZ with country code and xxxxxxxxxxx with phone number to dial
  updateSerial();

  delay(20000); // Wait for 20 seconds...
  mySerial.println("ATH"); // Hang up
  updateSerial();
}

void sendSMS() { 
  Serial.println("Initializing SMS...");
  mySerial.println("AT");
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode 
  updateSerial();
  mySerial.println("AT+CMGS=\"63xxxxxxxxxx\""); // Change ZZ with country code and xxxxxxxxxxx with phone number to SMS
  updateSerial();
  mySerial.print("GPS Tracking System"); // Text content
  updateSerial();
  mySerial.write(26);
}

void updateSerial() {
  delay(500);
  while (Serial.available()) {
    mySerial.write(Serial.read()); // Forward what Serial received to Software Serial Port
  }
  while (mySerial.available()) {
    Serial.write(mySerial.read()); // Forward what Software Serial received to Serial Port
  }
}
