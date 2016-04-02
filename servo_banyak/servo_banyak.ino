//zoomkat 11-22-12 simple delimited ',' string parse 
//from mySerial port input (via mySerial monitor)
//and print result out mySerial port
//multi servos added 

#include <SoftwareSerial.h>

SoftwareSerial mySerial (10, 11);

String readString;
#include <Servo.h> 
Servo myservoa, myservob, myservoc, myservod, myservoe;  // create servo object to control a servo 

void setup() {
  mySerial.begin(9600);

  //myservoa.writeMicroseconds(1500); //set initial servo position if desired

  myservoa.attach(9);  //the pin for the servoa control
  myservob.attach(7);  //the pin for the servoa control
  myservoc.attach(6);  //the pin for the servob control
  myservod.attach(5);  //the pin for the servoc control
  myservoe.attach(4);  //the pin for the servod control 
  //mySerial.println("multi-servo-delimit-test-dual-input-11-22-12"); // so I can keep track of what is loaded
     myservoa.write(15); 
     myservob.write(110);
     myservoc.write(180);
     myservod.write(90);
     myservoe.write(137);
     delay(500);
}

void loop() {

  //expect single strings like 700a, or 1500c, or 2000d,
  //or like 30c, or 90a, or 180d,
  //or combined like 30c,180b,70a,120d,

  if (mySerial.available())  {
    char c = mySerial.read();  //gets one byte from mySerial buffer
    if (c == 's') {
      if (readString.length() >1) {
        mySerial.println(readString); //prints string to mySerial port out

        int n = readString.toInt();  //convert readString into a number

        // auto select appropriate value, copied from someone elses code.
        if(n >= 500)
        {
          mySerial.print("writing Microseconds: ");
          mySerial.println(n);
          if(readString.indexOf('a') >0) myservoa.writeMicroseconds(n);
          if(readString.indexOf('b') >0) myservob.writeMicroseconds(n);
          if(readString.indexOf('c') >0) myservoc.writeMicroseconds(n);
          if(readString.indexOf('d') >0) myservod.writeMicroseconds(n);
          if(readString.indexOf('e') >0) myservoe.writeMicroseconds(n);
        }
        else
        {   
          mySerial.print("writing Angle: ");
          mySerial.println(n);
          if(readString.indexOf('a') >0) myservoa.write(n);
          if(readString.indexOf('b') >0) myservob.write(n);
          if(readString.indexOf('c') >0) myservoc.write(n);
          if(readString.indexOf('d') >0) myservod.write(n);
          if(readString.indexOf('e') >0) myservoe.write(n);
        }
         readString=""; //clears variable for new input
      }
    }  
    else {     
      readString += c; //makes the string readString
    }
  }
}


