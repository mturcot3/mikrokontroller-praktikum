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
  teg = nilaisensor * 6.0 / 1023;
  lcd.setCursor(0, 0);
  lcd.print("jarak potensio");
  lcd.setCursor(6, 1);                  // memindahkan kursor ke baris ke du
  lcd.print ("cm"); // menulis "Potensiometer" pada baris pertama
  lcd.setCursor (0, 1);
  lcd.print(teg); // menampilkan nilai parameter di dalam kurung
  
  delay(1000);
  lcd.clear();
}
