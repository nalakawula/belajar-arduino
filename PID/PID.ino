float Kp = 0, Ki = 0, Kd = 0;
float error = 0, P = 0, I = 0, D = 0, PID = 0;
float error_sebelumnya = 0, I_sebelumnya = 0;
int sensor[5] = {0, 0, 0, 0, 0};
int kecepatan_motor = 100;

void baca_sensor(void);
void hitung_pid(void);
void kontrol_motor(void);


void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  baca_sensor();
  hitung_pid();
  kontrol_motor();

}


