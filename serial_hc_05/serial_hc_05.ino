//#include <SoftwareSerial.h>

#define infra 52
#define suttle 27
#define serve 29

int led = 13;
//SoftwareSerial KRAI(10, 11); 
char sendBT;

void setup() {  
  Serial.begin(9600);  
  Serial.println("KRAI UNNES 2015 : Bledheg ijo");
  pinMode(infra,INPUT_PULLUP);
  pinMode(suttle,OUTPUT);
  pinMode(serve,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
 if (Serial.available()){ 
 sendBT=Serial.read(); 
 if(sendBT =='w'){
   Serial.println("B send : w");
   digitalWrite(suttle,HIGH);
   
  if(digitalRead(infra)==LOW){
  Serial.println("servis");
  digitalWrite(led,HIGH);
  digitalWrite(serve,HIGH);
  }
}
if(sendBT== 'x'){
     Serial.println("B send : x");
   digitalWrite(led,HIGH);
   digitalWrite(suttle,HIGH);
   delay(430);
   digitalWrite(serve,HIGH);
  }

 if(sendBT =='s'){
      Serial.println("B send : stop");
   digitalWrite(led,LOW);
   digitalWrite(suttle,LOW);
   digitalWrite(serve,LOW);
 }

  } 
if(digitalRead(infra)==LOW){
  Serial.println("servis");
  digitalWrite(led,HIGH);
  digitalWrite(serve,HIGH);
  }
}

