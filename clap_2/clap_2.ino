int input_sensor = 3; //output dari sensor masuk ke pin d3
int output_1 = 4; //output arduino ke pin d4
int tepuk = 0; //nilai tepuk yang terdeteksi
long awal_rentang_deteksi = 0; //timer untuk deteksi awal (berjalan setelah deteksi suara pertama)
long rentang_deteksi = 0; //nilai rentang waktu untuk deteksi suara kedua
boolean kondisi_output = false; //kondisi output
 
void setup() {
  pinMode(input_sensor, INPUT);
  pinMode(output_1, OUTPUT);
}
 
void loop() {
 
  int kondisi_sensor = digitalRead(input_sensor); //baca sensor
 
  if (kondisi_sensor == 0) //secara default, sensor suara berlogika 1 ketika idle, 0 ketika ada suara
  {
    if (tepuk == 0) //nilai tepuk di awal sudah di set 0
    {
      awal_rentang_deteksi = rentang_deteksi = millis(); //start fungsi millis untuk rentang deteksi
      tepuk++; //tepuk bertambah nilainya
    }
    else if (tepuk > 0 && millis()-rentang_deteksi >= 40)
    {
      rentang_deteksi = millis();
      tepuk++;
    }
  }
 
  if (millis()-awal_rentang_deteksi >= 400) //jeda tepukan pertama dengan kedua adalah 1000mili detik
  {
    if (tepuk == 2)
    {
      if (!kondisi_output)
        {
          kondisi_output = true;
          digitalWrite(output_1, HIGH);
        }
        else if (kondisi_output)
        {
          kondisi_output = false;
          digitalWrite(output_1, LOW);
        }
    }
    tepuk = 0;
  }
}
