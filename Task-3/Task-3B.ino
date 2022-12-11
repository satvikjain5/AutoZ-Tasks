#include <Adafruit_LiquidCrystal.h>

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>


const char BUTTON_PIN = 8;
bool pressed = false;
String myStr = " ";

String hexNum;

const byte ROWS = 4; 
const byte COLS = 4; 

char Keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'E','0','F','D'}
};

byte rowPins[ROWS] = {3, 2, 1, 0}; //{R1, R2, R3, R4}
byte colPins[COLS] = {7, 6, 5, 4}; //{C1, C2, C3, C4}

Keypad customKeypad = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 
Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  Wire.begin();
  Serial.begin(9600);
  lcd_1.begin(16, 2);
}
  
void loop()
{    
  char Key = customKeypad.getKey();
  bool currentState = digitalRead(BUTTON_PIN);

  
  
  if(Key)
  {
    if (Key != 'A' and Key != 'B' and Key != 'C' and Key != 'D' and Key != 'E' and Key != 'F') {
    myStr = myStr + Key;
    
    }
    hexNum = DecToHex(myStr);
    }
  if (currentState == pressed)
  {
    lcd_1.setCursor(0,0);
    lcd_1.print("Decimal: ");
    lcd_1.setCursor(8,0);
    lcd_1.setBacklight(1);
    lcd_1.print(myStr);
    lcd_1.setCursor(0,1);
    lcd_1.print("Hex: ");
    lcd_1.setCursor(4,1);
    lcd_1.print(hexNumber);
 
    while (digitalRead(BUTTON_PIN) == pressed)
    {
    }
  }
}

String DecToHex(String n1){
  String hexnum;
  long remainder;
  long n = n1.toInt();
 
  while (n > 0) {
 
    remainder = n % 16;
    n = n / 16;
 
    if (remainder < 10) {
      hexnum = String(remainder) + hexnum;
    }
 
    else {
     
      switch (remainder) {
     
        case 10:
          hexNum = "A" + hexnum;
          break;
 
        case 11:
          hexNum = "B" + hexnum;
          break;
 
        case 12:
          hexNum = "C" + hexnum;
          break;
 
        case 13:
          hexNum = "D" + hexnum;
          break;
 
        case 14:
          hexNum = "E" + hexNum;
          break;
 
        case 15:
          hexNum = "F" + hexnum;
          break;
 
      }
 
    }
 
  }
 
  return hexnum;
 
}
  
