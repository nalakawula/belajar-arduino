/*
Kendali robot 2 menggunakan dualshock 2.
 ditulis oleh: sumarsono, pada: Friday 06 March 2015 09:00:14
 
 Log edit:
 Friday 06 March 2015 09:00:27 --> menambah deskripsi roda dan pin ds2
 Friday 06 March 2015 23:54:27 --> fix motor
 Saturday 07 March 2015 01:00:57 --> konfigurasi ulang motor (mapping) dan perapian program
 Monday 09 March 2015 07:04:32 --> pembuatan kelas gerak
 Monday 30 March 2015 22:34:37 --> menambah fungsi gerak diagonal dan pukul
 
 ==konfigurasi roda:
 
  --------------
 1 0=-        -=0 2
  |            |
  |            |
  |            |
 3 0=-        -=0 4
  --------------
 
 ==konfigurasi pin ds2 :
 clock: 7
 command: 5
 attention: 4
 data: 6   
 Pressures: True 
 Rumble: False
 
 Catatan:
 Belum ditambah program sensor jarak
 
 Ukuran setelah kompile: 7,372 byte
 
 */

#include <PS2X_lib.h>

PS2X ps2x; 

int error = 0; 
byte type = 0;

int LED=13;

#define tamplek 53

//Logic motor 2
#define MOTOR2_MAJU  27
#define MOTOR2_MUNDUR  29
#define en_1  2

//Logic motor 1
#define MOTOR1_MAJU  23
#define MOTOR1_MUNDUR  25

//#define en_2  5

//Logic motor 4
#define MOTOR4_MAJU  35
#define MOTOR4_MUNDUR  37
//#define en_3  6

//Logic motor 3
#define MOTOR3_MAJU  31
#define MOTOR3_MUNDUR  33

//#define en_4  9

void setup() {
 // Serial.begin(9600);

  pinMode(LED,OUTPUT);
  
  pinMode(tamplek, OUTPUT);

  pinMode(MOTOR2_MAJU, OUTPUT);
  pinMode(MOTOR2_MUNDUR, OUTPUT);  
  pinMode(MOTOR1_MUNDUR, OUTPUT);
  pinMode(MOTOR1_MAJU, OUTPUT);
  pinMode(MOTOR4_MAJU, OUTPUT);
  pinMode(MOTOR4_MUNDUR, OUTPUT);
  pinMode(MOTOR3_MUNDUR, OUTPUT);
  pinMode(MOTOR3_MAJU, OUTPUT);

  pinMode(en_1, INPUT);
  /*  pinMode(en_2, INPUT);
   pinMode(en_3, INPUT);
   pinMode(en_4, INPUT);*/

  //error = ps2x.config_gamepad(11,9,8,10, true, false); //clock, command, attention, data, Pressures?, Rumble?
  //error = ps2x.config_gamepad(7,5,4,6, true, false);
  
  error = ps2x.config_gamepad(28,26,24,30, true, false); //MEGA
  
  /*
  if(error == 0){
    Serial.println("Gamepad terhubung mblo");   
  }

  if(error == 1)
    Serial.println("Cek pengkabelannya mblo, error.");

  if(error == 2)
    Serial.println("Coba enable debug mblo, gk mau nerima command");

  if(error == 3)
    Serial.println("-_- kaga support. error");
    */

  type = ps2x.readType(); //baca tipe kontroller apakah dualshock 2, guitar herro, atau unknown

}

void maju() {
  //Serial.print("ATAS: ");
  //Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, HIGH);      
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, HIGH);   
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW); 

  digitalWrite(MOTOR4_MAJU, HIGH);   
  digitalWrite(MOTOR4_MUNDUR, LOW);  
}

void maju_kanan() {
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, HIGH);      
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);   
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW); 

  digitalWrite(MOTOR4_MAJU, HIGH);   
  digitalWrite(MOTOR4_MUNDUR, LOW);

}

void maju_kiri() {
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, LOW);      
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, HIGH);   
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW); 

  digitalWrite(MOTOR4_MAJU, LOW);   
  digitalWrite(MOTOR4_MUNDUR, LOW);

}


void mundur() {
  //Serial.print("BAWAH: ");
  //Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, LOW);      
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, LOW);   
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH); 

  digitalWrite(MOTOR4_MAJU, LOW);   
  digitalWrite(MOTOR4_MUNDUR, HIGH);

}

