#include <SoftwareSerial.h>


SoftwareSerial BT(10, 11); //tx, rx
char btdata;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 7;



void setup()
{
 
  BT.begin(9600);
  Serial.begin(9600);
  BT.println("BT OK, tekan 1 atau 0 utk blink");
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  if(BT.available())
  {
    btdata = BT.read();

    if(btdata == 'i')
    {
      Serial.write(btdata);
      digitalWrite(led3,1);

    }
  }

  if(BT.available())
  {
    btdata = BT.read();

    if(btdata == 'j')
    {
      Serial.write(btdata);
      digitalWrite(led4,1);

    }
  }

  if(BT.available())
  {
    btdata = BT.read();

    if(btdata == 'k')
    {
      Serial.write(btdata);
      digitalWrite(led5,1);

    }
  }

  if(BT.available())
  {
    btdata = BT.read();

    if(btdata == 'l')
    {
      Serial.write(btdata);
      digitalWrite(led6,1);

    }
  }
  
  if(BT.available())
  {
    btdata = BT.read();

    if(btdata == 'C')
    {
      Serial.write(btdata);
      digitalWrite(led3,0);
      digitalWrite(led4,0);
      digitalWrite(led5,0);
      digitalWrite(led6,0);
      digitalWrite(led7,0);


    }
  }
  
    

}



