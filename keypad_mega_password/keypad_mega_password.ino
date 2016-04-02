#include <Password.h>
#include <Keypad.h>


Password password = Password("ABCD");

const byte numRows = 4;
const byte numCols = 4;

char keys[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {30, 31, 32, 33};
byte colPins[numCols] = {50, 51, 52, 53};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, numRows, numCols );

void setup() {
  Serial.begin(9600);
  Serial.write(254);
  Serial.write(0x01);
  delay(200);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
}

void loop() {
  keypad.getKey();
}

void keypadEvent(KeypadEvent eKey) {
  switch (keypad.getState()) {
    case PRESSED:

      Serial.print("Enter: ");
      Serial.println(eKey);
      delay(10);

      Serial.write(254);

      switch (eKey) {
        case '*': checkPassword(); delay(1); break;

        case '#': password.reset(); delay(1); break;

        default: password.append(eKey); delay(1);
      }
  }
}
void checkPassword() {

  if (password.evaluate()) { //if password is right open box

    Serial.println("Accepted");
    Serial.write(254);delay(10);

    digitalWrite(22, HIGH);//turn on
    delay(700); //wait 5 seconds
    digitalWrite(22, LOW);// turn off


  }

  else {
    Serial.println("Denied"); //if passwords wrong keep box locked
    Serial.write(254);delay(10);

    digitalWrite(23, HIGH); //turn on
    delay(700); //wait 5 seconds
    digitalWrite(23, LOW);//turn off

  }
}

