#include <Usb.h>
#include <USBJoystick.h>

USBJoystick gamepad;

const uint8_t LED = 2;


void buttonValueDidChangeCallback(uint8_t button, uint8_t valueb)
{
    Serial.print("buttonValueDidChangeCallback: ");
    Serial.print(button, DEC);
    Serial.print(": ");
    Serial.print(valueb, DEC);
    Serial.println("");
    
      
    if ((button == 9 || button == 10 || button == 11 || button == 12) && valueb == 0) {
      digitalWrite(LED, 0);
    }
    
    if (button == 9 && valueb == 1) {
      digitalWrite(LED, 1);
    }
    
    if (button == 10 && valueb == 1) {
      digitalWrite(LED, 1);
    }
    
    if (button == 11 && valueb == 1) {
      digitalWrite(LED, 1);
    }
    
    if (button == 12 && valueb == 1) {
      digitalWrite(LED, 1);
    }


    /*
    else {
      digitalWrite(LED, 0);
    }
    
    */
}

/*      
    void stickValueDidChangeCallback(uint8_t stick, uint8_t values)
{
    Serial.print("stickValueDidChangeCallback: ");
    Serial.print(stick, DEC);
    Serial.print(": ");
    Serial.print(values, DEC);
    Serial.println("");
    
    if (stick == 0  && values == 0) {
      digitalWrite(LED, 1);
    }
    
    else{
      digitalWrite(LED, 0);
    }

}
*/


void setup() {
  Serial.begin(9600);
  gamepad.init();
  pinMode(LED, OUTPUT);
  
  
}

void loop() {
  gamepad.run();
  gamepad.setButtonValueDidChangeCallback(buttonValueDidChangeCallback);
  //gamepad.setStickValueDidChangeCallback(stickValueDidChangeCallback);
  
}
