#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(2, DHT11);

const int pintriger = 13;
const int pinecho = 10;
long duration;
int distanceCm, distanceInch;
int LEDHIJAU = 8;
int LEDMERAH = 9;

void setup() {
lcd.begin();
Serial.begin(9600);
dht.begin();
pinMode(LEDMERAH, OUTPUT);
pinMode(LEDHIJAU, OUTPUT);
  pinMode(pintriger, OUTPUT);
  pinMode(pinecho, INPUT);
 }

void loop() {
  digitalWrite(pintriger,LOW);
  delayMicroseconds(2);
  digitalWrite(pintriger,HIGH);
  delayMicroseconds(10);
 digitalWrite(pintriger,LOW);

  duration = pulseIn(pinecho,HIGH);
  distanceCm = duration*0.034/2;
  distanceInch = duration*0.0133/2;
float kelembaban = dht.readHumidity();
float Sruang = dht.readTemperature();
delay(200);
Serial.print(" ");
Serial.print("Suhu : ");
Serial.print(suhu);


lcd.setCursor(0,0);
lcd.print("Suhu       :");
lcd.print((int)Sruang);
lcd.println("*C ");

delay(1000);
}

else if(suhu < 32){
digitalWrite(LEDHIJAU, HIGH);
digitalWrite(LEDMERAH, LOW);
delay(100);
}

else if(suhu > 32){
digitalWrite(LEDMERAH, high);
digitalWrite(LEDHIJAU, LOW);
delay(100);
}  
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
 lcd.print(distanceCm);   
 lcd.print("cm");
 delay(5);
 lcd.setCursor(0,1);
 lcd.print("Jarak: ");
 lcd.print(distanceInch);
  lcd.print("inch");
 delay(5);
}
