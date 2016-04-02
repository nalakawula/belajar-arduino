/*
  void setup() {
  pinMode (13, OUTPUT);
  pinMode (7, INPUT);


  }

  void loop() {
  digitalWrite(13, digitalRead(2));
  delay(50);

  }
*/

#define pir A0
#define led 13
#define relay1 6
#define relay2 7


void setup() {
  pinMode(pir, INPUT)  ;
  pinMode(led, OUTPUT)  ;
  pinMode(relay1, OUTPUT)  ;
  pinMode(relay2, OUTPUT)  ;
  Serial.begin(9600);
  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);


}

void loop() {
  int i = analogRead(pir);
  int L = map(i, 0, 1023, 0, 255);

  //Serial.print(i);
  //Serial.print("/");
  //Serial.println(L);
  if (L > 170) {
    digitalWrite(led, HIGH);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    delay(100);
  }
  
  else {
    digitalWrite(led, LOW);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    delay(100);
    }
  
}

