//RT_LCD_NANO_SUMARSONO

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#include <Wire.h>
#include "RTClib.h"

byte derajat[8] =
{
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
int pinLM35 = 0;
int bacapinLM35 = 0;
float suhuC = 0;

RTC_DS1307 RTC;
//int relay = 8;

void setup () {
  //Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(1, derajat);
  Wire.begin();
  RTC.begin();
  //pinMode(relay, OUTPUT);
  //digitalWrite(relay, HIGH);
  //IF YOU USE RTC FOR THE FIRST TIME: If we remove the comment from  the following line, we will set up the module time and date with the computer one
  //RTC.adjust(DateTime(__DATE__, __TIME__));

  lcd.setCursor(0, 0);
  lcd.print("=====_JAM_======");
  lcd.setCursor(0, 1);
  lcd.print("===_DIGITAL_====");
  delay(3000);
  lcd.clear();
}

void loop () {
  bacapinLM35 = analogRead(pinLM35);
  suhuC = (bacapinLM35 * 0.0049);
  suhuC = suhuC * 100;

  DateTime now = RTC.now();
  lcd.clear();
  lcd.setCursor(0, 0);

 lcd.print("===_");
  
  lcd.print(now.day(), DEC);
  lcd.print("-");
  lcd.print(now.month(), DEC);
  lcd.print("-");
  lcd.print(now.year(), DEC);
  lcd.print("_===");
  lcd.setCursor(0, 1);
  //lcd.print("Jam    :");
  lcd.print(now.hour(), DEC);
  lcd.print(".");
  lcd.print(now.minute(), DEC);
  lcd.print(".");
  lcd.print(now.second(), DEC);
  lcd.print("-");
  lcd.print(suhuC);
  lcd.write(1);
  lcd.print("C");

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
  //if (now.dayOfYear() % 2 == 0) {
   // if (now.hour() == 20) {
   //   if (now.minute() == 54) {
   //     digitalWrite(relay, LOW);
    //  }
    //  else {
     //   digitalWrite(relay, HIGH);
     // }
    //}
  //}

  ////Serial.println(digitalRead(relay));
  ////Serial.println();
  //delay(3000);
}
