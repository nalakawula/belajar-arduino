int led = 13;
int button = 12;
int buttonState = 0;
int brightness = 0;
int brightup = 2;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}
void loop() {
  analogWrite(led, brightness);
  buttonState = digitalRead(button);
  if ( buttonState == HIGH ) {
    brightness = brightness + brightup;
  }
  if ( brightness == 255 ) {
    brightness = 0;
  }
  delay(30);
}
