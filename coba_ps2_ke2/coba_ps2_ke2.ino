/*
Kendali arduino pake dualshock 2,
 Sumarsono, ditulis pada Thursday 05 March 2015 19:22:10 .
 Terakhir diedit pada: Friday 06 March 2015 08:58:19
 */


#include <PS2X_lib.h>

PS2X ps2x;

int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup() {
  //Serial.begin(57600);
  Serial.begin(9600);

  //error = ps2x.config_gamepad(13,11,10,12, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  error = ps2x.config_gamepad(11,9,8,10, true, false); //clock, command, attention, data, Pressures?, Rumble?

  if(error == 0){
    Serial.println("Gamepad terhubung mblo");   
  }

  else if(error == 1)
    Serial.println("Cek pengkabelannya mblo, error.");

  else if(error == 2)
    Serial.println("Coba enable debug mblo, gk mau nerima command");

  else if(error == 3)
    Serial.println("-_- kaga support. error");

  type = ps2x.readType();


}

void loop() {
  if(error == 1){
    return;
  }

  if(type == 1) {
    ps2x.read_gamepad();
    if(ps2x.Button(PSB_PAD_UP)) {
      Serial.print("ATAS: ");
      Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
      digitalWrite(2, 1);
    }
    else if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.print("KANAN: ");
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
      digitalWrite(2, 1);
    }
    else if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.print("KIRI: ");
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
      digitalWrite(2, 1);
    }
    else if(ps2x.Button(PSB_PAD_DOWN)){
      Serial.print("BAWAH: ");
      Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
      digitalWrite(2, 1);
    }   

    else if(ps2x.Button(PSB_GREEN)){
      Serial.println("SEGITIGA");
      digitalWrite(2, 1);
    }

    else if(ps2x.Button(PSB_RED)){
      Serial.println("BUNDER");
      digitalWrite(2, 1);
    }

    else if(ps2x.Button(PSB_PINK)) {
      Serial.println("KOTAK");
      digitalWrite(2, 1);   
    }  

    else if(ps2x.Button(PSB_BLUE))  {
      Serial.println("X");  
      digitalWrite(2, 1);
    }

    else
      digitalWrite(2, 0);

  }



}




