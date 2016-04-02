// arduino>>bluetooth
// D11   >>>  Rx
// D10   >>>  Tx
//Written By M. Ishaq
//BLEDHEG IJO KRN NASIONAL JUARA 1 REGIONAL 3 JATENG-DIY
//BISMILLAH COBA JALAN LURUS 
#include <SoftwareSerial.h>// import the serial library
SoftwareSerial KRAI(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
char BluetoothData; // the data given from Computer
int pukul = 2;
//////////define for motor//////////////////////////
#define inka_1  A0
#define inki_1  A1
#define en_1  3
////////////////
#define inka_2  A2
#define inki_2  A3

void setup() {
  KRAI.begin(9600);  
  KRAI.println("\t Bismillah \n KRAI UNNES : Bledheg ijo");
  pinMode(ledpin,OUTPUT);
  ///////motor////////
  pinMode(inka_1, OUTPUT);
  pinMode(inki_1, OUTPUT);  
  pinMode(inka_2, OUTPUT);
  pinMode(inki_2, OUTPUT);
  pinMode(pukul, INPUT);
  
    pinMode(en_1, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BluetoothData =='w'){ 
  digitalWrite(ledpin,1);
     KRAI.println(" MAJU >>> PWM 70 ");
  analogWrite(en_1, 80);
   digitalWrite(inka_1, HIGH);   
   digitalWrite(inki_1, LOW);              
   digitalWrite(inka_2, HIGH);   
   digitalWrite(inki_2, LOW);                 
  }        
if (BluetoothData=='x'){ 
   digitalWrite(ledpin,1);
   KRAI.println(" <<< MUNDUR PWM 70");
 analogWrite(en_1, 80);
     digitalWrite(inka_1, LOW);   
     digitalWrite(inki_1, HIGH);
      digitalWrite(inka_2, LOW);   
      digitalWrite(inki_2, HIGH);
   } 
if (BluetoothData=='a'){ 
   digitalWrite(ledpin,1);
   KRAI.println(" <<< kiri PWM 70");
 analogWrite(en_1, 70);
     digitalWrite(inka_1, HIGH);   
     digitalWrite(inki_1, LOW);
       digitalWrite(inka_2, LOW);   
       digitalWrite(inki_2, LOW);
    } 
if (BluetoothData=='d'){ // if d pressed ....
   digitalWrite(ledpin,1);
   KRAI.println(" >>> kanan PWM 70");
 analogWrite(en_1, 70);
     digitalWrite(inka_1, LOW);   
     digitalWrite(inki_1, LOW);
       digitalWrite(inka_2, HIGH);   
       digitalWrite(inki_2, LOW);
    } 
    if (BluetoothData=='p'){ 
   digitalWrite(ledpin,1);
   KRAI.println(" >>> hajarrrr");
     digitalWrite(pukul, HIGH);   
    }
    if (BluetoothData=='s'){   
  KRAI.println(" STOPPPP ");
      digitalWrite(ledpin,LOW);
    digitalWrite(inka_1, LOW);   
    digitalWrite(inki_1, LOW);
    digitalWrite(inka_2, LOW);
    digitalWrite(inki_2, LOW);
    analogWrite(en_1, 0);
    digitalWrite(pukul, LOW);
    
  }
}
