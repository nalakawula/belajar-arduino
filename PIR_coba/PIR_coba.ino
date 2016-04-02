#define pir 4
#define led 13
#define relay1 6
#define relay2 7

int kondisi_akhir = 0;
int kondisi = 0;
int hitung = 0;

int kondisiled = HIGH;

void setup() {
  pinMode(pir, INPUT)  ;
  pinMode(led, OUTPUT)  ;
  pinMode(relay1, OUTPUT)  ;
  pinMode(relay2, OUTPUT)  ;
  Serial.begin(9600);
  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);


}

void loop() {
  int baca = digitalRead(pir);

  if (baca != kondisi_akhir) {
    //if (kondisi == HIGH) {
    hitung = 1;
    Serial.println("on");
  }
  // else
  //hitung = 0;
  // Serial.println("off");
  // }

  //kondisi_akhir = kondisi;

  if (hitung  == 1) {
    if (baca != kondisi) {
      kondisi = baca;

      if (kondisi == HIGH) {
        kondisiled = !kondisiled;
      }
    }
    //  digitalWrite(led, HIGH);
    //digitalWrite(relay1, LOW);
    //digitalWrite(relay2, LOW);


digitalWrite(led, kondisiled);
  }

  //else {
  // digitalWrite(led, LOW);
  // digitalWrite(relay1, HIGH);
  // digitalWrite(relay2, HIGH);

  // }
  /*
    int i = digitalRead(pir);
    //int L = map(i, 0, 1023, 0, 255);

    Serial.println(i);
    //Serial.print("/");
    //Serial.println(L);
  */
}


