//======================================================================================
//Filename : PAZ_Arduino Based Joystick Controlled 2WD DC Motor.ino
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number:1
//Description :An arduino code that can be used to controlled the 2WD DC Motor with the Joystick
//Last modified: March 16, 2023
//======================================================================================


int joystrick1 = A1;
int joystrick2 = A2;
int val1;
int val2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val1 = analogRead(joystrick1);
int val2 = analogRead(joystrick2);

if(val1 > 1 && val1 < 490){
val1 = map(val1, 1, 490, 255, 0);

analogWrite(6,val1);
analogWrite(5,0);
}

if(val1 > 530 && val1 < 1023){
val1 = map(val1, 530, 1023, 0, 255);

analogWrite(5,val1);
analogWrite(6,0);
}

if(val1 > 491 && val1 < 529){
val1 = map(val1, 491, 529, 0, 0);

analogWrite(5,val1);
analogWrite(6,val1);
}

if(val2 > 1 && val2 < 490){
val2 = map(val2, 1, 490, 255, 0);

analogWrite(10,val2);
analogWrite(9,0);
}

if(val2 > 530 && val2 < 1023){
val2 = map(val2, 530, 1023, 0, 255);

analogWrite(9,val2);
analogWrite(10,0);
}

if(val2 > 491 && val2 < 529){
val2 = map(val2, 491, 529, 0, 0);

analogWrite(9,val2);
analogWrite(10,val2);
}
Serial.println(val1);
Serial.println(val2);
}
