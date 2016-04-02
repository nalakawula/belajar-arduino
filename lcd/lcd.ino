#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); //(rs, enable, d4, d5, d6, d7) 
void setup() { 
  lcd.begin(16,2); //width and height) of the display
}
void loop() { 
  lcd.print("Arduino"); // Prints "Arduino" on the LCD 
  delay(3000);
  lcd.setCursor(2,1); 
  lcd.print("LCD Tutorial"); 
  delay(3000); 
  lcd.clear();
  lcd.blink();// Displays the blinking LCD cursor 
  delay(4000); 
  lcd.setCursor(7,1); 
  delay(3000); 
  lcd.noBlink(); // Turns off the blinking LCD cursor 
  lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
  delay(4000); 
  lcd.noCursor(); // Hides the LCD cursor 
  lcd.clear(); // Clears the LCD screen 
}
