const int sensor = A4;
const int led1 = 2;
const int led2 = 4;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensor);
  
  if (sensorValue > 850) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if (sensorValue < 950) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  

  Serial.println(sensorValue);
  Serial.println();
  delay(300);

}
