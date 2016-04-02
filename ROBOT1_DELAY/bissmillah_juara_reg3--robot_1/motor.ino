void maju(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_2,HIGH);
	digitalWrite(enki_2,LOW);
	digitalWrite(enka_4,HIGH);
	digitalWrite(enki_4,LOW);
///////////////////////////////////////////
	digitalWrite(enka_1,LOW);
	digitalWrite(enki_1,LOW);
	digitalWrite(enka_3,LOW);
	digitalWrite(enki_3,LOW);
}
void mundur(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_2,LOW);
	digitalWrite(enki_2,HIGH);
	digitalWrite(enka_4,LOW);
	digitalWrite(enki_4,HIGH);
///////////////////////////////////////////
	digitalWrite(enka_1,LOW);
	digitalWrite(enki_1,LOW);
	digitalWrite(enka_3,LOW);
	digitalWrite(enki_3,LOW);
}
void kiri(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_1,HIGH);
	digitalWrite(enki_1,LOW);
	digitalWrite(enka_3,HIGH);
	digitalWrite(enki_3,LOW);	
///////////////////////////////////////////
	digitalWrite(enka_2,LOW);
	digitalWrite(enki_2,LOW);
	digitalWrite(enka_4,LOW);
	digitalWrite(enki_4,LOW);
}
void kanan(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_1,LOW);
	digitalWrite(enki_1,HIGH);
	digitalWrite(enka_3,LOW);
	digitalWrite(enki_3,HIGH);	
///////////////////////////////////////////
	digitalWrite(enka_2,LOW);
	digitalWrite(enki_2,LOW);
	digitalWrite(enka_4,LOW);
	digitalWrite(enki_4,LOW);
}
void ser_kadep(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_1,LOW);
	digitalWrite(enki_1,HIGH);
	digitalWrite(enka_3,LOW);
	digitalWrite(enki_3,HIGH);	
///////////////////////////////////////////
	digitalWrite(enka_2,HIGH);
	digitalWrite(enki_2,LOW);
	digitalWrite(enka_4,HIGH);
	digitalWrite(enki_4,LOW);  
}
void ser_kidep(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_1,HIGH);
	digitalWrite(enki_1,LOW);
	digitalWrite(enka_3,HIGH);
	digitalWrite(enki_3,LOW);	
///////////////////////////////////////////
	digitalWrite(enka_2,HIGH);
	digitalWrite(enki_2,LOW);
	digitalWrite(enka_4,HIGH);
	digitalWrite(enki_4,LOW);  
}
void ser_kabel(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_1,LOW);
	digitalWrite(enki_1,HIGH);
	digitalWrite(enka_3,LOW);
	digitalWrite(enki_3,HIGH);	
///////////////////////////////////////////
	digitalWrite(enka_2,LOW);
	digitalWrite(enki_2,HIGH);
	digitalWrite(enka_4,LOW);
	digitalWrite(enki_4,HIGH);  
}
void ser_kibel(unsigned char kec){
	analogWrite(pwm, kec);
///////////////////////////////////////////
	digitalWrite(enka_1,HIGH);
	digitalWrite(enki_1,LOW);
	digitalWrite(enka_3,HIGH);
	digitalWrite(enki_3,LOW);	
///////////////////////////////////////////
	digitalWrite(enka_2,LOW);
	digitalWrite(enki_2,HIGH);
	digitalWrite(enka_4,LOW);
	digitalWrite(enki_4,HIGH);  
}
void rotate_left(unsigned char kec){
    analogWrite(pwm, kec);
//****************************************//
    digitalWrite(enka_1, HIGH);   
    digitalWrite(enki_1, LOW);         
    digitalWrite(enka_2, HIGH);   
    digitalWrite(enki_2, LOW);
    digitalWrite(enka_3, LOW);   
    digitalWrite(enki_3, HIGH);
    digitalWrite(enka_4, LOW);   
    digitalWrite(enki_4, HIGH);
}
void rotate_right(unsigned char kec){
    analogWrite(pwm, kec);
//****************************************//
    digitalWrite(enka_1, LOW);   
    digitalWrite(enki_1, HIGH);         
    digitalWrite(enka_2, LOW);   
    digitalWrite(enki_2, HIGH);
    digitalWrite(enka_3, HIGH);   
    digitalWrite(enki_3, LOW);
    digitalWrite(enka_4, HIGH);   
    digitalWrite(enki_4, LOW);
}
