#include <SoftwareSerial.h>
#include <Servo.h> 

SoftwareSerial BT(10, 11); //tx, rx
int led = 13;
char btdata;
char btdata2;

Servo myservo;

void setup()
{
  myservo.attach(9);
  BT.begin(9600);
  Serial.begin(9600);
  BT.println("BT OK, tekan 1 atau 0 utk blink");
  pinMode(led, OUTPUT);
}

void loop()
{
  if(BT.available())
  {
    btdata = BT.read();
    
    if(btdata == 'i')
    {
      Serial.write(btdata);
      digitalWrite(led,1);
      Serial.println("atas");
      myservo.write(1);
    }
  }
  
  if(BT.available())
  {
    btdata = BT.read();
    
    if(btdata == 'l')
    {
      Serial.write(btdata);
      digitalWrite(led,0);
      Serial.println("kanan");
      myservo.write(-1);
    }
  }
  
  if(BT.available())
  {
    btdata = BT.read();
    
    if(btdata == 's')
    {
      Serial.write(btdata);
      digitalWrite(led,0);
      Serial.println("bawah");
    }
  }
  
  if(BT.available())
  {
    btdata = BT.read();
    
    if(btdata == 'a')
    {
      Serial.write(btdata);
      digitalWrite(led,0);
      Serial.println("kiri");
    }
  }

  if(BT.available())
  {
    btdata = BT.read();
    if(btdata == '0')
    {
      Serial.write(btdata);
      digitalWrite(led,0);
      Serial.println("led 13 mati");
    }
  }

  //delay(100);


}


