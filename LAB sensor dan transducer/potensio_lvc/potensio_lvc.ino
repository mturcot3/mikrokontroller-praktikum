#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int potensioPin = A0;
const int LEDPin = 9;

int nilaiPotensio = 0;

void setup() {
  lcd.begin(16, 2);                      // inisialisasi lcd
  lcd.print("RG TECH");           //menulis "RG TECH" di baris pertama
  lcd.setCursor(0, 1);                 // memindahkan kursor ke baris ke dua
  lcd.print ("Belajar Arduino"); // menulis "Belajar Arduino" di baris ke dua
  delay(2000);                            // tunda proses program selama 2000mSec atau 2 detik
  lcd.setCursor (0, 0);                 // memindahkan kursor ke baris pertama
  lcd.print ("Potensiometer:  "); // menulis "Potensiometer" pada baris pertama
  lcd.setCursor(0, 1);                  // memindahkan kursor ke baris ke dua
  lcd.print ("                ");           // sebagai clear screen pada baris ke dua
  Serial.begin(9600);
}

void loop()
{
  nilaiPotensio = analogRead(potensioPin);
  lcd.setCursor (0, 1);
  lcd.print(nilaiPotensio); // menampilkan nilai parameter di dalam kurung
  delay(20);
}
