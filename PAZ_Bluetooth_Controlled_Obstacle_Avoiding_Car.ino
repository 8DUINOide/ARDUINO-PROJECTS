#include <NewPing.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//======================================================================================
//Filename : PAZ_Bluetooth Controlled Obstacle Avoiding Car.ino
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number:8
//Description : This project is a 4WD Bluetooth Controlled Obstacle Avoiding Car. This project used Ultrasonic Sensor that detects an object and will automatically stop, when the distance from the object is nearer.
//Last modified: October 20, 2023
//======================================================================================
char t;
int frontDistance1 = -1;
int frontDistance2 = -1;
int frontDistance3 = -1;
int backDistance = -1;

#define TRIGGER_PIN_FRONT_1 2  // Arduino pin connected to the first front sensor's trigger pin
#define ECHO_PIN_FRONT_1 3     // Arduino pin connected to the first front sensor's echo pin
#define TRIGGER_PIN_FRONT_2 4  // Arduino pin connected to the second front sensor's trigger pin
#define ECHO_PIN_FRONT_2 5     // Arduino pin connected to the second front sensor's echo pin
#define TRIGGER_PIN_FRONT_3 6  // Arduino pin connected to the third front sensor's trigger pin
#define ECHO_PIN_FRONT_3 7     // Arduino pin connected to the third front sensor's echo pin
#define TRIGGER_PIN_BACK 8     // Arduino pin connected to the back sensor's trigger pin
#define ECHO_PIN_BACK 9        // Arduino pin connected to the back sensor's echo pin
#define MAX_DISTANCE 200        // Maximum distance in centimeters for the sensors to detect

NewPing frontSensor1(TRIGGER_PIN_FRONT_1, ECHO_PIN_FRONT_1, MAX_DISTANCE);
NewPing frontSensor2(TRIGGER_PIN_FRONT_2, ECHO_PIN_FRONT_2, MAX_DISTANCE);
NewPing frontSensor3(TRIGGER_PIN_FRONT_3, ECHO_PIN_FRONT_3, MAX_DISTANCE);
NewPing backSensor(TRIGGER_PIN_BACK, ECHO_PIN_BACK, MAX_DISTANCE);

void setup() {
  pinMode(13, OUTPUT);  // left motors forward
  pinMode(12, OUTPUT);  // left motors reverse
  pinMode(11, OUTPUT);  // right motors forward
  pinMode(10, OUTPUT);  // right motors reverse

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Al Francis Paz");
  lcd.setCursor(4, 1);
  lcd.print("2-BSCpE");
  delay(5000);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  // Check distances with the front and back sensors
  frontDistance1 = frontSensor1.ping_cm();
  frontDistance2 = frontSensor2.ping_cm();
  frontDistance3 = frontSensor3.ping_cm();
  backDistance = backSensor.ping_cm();

  Serial.print("Front Distances: ");
  Serial.print(frontDistance1);
  Serial.print("cm | ");
  Serial.print(frontDistance2);
  Serial.print("cm | ");
  Serial.print(frontDistance3);
  Serial.print("cm | ");
  Serial.print("Back Distance: ");
  Serial.print(backDistance);
  Serial.print("cm | ");

  // If any front sensor detects an obstacle and you're trying to move forward, stop the car
  if ((frontDistance1 > 0 && frontDistance1 < 20 || frontDistance2 > 0 && frontDistance2 < 20 || frontDistance3 > 0 && frontDistance3 < 20) && t == 'F') {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  } else if (backDistance > 0 && backDistance < 20 && t == 'B') {
    // If the back sensor detects an obstacle and you're trying to move backward, stop the car
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  } else {
    if (t == 'F') {  // Move forward (all motors rotate in forward direction)
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW); // Stop the reverse motors
      digitalWrite(10, LOW); // Stop the reverse motors
    } else if (t == 'B') {  // Move backward (all motors rotate in reverse direction)
      digitalWrite(12, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
    } else if (t == 'L') {  // Turn right (left side motors rotate in forward direction, right side motors don't rotate)
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW); // Stop the reverse motors
      digitalWrite(13, LOW); // Stop the forward motors
      digitalWrite(10, LOW); // Stop the reverse motors
    } else if (t == 'R') {  // Turn left (right side motors rotate in forward direction, left side motors don't rotate)
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW); // Stop the reverse motors
      digitalWrite(11, LOW); // Stop the forward motors
      digitalWrite(10, LOW); // Stop the reverse motors
    } else if (t == 'S') {  // STOP (all motors stop)
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
    }
  }
  // Add more control commands as needed here.
  // If the distances allow, you can continue moving in other directions.
}
