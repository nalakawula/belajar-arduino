#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//RT_LCD_NANO_SUMARSONO

//#include <LiquidCrystal.h>
//LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;
int relay = 8;

void setup () {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.backlight();

  Wire.begin();
  RTC.begin();

  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  //IF YOU USE RTC FOR THE FIRST TIME: If we remove the comment from  the following line, we will set up the module time and date with the computer one
  //RTC.adjust(DateTime(__DATE__, __TIME__));

  lcd.setCursor(0, 0);
  lcd.print("    JAM    ");
  lcd.setCursor(0, 1);
  lcd.print("  DIGITAL   ");
  delay(1000);
  lcd.clear();
}

void loop () {

  DateTime now = RTC.now();
  Serial.println(now.day(), DEC);
  Serial.println(now.month(), DEC);
  Serial.println(now.year(), DEC);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(now.day(), DEC);
  lcd.print("-");
  
  lcd.print(now.month(), DEC);
  lcd.print("-");
  
  lcd.print(now.year(), DEC);
  lcd.setCursor(0, 1);
  
  lcd.print(now.hour(), DEC);
  lcd.print(".");
  lcd.print(now.minute(), DEC);
  lcd.print(".");
  lcd.print(now.second(), DEC);

  delay(1000);

  //We print the day
  ////Serial.print(now.day(), DEC);
  ////Serial.print('/');
  //We print the month
  //Serial.print(now.month(), DEC);
  //Serial.print('/');
  //We print the year
  //Serial.print(now.year(), DEC);
  //Serial.print(' ');
  //We print the hour
  //Serial.print(now.hour(), DEC);
  //Serial.print(':');
  //We print the minutes
  //Serial.print(now.minute(), DEC);
  //Serial.print(':');
  //We print the seconds
  //Serial.print(now.second(), DEC);
  //Serial.println();
  //We check the time and sent through the serial port every 3s
  if (now.dayOfYear() % 2 == 0) {
    if (now.hour() == 20) {
      if (now.minute() == 54) {
        digitalWrite(relay, LOW);
      }
      else {
        digitalWrite(relay, HIGH);
      }
    }
  }

  ////Serial.println(digitalRead(relay));
  ////Serial.println();
  //delay(3000);
}
