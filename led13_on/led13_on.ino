int led = 13;
int sensor1 = 41;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(led, OUTPUT);
  pinMode(sensor1,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sensor1) == LOW){
  digitalWrite(led, HIGH);
  }

}
