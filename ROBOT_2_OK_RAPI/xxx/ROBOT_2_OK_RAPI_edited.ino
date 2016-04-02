/*
Program untuk robot 2 bledheg ijo, KRAI Unnes. Bismillah, semoga lolos nasional. aamiin.
Ditulis pada: Saturday 04 April 2015 00:54:55
Oleh: Sumarsono

Log:
Saturday 04 April 2015 16:48:48 - 

*/

//pwm
unsigned char pwm = 2;

char slowmode = 60;
char normal = 90;
char fastmode = 140;


//led
int led = 13;

//blutut
char readBT;

//selonoid
#define pukul   51

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

  //***********motor*************//

  pinMode(pwm, INPUT);

  pinMode(MOTOR1_MAJU, OUTPUT);
  pinMode(MOTOR1_MUNDUR, OUTPUT);

  pinMode(MOTOR2_MAJU, OUTPUT);
  pinMode(MOTOR2_MUNDUR, OUTPUT);

  pinMode(MOTOR3_MAJU, OUTPUT);
  pinMode(MOTOR3_MUNDUR, OUTPUT);

  pinMode(MOTOR4_MAJU, OUTPUT);
  pinMode(MOTOR4_MUNDUR, OUTPUT);

  pinMode(pukul, OUTPUT);
  digitalWrite(pukul, LOW);

  pinMode(led, OUTPUT);
}


void loop() {
utama:
if (Serial3.available()) {
  readBT = Serial3.read();


  if (readBT == 'g') {
maju:
    readBT = Serial3.read();
    maju(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto maju;
  }

  if (readBT == 'k') {
mundur:
    readBT = Serial3.read();
    mundur(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto mundur;
  }

  if (readBT == 'i') {
kanan:
    readBT = Serial3.read();
    kanan(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto kanan;
  }

  if (readBT == 'm') {
kiri:
    readBT = Serial3.read();
    kiri(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto kiri;
  }

  if (readBT == 'h') {
kadep:
    readBT = Serial3.read();
    kadep(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto kadep;
  }

  if (readBT == 'n') {
kidep:
    readBT = Serial3.read();
    kidep(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto kidep;
  }

  if (readBT == 'j') {
kabel:
    readBT = Serial3.read();
    kabel(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto kabel;
  }

  if (readBT == 'l') {
kibel:
    readBT = Serial3.read();
    kibel(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto kibel;
  }


  if (readBT == 'd') {
putar_kiri:
    readBT = Serial3.read();
    putar_kiri(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto putar_kiri;
  }

  if (readBT == 'b') {
putar_kanan:
    readBT = Serial3.read();
    putar_kanan(normal);
    digitalWrite(led, HIGH);
    if (readBT == 'z') {

      goto utama;
    }
    goto putar_kanan;
  }
  
  
  //GERAK KOMBINASI SLOW
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


  //GERAK KOMBINASI BANTER
  if (readBT == '1') {
maju_cepat:

    maju(fastmode);
    digitalWrite(led, HIGH);
    readBT = Serial3.read();
    if (readBT == 'z') {
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
      goto utama;
    }
    goto kibel_cepat;
  }


  /////PUKUL

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
    
    analogWrite(pwm, 50);
    analogWrite(pwm, 40);
    analogWrite(pwm, 30);
    
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
    
    analogWrite(pwm, 50);
    analogWrite(pwm, 40);
    analogWrite(pwm, 30);

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
}


