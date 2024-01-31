#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int potensioPin = A1;
const int LEDPin = 9;
int nilaiPotensio = 0;

void setup() {
  lcd.begin();         // inisialisasi lcd
  lcd.print ("Potensiometer:  ");    // menulis "Potensiometer" pada baris pertama
  lcd.setCursor(0, 1);      // memindahkan kursor ke baris ke dua
  lcd.print ("                ");     // sebagai clear screen pada baris ke dua
  Serial.begin(9600);
}
void loop()
{
  nilaiPotensio = analogRead(potensioPin);
  lcd.setCursor (0, 1);
  lcd.print(nilaiPotensio); // menampilkan nilai parameter di dalam kurung
  delay(200);
}
