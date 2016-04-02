//*******created by: M.ishaq Bledheg-Ijo **********// master
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(10, 11); // RX, TX
//********A**********//
#define L_1         12
#define L_2         11
#define up          8
#define up_right    9
#define up_left     10
#define right       5
#define left        7
#define down        4
#define down_right  3
#define down_left   6
//********B**********//
#define R_1         A0
#define R_2         A1
#define segi3       A2
#define lingkaran   A3
#define silang      A5
#define kotak       A4
//*******End*********//
#define start       2
void setup() {
  //mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(L_1,  INPUT_PULLUP);
  pinMode(L_2,  INPUT_PULLUP);
  pinMode(up,  INPUT_PULLUP);
  pinMode(up_right,  INPUT_PULLUP);
  pinMode(up_left,  INPUT_PULLUP);
  pinMode(right,  INPUT_PULLUP);
  pinMode(left,  INPUT_PULLUP);
  pinMode(down,  INPUT_PULLUP);
  pinMode(down_right,  INPUT_PULLUP);
  pinMode(down_left,  INPUT_PULLUP);
//***********************************//  
  pinMode(R_1,INPUT_PULLUP);
  pinMode(R_2,INPUT_PULLUP);
  pinMode(segi3,INPUT_PULLUP);
  pinMode(lingkaran,INPUT_PULLUP);
  pinMode(silang,INPUT_PULLUP);
  pinMode(kotak,INPUT_PULLUP);
//***********************************//
  pinMode(start,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
//***********A**************//  
  if(digitalRead(segi3)==LOW){
    Serial.print('a');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(lingkaran)==LOW){
    Serial.print('b');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(silang)==LOW){
    Serial.print('c');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(kotak)==LOW){
    Serial.print('d');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(R_2)==LOW){
    Serial.print('e');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(R_1)==LOW){
    Serial.print('f');
    digitalWrite(13,HIGH);
  }
//*************B****************//      
  if(digitalRead(up)==LOW){
    Serial.print('g');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(up_right)==LOW){
    Serial.print('h');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(up_left)==LOW){
    Serial.print('n');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(right)==LOW){
    Serial.print('i');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(left)==LOW){
    Serial.print('m');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(down)==LOW){
    Serial.print('k');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(down_right)==LOW){
    Serial.print('j');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(down_left)==LOW){
    Serial.print('l');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(L_1)==LOW){
    Serial.print('p');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(L_2)==LOW){
    Serial.print('o');
    digitalWrite(13,HIGH);
  }
//********************************//  
  if(digitalRead(start)==LOW){
    Serial.print('q');
    digitalWrite(13,HIGH);
  }
//**************Run*****************//    
  if(digitalRead(up)==LOW && digitalRead(R_1)==LOW){
    Serial.print('r');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(down)==LOW && digitalRead(R_1)==LOW){
    Serial.print('s');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(right)==LOW && digitalRead(R_1)==LOW){
    Serial.print('t');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(left)==LOW && digitalRead(R_1)==LOW){
    Serial.print('u');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(up_right)==LOW && digitalRead(R_1)==LOW){
    Serial.print('v');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(up_left)==LOW && digitalRead(R_1)==LOW){
    Serial.print('w');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(down_right)==LOW && digitalRead(R_1)==LOW){
    Serial.print('x');
    digitalWrite(13,HIGH);
  }
  if(digitalRead(down_left)==LOW && digitalRead(R_1)==LOW){
    Serial.print('y');
    digitalWrite(13,HIGH);
  }
//*********************************************************//  
  else{
    Serial.print('z');
    digitalWrite(13,LOW);
  }
}
