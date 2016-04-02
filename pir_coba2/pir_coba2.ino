#define pir 4
#define led 13
#define relay1 6
#define relay2 7

int kondisi_akhir = LOW;
int kondisi;
int hitung = 0;

int kondisiled = HIGH;

long debounce_t = 0;
long debounce_d = 50;

void setup() {
  pinMode(pir, INPUT)  ;
  pinMode(led, OUTPUT)  ;
  pinMode(relay1, OUTPUT)  ;
  pinMode(relay2, OUTPUT)  ;
  Serial.begin(9600);
  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);
  digitalWrite (led, kondisiled);


}

void loop() {
  kondisi = digitalRead(pir);

  if (kondisi != kondisi_akhir) {
    hitung = 1;
  }

  if (hitung == 1) {
    if (kondisi != kondisi_akhir) {
      kondisi_akhir = kondisi;

      if (kondisi = HIGH) {
        kondisiled = !kondisiled;
      }
    }
  }
}

