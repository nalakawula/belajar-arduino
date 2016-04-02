void maju(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);

  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
}

void mundur(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);


  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);
}

void kiri(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);

}

void kanan(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);

  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
}

void kadep(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);

  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
}

void kidep(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);
}

void kabel(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);


  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);
}

void kibel(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);


  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);
}

void putar_kanan(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);


  digitalWrite(MOTOR1_MAJU, HIGH);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, HIGH);

  digitalWrite(MOTOR3_MAJU, HIGH);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, HIGH);
}

void putar_kiri(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm, nilai);
  digitalWrite(led, HIGH);

  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, HIGH);

  digitalWrite(MOTOR2_MAJU, HIGH);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, HIGH);

  digitalWrite(MOTOR4_MAJU, HIGH);
  digitalWrite(MOTOR4_MUNDUR, LOW);
}

void berhenti() {
  readBT = Serial3.read();
  analogWrite(pwm, 0);
  digitalWrite(led, LOW);
  
  digitalWrite(MOTOR5_MAJU, LOW);
  digitalWrite(MOTOR5_MUNDUR, LOW);
  
  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);

}

void motor_pukul(char nilai) {
  readBT = Serial3.read();
  digitalWrite(led, HIGH);
  analogWrite(pwm_raket, nilai);
  digitalWrite(MOTOR5_MAJU, LOW);
  digitalWrite(MOTOR5_MUNDUR, HIGH);
  //delay(1000);
  
  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);
  
  

}

void motor_tarik(char nilai) {
  readBT = Serial3.read();
  analogWrite(pwm_raket, nilai);

  digitalWrite(MOTOR5_MAJU, HIGH);
  digitalWrite(MOTOR5_MUNDUR, LOW);
    
  digitalWrite(MOTOR1_MAJU, LOW);
  digitalWrite(MOTOR1_MUNDUR, LOW);

  digitalWrite(MOTOR2_MAJU, LOW);
  digitalWrite(MOTOR2_MUNDUR, LOW);

  digitalWrite(MOTOR3_MAJU, LOW);
  digitalWrite(MOTOR3_MUNDUR, LOW);

  digitalWrite(MOTOR4_MAJU, LOW);
  digitalWrite(MOTOR4_MUNDUR, LOW);

}


