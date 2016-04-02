/*
Bismillah,
Program revisi untuk Robot 2, dibuat dan didedikasikan untuk tim Bledheg ijo.
Semoga juara ditingkat nasional.

Selalu ada cacat pada produk manusia, be aware.

ditulis oleh: sumarsono
Last edit pada: senin, 1 Juni 2015 23:23
*/


/*VARIABEL*/

//SPEED
//char ayun = 255;
char slow = 200;
char normal = 240;
char fast = 255;

//PWM
unsigned char pwm = 2;
//unsigned char pwm_raket = 11;

//LED INDIKATOR
int led = 13;

//BT
char readBT;

//selonoid
#define pukul   51
#define pukul2  47

//#define MOTORx_MAJU  6
//#define MOTORx_MUNDUR  7

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

  /*MOTOR*/
  pinMode(pwm, INPUT);
  // pinMode(pwm_raket, INPUT);

  //pinMode(MOTORx_MAJU, OUTPUT);
  //pinMode(MOTORx_MUNDUR, OUTPUT);

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



    /*GERAK NORMAL*/
    if (readBT == 'g') {
      start(); //Penting agar tegangan dan arus motor tidak over > 24volt, eman2 baterene
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


    if (readBT == '1') {
      //putar_kanan(normal);
      start();
putar_kanan:
      readBT = Serial3.read();

      putar_kanan(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto putar_kanan;
    }
    
    if (readBT == '2') {
      // putar_kiri(normal);
      start();
putar_kiri:
      readBT = Serial3.read();

      putar_kiri(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        //pelan();
        goto utama;
      }
      goto putar_kiri;
    }


    /*AKHIR GERAK NORMAL*/

    /*RAKET*/
    /*
    if (readBT == 'a') {
      goto ayun;
    ayun:
      readBT = Serial3.read();
      digitalWrite(led, HIGH);

      berhenti(0);

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

      berhenti(0);

      motor_tarik(ayun);

      goto utama;

      if (readBT == 'z') {
        goto utama;
      }
    }
    */

    if (readBT == 'c') {
pukulx:

      readBT = Serial3.read();

      memukul();

      berhenti(); //set semua motor berhenti

      if (readBT == 'o') {

        goto utama;
      }
      goto pukulx;
    }

    if (readBT == 'd') {
pukul_kotak:

      readBT = Serial3.read();

      memukul();

      berhenti();

      if (readBT == 'o') {

        goto utama;
      }
      goto pukul_kotak;
    }


    if (readBT == 'o') {
      analogWrite(pwm, 0); //penting, agar tdk ada konflik tegangan pada motor

      stop_pukul();

      berhenti();

      goto utama;
    }


    if (readBT == 'z') {
      //analogWrite(pwm, 0); //penting, agar tdk ada konflik tegangan pada motor
      readBT = Serial3.read();

      stop_pukul();

      berhenti();

      goto utama;
    }

  }
/*
  else {

  {
    stop_pukul();

    berhenti();
  }
  */

  
}


