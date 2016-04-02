void memukul() {
  readBT = Serial3.read();
  digitalWrite(led, HIGH);
  digitalWrite(sol_1, HIGH);
  digitalWrite(sol_2, HIGH);
  
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

void stop_pukul() {
  readBT = Serial3.read();
  digitalWrite(led, LOW);
  digitalWrite(sol_1, LOW);
  digitalWrite(sol_2, LOW);
  
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

