// Smart Room Automation

int ldrPin = A0;      // LDR connected to A0
int pirPin = 2;       // PIR connected to D2
int ledPin = 8;       // LED connected to D8
int buzzerPin = 9;    // Buzzer connected to D9

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int lightValue = analogRead(ldrPin);
  int motion = digitalRead(pirPin);

  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print("  Motion: ");
  Serial.println(motion);

  if (lightValue < 500 && motion == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}