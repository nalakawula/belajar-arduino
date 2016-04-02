/*
  Tombol.
 sumar, Wednesday, December 17, 2014 02:06:57 PM
 skema:
 * LED --> pin 9 --> ground
 * PB --> pin2 --> ground
 * ground --> R 10k --> pin2
 
 */

//variabel
const int tombolPin = 2;     
const int ledPin =  13;      
int tombolState = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);      //ledPin sbg output
  pinMode(tombolPin, INPUT);     //tombolPin sbg input
}

void loop(){
  tombolState = digitalRead(tombolPin);

  if (tombolState == HIGH) {     
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
}
