/*
 Led berkedip.
 sumar, Wednesday, December 17, 2014 01:49:53 PM
 */
 

int lampu1 = 2; //set output untuk led di pin 13
int lampu2 = 3;
int lampu3 = 4;
int lampu4 = 5;
int lampu5 = 6;

void setup() {                
  pinMode(lampu1, OUTPUT);    //set pin 13 sbg output  
  pinMode(lampu2, OUTPUT);
  pinMode(lampu3, OUTPUT);
  pinMode(lampu4, OUTPUT);
  pinMode(lampu5, OUTPUT);
     
}

void loop() {
  digitalWrite(lampu1, HIGH);
  digitalWrite(lampu2, HIGH);
  digitalWrite(lampu3, HIGH);
  digitalWrite(lampu4, HIGH);
  digitalWrite(lampu5, HIGH);
  delay(500);
  digitalWrite(lampu1, LOW);
  digitalWrite(lampu2, LOW);
  digitalWrite(lampu3, LOW);
  digitalWrite(lampu4, LOW);
  digitalWrite(lampu5, LOW);
  delay(500);
  
  
}
