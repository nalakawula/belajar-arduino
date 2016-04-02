/* ///////////////////////
  Bismillahirrohmanirohim
  JUARA KRN 2015 11-14 Juni 2015
  Goto Abu Robocon 2015
*/ //////////////////////
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
  pinMode(13, OUTPUT);
  error = ps2x.config_gamepad(8,7,6,9, true, true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
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
    }
    

    /*L1 L2 L3 R1 R2 R3*/
    if (ps2x.Button(PSB_L2)){
      mySerial.print('o');
      digitalWrite(13,HIGH);
    }
    if (ps2x.Button(PSB_R2)){
      mySerial.print('e');
      digitalWrite(13,HIGH);
    }
    if (ps2x.Button(PSB_L1)){
      //mySerial.print('p');
      mySerial.print('2');      
      digitalWrite(13,HIGH);
    }
    if (ps2x.Button(PSB_R1)){
      //mySerial.print('f');
      mySerial.print('1');
      digitalWrite(13,HIGH);
    }
    
    else {
      mySerial.print('z');
      digitalWrite(13,LOW);
     }
    /*SILANG KOTAK SEGITIGA BUNDAR*/
    if (ps2x.Button(PSB_GREEN)) { //segitiga
      mySerial.print('a');
      digitalWrite(13,HIGH);
    }
    
    if (ps2x.Button(PSB_RED)) {  //LINGKARAN
       mySerial.print('b');
       digitalWrite(13,HIGH);
    }
    /////////////////////////////////
    if (ps2x.Button(PSB_BLUE)) { //SILANG
      mySerial.print('c');
      digitalWrite(13,HIGH);
    }
    
    if (ps2x.Button(PSB_PINK)) { //KOTAK
       mySerial.print('d');
       digitalWrite(13,HIGH);
    }
    
    //if(ps2x.ButtonPressed(PSB_GREEN))  //SGTIGA
     //Serial.println("Triangle pressed");
    
    /*ANALOG*/
    if (ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 0 ) //up
    {
      
      mySerial.print('g');
     /* Serial.print("UPpp");
      digitalWrite(13,HIGH);*/
      
      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }

    }


    if (ps2x.Analog(PSS_LX) == 128 && ps2x.Analog(PSS_LY) == 255 ) //down
    {
      mySerial.print('k');
     

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }

    }
    if (ps2x.Analog(PSS_LX) == 255 && ps2x.Analog(PSS_LY) == 128 ) //kanan
    {
      mySerial.print('i');
      

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }
    }

    if (ps2x.Analog(PSS_LX) == 0 && ps2x.Analog(PSS_LY) == 128 ) //kiri
    {
      mySerial.print('m');
      

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }
    }

    /*AKHIR ANALOG*/

    /*SERONG*/
    if (ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) < 128 ) //upleft
    {
      mySerial.print('n');

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }
    }
    if (ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) > 128 ) //downright
    {
      mySerial.print('j');

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }
    }

    if (ps2x.Analog(PSS_LX) > 128 && ps2x.Analog(PSS_LY) < 128 ) //upright
    {
      mySerial.print('h');

      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }
    }

    if (ps2x.Analog(PSS_LX) < 128 && ps2x.Analog(PSS_LY) > 128 ) //downleft
    {
      mySerial.print('l');
      
      if (ps2x.Button(PSB_BLUE)) { //SILANG
        mySerial.print('c');
      }

      if (ps2x.Button(PSB_PINK)) { //KOTAK
        mySerial.print('d');
      }

      if (ps2x.Button(PSB_RED)) {  //LINGKARAN
        mySerial.print('b');
      }
      if (ps2x.Button(PSB_GREEN)) {  //segitiga
        mySerial.print('a');
      }
    }    
    /*ANALOG SEBELAH KANAN*/
    if (ps2x.Analog(PSS_RX) == 255 && ps2x.Analog(PSS_RY) == 128 ){ //PUTAR KANAN
      mySerial.write('1');  
      Serial.println("1");
     }  
    if (ps2x.Analog(PSS_RX) == 0 && ps2x.Analog(PSS_RY) == 128 ){ //PUTAR KIRI
      mySerial.write('2');  
      Serial.println("2");
    }
    if (ps2x.Analog(PSS_RX) == 128 && ps2x.Analog(PSS_RY) == 0 ){ //atas
      mySerial.write('3');
      Serial.println("3");
    }
    if (ps2x.Analog(PSS_RX) == 128 && ps2x.Analog(PSS_RY) == 255 ){ //bawah
      mySerial.write('4');
       Serial.println("4");
    }
    
    }





