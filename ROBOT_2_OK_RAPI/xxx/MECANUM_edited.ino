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
}

void berhenti(char kec) {
  analogWrite(pwm, 50);
  analogWrite(pwm, 40);
  analogWrite(pwm, 30);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);
}