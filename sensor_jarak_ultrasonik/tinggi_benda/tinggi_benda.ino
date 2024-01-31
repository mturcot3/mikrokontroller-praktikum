#include <LiquidCrystal_I2C.h>    //memasukan library LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); //Setting alamat I2C dan ukuran LCD

#define ECHOPIN  12
#define TRIGPIN 13

int Led1 = 2;     //Led1 pada pin digital 0
int Led2 = 4;     //Led2 pada pin digital 1
int Led3 = 7;    //Led3 pada pin digital 2
int buzzer = 9;
float jarak;
float batasJarak=89;
float tinggi;
//objek 55 
void setup() {
  lcd.begin();    //memanggil lcd I2C
  lcd.backlight();
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  delay(2000);
}

void loop() {
  
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  long distance = pulseIn(ECHOPIN, HIGH);
  jarak = (distance * 0.034) / 2.0;
  tinggi= batasJarak-jarak;
  //jarak= (distance/2)/29.1;

  //Mengaktifka backlight LCD
  lcd.setCursor(0, 0);
  lcd.print("Jarak :");
  lcd.setCursor(7, 0);
  lcd.print(jarak);
  lcd.print(" cm  ");
  lcd.setCursor(0, 1);
  lcd.print("Tinggi:");
  lcd.setCursor(7, 1);
  lcd.print(tinggi);
  lcd.print(" cm  ");
  delay(1000);
}
