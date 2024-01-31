#include <LiquidCrystal_I2C.h>     
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ldr = A3;
float tegangan;
int adc;
int kecerahan;
int nilaildr;
const int LED1 = 2;
const int LED2 = 4;
int buzzer = 7;

void setup() {
  lcd.begin();
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  adc = analogRead(ldr);
  nilaildr = 1023 - adc;
  tegangan = (adc*5.0)/1023;
  kecerahan = map(adc,0,1023,100,0);

  lcd.setCursor(0, 1);
  lcd.print("Tingkat=");
  lcd.setCursor(0,0);
  lcd.print("Kecerahan= ");
  lcd.print(kecerahan);
  lcd.setCursor(15,0);
  lcd.print("%");
  delay(100);

  if (kecerahan >= 60){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(8,1);
  lcd.println(" JERNIH  ");
    delay(100);
  }
  else if (kecerahan > 35 && kecerahan < 60 ){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(8,1);
  lcd.println(" KERUH  ");
    delay(100);
  }
  else if (kecerahan < 35){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
      digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(8,1);
  lcd.println(" KOTOR  ");

     delay(100);
  }
  
  delay(1000);
  lcd.clear();

  }
