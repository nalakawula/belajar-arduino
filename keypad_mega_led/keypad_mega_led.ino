//kontrol led menggunakan keypad 4x4
//sumar
#include <Keypad.h>

const byte numRows= 4; //row keypad
const byte numCols= 4; //kolom keyapd

//keymap
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//koneksi kolom dan row ke arduino, 1-4 ke 30-33. 5-8 ke 50-53.
byte rowPins[numRows] = {30,31,32,33}; //Rows 0 to 3
byte colPins[numCols]= {50,51,52,53}; //Columns 0 to 3

//inisialisasi class keypad
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
Serial.begin(9600);
pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
}


void loop()
{
char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY)

{
	
	switch (keypressed) {
	    case '*':
	      digitalWrite(23, HIGH);
	      break;
	    case '#':
	      digitalWrite(23, LOW);
	      break;
	    default:
	      Serial.println(keypressed);
       
	}
  
}
}

