'''
Program kendali arduino menggunakan dualshock 2 (gamepad ps2).
Oleh Sumarsono
Pada Wednesday 04 March 2015 11:01:45

Bismillah, go nasional
'''

#include <PS2X_lib.h>

PS2X ps2x;


int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {
  Serial.begin(57600);
  
  error = ps2x.config_gamepad(13,11,10,12, true, true); //GamePad(clock, command, attention, data, Pressures?, Rumble?)
  
  if(error == 0) {
    Serial.println("Kontroller terhubung");
    Serial.println("tekan X utk coba getar");
    Serial.println("L1 atau R1 untuk cetak nilai stick");
  }
  
  else if(error == 1) 
    Serial.println("Kontroler tidak terhubung, cek koneksi kabelnya");
  
  
  else if(error == 2) 
    Serial.println("Kontroler terhubung tapi tidak bisa menerima perintah, enable debug nya utk cek");
  
  
  else if(error == 3) 
    Serial.println("kontroller tidak mendukung pressures mode :(");
  
  
    type = ps2x.readType();
      switch(type) {
        case 0:
          Serial.println("Unknown kontroler");
        break;
      
        case 1:
          Serial.println("DS2 found");
        break;
      
        case 2:
          Serial.println("GuitarHero found");
        break;
      }
}

