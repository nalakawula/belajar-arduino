/*
 Led berkedip.
 sumar, Wednesday, December 17, 2014 01:49:53 PM
 */
 

int led1 = 13; //set output untuk led di pin 13
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;

void setup() {                
  pinMode(led1, OUTPUT);    //set pin 13 sbg output  
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  delay(200);
  
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led2, LOW);
  delay(200);
  
  digitalWrite(led3, HIGH);
  delay(200);
  digitalWrite(led3, LOW);
  delay(200);
  
  digitalWrite(led4, HIGH);
  delay(200);
  digitalWrite(led4, LOW);
  delay(200);
  
  digitalWrite(led5, HIGH);
  delay(200);
  digitalWrite(led5, LOW);
  delay(200);
  
}
