unsigned char pwm = 2;

//***********motor 1 *********//
#define enka_1  23
#define enki_1  25
//***********motor 2 *********//
#define enka_2  27
#define enki_2  29
//***********motor 3 *********//
#define enka_3  31
#define enki_3  33
//***********motor 4 *********//
#define enka_4  35
#define enki_4  37
//***********pneumatic*********//
#define cock    53
#define servis  49
#define pukul1  47
int infra = 8;
int infra_2 = 9;
int led = 13;
char readBT;

 unsigned char normal = 200;
    unsigned char slow = 160;


void setup() {

  Serial3.begin(9600);


  pinMode(pwm, INPUT);

  pinMode(enka_1, OUTPUT);
  pinMode(enki_1, OUTPUT);
  pinMode(enka_2, OUTPUT);
  pinMode(enki_2, OUTPUT);
  pinMode(enka_3, OUTPUT);
  pinMode(enki_3, OUTPUT);
  pinMode(enka_4, OUTPUT);
  pinMode(enki_4, OUTPUT);

  pinMode(cock, OUTPUT);
  pinMode(servis, OUTPUT);
  pinMode(pukul1, OUTPUT);
  digitalWrite(cock, LOW);
  digitalWrite(servis, LOW);
  digitalWrite(pukul1, LOW);

  pinMode(infra, INPUT_PULLUP);
  pinMode(infra_2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
menu:
  if (Serial3.available()) {

   
    readBT = Serial3.read();

    if (readBT == 'g') {           //Up
g:
      readBT = Serial3.read();
      maju(normal);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto g;
    }

    if (readBT == 'k') {     //Down
k:
      readBT = Serial3.read();
      mundur(normal);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto k;
    }

    if (readBT == 'm') {     //Left
m:
      readBT = Serial3.read();
      kiri(normal);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto m;
    }

    if (readBT == 'i') {      //Right
i:
      readBT = Serial3.read();
      kanan(normal);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto i;
    }

    if (readBT == 'h') {     //Up-right
h:
      readBT = Serial3.read();
      ser_kadep(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto h;
    }

    if (readBT == 'n') {         //Up-left
n:
      readBT = Serial3.read();
      ser_kidep(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto n;
    }

    if (readBT == 'l') {         //Down-left
l:
      readBT = Serial3.read();
      ser_kibel(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto l;
    }

    if (readBT == 'j') {       //Down-right
j:
      readBT = Serial3.read();
      ser_kabel(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto j;
    }


    if (readBT == 'f') {             //R_1
f:
      readBT = Serial3.read();
      rotate_right(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto f;
    }

    if (readBT == 'p') {             //L_1
p:
      readBT = Serial3.read();
      rotate_left(slow);
      digitalWrite(led, HIGH);
      if (readBT == 'z') {
        goto menu;
      }
      goto p;
    }



    if (readBT == 'a') {   //segitiga
      delay1();
a:
      {
        digitalWrite(49, HIGH);
        readBT = Serial3.read();
        if (readBT == 'o') {
          stop();
          goto menu;
        }
      }
      goto a;
    }

    if (readBT == 'b') {   //lingkaran(o)
      delay2();
b:
      {
        digitalWrite(49, HIGH);
        readBT = Serial3.read();
        if (readBT == 'o') {
          stop();
          goto menu;
        }
      }
      goto b;
    }

    if (readBT == 'c') {          //silang(X)
c:
      readBT = Serial3.read();
      stopmotor();
      digitalWrite(led, HIGH);
      digitalWrite(pukul1, HIGH);
      if (readBT == 'o') {
        stop();
        goto menu;
      }
      goto c;
    }

    if (readBT == 'd') {           //kotak
      delay3();
d:
      {
        digitalWrite(49, HIGH);
        readBT = Serial3.read();
        if (readBT == 'o') {
          stop();
          goto menu;
        }
      }
      goto d;
    }


    /*
        if (readBT == 'd') {           //kotak
    d:
          readBT = Serial3.read();
          digitalWrite(cock, HIGH);
          if (digitalRead(infra) == LOW || digitalRead(infra_2) == LOW) {
            digitalWrite(led, HIGH);
            digitalWrite(servis, HIGH);
          }
          if (readBT == 'o') {
            stop();
            goto menu;
          }
          goto d;
        }
        */

    if (readBT == 'o') {         //L2
      stop_servis();
      readBT = Serial3.read();
    }

    if (readBT == 'z') {
      stop_servis();
      digitalWrite(pukul1, LOW);
      digitalWrite(enka_2, LOW);
      digitalWrite(enki_2, LOW);
      digitalWrite(enka_4, LOW);
      digitalWrite(enki_4, LOW);
      digitalWrite(enka_1, LOW);
      digitalWrite(enki_1, LOW);
      digitalWrite(enka_3, LOW);
      digitalWrite(enki_3, LOW);
      readBT = Serial3.read();
      goto menu;
    }


    else {
      stop();
      digitalWrite(led, LOW);
      digitalWrite(infra, HIGH);
      digitalWrite(cock, LOW);
      digitalWrite(servis, LOW);
      digitalWrite(pukul1, LOW);
      readBT = Serial3.read();
      goto menu;
    }
    goto menu;
  }
}

void stop() {
  stop_servis();
  digitalWrite(pukul1, LOW);
  digitalWrite(enka_2, LOW);
  digitalWrite(enki_2, LOW);
  digitalWrite(enka_4, LOW);
  digitalWrite(enki_4, LOW);
  digitalWrite(enka_1, LOW);
  digitalWrite(enki_1, LOW);
  digitalWrite(enka_3, LOW);
  digitalWrite(enki_3, LOW);
}

void stopmotor() {
  stop_servis();
  
  digitalWrite(enka_2, LOW);
  digitalWrite(enki_2, LOW);
  digitalWrite(enka_4, LOW);
  digitalWrite(enki_4, LOW);
  digitalWrite(enka_1, LOW);
  digitalWrite(enki_1, LOW);
  digitalWrite(enka_3, LOW);
  digitalWrite(enki_3, LOW);
}
