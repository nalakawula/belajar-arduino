//  
//    This is a sound trigger for Arduino using simple Piezo 
//    as sound sensor, it is quick and dirty, but highly sensitive
//    device that can detect a moderate finger snap in 3 ft
//    
//    Just connect one terminal of piezo to A0 and the other to Gnd
//
//    You can use a photodiode with large sensing area to detect
//    lightning strikes.
//
//    Just connect the positive (photodiode) terminal to A0 and negative terminal
//    to Gnd
//
//    Copyright (c) 2013 Peter Y Lin (a.k.a MJKZZ)
// 
//    Permission is hereby granted, free of charge, to any person
//    obtaining a copy of this software and associated documentation
//    files (the "Software"), to deal in the Software without
//    restriction, including without limitation the rights to use,
//    copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the
//    Software is furnished to do so, subject to the following
//    conditions:
// 
//    This permission notice shall be included in all copies or 
//    substantial portions of the Software.
// 
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//    OTHER DEALINGS IN THE SOFTWARE.
//
#include <avr/io.h>
#include <avr/interrupt.h>

#define    FLASH_PIN      13
#define    SOUND_PIN      A0

#define    TIMEOUT        100  // 100 milliseconds
#define    THRESHHOLD     1 

void setup()
{
  Serial.begin(115200);
  
  // make flash trigger pin output
  pinMode(FLASH_PIN, OUTPUT);
  // keep flash trigger pin low
  digitalWrite(FLASH_PIN, LOW);
}

volatile int v1 = 0;
volatile int v2 = 0;
volatile int to = 0;

void loop()
{
  // start analog read
  v1 = analogRead(SOUND_PIN);
  while(1)
  {
    // acquire again
    v2 = analogRead(SOUND_PIN); 
    
    // if difference between two analog read exceeds threshhold, 
    // and it has been timed out since last trigger,
    // then trigger flash
    if (abs(v1 - v2) > THRESHHOLD && to == 0)
    {
      // debug only, you can remove it 
      Serial.println(abs(v1 - v2), DEC);
      //Serial.println(v2, DEC);
      
      // *** edit your code to insert time delay here ***
      
      // trigger flash
      digitalWrite(FLASH_PIN, HIGH);
      // keep flash trigger high for 1ms
      delay(1000);   
      // done triggering, reset back   
      digitalWrite(FLASH_PIN, LOW);

      // set timeout value to prevent multiple triggering
      // unit is number of milliseconds
      to = TIMEOUT;
    }
    v1 = v2;
    // decrease timeout value 
    if (to)
    {
      to--;
      delay(1);
    }
  }
}
