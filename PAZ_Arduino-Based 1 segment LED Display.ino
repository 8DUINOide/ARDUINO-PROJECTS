
//======================================================================================
//Filename : PAZ_Arduino-Based 1 segment LED Display.ino
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number:9
//Description : This project is a 1 segment LED Display, that outputs the numbers from 1 to 9
//Last modified: March 17, 2023
//======================================================================================

byte pin[] = {2, 3, 4, 5, 6, 7, 8, 9};//arduino pin array
 
int number[9][8] = {//number array

  {0, 0, 1, 1, 1, 0, 0, 0},//1
  {1, 1, 0, 1, 1, 1, 0, 1},//2
  {0, 1, 1, 1, 1, 1, 0, 1},//3
  {0, 0, 1, 1, 1, 0, 1, 1},//4
  {0, 1, 1, 1, 0, 1, 1, 1},//5
  {1, 1, 1, 1, 0, 1, 1, 1},//6
  {0, 0, 1, 1, 1, 1, 1, 0},//7
  {1, 1, 1, 1, 1, 1, 1, 1},//8
  {0, 0, 1, 1, 1, 1, 1, 1},//9

  
};
 
void setup() {
  for (byte a = 0; a < 8; a++) {
    pinMode(pin[a], OUTPUT);//define output pins
  }
}
 
void loop() {
  for (int a = 0; a < 9; a++) {
    for (int b = 0; b < 8; b++) {
      digitalWrite(pin[b], number[a][b]);//display numbers
    }
    delay(500);//delay
  }
}
