/*
Kontrol led menggunakan dualshock 3.
ds3 (via kabel usb) -> bluetooth -> usb host shield -> arduino uno -> led
latihan dalam rangka kontes robot indonesia.
Oleh Sumarsono 
Monday 02 March 2015 16:10:45

catatan: pin 13 tdk bisa digunakan krn digunakan utk komunikasi SPI usb host shield.
cek disini: http://www.circuitsathome.com/usb-host-shield-hardware-manual.
*/

#include <PS3BT.h>

USB Usb;
BTD Btd (&Usb);
PS3BT PS3 (&Btd);

const uint8_t LED = 2;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nerror gan"));
    while(1);
  }
  Serial.print(F("\r\nSip, jalan"));
}

void loop() {
  Usb.Task();
  if (PS3.PS3Connected)
    digitalWrite(LED, PS3.getButtonPress(CROSS));
    
  if (PS3.PS3Connected)
    digitalWrite(LED, PS3.getAnalogHat(LeftHatX));
    
  
  else
    digitalWrite(LED, LOW);
}
