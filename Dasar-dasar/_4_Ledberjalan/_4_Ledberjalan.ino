/*
  Led berjalan menggunakan kondisi for loop
 
 Sumar, Wednesday, December 17, 2014 02:06:57 PM
 */

int timer = 100;

void setup() {
  
  for (int ledPin = 2; ledPin < 8; ledPin++)  {
    pinMode(ledPin, OUTPUT);      
  }

}


void loop() {
  
  for (int ledPin = 2; ledPin <= 6; ledPin++) { 
    //on:
    digitalWrite(ledPin, HIGH);   
    delay(timer);                  
    //off:
    digitalWrite(ledPin, LOW);    
  }

   for (int ledPin = 6; ledPin >= 2; ledPin--) { 
    //on:
    digitalWrite(ledPin, HIGH);
    delay(timer);
    //off:
    digitalWrite(ledPin, LOW);
  }
}
