#include <LiquidCrystal.h> //Librari LCD

LiquidCrystal lcd(2,3,4,5,6,7); //Konfigurasi pin arduino ke LCD
int adc0, temp; //adc0 adalah pin analog0
int ledPin1 = 9; //BUZZER
int ledPin2 = 10; //BIRU
int ledPin3 = 11; //HIJAU


void setup(){
  lcd.begin(16,2); //Inisialisasi ukuran LCD yang diguanakan adalah type 16x2
  lcd.print("Suhu Ruangan");
  lcd.setCursor(0,1); //Mengatur kolom 1 baris 2
  lcd.print("Temp:"); //Menampilkan nilai dari temperatur
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}
void loop (){
  adc0 = analogRead(0);
  temp = (adc0*5)/10; //Di konversi ke celcius
  if (temp < 35) {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  }
  else if (temp < 40) {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  }
  else if (temp > 40 ) {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  }
  
  lcd.setCursor(5, 1);
  lcd.print(temp);
  lcd.print(" Celcius");
  delay(500); //Merefresh pembacaan dari sensor
    
}




