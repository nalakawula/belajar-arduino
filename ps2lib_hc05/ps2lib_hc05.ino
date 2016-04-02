#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

#include <PS2X_lib.h>

PS2X ps2x;
int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup(){
 Serial.begin(57600);
 mySerial.begin(9600);
 error = ps2x.config_gamepad(8,9,7,12, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
 if(error == 0){
   Serial.println("Found Controller, configured successful");
   Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
   Serial.println("holding L1 or R1 will print out the analog stick values.");
   Serial.println("Go to www.billporter.info for updates and to report bugs.");
 }
   
  else if(error == 1)
   Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if(error == 2)
   Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if(error == 3)
   Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
   //Serial.print(ps2x.Analog(1), HEX);
   
   type = ps2x.readType(); 
     switch(type) {
       case 0:
        Serial.println("Unknown Controller type");
       break;
       case 1:
        Serial.println("DualShock Controller Found");
       break;
     }
}
//***************************************************************************************************//
void loop(){

  if(error == 1) //skip loop if no controller found
  return; 
///////////////////////////////////////////////////////////////////////
 //else { //DualShock Controller
 if(type == 1) { //DualShock Controller  
    ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
    
    if(ps2x.Button(PSB_START))                   //will be TRUE as long as button is pressed
         Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
         Serial.println("Select is being held");
//************************************//ARAH
      if(ps2x.Button(PSB_PAD_UP)) {         //will be TRUE as long as button is pressed
        mySerial.print('g');
       /*Serial.print("Up held this hard: ");
       Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);*/
      }
      if(ps2x.Button(PSB_PAD_RIGHT)){
        mySerial.print('i');
       /*Serial.print("Right held this hard: ");
       Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);*/
      }
      if(ps2x.Button(PSB_PAD_LEFT)){
        mySerial.print('m');
/*       Serial.print("LEFT held this hard: ");
       Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);*/
      }
      if(ps2x.Button(PSB_PAD_DOWN)){
        mySerial.print('k');
/*       Serial.print("DOWN held this hard: ");
       Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);*/
      }   
//******************************************************// 
//      vibrate = ps2x.Analog(PSAB_BLUE);        //this will set the large motor vibrate speed based on 
                                              //how hard you press the blue (X) button    
    if (ps2x.NewButtonState()){               //will be TRUE if any button changes state (on to off, or off to on)
        if(ps2x.Button(PSB_L3))
         Serial.println("L3 pressed");
        if(ps2x.Button(PSB_R3))
         Serial.println("R3 pressed");
        if(ps2x.Button(PSB_L2))
         mySerial.print('o');
         //Serial.println("L2 pressed");
        if(ps2x.Button(PSB_R2))
         Serial.println("R2 pressed");
         
     if(ps2x.Button(PSB_L1))
      Serial.println("L1");
     if(ps2x.Button(PSB_R1))
      Serial.println("R1");
      
      
                
    }   
    else{
      mySerial.print('z');
    }
     if(ps2x.ButtonPressed(PSB_BLUE)){   //X
         //Serial.println("Croos pressed");
         mySerial.print('c');
     }
     if(ps2x.Button(PSB_PINK)){   //KOTAK
         //Serial.println("SQUARE pressed");
         mySerial.print('d');
     }
     if(ps2x.Button(PSB_RED)){    //O LINGKAR
         //Serial.println("Circle Rotate pressed");
         mySerial.print('b');
     }
        /*if(ps2x.ButtonPressed(PSB_GREEN))  //SGTIGA
         Serial.println("Triangle pressed");
       // if(ps2x.ButtonPressed(PSB_RED))    //O LINGKAR
       //  Serial.println("Circle Rotate pressed");
         //mySerial.print('b');
        if(ps2x.ButtonPressed(PSB_BLUE))   //X
         //Serial.println("Croos pressed");
         mySerial.print('c');
        if(ps2x.ButtonPressed(PSB_PINK))   //KOTAK
         //Serial.println("SQUARE pressed");
         mySerial.print('d');
        else
         mySerial.print('z');
        */
///////**********************************************************analog
       if(ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 0 )  //up
          mySerial.print('g');
          //Serial.println("up-----------");
        if(ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 255 )//down
          mySerial.print('k');
          //Serial.println("down---------");
        if(ps2x.Analog(PSS_LX) == 255 && ps2x.Analog(PSS_LY) == 128 )//kanan
          //Serial.println("right------");
          mySerial.print('i');
        if(ps2x.Analog(PSS_LX) == 0 && ps2x.Analog(PSS_LY) == 128 )//kiri
          //Serial.println("left-----");
          mySerial.print('m');
///////////////////////////////////////////// SERONG-----------       
        if(ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) < 128 )//upleft
          //Serial.println("upleft-------");
          mySerial.print('n');
        if(ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) > 128 )//downright
          //Serial.println("downright----");
          mySerial.print('j');
        if(ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) < 128 )//upright
          //Serial.println("upright------");
          mySerial.print('h');
        if(ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) > 128 )//downleft
          //Serial.println("downleft-----");
          mySerial.print('l');
//////////////////////////////////////slow--------------------------------------    
    /*if(ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) > 128 && ps2x.Button(PSB_R2))//downleft slow
          //Serial.println("downleft-----slowww");
       mySerial.print('8');*/
       
      /* 
        if(ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 0 && ps2x.Button(PSB_R2) )  //up
          mySerial.print('r');
          //Serial.println("up-----------");
        if(ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 255 && ps2x.Button(PSB_R2) )//down
          mySerial.print('s');
          //Serial.println("down---------");
        if(ps2x.Analog(PSS_LX) == 255 && ps2x.Analog(PSS_LY) == 128 && ps2x.Button(PSB_R2) )//kanan
          //Serial.println("right------");
          mySerial.print('t');
        if(ps2x.Analog(PSS_LX) == 0 && ps2x.Analog(PSS_LY) == 128 && ps2x.Button(PSB_R2) )//kiri
          //Serial.println("left-----");
          mySerial.print('u');
///////////////////////////////////////////// SERONG-----------       
        if(ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) < 128 && ps2x.Button(PSB_R2) )//upleft
          //Serial.println("upleft-------");
          mySerial.print('w');
        if(ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) > 128 && ps2x.Button(PSB_R2) )//downright
          //Serial.println("downright----");
          mySerial.print('x');
        if(ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) < 128 && ps2x.Button(PSB_R2) )//upright
          //Serial.println("upright------");
          mySerial.print('v');
        if(ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) > 128 && ps2x.Button(PSB_R2) )//downleft
          //Serial.println("downleft-----");
          mySerial.print('y');*/
/////////////////////////////////////////////////-----------------------    rotatte slow
        /*if(ps2x.ButtonPressed(PSB_RED) && ps2x.Button(PSB_R2))    //O LINGKAR
         Serial.println("rotate slow o");
         mySerial.print('9');
        if(ps2x.ButtonPressed(PSB_PINK) && ps2x.Button(PSB_R2))   //KOTAK
         Serial.println("rotateslowkotak");
         mySerial.print('0');*/
//*****************************************--------------analog right----------------*************************/
        if(ps2x.Analog(PSS_RX) == 255 && ps2x.Analog(PSS_RY) == 128 )//kanan
          //Serial.println("right------");
          mySerial.write('9');
        if(ps2x.Analog(PSS_RX) == 0 && ps2x.Analog(PSS_RY) == 128 )//kiri
          //Serial.println("left-----");
          mySerial.write('0');
        //else
     // mySerial.print('z');

 }
    
// delay(10);    
}