void mundur_kanan() {
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, LOW);      
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);   
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH); 

  digitalWrite(MOTOR4_MAJU, LOW);   
  digitalWrite(MOTOR4_MUNDUR, LOW);

}

void mundur_kiri() {
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, LOW);      
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, LOW);   
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW); 

  digitalWrite(MOTOR4_MAJU, LOW);   
  digitalWrite(MOTOR4_MUNDUR, HIGH);

}

void kanan() {
  //Serial.print("KANAN: ");
  //Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, HIGH);      
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);   
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH); 

  digitalWrite(MOTOR4_MAJU, HIGH);   
  digitalWrite(MOTOR4_MUNDUR, LOW);

}

void kiri() {
  //Serial.print("KIRI: ");
  //Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, LOW);      
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, HIGH);   
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW); 

  digitalWrite(MOTOR4_MAJU, LOW);   
  digitalWrite(MOTOR4_MUNDUR, HIGH);

}

void putar_kanan() {
  //Serial.println("R1");
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, HIGH);      
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);   
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW); 

  digitalWrite(MOTOR4_MAJU, LOW);   
  digitalWrite(MOTOR4_MUNDUR, HIGH);   

}

void putar_kiri() {
  //Serial.println("L1");
  digitalWrite(LED, 1);
  analogWrite(en_1, 70);

  digitalWrite(MOTOR1_MAJU, LOW);      
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, HIGH);   
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH); 

  digitalWrite(MOTOR4_MAJU, HIGH);   
  digitalWrite(MOTOR4_MUNDUR, LOW);

}

void darurat() {
  digitalWrite(LED, 0);
  // analogWrite(en_1, 0);
  
  digitalWrite(tamplek, LOW);

  digitalWrite(MOTOR1_MUNDUR, LOW);   
  digitalWrite(MOTOR1_MAJU, LOW); 

  digitalWrite(MOTOR2_MAJU, LOW);   
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MUNDUR, LOW);   
  digitalWrite(MOTOR3_MAJU, LOW);                    

  digitalWrite(MOTOR4_MAJU, LOW);   
  digitalWrite(MOTOR4_MUNDUR, LOW);
}

void pukul() {
  digitalWrite(LED, 1);
  digitalWrite(tamplek, HIGH);
}

void loop() { 
  // if(error == 1){
  //  return;
  //}

  //if(type == 1) {
  ps2x.read_gamepad(); //baca konfigurasi kontroller
  
  
  //MAJU
  if(ps2x.Button(PSB_PAD_UP)){  //bernilai True jika ditekan dan ditahan
    maju();
  }

  //MUNDUR
  else if(ps2x.Button(PSB_PAD_DOWN)){
    mundur();
  }

  //KANAN
  else if(ps2x.Button(PSB_PAD_RIGHT)){
    kanan();
  }

  //KIRI
  else if(ps2x.Button(PSB_PAD_LEFT)){
    kiri();
  }
  
  //pukul
  else if (ps2x.Button(PSB_R2)){
    pukul();
  }



  //PUTAR KANAN
  else if(ps2x.Button(PSB_R1)) {
    putar_kanan();
  }

  //PUTAR KIRI
  else if(ps2x.Button(PSB_L1)){ 
    putar_kiri();
  }


  
  else if(ps2x.Button(PSB_GREEN)){ //segitiga
   maju_kanan();
  }
   
  else if(ps2x.Button(PSB_RED)) { //lingkaran
   mundur_kanan();
  }
   
  else if(ps2x.Button(PSB_PINK)) { //kotak
   maju_kiri();   
  }
   
  else if(ps2x.Button(PSB_BLUE)) { //x
   mundur_kiri();
  }
   
   

  else if(ps2x.Button(PSB_L2)){
    darurat();
  }
  
  else {
    digitalWrite(LED, 0);
    // analogWrite(en_1, 0);

    digitalWrite(MOTOR1_MUNDUR, LOW);   
    digitalWrite(MOTOR1_MAJU, LOW);   

    digitalWrite(MOTOR2_MAJU, LOW);   
    digitalWrite(MOTOR2_MUNDUR, LOW); 

    digitalWrite(MOTOR3_MUNDUR, LOW);   
    digitalWrite(MOTOR3_MAJU, LOW);                    

    digitalWrite(MOTOR4_MAJU, LOW);   
    digitalWrite(MOTOR4_MUNDUR, LOW);

  }


}














