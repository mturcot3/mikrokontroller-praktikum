#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pintriger = 13;
const int pinecho = 12;

long duration;
int distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
   
  pinMode(pintriger, OUTPUT);
  pinMode(pinecho, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pintriger,LOW);
  delayMicroseconds(2);

  digitalWrite(pintriger,HIGH);
  delayMicroseconds(10);
  digitalWrite(pintriger,LOW);

  duration = pulseIn(pinecho,HIGH);
  distanceCm = duration*0.034/2;
  distanceInch = duration*0.0133/2;

  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(distanceCm);
  lcd.print("cm");
  delay(5);
  lcd.setCursor(0,1);
  lcd.print("Jarak: ");
  lcd.print(distanceInch);
  lcd.print("inch");
  delay(5);
}
