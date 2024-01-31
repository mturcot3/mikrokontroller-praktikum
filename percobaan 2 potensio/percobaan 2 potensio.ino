//Menampilkan nilai tengangan potensiometer di LCD I2C
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

float pinPot = A1;
float nilaiPotensio = 0;

void setup() {
lcd.begin();
lcd.print ("Potensiometer:  "); 
lcd.setCursor(0, 1);                           
Serial.begin(9600);
}
void loop()
{
float nilaisensor = analogRead(pinPot);
float teg = nilaisensor * (5.0 / 1023.0);
Serial.println(teg);
lcd.setCursor (0, 1);
lcd.print(teg); 
lcd.setCursor(6, 1);
lcd.print ("Volt");
delay(1000);
}

//Menampilkan tingkat kecerahan LED di LCD I2C
/*#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pinPot = A1;
int nilaiPot = 0;
int led = 11;
void setup() {
lcd.begin();
pinMode(A1, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);
}
void loop(){
lcd.setCursor(0, 0); 
lcd.print ("Brightness :  "); 
lcd.setCursor(5, 1);
lcd.print ("%"); 
nilaiPot= analogRead(pinPot);
nilaiPot = map(nilaiPot, 0, 1023, 0, 255);
int pwm = (nilaiPot * 100) / 255;
Serial.println(pwm);
analogWrite(led, nilaiPot);
lcd.setCursor (0, 1);
lcd.print(pwm);
delay (1000);
}
*/