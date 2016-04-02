/*
Bismillah,
program ini ditulis untuk robot 2 dan di dedikasikan untuk tim bledheg ijo.
Metode switching.

ditulis pada: 29 Mei 2015
Oleh: Sumarsono

Last edit pada: senin, 1 Juni 2015 23:23

kenali robotmu dan rasakan bedanya
  --------------
 1 0=-        -=0 2
  |            |
  |            |
  |            |
 3 0=-        -=0 4
  --------------

*/



#define sol_1   51
#define sol_2  47

char ayun = 255;
char slowmode = 80;
char normal = 230;
char fastmode = 255;

unsigned char pwm = 2;
unsigned char pwm_raket = 11;

int led = 13;

char readBT;




//motor1
int MOTOR1_MAJU = 23;
int MOTOR1_MUNDUR = 25;

//motor2
int MOTOR2_MAJU =  27;
int MOTOR2_MUNDUR = 29;

//motor3
int MOTOR3_MAJU = 31;
int MOTOR3_MUNDUR = 33;

//motor4
int MOTOR4_MAJU = 35;
int MOTOR4_MUNDUR = 37;

//motor raket
int MOTOR5_MAJU = 6;
int MOTOR5_MUNDUR = 7;

void setup() {
  Serial3.begin(9600);
  //Serial.begin(9600);


  pinMode(pwm, OUTPUT);

  pinMode(MOTOR1_MAJU, OUTPUT);
  pinMode(MOTOR1_MUNDUR, OUTPUT);

  pinMode(MOTOR2_MAJU, OUTPUT);
  pinMode(MOTOR2_MUNDUR, OUTPUT);

  pinMode(MOTOR3_MAJU, OUTPUT);
  pinMode(MOTOR3_MUNDUR, OUTPUT);

  pinMode(MOTOR4_MAJU, OUTPUT);
  pinMode(MOTOR4_MUNDUR, OUTPUT);

  pinMode(MOTOR5_MAJU, OUTPUT);
  pinMode(MOTOR5_MUNDUR, OUTPUT);

  pinMode(led, OUTPUT);

  pinMode(sol_1, OUTPUT);
  pinMode(sol_2, OUTPUT);

  digitalWrite(sol_1, LOW);
  digitalWrite(sol_2, LOW);

  if (Serial3.available() > 0) {
    readBT = Serial3.read();
  }
}


void loop() {
  readBT = Serial3.read();

  switch (readBT) {

    //MAJU
    case 'g':
maju:
      maju(normal);
      if (readBT == 'z') {
        break;
      }
      goto maju;

    //MUNDUR
    case 'k':
mundur:
      mundur(normal);
      if (readBT == 'z') {
        break;
      }
      goto mundur;

    //KANAN
    case 'i':
kanan:
      kanan(normal);
      if (readBT == 'z') {
        break;
      }
      goto kanan;

    //KIRI
    case 'm':
kiri:
      kiri(normal);
      if (readBT == 'z') {
        break;
      }
      goto kiri;

    //KADEP
    case 'h':
kadep:
      kadep(normal);
      if (readBT == 'z') {
        break;
      }
      goto kadep;

    //KIDEP
    case 'n':
kidep:
      kidep(normal);
      if (readBT == 'z') {
        break;
      }
      goto kidep;

    //KABEL
    case 'j':
kabel:
      kabel(normal);
      if (readBT == 'z') {
        break;
      }
      goto kabel;

    //KIBEL
    case 'l':
kibel:

      kibel(normal);
      if (readBT == 'z') {
        break;
      }
      goto kibel;

    //PUTAR KANAN
    case '1':
putar_kanan:
      putar_kanan(normal);
      if (readBT == 'z') {
        break;
      }
      goto putar_kanan;

    //PUTAR KIRI
    case '2':
putar_kiri:
      putar_kiri(normal);
      if (readBT == 'z') {
        break;
      }
      goto putar_kiri;

    //RAKET
    case 'a':
      motor_pukul(200);
      break;

    case 'b':
      motor_pukul(200);
      break;

    case 'c':
a:
      memukul();
      if (readBT == 'z') {
        break;
      }
      goto a;

    case 'd':
b:
      memukul();
      if (readBT == 'z') {
        break;
      }
      goto b;

    //DEFAULT
    default:
      /*
        for (int Pin = 2; Pin < 11; Pin++) {
        digitalWrite(Pin, LOW);
        }
      */
      digitalWrite(led, LOW);
      berhenti();
      stop_pukul();
      break;

  }
}

