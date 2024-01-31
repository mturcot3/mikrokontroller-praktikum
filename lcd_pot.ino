#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h>
#include <DHT_U.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

float potensioPin = A1;
float nilaiPotensio = 0;

void setup() {
  lcd.begin();
  lcd.print ("Potensiometer:  "); // menulis "Potensiometer" pada baris pertama
  lcd.setCursor(0, 1);                  // memindahkan kursor ke baris ke dua
  lcd.print ("volt");           // sebagai clear screen pada baris ke dua

  Serial.begin(9600);
}

void loop()
{
  float sensorValue= analogRead(potensioPin);
  float teg = sensorValue * (5.0 / 1023.0);
  Serial.println(teg);
  lcd.setCursor (0, 1);
  lcd.print(teg); // menampilkan nilai parameter di dalam kurung
  lcd.setCursor(7, 1);
  lcd.print ("volt");
  delay(1000);
}
