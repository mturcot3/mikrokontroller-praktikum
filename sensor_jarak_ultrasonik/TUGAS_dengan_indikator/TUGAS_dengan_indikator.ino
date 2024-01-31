#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 13;
const int echoPin = 12;
const int LED1 = 2;
const int LED2 = 4;
const int LED3 = 7; 
const int buzzer = 9;
long durasi;
int jarak;

void setup() {
lcd.begin();
pinMode(trigPin, OUTPUT); 
pinMode(LED1, OUTPUT); 
pinMode(LED2, OUTPUT); 
pinMode(LED3, OUTPUT); 
pinMode(buzzer, OUTPUT);
pinMode(echoPin, INPUT);
 
Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigPin, LOW);  // Trig tidak aktif
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); // Trig aktif
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Membaca sinyal masuk pada echo
  durasi = pulseIn(echoPin, HIGH);
  // Menghitung Jarak
  jarak = durasi * 0.034 / 2;     // Rumus menghitung jarak ultrasonik
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(jarak);
  lcd.print("   cm");
  delay(1000);

 
  if (jarak >= 60){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  else if (jarak > 25 && jarak < 60 ){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  else if (jarak < 25){                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(LED3, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);

     delay(100);
  }
  
}
