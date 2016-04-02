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

Log:
Saturday 04 April 2015 16:48:48 - 
Monday 06 April 2015 07:42:52 - Edit putar kanan dan kiri ke mode normal dan slow.
Thursday 09 April 2015 15:56:13 - Penambahan keterangan tata letak roda mecanum.

*/


/*VARIABEL*/
unsigned char pwm = 2;

int led = 13;

char readBT;

char slowmode = 70;
char normal = 110;
char fastmode = 140;



//selonoid
#define pukul   51
#define pukul2  49

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

  //***********LCD***************//
  //lcd.begin(16,2);

  /*MOTOR*/
  pinMode(pwm, INPUT);

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
  digitalWrite(pukul, LOW);

  pinMode(led, OUTPUT);
}


void loop() {

if (Serial3.available()) {
  utama:
  readBT = Serial3.read();

/*GERAK NORMAL*/
  if (readBT == 'g') {
    //maju(40);
maju:
    readBT = Serial3.read();
    maju(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto maju;
  }

  if (readBT == 'k') {
    mundur(40);
mundur:
    readBT = Serial3.read();
    mundur(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto mundur;
  }

  if (readBT == 'i') {
    kanan(40);
kanan:
    readBT = Serial3.read();
    kanan(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto kanan;
  }

  if (readBT == 'm') {
    kiri(40);
kiri:
    readBT = Serial3.read();
    kiri(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto kiri;
  }

  if (readBT == 'h') {
    kadep(40);
kadep:
    readBT = Serial3.read();
    kadep(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto kadep;
  }

  if (readBT == 'n') {
    kidep(40);
kidep:
    readBT = Serial3.read();
    kidep(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto kidep;
  }

  if (readBT == 'j') {
    kabel(40);
kabel:
    readBT = Serial3.read();
    kabel(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto kabel;
  }

  if (readBT == 'l') {
    kibel(40);
kibel:
    readBT = Serial3.read();
    kibel(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto kibel;
  }


  if (readBT == 'd') {
    putar_kiri(normal);
putar_kiri:
    readBT = Serial3.read();
    putar_kiri(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto putar_kiri;
  }

  if (readBT == 'b') {
    putar_kanan(normal);
putar_kanan:
    readBT = Serial3.read();
    putar_kanan(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {
      pelan();
      goto utama;
    }
    goto putar_kanan;
  }
/*AKHIR GERAK NORMAL*/ 
  
/*GERAK LAMBAT*/
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

  if (readBT == 'c') {
pukulx:
    readBT = Serial3.read();
    digitalWrite(led, HIGH);
    digitalWrite(pukul, HIGH);
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


  if (readBT == 'o') {


    digitalWrite(pukul, LOW);
    digitalWrite(led, LOW);
    
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

  }


  if (readBT == 'z') {
    digitalWrite(pukul, LOW);
    digitalWrite(led, LOW);

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
  goto utama;
}



