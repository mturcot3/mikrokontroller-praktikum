//Menampilkan nilai potensiometer geser di LCD I2C dengan Arduino UNO
/*#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int potPin = A3;
int nilaisensor;
int teg;

void setup() {
  lcd.begin();
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop()
{ 
nilaisensor = analogRead(potPin);
  teg = nilaisensor * 6.0 / 1023;
  lcd.setCursor(0, 0);
  lcd.print("jarak potensio");
  lcd.setCursor(6, 1);          
  lcd.print ("cm"); 
  lcd.setCursor (0, 1);
  lcd.print(teg); 
  
  delay(1000);
  lcd.clear();
}
*/
//Menampilkan nilai potensiometer putar di LCD I2C dengan Arduino UNO
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int potPin = A3;
int nilaisensor;
int teg;

void setup() {
  lcd.begin();
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  nilaisensor = analogRead(potPin);
  teg = nilaisensor * 300.0 / 1023;
  lcd.setCursor(0, 0);
  lcd.print("sudut potensio");
  lcd.setCursor(6, 1);       
  lcd.print ("derajat"); 
  lcd.setCursor (0, 1);
  lcd.print(teg); 
  delay(1000);
  lcd.clear();
}
/*
const int LED = 11;
int input = 0;
int pot = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // membaca input dari pin A0:
  input = analogRead(A0);
  // mengubah range analog(0-1023) ke range PWM(0-255)
  pot = map(input, 0, 1023, 0, 255);
  // menampilkan nilai:
  Serial.println(pot);
  // mengatur kecerahan LED
  
  analogWrite(LED,pot);
  // delay sedikit untuk memperlancar kerja program
  delay(10); 
}
*/