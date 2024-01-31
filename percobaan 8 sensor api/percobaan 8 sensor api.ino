//Menampilkan nilai ADC dan tegangan hasil pembacaan sensor di LCD
#include <LiquidCrystal_I2C.h>     
LiquidCrystal_I2C lcd(0x27, 16, 2);
int api = A0 ;
int led = 7 ;
int adc;
float tegangan;

void setup() {
  lcd.begin();
 
}

void loop() {
  adc = analogRead(api);
  tegangan = (adc*5.0)/1023;

  lcd.setCursor(0,0);
  lcd.print("ADC=");
  lcd.print(adc);

  lcd.setCursor(0,1);
  lcd.print("Tegangan=");
  lcd.print(tegangan);
  lcd.setCursor(15,1);
  lcd.print("V");
  delay(100);
  lcd.clear();
 
}

//Mengetahui pengaruh sudut pada pembacaan sensor
/*#include <LiquidCrystal_I2C.h>     
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pinapi = 4 ;
int led = 7 ;
int api = HIGH;

void setup() {
  lcd.begin();
  pinMode(led, OUTPUT);
  pinMode(pinapi, INPUT);
  Serial.begin(9600);
}

void loop() {
  api = digitalRead(pinapi);
  if(api==HIGH)
  {
  digitalWrite(led,HIGH);
   lcd.setCursor(0, 0);
  lcd.print("Terdeteksi");
  delay(100);
  }
  
  else {
  digitalWrite(led,LOW);
  lcd.setCursor(0,1);
  lcd.print("Tidak Terdeteksi");
  delay(100);
}

  delay(100);
  lcd.clear();
  }
*/
// Flame Sensor Module
/*
int LED = 13; // Use the onboard Uno LED
int isFlamePin = 7;  // This is our input pin
int isFlame = HIGH;  // HIGH MEANS NO FLAME

void setup() {
  pinMode(LED, OUTPUT); // put onboard LED as output
  pinMode(isFlamePin, INPUT); //flame sensor should be input as it is giving data
  Serial.begin(9600); //begin Serial communication
  
}

void loop() {
  isFlame = digitalRead(isFlamePin);//Readd the data gien by the flame sensor
  if (isFlame== LOW)  //if it is low
  {
    Serial.println("FLAME, FLAME, FLAME"); //Print Flame Flame
    digitalWrite(LED, HIGH);  //LED on
  }
  else                           //if not
  {                               
    Serial.println("no flame"); //print no  flame
    digitalWrite(LED, LOW);    //off the LED
  }
}*/
// lowest and highest sensor readings:
/*
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
}
void loop() {
  // read the sensor on analog A0:
	int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Close Fire **");
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire **");
    break;
  case 2:    // No fire detected.
    Serial.println("No Fire");
    break;
  }
  delay(1);  // delay between reads
}
*/