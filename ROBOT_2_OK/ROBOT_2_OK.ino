/*
Program untuk robot 2 bledheg ijo, KRAI Unnes. Bismillah, semoga lolos nasional. aamiin.
Ditulis pada: Saturday 04 April 2015 00:54:55
Oleh: Sumarsono


*/

//pwm
unsigned char pwm = 2;

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
menu:
  if (Serial3.available()) {
    readBT = Serial3.read();

    //******************PERGERAKAN ROBOT*******************//

    if (readBT == 'g') {
maju:

      maju(80);
      digitalWrite(led, HIGH);
      readBT = Serial3.read();
      if (readBT == 'k') {
        return;
      }
      goto maju;
    }

    else if (readBT == 'f') {
mundur:

      mundur(80);
      digitalWrite(led, HIGH);
      readBT = Serial3.read();
      if (readBT == 'z') {
        return;
      }
      goto mundur;
    }


    else if (readBT == 'm') {
kiri:
      readBT = Serial3.read();
      kiri(80);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto kiri;
    }

    else if (readBT == 'i') {
kanan:
      readBT = Serial3.read();
      kanan(80);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto kanan;
    }

    else if (readBT == 'h') {
kadep:
      readBT = Serial3.read();
      kadep(80);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto kadep;
    }

    else if (readBT == 'n') {
Z2:
      readBT = Serial3.read();
      kidep(80);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z2;
    }
    else if (readBT == 'l') {
Z3:
      readBT = Serial3.read();
      kibel(80);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z3;
    }
    else if (readBT == 'j') {
Z4:
      readBT = Serial3.read();
      kabel(80);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z4;
    }

    else if (readBT == 'd') {
Z5:
      readBT = Serial3.read();
      putar_kiri(70);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z5;
    }

    else if (readBT == 'b') {
Z6:
      readBT = Serial3.read();
      putar_kanan(70);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z6;
    }


    //GERAK KOMBINASI SLOW
    else if (readBT == 'r') {
Z7:
      readBT = Serial3.read();
      maju(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z7;
    }

    else if (readBT == 's') {
Z8:
      readBT = Serial3.read();
      mundur(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z8;
    }

    else if (readBT == 't') {
Z9:
      readBT = Serial3.read();
      kanan(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z9;
    }

    else if (readBT == 'u') {
Z10:
      readBT = Serial3.read();
      kiri(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z10;
    }

    else if (readBT == 'v') {
Z11:
      readBT = Serial3.read();
      kadep(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z11;
    }

    else if (readBT == 'w') {
Z12:
      readBT = Serial3.read();
      kidep(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z12;
    }

    else if (readBT == 'x') {
Z13:
      readBT = Serial3.read();
      kabel(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z13;
    }

    else if (readBT == 'y') {
Z14:
      readBT = Serial3.read();
      kabel(50);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z14;
    }


    else if (readBT == '0') {
Z51:
      readBT = Serial3.read();
      putar_kiri(40);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z51;
    }

    else if (readBT == '9') {
Z61:
      readBT = Serial3.read();
      putar_kanan(40);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z61;
    }


    //GERAK KOMBINASI BANTER
    else if (readBT == '1') {
Z71:
      readBT = Serial3.read();
      maju(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z71;
    }

    else if (readBT == '2') {
Z81:
      readBT = Serial3.read();
      mundur(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z81;
    }

    else if (readBT == '3') {
Z91:
      readBT = Serial3.read();
      kanan(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z91;
    }

    else if (readBT == '4') {
Z101:
      readBT = Serial3.read();
      kiri(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z101;
    }

    else if (readBT == '5') {
Z111:
      readBT = Serial3.read();
      kadep(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z111;
    }

    else if (readBT == '6') {
Z121:
      readBT = Serial3.read();
      kidep(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z121;
    }

    else if (readBT == '7') {
Z131:
      readBT = Serial3.read();
      kabel(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z131;
    }

    else if (readBT == '8') {
Z141:
      readBT = Serial3.read();
      kabel(100);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        return;
      }
      goto Z141;
    }

    /////PUKUL

    else if (readBT == 'c') {
Z18:
      readBT = Serial3.read();
      //memukul();
      digitalWrite(led, HIGH);
      digitalWrite(pukul, HIGH);
      if (readBT == 'o') {
        return;
      }
      goto Z18;
    }


    else if (readBT == 'o') {
      //stop_pukul();
      digitalWrite(pukul, LOW);
      digitalWrite(MOTOR1_MUNDUR, LOW);
      digitalWrite(MOTOR1_MAJU, LOW);

      digitalWrite(MOTOR2_MAJU, LOW);
      digitalWrite(MOTOR2_MUNDUR, LOW);

      digitalWrite(MOTOR3_MUNDUR, LOW);
      digitalWrite(MOTOR3_MAJU, LOW);

      digitalWrite(MOTOR4_MAJU, LOW);
      digitalWrite(MOTOR4_MUNDUR, LOW);

    }


    else {
      //stop_pukul();
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
      return;
    }


  }
  //goto menu;
}

