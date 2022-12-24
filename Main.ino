#include <LiquidCrystal.h>
#define trigPin 3
#define echoPin 2
float change_in_time, distance;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  lcd.begin(16, 2);
  lcd.print("Length=");
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  change_in_time = pulseIn(echoPin, HIGH);
  distance = (change_in_time / 2) * 0.0343;
  Serial.print("Distance=");
  Serial.print(distance);
  Serial.print("cm\n");
  lcd.setCursor(7, 0);
  lcd.print(distance);
  lcd.print(" cm");
  delay(2000);
}
