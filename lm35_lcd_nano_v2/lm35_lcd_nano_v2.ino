#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

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
float suhuF = 0;

void setup() {
  // Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(1, derajat);

  lcd.setCursor(0, 0);
  lcd.print("    Digital    ");
  lcd.setCursor(0, 1);
  lcd.print("  Thermometer   ");
  delay(1000);
  lcd.clear();
  lcd.print(" ____Sumar OSC___  ");
  delay(1000);
  lcd.clear();
}

void loop() {
  bacapinLM35 = analogRead(pinLM35);
  suhuC = (bacapinLM35 * 0.0049);
  suhuC = suhuC * 100;
  suhuF = (suhuC * 1.8) + 32;

  lcd.clear();


  lcd.setCursor(0, 0);
  lcd.print(suhuC);
  lcd.write(1);
  lcd.setCursor(6, 0);
  lcd.print("C |DataLog");

  // Serial.print("suhuC: ");
  // Serial.print(suhuC);
  //Serial.print("*C ");

  lcd.setCursor(0, 1);
  lcd.print(suhuF);
  lcd.write(1);
  lcd.setCursor(6, 1);
  lcd.print("F |suhu");
  lcd.cursor();
  lcd.blink();

  // Serial.print(suhuF);
  //Serial.println("*F");
  delay(1000);
}

