//http://forum.arduino.cc/index.php?topic=262177.0

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
int ledPin = 5;
int state = 0;


void setup() {
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
mySerial.begin(9600);
Serial.begin(9600);
}

void loop() {
 
if(mySerial.available() > 0){
state = mySerial.read();

}

if (state == '2') {
digitalWrite(ledPin, LOW);
Serial.println("LED: off");

}


if (state == '1') {
digitalWrite(ledPin, HIGH);
Serial.println("LED: on");
}
}
