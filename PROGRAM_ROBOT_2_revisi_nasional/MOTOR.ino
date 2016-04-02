void maju(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  readBT = Serial3.read();
}

void mundur(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);
  readBT = Serial3.read();
}

void kiri(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);
  readBT = Serial3.read();

}

void kanan(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  readBT = Serial3.read();
}

void kadep(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  readBT = Serial3.read();
}

void kidep(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  readBT = Serial3.read();
}

void kabel(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  readBT = Serial3.read();
}

void kibel(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);
  readBT = Serial3.read();
}

void putar_kanan(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);
  readBT = Serial3.read();
}

void putar_kiri(char kec) {
  analogWrite(pwm, kec);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  readBT = Serial3.read();
}

void berhenti() {
  
 // digitalWrite(MOTORx_MAJU, LOW);
 // digitalWrite(MOTORx_MUNDUR, LOW);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  readBT = Serial3.read();
}
/*
void motor_pukul(char kec) {
  analogWrite(pwm_raket, kec);
  
  digitalWrite(MOTOR1_MUNDUR, LOW);
  digitalWrite(MOTOR1_MAJU, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MUNDUR, LOW);
  digitalWrite(MOTOR3_MAJU, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);

  digitalWrite(MOTORx_MAJU, LOW);
  digitalWrite(MOTORx_MUNDUR, HIGH);



}

void motor_tarik(char kec) {
  analogWrite(pwm_raket, kec);

  digitalWrite(MOTOR1_MUNDUR, LOW);
  digitalWrite(MOTOR1_MAJU, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MUNDUR, LOW);
  digitalWrite(MOTOR3_MAJU, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);

  digitalWrite(MOTORx_MAJU, HIGH);
  digitalWrite(MOTORx_MUNDUR, LOW);


}
*/
