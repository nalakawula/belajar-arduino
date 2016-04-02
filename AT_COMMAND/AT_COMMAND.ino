/*
BT        ARDUINO
KEY   : PIN 9    (orange wire)
VCC   : PIN +5v  (red wire)
GND   : PIN GND  (black wire)
TXD   : PIN 10   (green wire)
RXD   : PIN 11   (yellow wire)

*/



#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  pinMode(13, OUTPUT);    // Let's use an onboard LED as communication activity indicator 
  pinMode(9, OUTPUT);     // Pin to activate the configuration mode (KEY pin of the module)
  digitalWrite(9, HIGH);  // Activate configuration mode in order to accept Hayes commands
  Serial.begin(38400);
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
  delay(1000);
  Serial.println("Enter Hayes commands:");
}

void loop()
{

  // Read the output of the HC-05 and send to the serial monitor of the Arduino 
  if (BTSerial.available()){
    digitalWrite(13, HIGH);
    //Serial.println("AT+BAUD4");
    Serial.write(BTSerial.read());
    digitalWrite(13, LOW);
  }

  // Read what was typed on the serial monitor of the Arduino and send to the HC-05
  if (Serial.available()){
    //Serial.println("AT+BAUD4");
    digitalWrite(13, HIGH);
    BTSerial.write(Serial.read());
    digitalWrite(13, LOW);
  }
}


/*
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("AT");
  delay(2000);
  Serial.println("AT+NAMEArty4");
  delay(2000);
  //AT+BAUD6    OK38400    Sets the baud rate to 38400
  //AT+BAUD5    OK19200    Sets the baud rate to 19200
  Serial.println("AT+BAUD4");
  delay(2000);
}

*/
