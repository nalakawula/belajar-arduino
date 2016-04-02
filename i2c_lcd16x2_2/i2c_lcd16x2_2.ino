/* YourDuino.com Example Software Sketch
  16 character 2 line I2C Display
  Backpack Interface labelled "A0 A1 A2" at lower right.
  ..and
  Backpack Interface labelled "YwRobot Arduino LCM1602 IIC V1"
  MOST use address 0x27, a FEW use 0x3F
  terry@yourduino.com */
// Get the LCD I2C Library here:
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.


#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>


// set the LCD address to 0x27 for a 16 chars 2 line display
// A FEW use address 0x3F
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);

  //kedip 3x
  for (int i = 0; i < 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }

  //backlight on
  lcd.backlight();


  lcd.setCursor(0, 0);
  lcd.print("LINK START");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("WELCOME.........");
  delay(8000);


  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Buka Ser.Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Ketik apa saja");


}


void loop()
{
  {
    if (Serial.available())
    {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0)
      {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }
  }

}
