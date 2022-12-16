#define vin A0
unsigned long R1 = 5010;
unsigned long R2 = 25000;
void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  float digitalVoltage = sensorValue * (5.0/1023.0);
  float inputVoltage = digitalVoltage * (1 + (float(R2)/float(R1)));
  Serial.print("Input voltage = ");
  Serial.println(inputVoltage);
}
