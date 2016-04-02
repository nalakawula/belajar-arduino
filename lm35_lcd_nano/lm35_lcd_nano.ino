/*****************************************************************************
  /*****************************************************************************/
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

unsigned char i;
int pinlm35 = 0;
int tempc = 0, tempf = 0;
int sample[8];
int maxi = -100, mini = 100;
int j;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  for (j = 0; j <= 7; j++) {
    sample[j] = (5.0 * analogRead(pinlm35) * 100.0) / 1024.0;
    tempc = tempc + sample[i];
    delay(1000);
  }

  tempc = tempc / 8.0;
  tempf = (tempc * 9) / 5 + 32;

  if (tempc > maxi) {
    maxi = tempc;
  }
  if (tempc < mini) {
    mini = tempc;
  }

  Serial.print(tempc, DEC);
  Serial.print(" Celcius, ");

  Serial.print(tempf, DEC);
  Serial.print(" Fahrenheit -> ");

  Serial.print(maxi, DEC);
  Serial.print(" maxi, ");

  Serial.print(mini, DEC);
  Serial.print(" mini ");

  tempc = 0;

  delay(100);



  for (i = 0 ; i <= 15 ; i++)
  {
    lcd.setCursor(i, 0);
    lcd.print("->sumar");
    delay(100);
    lcd.clear();
  }

  for (i = 0 ; i <= 15 ; i++)
  {
    lcd.setCursor(i, 1);
    lcd.print("__osc__");
    delay(100);
    lcd.clear();
  }
}
