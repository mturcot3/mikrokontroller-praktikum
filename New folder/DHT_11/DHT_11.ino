#include <LiquidCrystal.h>

#include <LiquidCrystal_I2C_Hangul.h>

int sensorPin = A0;  // pin sensor
int powerPin = 6;    // untuk pengganti VCC
 
void setup() {  
  // jadikan pin power sebagai output
  pinMode(powerPin, OUTPUT);
  // default bernilai LOW
  digitalWrite(powerPin, LOW);
  // mulai komunikasi serial
  Serial.begin(9600);
}
 
void loop() {
  Serial.print("Nilai kelembaban: ");
  Serial.println(bacaSensor());
  // baca setiap 5 detik
  delay(5000);
}
 
int bacaSensor() {
  // hidupkan power
  digitalWrite(powerPin, HIGH);
  delay(500);
  // baca nilai analog dari sensor
  int nilaiSensor = analogRead(sensorPin);
  digitalWrite(powerPin, LOW);
  // makin lembab maka makin tinggi nilai outputnya
  return 1023 - nilaiSensor;
}
