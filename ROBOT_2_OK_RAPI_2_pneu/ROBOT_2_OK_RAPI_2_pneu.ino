/*
Program untuk robot 2 bledheg ijo, KRAI Unnes. Bismillah, semoga lolos nasional. aamiin.
Ditulis pada: Saturday 04 April 2015 00:54:55
Oleh: Sumarsono

 ==konfigurasi roda mecanum:

  --------------
 1 0=-        -=0 2
  |            |
  |            |
  |            |
 3 0=-        -=0 4
  --------------
  
  
DATA BT:
MAJU  g
MUNDUR  k
KANAN  i
KIRI  m
KADEP  h
KIDEP  n
KABEL  j
KIBEL  l
ROT_KANAN  1
ROT_KIRI  2
SEGITIGA  a
BUNDER  b
SILANG  c
KOTAK  d
LI
L2  o
R1
R2

Log:
Saturday 04 April 2015 16:48:48 -
Monday 06 April 2015 07:42:52 - Edit putar kanan dan kiri ke mode normal dan slow.
Thursday 09 April 2015 15:56:13 - Penambahan keterangan tata letak roda mecanum.

*/


/*VARIABEL*/

//SPEED
char ayun = 255;
char slowmode = 80;
char normal = 230;
char fastmode = 255;

//PWM
unsigned char pwm = 2;
unsigned char pwm_raket = 11;

//unsigned char pwm1 = 3;
//unsigned char pwm2 = 6;
//unsigned char pwm3 = 5;

//LED INDIKATOR
int led = 13;

//BT
char readBT;



//sensor
//int sensor39 = 39;
//int sensor41 = 41;
//int sensor41 = 10;
//int sensor43 = 43;
//int sensor45 = 45;

//selonoid
#define pukul   51
#define pukul2  47

#define MOTORx_MAJU  6
#define MOTORx_MUNDUR  7

//motor1
#define MOTOR1_MAJU  23
#define MOTOR1_MUNDUR  25

//motor2
#define MOTOR2_MAJU  27
#define MOTOR2_MUNDUR  29

//motor3
#define MOTOR3_MAJU  31
#define MOTOR3_MUNDUR  33

//motor4
#define MOTOR4_MAJU  35
#define MOTOR4_MUNDUR  37

void setup() {
  Serial3.begin(9600);
  /*SENSOR*/
//  pinMode(sensor39, INPUT_PULLUP);
//  pinMode(sensor41, INPUT_PULLUP);
//  pinMode(sensor43, INPUT_PULLUP);
//  pinMode(sensor45, INPUT_PULLUP);

  /*MOTOR*/
  pinMode(pwm, INPUT);
  //pinMode(pwm1, INPUT);
  //pinMode(pwm2, INPUT);
  //pinMode(pwm3, INPUT);
  pinMode(pwm_raket, INPUT);

  pinMode(MOTORx_MAJU, OUTPUT);
  pinMode(MOTORx_MUNDUR, OUTPUT);

  pinMode(MOTOR1_MAJU, OUTPUT);
  pinMode(MOTOR1_MUNDUR, OUTPUT);

  pinMode(MOTOR2_MAJU, OUTPUT);
  pinMode(MOTOR2_MUNDUR, OUTPUT);

  pinMode(MOTOR3_MAJU, OUTPUT);
  pinMode(MOTOR3_MUNDUR, OUTPUT);

  pinMode(MOTOR4_MAJU, OUTPUT);
  pinMode(MOTOR4_MUNDUR, OUTPUT);
  /*AKHIR MOTOR*/

  pinMode(pukul, OUTPUT);
  pinMode(pukul2, OUTPUT);
  digitalWrite(pukul, LOW);
  digitalWrite(pukul2, LOW);

  pinMode(led, OUTPUT);
}


