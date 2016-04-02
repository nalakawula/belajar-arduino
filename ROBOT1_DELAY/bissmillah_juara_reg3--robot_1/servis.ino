void stop_servis(){
  digitalWrite(led,LOW);
  digitalWrite(cock,LOW);
  digitalWrite(servis,LOW);
  digitalWrite(pukul1,LOW);
}

void servis_delay(){
       digitalWrite(led,HIGH);
       digitalWrite(cock,HIGH);
       delay(350);
       digitalWrite(servis,HIGH);
       delay(800);
       //loop();
       //goto menu;
}

