#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

float pinPot = A1;
float nilaiPotensio = 0;

void setup() {
  lcd.begin();
  lcd.print ("Potensiometer:  "); // menulis "Potensiometer" pada baris pertama
  lcd.setCursor(0, 1);                  // memindahkan kursor ke baris ke dua
           
  Serial.begin(9600);
}

void loop()
{
  float nilaisensor= analogRead(pinPot);
 
  float s = (nilaisensor * 6.0) / 1023.0;
  Serial.println(s);
  lcd.setCursor (0, 1);
  lcd.print(s); // menampilkan nilai parameter di dalam kurung
  lcd.setCursor(6, 1);
  lcd.print ("cm");
  delay(200);
  lcd.clear();
}
