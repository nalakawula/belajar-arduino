void memukul() {
  digitalWrite(led, HIGH);
  digitalWrite(pukul, HIGH);
  digitalWrite(pukul2, HIGH);
  readBT = Serial3.read();
  
  
}

void stop_pukul() {
  digitalWrite(led, LOW);
  digitalWrite(pukul, LOW);
  digitalWrite(pukul2, LOW);
  readBT = Serial3.read();
}
