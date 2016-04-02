const int servoPin = 7;    // the pin number (no PWM) of the servo.	
const long delayTime = 10; // servo movement delay time in millis.

int myAngle = 0;    // angle of the servo (roughly in degrees) 0-180.
int pulseWidth = 0; // angle to microseconds.
int tombol = 4;
int tombol1 = 8;
int pneu = 2;     //pneumatic

// startup point entry (runs once).
void setup() {
  // set servo pin as output.
  pinMode(servoPin, OUTPUT);
  pinMode(tombol, INPUT_PULLUP);
  pinMode(tombol1, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  pinMode(pneu, OUTPUT);  
}
// loop the main sketch.

void loop(){	
  if (digitalRead(tombol)== LOW)
  { 
     digitalWrite(13,HIGH);ser_1(); delay(500); 
  digitalWrite(pneu,HIGH);
ser_2();
  }
  if (digitalRead(tombol1)== LOW){
    digitalWrite(13,HIGH);
  digitalWrite(pneu,HIGH);
  }
else {digitalWrite(13,LOW);
    digitalWrite(pneu,LOW);}
}// move the servo.

void ser_1(){
    for (myAngle = 0; myAngle <= 180; myAngle++) {  
    servoPulse(7, 90);
  }  
}
void ser_2(){
  for (myAngle = 180; myAngle >= 0; myAngle--) {  
    servoPulse(7, 0);
}
}

void servoPulse(int servoPin, int myAngle) {
  pulseWidth = (myAngle * 11) + 1000; // converts angle to microseconds.
  digitalWrite(servoPin, HIGH);      // set servo high.
  delayMicroseconds(pulseWidth);     // wait a very small amount.
  digitalWrite(servoPin, LOW);       // set servo low.
  delay(delayTime);                  // refresh cycle of typical servos.
}


