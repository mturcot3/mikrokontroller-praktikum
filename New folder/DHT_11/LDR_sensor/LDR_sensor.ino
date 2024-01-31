#include <LiquidCrystal_I2C.h>     
LiquidCrystal_I2C lcd(0x27, 16, 2);
int api = A0 ;
int led = 7 ;
int adc;
float tegangan;

void setup() {
  lcd.begin();
 
}

void loop() {
  adc = analogRead(api);
  tegangan = (adc*5.0)/1023;

  lcd.setCursor(0,0);
  lcd.print("ADC=");
  lcd.print(adc);

  lcd.setCursor(0,1);
  lcd.print("Tegangan=");
  lcd.print(tegangan);
  lcd.setCursor(15,1);
  lcd.print("V");
  delay(100);
  lcd.clear();
  
 
}
