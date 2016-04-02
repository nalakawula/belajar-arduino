/***
BLEDHEG IJO-KONTROL DENGAN STIK WIRELESS 
BY: ROBOTIKA UNNES "nMn"
***/
//  Bissmillah juara KRN 2015 amin,... :) goto abu robocon 2015 

unsigned char pwm_1 =2;
unsigned char pwm_2 =3;
unsigned char pwm_3 =4;
unsigned char pwm_4 =5;

//***********motor 1 *********//
#define enka_1  23  
#define enki_1  25
//***********motor 2 *********//
#define enka_2  27
#define enki_2  29
//***********motor 3 *********//
#define enka_3  31
#define enki_3  33
//***********motor 4 *********//
#define enka_4  35
#define enki_4  37
//***********pneumatic*********//
#define cock    53
#define servis  49
#define pukul1  47
int infra = 8;
int infra_2 = 9;
int led = 13;
char readBT;
//*************//

//************//
void setup() {
//************Serial************//
	//Serial.begin(9slow0);	//default serial(Tz0,Rz0)
        Serial3.begin(9600);
//***********motor*************//
        pinMode(pwm_1,INPUT);
        pinMode(pwm_2,INPUT);
        pinMode(pwm_3,INPUT);
        pinMode(pwm_4,INPUT);
        ////////////////////////
	pinMode(enka_1,OUTPUT);
	pinMode(enki_1,OUTPUT);
	pinMode(enka_2,OUTPUT);
	pinMode(enki_2,OUTPUT);
	pinMode(enka_3,OUTPUT);
	pinMode(enki_3,OUTPUT);
	pinMode(enka_4,OUTPUT);
	pinMode(enki_4,OUTPUT);
//*************pneumatic************//
	pinMode(cock,OUTPUT);
	pinMode(servis,OUTPUT);
        pinMode(pukul1,OUTPUT);
        digitalWrite(cock,LOW);
        digitalWrite(servis,LOW);
        digitalWrite(pukul1,LOW);
//********************************//
        pinMode(infra,INPUT_PULLUP);
        pinMode(infra_2,INPUT_PULLUP);
        pinMode(led,OUTPUT);
}

