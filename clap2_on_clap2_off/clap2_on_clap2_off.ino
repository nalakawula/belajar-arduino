// Arduino Clapper - by WilliamK @ Wusik.com & Beat707.com - November 06 2011 - V 1.4.0 //
// On V1.4.0, a volume checker is placed which checks for background noise x sound "pops".

#define inPin A1               // Pin input for the audio sensor
#define outPin 0               // Output pin to active external device (use relay for 110/220V)
#define touchPin PINB4         // Must be in PINB# format (digital pin 8 ~ 13 = PINB0 ~ PINB5)

// ------------------------------------------------------------------------------------------------------------------------ //
uint8_t isOn = false;
uint8_t prevIsOn = false;
uint8_t prevButton = 0;
uint8_t curButton = 0;
uint8_t wasButtonLow = 1;

unsigned long sensorValue = 0;
unsigned char counter = 0;
unsigned long backgroundNoise = 0;
unsigned char claps = 0;
unsigned long milliS = millis();

// ------------------------------------------------------------------------------------------------------------------------ //
void setup() 
{
  pinMode(outPin, OUTPUT);
  pinMode(inPin, INPUT);
 
  prevButton = getcap(1<<PINB0);
}

// ------------------------------------------------------------------------------------------------------------------------ //
void loop() 
{ 
  if (isOn)
  {
    sensorValue += analogRead(inPin);
    counter++;
    if (counter > 125)
    {
      if (backgroundNoise > 0 && sensorValue > (backgroundNoise+1400))
      {
        claps++;
        if (claps == 2) milliS = millis() + 1000; else milliS = millis() + 4000;
      }
      if (sensorValue > backgroundNoise) backgroundNoise = sensorValue;
        else if (backgroundNoise > sensorValue && backgroundNoise >= 400) backgroundNoise -= 400;
      counter = 0;
      sensorValue = 0;
    }
    delayMicroseconds(250);
 
    if (milliS > 0 && millis() > milliS)
    {
      if (claps == 2)
      {
        isOn = !isOn;
        checkNewOn();
      }
     
      claps = milliS = 0;
    }
  }
 
  checkButton();
}

// ------------------------------------------------------------------------------------------------------------------------ //
void checkNewOn()
{
  if (isOn != prevIsOn)
  {
    digitalWrite(outPin, isOn);
    prevIsOn = isOn;
    sensorValue = backgroundNoise = claps = counter = milliS = 0;
    delay(2000);
  }
}

// ------------------------------------------------------------------------------------------------------------------------ //
void checkButton()
{
  curButton = getcap(1<<touchPin);
 
  if (curButton != prevButton)
  {
    prevButton = curButton;
    if (wasButtonLow == 1 && curButton > 1)
    {
      isOn = !isOn;
      wasButtonLow = 0;
      checkNewOn();
      delay(500);
    }
    if (curButton <= 1) wasButtonLow = 1;
  }
 
  checkNewOn();
}

// ------------------------------------------------------------------------------------------------------------------------ //
char getcap(char pin)
{
  char i = 0;
  DDRB &= ~pin;          // input
  PORTB |= pin;          // pullup on
  for(i = 0; i < 2; i++)
  {
    if( (PINB & pin) ) break;
  }
  PORTB &= ~pin;         // low level
  DDRB |= pin;           // discharge
  return i;
}