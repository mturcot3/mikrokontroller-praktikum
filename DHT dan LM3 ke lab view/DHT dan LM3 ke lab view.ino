// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

const int sensor = A1;
int suhu;
//float tempf;
float vout;
float adc;

int led1=5;
int led2=9; 

void setup() {
  Serial.begin(9600);
  dht.begin();
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 

}

void loop() {
  // Wait a few seconds between measurements.
  delay(500);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float kelembaban = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float suhuC = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
//  float suhuF = dht.readTemperature(true);
 
// Program lm
  adc = analogRead(sensor);
  vout = adc / 1023 * 5;
  suhu = vout * 100;

  Serial.print(kelembaban);
  Serial.print(",");
  Serial.print(suhu);

if (kelembaban < 50){  
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
delay(100);
}

else if (kelembaban > 50){
  
digitalWrite(led2, HIGH);
digitalWrite(led1, LOW);
delay(100);
}  
 }