void loop() {
  menu:
  if (Serial3.available()){
    
    unsigned char normal = 1850;
    unsigned char fast = 140;
    unsigned char slow = 70;
    
    readBT=Serial3.read();
//**********************satu-tombol-jalan_motor*****************************//
    if(readBT== 'g'){              //Up
      g:
        readBT=Serial3.read();
        maju(normal);
        digitalWrite(led,HIGH);
      if(readBT == 'z'){
         goto menu;
      }
      goto g;
    }  
    if(readBT== 'k'){        //Down
      k:
        readBT=Serial3.read();
        mundur(normal);
        digitalWrite(led,HIGH);
      if(readBT == 'z'){
         goto menu;
      }
      goto k;
    } 
    if(readBT== 'm'){        //Left
      m:
        readBT=Serial3.read();
        kiri(normal);
        digitalWrite(led,HIGH);
      if(readBT == 'z'){
         goto menu;
      }
      goto m;    
    }
    if(readBT== 'i'){         //Right
      i:
        readBT=Serial3.read();
        kanan(normal);
        digitalWrite(led,HIGH);
      if(readBT == 'z'){
         goto menu;
      }
      goto i;
    }
    if(readBT== 'h'){        //Up-right
      h:
        readBT=Serial3.read();
        ser_kadep(normal);
        digitalWrite(led,HIGH);
      if(readBT == 'z'){
         goto menu;
      }
      goto h;
    }
    if(readBT== 'n'){            //Up-left
       n:
         readBT=Serial3.read();
         ser_kidep(normal);
         digitalWrite(led,HIGH);
       if(readBT == 'z'){
          goto menu;
       }
       goto n;
    }
    if(readBT== 'l'){            //Down-left
      l:
        readBT=Serial3.read();
        ser_kibel(normal);
        digitalWrite(led,HIGH);
      if(readBT == 'z'){
         goto menu;
      }
      goto l;
    }
    if(readBT== 'j'){          //Down-right
       j:
         readBT=Serial3.read();
         ser_kabel(normal);
         digitalWrite(led,HIGH);
       if(readBT == 'z'){
           goto menu;
       }
       goto j;
    }
//**************************Rotasi-Right-Left***************************//
    if(readBT== 'f'){                //R_1
      f:
        readBT=Serial3.read();
        rotate_right(normal);
        digitalWrite(led,HIGH);
      if(readBT == 'z'){
         goto menu;
      }
      goto f;
    }
    if(readBT== 'p'){                //L_1
       p:
         readBT=Serial3.read();
         rotate_left(normal);
         digitalWrite(led,HIGH);
       if(readBT == 'z'){
         goto menu;
       }
       goto p;
    }
//******************End satu-tombol-Motor*******************************//
//*********************Pneumatic-servis-pukul***************************//
    if(readBT== 'd'){              //kotak
      d:
        readBT=Serial3.read();
        digitalWrite(cock,HIGH);
      if(digitalRead(infra) == LOW || digitalRead(infra_2) == LOW){
        digitalWrite(led,HIGH);
        digitalWrite(servis,HIGH);
      }
      if (readBT == 'o'){
        stop();
        goto menu;
      }
      goto d;
    }
    if(readBT== 'c'){             //silang(X)
      c:
        readBT=Serial3.read();
          digitalWrite(led,HIGH);
          digitalWrite(pukul1,HIGH);
        if (readBT == 'o'){
          stop();
          goto menu;
         }
      goto c;
    }
    //////////////////////////////////////////
    
     
    
    if(readBT== 'b'){      //lingkaran(o)
    xxxx();
    
    zzz:
    {
    digitalWrite(49, HIGH);
    readBT=Serial3.read();
    if (readBT == 'o'){
          stop();
          goto menu;
         }
    }
    
    goto zzz;
       
    }
    
    //goto b;  
    /*b:
        readBT=Serial3.read();
          digitalWrite(led,HIGH);
          digitalWrite(cock,HIGH);
          delayMicroseconds(3500);
          digitalWrite(servis,HIGH);
       goto b1;
       b1:
         digitalWrite(led,HIGH);
         digitalWrite(servis,HIGH);
        if (readBT == 'o'){
          stop();
          goto menu;
         }
        goto b1;*/
   // }
    //////////////////////////////////////////
//*********************End-pneumatic**************************//  
//*******************STOP*******************************//  
    if(readBT== 'o'){            //L2
      stop_servis();    
    }
    else {
      stop();
      digitalWrite(led,LOW);
      digitalWrite(infra,HIGH);
      digitalWrite(cock,LOW);
      digitalWrite(servis,LOW);
      digitalWrite(pukul1,LOW);
      goto menu;
    }
// ***********************End-tombol-satu******************************* //   
// ***********************tombol-kombinasi****************************** //
          //*******************Run**********************//
           if(readBT== '1'){               //Run-Up
              a1:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                maju(fast);
              if(readBT == 'z'){
                 loop();
              }
              goto a1;
           }
           if(readBT== '2'){               //Run-Down
              a2:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                mundur(fast);
              if(readBT == 'z'){
                 goto menu;
              }
              goto a2;
           }
           if(readBT== '3'){               //Run-Right
              a3:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                kanan(fast);
              if(readBT == 'z'){
                 goto menu;
              }
              goto a3;
           }
           if(readBT== '4'){               //Run-Left
              a4:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                kiri(fast);
              if(readBT == 'z'){
                 goto menu;
              }
              goto a4;
           }
           if(readBT== '5'){               //Run-Up-Right
              a5:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kadep(fast);
              if(readBT == 'z'){
                 goto menu;
              }
              goto a5;
           }
           if(readBT== '6'){               //Run-Up-Left
              a6:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kidep(fast);
              if(readBT == 'z'){
                 goto menu;
              }
              goto a6;
           }
           if(readBT== '7'){               //Run-Down-Right
              a7:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kabel(fast);
              if(readBT == 'z'){
                 goto menu;
              }
              goto a7;
           }
           if(readBT== '8'){               //Run-Down-Left
              a8:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kibel(fast);
              if(readBT == 'z'){
                 goto menu;
              }
              goto a8;
           }
          //*******************End-Run******************//
          //*******************Slow*********************//
          if(readBT== 'r'){               //Slow-Up
              r:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                maju(slow);
              if(readBT == 'z'){
                 goto menu;
              }
              goto r;
           }
           if(readBT== 's'){               //Slow-Down
              s:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                mundur(slow);
              if(readBT == 'z'){
                 goto menu;
              }
              goto s;
           }
           if(readBT== 't'){               //Slow-Right
              t:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                kanan(slow);
              if(readBT == 'z'){
                 goto menu;
              }
              goto t;
           }
           if(readBT== 'u'){               //Slow-Left
              u:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                kiri(slow);
              if(readBT == 'z'){
                 goto menu;
              }
              goto u;
           }
           if(readBT== 'v'){               //Slow-Up-Right
              v:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kadep(slow);
              if(readBT == 'z'){
                 goto menu;
              }
              goto v;
           }
           if(readBT== 'w'){               //Slow-Up-Left
              w:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kidep(slow);
              if(readBT == 'z'){
                 goto menu;
              }
              goto w;
           }
           if(readBT== 'x'){               //Slow-Down-Right
              x:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kabel(slow);
              if(readBT == 'z'){
                 goto menu;
              }
              goto x;
           }
           if(readBT== 'y'){               //Slow-Down-Left
              y:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                ser_kibel(slow);
              if(readBT == 'z'){
                goto menu;
              }
              goto y;
           }
           
           if(readBT== '9'){               //Slow-roatate-Right
              RR:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                rotate_right(slow);
              if(readBT == 'z'){
                goto menu;
              }
              goto RR;
           }
           if(readBT== '0'){               //Slow-Rotate-Left
              RL:
                readBT=Serial3.read();
                digitalWrite(led,HIGH);
                rotate_left(slow);
              if(readBT == 'z'){
                goto menu;
              }
              goto RL;
           }
          //*******************End-Slow*****************//
          if(readBT == 'z'){
            stop_servis();
            digitalWrite(pukul1,LOW);
      	    digitalWrite(enka_2,LOW);
	    digitalWrite(enki_2,LOW);
	    digitalWrite(enka_4,LOW);
	    digitalWrite(enki_4,LOW);
	    digitalWrite(enka_1,LOW);
	    digitalWrite(enki_1,LOW);
	    digitalWrite(enka_3,LOW);
	    digitalWrite(enki_3,LOW);    
            goto menu;}
                
/*              else {
                  stop();
                  digitalWrite(led,LOW);
                  digitalWrite(infra,HIGH);
                  digitalWrite(cock,LOW);
                  digitalWrite(servis,LOW);
                  digitalWrite(pukul1,LOW);
                  goto menu;
              }*/
//********************************************************************** //
goto menu; } 
}

//**************************************************//
void stop(){
        stop_servis();
        digitalWrite(pukul1,LOW);
  	digitalWrite(enka_2,LOW);
	digitalWrite(enki_2,LOW);
	digitalWrite(enka_4,LOW);
	digitalWrite(enki_4,LOW);
	digitalWrite(enka_1,LOW);
	digitalWrite(enki_1,LOW);
	digitalWrite(enka_3,LOW);
	digitalWrite(enki_3,LOW);  
}
