#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int led = 11; //deklarasi pin led
int pinPot = A1; //deklarasi pin analog yang terhubung dengan potensio
int nilaiPot = 0; // variabel untuk menyimpan data potensio
     
void setup() { 
  lcd.begin();
  lcd.print ("Potensiometer:  "); // menulis "Potensiometer" pada baris pertama
  lcd.setCursor(0, 1);                  // memindahkan kursor ke baris ke dua
  lcd.backlight();
  pinMode(led, OUTPUT); // Mengatur pin 13 untuk output lampu LED
  Serial.begin(9600); //inisialisasi komunikasi serial pada baudrate 9600
} 

void loop() { 
  int value = analogRead(pinPot); // read of potentiometer value
  int n = map(value, 0, 1023, 0, 255);
  Serial.println(n);
  lcd.setCursor(0,1);
  lcd.print(n);
  lcd.setCursor(7,0);
  lcd.print(value);

  delay(200);
  lcd.clear();

}
