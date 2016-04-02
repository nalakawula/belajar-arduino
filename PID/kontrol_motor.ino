void kontrol_motor() {
  int kec_motor_kanan = (kecepatan_motor - PID);
  int kec_motor_kiri = (kecepatan_motor + PID);

  constrain(kec_motor_kanan, 0, 255);
  constrain(kec_motor_kiri, 0, 255);

  analogWrite(9, kec_motor_kiri);
  analogWrite(10, kec_motor_kanan);

  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);


}
