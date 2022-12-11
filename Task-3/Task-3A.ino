
#include <Adafruit_LiquidCrystal.h>

#include <Keypad.h>
#include <Wire.h>

const char BUTTON_PIN = 8;
bool pressed = false;
String myStr = " ";
String decimalNum;
long decimalNumber;
String hexNumber;


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
    myStr = myStr + Key;
    delay(100);
  }
  if (currentState == pressed)
  {
    lcd_1.setCursor(0,0);
    lcd_1.print("Hex: ");
    lcd_1.setCursor(5,0);
    lcd_1.setBacklight(1);
    lcd_1.print(myStr);
 
    while (digitalRead(BUTTON_PIN) == pressed)
    {
    }
  }
}
