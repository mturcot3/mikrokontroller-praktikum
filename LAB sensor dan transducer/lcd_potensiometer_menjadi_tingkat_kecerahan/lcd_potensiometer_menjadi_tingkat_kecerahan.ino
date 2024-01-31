#include <LiquidCrystal_I2C.h>     
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pinapi = 4 ;
int led = 7 ;
int api = HIGH;
//float tegangan;
//int adc;
//int kecerahan;
//int nilaildr;
//const int LED1 = 2;
//const int LED2 = 4;
//int buzzer = 7;

void setup() {
  lcd.begin();
  pinMode(led, OUTPUT);
  pinMode(pinapi, INPUT);
  //pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  api = digitalRead(pinapi);
  //nilaildr = 1023 - adc;
  //tegangan = (adc*5.0)/1023;
  //kecerahan = map(adc,0,1023,100,0);
  if(api==HIGH)
  {
  digitalWrite(led,HIGH);
   lcd.setCursor(0, 0);
  lcd.print("Terdeteksi");
  delay(100);
  }
  
  else {
  digitalWrite(led,LOW);
  lcd.setCursor(0,1);
  lcd.print("Tidak Terdeteksi");
  delay(100);
}

  delay(100);
  lcd.clear();
  }