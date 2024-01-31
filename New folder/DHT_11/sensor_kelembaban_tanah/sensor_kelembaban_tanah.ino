#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal_I2C.h>       //memasukan library LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);  //Setting alamat I2C dan ukuran LCD
int sensorPin = A0;  // pin sensor
const int LED1 = 2;

int nilaiSensor;
int lembab;
float tegangan;
void setup() {
  lcd.begin();//memanggil lcd I2C
  lcd.backlight();
  pinMode(sensorPin, INPUT);
  pinMode(LED1, OUTPUT);

}
void loop() {

  nilaiSensor = analogRead(sensorPin);  //Nilai Kondisi adalah nilai pembacan nilai pin Pot tempat INPUT Potensiometer
  

  int nilaiRes = 1023 - nilaiSensor;
  
  //lembab =((nilaiRes*1023)/100);
  lembab = map(nilaiRes, 0, 1023, 0, 100);
  //tegangan = map(nilaiRes, 0, 1023, 0, 5);
  lcd.setCursor(0, 0);
  lcd.print("Tingkat");            // Menampilkan data kelembaban (%) di LCD
  lcd.setCursor(0, 1);
  lcd.print("lembab:");           // Menampilkan data kelembaban (%) di LCD
  

  if (lembab >= 60){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED1, LOW);
    lcd.setCursor(8,1);
  lcd.println(" basah  ");
    delay(100);
  }
  else if (lembab > 25 && lembab < 60 ){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED1, LOW);
    lcd.setCursor(8,1);
  lcd.println(" sedang  ");
    delay(100);
  }
  else if (lembab < 25){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED1, HIGH);
    lcd.setCursor(8,1);
  lcd.println(" kering  ");

     delay(100);
  }
  
  delay(1000);
  lcd.clear();

}
