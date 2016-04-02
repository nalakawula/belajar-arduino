#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

#include <PS2X_lib.h>

PS2X ps2x;
int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {
  Serial.begin(57600);
  mySerial.begin(9600);
  error = ps2x.config_gamepad(8, 9, 7, 12, true, true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
  }
}


void loop() {

  if (error == 1) //skip loop if no controller found
    return;

  if (type == 1) { //DualShock Controller
    ps2x.read_gamepad();  //read controller and set large motor to spin at 'vibrate' speed

    /*START SELECT*/
    if (ps2x.Button(PSB_START)) //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
    if (ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");
    /*AKHIR START SELECT*/
      

    /*ARAH/
    if (ps2x.Button(PSB_PAD_UP)) { //will be TRUE as long as button is pressed
      mySerial.print('g');
    }

    if (ps2x.Button(PSB_PAD_RIGHT)) {
      mySerial.print('i');
    }

    if (ps2x.Button(PSB_PAD_LEFT)) {
      mySerial.print('m');

    }
    if (ps2x.Button(PSB_PAD_DOWN)) {
      mySerial.print('k');

    }
    /AKHIR ARAH*/
    
     else {
      mySerial.print('z');

    /*L1 L2 L3 R1 R2 R3*/
    if (ps2x.Button(PSB_L2))
      mySerial.print('o');

    //if (ps2x.NewButtonState()) {              //will be TRUE if any button changes state (on to off, or off to on)
    //if(ps2x.Button(PSB_L3))
    //Serial.println("L3 pressed");
    //if(ps2x.Button(PSB_R3))
    //Serial.println("R3 pressed");
    //if (ps2x.Button(PSB_L2))
    //  mySerial.print('o');
    //Serial.println("L2 pressed");
    //if(ps2x.Button(PSB_R2))
    //Serial.println("R2 pressed");

    //if(ps2x.Button(PSB_L1))
    //Serial.println("L1");
    //if(ps2x.Button(PSB_R1))
    //Serial.println("R1");



    //}
    /*AKHIR L1 L2 L3 R1 R2 R3*/
    
    /*SILANG KOTAK SEGITIGA BUNDAR*/
    if (ps2x.Button(PSB_BLUE)) { //SILANG
      mySerial.print('c');
    }
    
    if (ps2x.Button(PSB_PINK)) { //KOTAK
       mySerial.print('c');
    }
    
    if (ps2x.Button(PSB_RED)) {  //LINGKARAN
       mySerial.print('c');
    }
    
    //if(ps2x.ButtonPressed(PSB_GREEN))  //SGTIGA
     //Serial.println("Triangle pressed");
    
    /*ANALOG*/
    if (ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 0 ) //up
    {
      mySerial.print('1');
      
      
      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }
      /*
      /*SLOW/
      if (ps2x.Button(PSB_R2)) {
        mySerial.print('1');
      }
      
      if (ps2x.Button(PSB_R2)) {
        mySerial.print('s');
      }
      
      if (ps2x.Button(PSB_R2)) {
        mySerial.print('t');
      }
      
      if (ps2x.Button(PSB_R2)) {
        mySerial.print('u');
      }
     
      /*AKHIR SLOW*/

    }


    if (ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 255 ) //down
    {
      mySerial.print('2');
     

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }


    }
    if (ps2x.Analog(PSS_LX) == 255 && ps2x.Analog(PSS_LY) == 128 ) //kanan
    {
      mySerial.print('3');
      

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }
    }

    if (ps2x.Analog(PSS_LX) == 0 && ps2x.Analog(PSS_LY) == 128 ) //kiri
    {
      mySerial.print('4');
      

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }
    }

    /*AKHIR ANALOG*/

    /*SERONG*/
    if (ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) < 128 ) //upleft
    {
      mySerial.print('6');

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }
    }


    if (ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) > 128 ) //downright
    {
      mySerial.print('7');

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }
    }

    if (ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) < 128 ) //upright
    {
      mySerial.print('5');

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }
    }

    if (ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) > 128 ) //downleft
    {
      mySerial.print('8');
      
      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('c');
      }
    }
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
    
    /*ANALOG SEBELAH KANAN*/
    if (ps2x.Analog(PSS_RX) == 255 && ps2x.Analog(PSS_RY) == 128 ) //PUTAR KANAN
      mySerial.write('9');
      
    if (ps2x.Analog(PSS_RX) == 0 && ps2x.Analog(PSS_RY) == 128 ) //PUTAR KIRI
      mySerial.write('0');
    /*AKHIR ANALOG SEBELAH KANAN*/
    
   
    }

  }

}

