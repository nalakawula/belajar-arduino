/*
DS3231.ino
Uji coba modul rtc.
*/

#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Inisialisasi pakai interface i2c
DS3231  rtc(SDA, SCL);


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


void setup()
{
  //Serial.begin(115200);
  Serial.begin(9600);
  // Uncomment baris berikut jika pakai Arduino Leonardo
  //while (!Serial) {}
  
  
  rtc.begin();
  
  // set waktu
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.createChar(1, derajat);

  lcd.setCursor(0,0);
  lcd.print("----------------");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("----------------");
  delay(1000);
  lcd.clear();
}

void loop()
{
  /*
  // Hari
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // tanggal
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // jam
  Serial.println(rtc.getTimeStr());
  //Serial.print(" -- ");

  // suhu
  Serial.print("Suhu: ");
  Serial.print(rtc.getTemp());
  Serial.println(" C");
  */
  lcd.setCursor(0,0);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  lcd.print(" ");
  lcd.print(rtc.getDateStr());

  lcd.setCursor(0,1);
  lcd.print(rtc.getTimeStr());
  lcd.print(">");
  
  lcd.print(rtc.getTemp());
  lcd.write(1);
  lcd.print("C");
  
  delay (1000);
  lcd.clear();
}
