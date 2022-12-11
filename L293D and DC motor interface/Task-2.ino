int potIN;
#define IN1 5
#define IN2 6
void setup()
{
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
}

void loop()
{
  potIN = analogRead(A0);
  int output = potIN/4;
  analogWrite(IN1,output);
  delay(100);
}