void loop() {

  if (Serial3.available()) {
utama:
    readBT = Serial3.read();
    //sensor_on();

    /*GERAK NORMAL*/
    if (readBT == 'g') {
      start();
maju:
      readBT = Serial3.read();
      maju(normal);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto maju;
    }

    if (readBT == 'k') {
      start();
mundur:
      readBT = Serial3.read();
      mundur(normal);

      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto mundur;
    }



    if (readBT == 'i') {
      start();
kanan:
      readBT = Serial3.read();
      kanan(normal);
      
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto kanan;
    }

    if (readBT == 'm') {
      start();
kiri:
      readBT = Serial3.read();
      kiri(normal);
      
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto kiri;
    }

    if (readBT == 'h') {
      start();
kadep:
      readBT = Serial3.read();
      kadep(normal);
      
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto kadep;
    }

    if (readBT == 'n') {
      start();
kidep:
      readBT = Serial3.read();
      kidep(normal);
      
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto kidep;
    }

    if (readBT == 'j') {
      start();
kabel:
      readBT = Serial3.read();
      kabel(normal);
      
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto kabel;
    }

    if (readBT == 'l') {
      start();
kibel:
      readBT = Serial3.read();
      kibel(normal);
      
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto kibel;
    }


    if (readBT == '2') {
      putar_kiri(normal);
putar_kiri:
      readBT = Serial3.read();
      
      putar_kiri(normal);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto putar_kiri;
    }

    if (readBT == '1') {
      putar_kanan(normal);
putar_kanan:
      readBT = Serial3.read();
      
      putar_kanan(normal);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto putar_kanan;
    }
    /*AKHIR GERAK NORMAL*/


    /*GERAK LAMBAT*/

    /*
      if (readBT == 'r') {
    maju_slow:
        readBT = Serial3.read();
        maju(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto maju_slow;
      }

      if (readBT == 's') {
    mundur_slow:
        readBT = Serial3.read();
        mundur(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto mundur_slow;
      }

      if (readBT == 't') {
    kanan_slow:
        readBT = Serial3.read();
        kanan(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto kanan_slow;
      }

      if (readBT == 'u') {
    kiri_slow:
        readBT = Serial3.read();
        kiri(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto kiri_slow;
      }

      if (readBT == 'v') {
    kadep_slow:
        readBT = Serial3.read();
        kadep(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto kadep_slow;
      }

      if (readBT == 'w') {
    kidep_slow:
        readBT = Serial3.read();
        kidep(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto kidep_slow;
      }

      if (readBT == 'x') {
    kabel_slow:
        readBT = Serial3.read();
        kabel(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto kabel_slow;
      }

      if (readBT == 'y') {
    kibel_slow:
        readBT = Serial3.read();
        kibel(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto kibel_slow;
      }


      if (readBT == '0') {
    putar_kiri_slow:
        readBT = Serial3.read();
        putar_kiri(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto putar_kiri_slow;
      }

      if (readBT == '9') {
    putar_kanan_slow:
        readBT = Serial3.read();
        putar_kanan(slowmode);
        digitalWrite(led, HIGH);
        if (readBT == 'z') {

          goto utama;
        }
        goto putar_kanan_slow;
      }

    /*AKHIR GERAK LAMBAT*/




    /*GERAK CEPAT*/
    /*
      if (readBT == '1') {
    maju_cepat:
        maju(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto maju_cepat;
      }


      if (readBT == '2') {
    mundur_cepat:
        mundur(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto mundur_cepat;
      }

      if (readBT == '3') {
    kanan_cepat:
        kanan(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto kanan_cepat;
      }

      if (readBT == '4') {
    kiri_cepat:
        kiri(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto kiri_cepat;
      }

      if (readBT == '5') {
    kadep_cepat:
        kadep(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto kadep_cepat;
      }

      if (readBT == '6') {
    kidep_cepat:
        kidep(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto kidep_cepat;
      }

      if (readBT == '7') {
    kabel_cepat:
        kabel(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto kabel_cepat;
      }

      if (readBT == '8') {
    kibel_cepat:
        kibel(fastmode);
        digitalWrite(led, HIGH);
        readBT = Serial3.read();
        if (readBT == 'z') {
          pelan();
          goto utama;
        }
        goto kibel_cepat;
      }
    /*AKHIR GERAK CEPAT*/




    /*RAKET*/
    if (readBT == 'a') {
      goto ayun;
ayun:
      readBT = Serial3.read();
      digitalWrite(led, HIGH);
      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);

      motor_pukul(ayun);
      
     

      goto utama;

      if (readBT == 'z') {
        goto utama;
      }

    }

    if (readBT == 'b') {
      goto tarik;
tarik:
      readBT = Serial3.read();
      digitalWrite(led, HIGH);
      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);
      motor_tarik(ayun);
      
      


      goto utama;

      if (readBT == 'z') {
        goto utama;
      }
    }


    if (readBT == 'c') {
pukulx:

      readBT = Serial3.read();

      digitalWrite(led, HIGH);

      digitalWrite(pukul, HIGH);
      digitalWrite(pukul2, HIGH);

      digitalWrite(MOTORx_MUNDUR, LOW);
      digitalWrite(MOTORx_MAJU, LOW);

      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);

      if (readBT == 'o') {

        goto utama;
      }
      goto pukulx;
    }

    if (readBT == 'd') {
pukul_kotak:

      readBT = Serial3.read();

      digitalWrite(led, HIGH);

      digitalWrite(pukul, HIGH);
      digitalWrite(pukul2, HIGH);

      digitalWrite(MOTORx_MUNDUR, LOW);
      digitalWrite(MOTORx_MAJU, LOW);

      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);

      if (readBT == 'o') {

        goto utama;
      }
      goto pukul_kotak;
    }





    //if (readBT == 'o' || digitalRead(sensor39) == LOW || digitalRead(sensor41) == LOW || digitalRead(sensor43) == LOW || digitalRead(sensor45) == LOW) {
    if (readBT == 'o') {
      analogWrite(pwm, 0);

      //sensor_off();
      //digitalWrite(sensor39, HIGH);
      //digitalWrite(sensor41, HIGH);
      //digitalWrite(sensor43, HIGH);
      //digitalWrite(sensor45, HIGH);

      digitalWrite(pukul, LOW);
      digitalWrite(pukul2, LOW);
      digitalWrite(led, LOW);


      digitalWrite(MOTORx_MUNDUR, LOW);
      digitalWrite(MOTORx_MAJU, LOW);

      //delay(1500);
      //digitalWrite(sensor39, HIGH);
      //digitalWrite(sensor41, HIGH);
      //digitalWrite(sensor43, HIGH);
      //digitalWrite(sensor45, HIGH);

      //analogWrite(pwm, 50);
      //analogWrite(pwm, 40);
      //analogWrite(pwm, 30);
      //analogWrite(pwm, 20);

      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);

      goto utama;
    }


    if (readBT == 'z') {
      //sensor_off();
      
      analogWrite(pwm, 0);

      digitalWrite(pukul, LOW);
      digitalWrite(pukul2, LOW);
      digitalWrite(led, LOW);


      //digitalWrite(sensor39, HIGH);
      //digitalWrite(sensor41, HIGH);
      //digitalWrite(sensor43, HIGH);
      //digitalWrite(sensor45, HIGH);

      digitalWrite(MOTORx_MUNDUR, LOW);
      digitalWrite(MOTORx_MAJU, LOW);


      //digitalWrite(sensor39, HIGH);
      //digitalWrite(sensor41, HIGH);
      //digitalWrite(sensor43, HIGH);
      //digitalWrite(sensor45, HIGH);

      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);
      goto utama;
    }

  }
  //goto utama;
  //}

  //////////////////////


  /*
  //void sensor_on(){
    //if(readBT == 'c' || readBT == 'd' || digitalRead(sensor39) == LOW || digitalRead(sensor41) == LOW || digitalRead(sensor43) == LOW || digitalRead(sensor45) == LOW){  //tambah tombol pneumatic
    //if(readBT == 'c' || readBT == 'd'){
  pukulx:

      readBT = Serial3.read();

      digitalWrite(led, HIGH);

      digitalWrite(pukul, HIGH);
      digitalWrite(pukul2, HIGH);

      digitalWrite(MOTORx_MUNDUR, LOW);
      digitalWrite(MOTORx_MAJU, LOW);

      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);

      if (readBT == 'o' || digitalRead(sensor39) == LOW || digitalRead(sensor41) == LOW || digitalRead(sensor43) == LOW || digitalRead(sensor45) == LOW) {
   kkkk:
      //sensor_off();

      digitalWrite(sensor39,HIGH);
      digitalWrite(sensor41,HIGH);
      digitalWrite(sensor43,HIGH);
      digitalWrite(sensor45,HIGH);

      digitalWrite(pukul, LOW);
      digitalWrite(pukul2, LOW);
      digitalWrite(led, LOW);
      if (readBT == 'o') {


  goto utama;
    }

      }
      goto pukulx;
    }
  */
}





