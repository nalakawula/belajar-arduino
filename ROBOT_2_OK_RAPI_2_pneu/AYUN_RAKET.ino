void memukul() {
  digitalWrite(led, HIGH);
  digitalWrite(pukul, HIGH);
  digitalWrite(pukul2, HIGH);
  
  
}

void stop_pukul() {
  digitalWrite(led, LOW);
  digitalWrite(pukul, LOW);
  digitalWrite(pukul2, LOW);
}


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
  
  

      
  //delayMicroseconds(50);
  //digitalWrite(MOTORx_MAJU, HIGH);
  //digitalWrite(MOTORx_MUNDUR, LOW);
  //delayMicroseconds(50);

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

