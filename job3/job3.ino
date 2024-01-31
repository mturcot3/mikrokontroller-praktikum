#include <LiquidCrystal.h>
LiquidCrystal lcd(10,8,3,2,1,0);
void setup() {
pinMode(A0,INPUT);
lcd.begin(16, 2);
}
void loop() {
lcd.setCursor(0,0);
lcd.print(analogRead(A0));
}
