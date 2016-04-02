/*
Kontrol led menggunakan dualshock 3.
ds3 (via kabel usb) -> usb host shield -> arduino uno -> led
latihan dalam rangka kontes robot indonesia.
Oleh Sumarsono 
Monday 02 March 2015 16:10:45

catatan: pin 13 tdk bisa digunakan krn digunakan utk komunikasi SPI usb host shield.
cek disini: http://www.circuitsathome.com/usb-host-shield-hardware-manual.
*/

#include <PS3USB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

USB Usb;
PS3USB PS3 (&Usb);

const uint8_t LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  while (!Serial);
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nerror gan"));
    while(1);
  }
  Serial.print(F("\r\nSip, jalan"));
}

void loop() {
  Usb.Task();
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
    digitalWrite(LED, PS3.getButtonPress(TRIANGLE));
    digitalWrite(LED, PS3.getButtonPress(CIRCLE));
    digitalWrite(LED, PS3.getButtonPress(CROSS));
    digitalWrite(LED, PS3.getButtonPress(SQUARE));
    
    //digitalWrite(LED, PS3.getButtonClick(UP));
    digitalWrite(LED, PS3.getButtonPress(LEFT));
    
    digitalWrite(LED, PS3.getButtonPress(DOWN));
    digitalWrite(LED, PS3.getButtonPress(UP));
    digitalWrite(LED, PS3.getButtonPress(RIGHT));
    
   // if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117 || PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117 || PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117) {
    //  digitalWrite(LED, HIGH);
    // }
  }
  
  
    
  else
    digitalWrite(LED, LOW);
}
