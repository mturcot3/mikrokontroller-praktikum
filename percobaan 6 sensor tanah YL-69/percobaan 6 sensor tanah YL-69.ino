/*//Menampilkan nilai kelembaban pada sensor kelembaban tanah YL-69
#include <LiquidCrystal_I2C.h>       
LiquidCrystal_I2C lcd(0x27, 16, 2);  
int sensorPin = A0;  

int nilaiSensor;
int lembab;
float tegangan;
void setup() {
lcd.begin();
lcd.backlight();
pinMode(sensorPin, INPUT);
}
void loop() {

nilaiSensor = analogRead(sensorPin);
int nilaiRes = 1023 - nilaiSensor;
  
 lembab = map(nilaiRes, 0, 1023, 0, 100);
 tegangan = map(nilaiRes, 0, 1023, 0, 5);
 lcd.setCursor(0, 0);
 lcd.print("Tingkat");           
 lcd.setCursor(0, 1);
 lcd.print("lembab:");      
}
*/
/*
// YL-39 + YL-69 humidity sensor
byte humidity_sensor_pin = A1;
byte humidity_sensor_vcc = 6;

void setup() {
  // Init the humidity sensor board
  pinMode(humidity_sensor_vcc, OUTPUT);
  digitalWrite(humidity_sensor_vcc, LOW);

  // Setup Serial
  while (!Serial);
  delay(1000);
  Serial.begin(9600);
}

int read_humidity_sensor() {
  digitalWrite(humidity_sensor_vcc, HIGH);
  delay(500);
  int value = analogRead(humidity_sensor_pin);
  digitalWrite(humidity_sensor_vcc, LOW);
  return 1023 - value;
}

void loop() {
  Serial.print("Humidity Level (0-1023): ");
  Serial.println(read_humidity_sensor()); 
  delay(10000);
}
*/