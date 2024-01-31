#include <LiquidCrystal_I2C.h> 
#include <OneWire.h> 
#include <DallasTemperature.h> 
#define ONE_WIRE_BUS 2  
#define merah 7
#define kuning 8
#include <DHT.h>
DHT dht(4, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2); 

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensor(&oneWire);
float suhuDS18B20; 

void setup(void)
{
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
}

void loop(void)
{

  float suhudht = dht.readTemperature();   
  sensor.setResolution(11);
  sensor.requestTemperatures();  
  suhuDS18B20 = sensor.getTempCByIndex(0);  

  //Serial.println(suhuDS18B20, 1);  
  //Serial.println(suhuDS18B20, 2);  
  //Serial.println(suhuDS18B20, 3);  
  //Serial.println(suhuDS18B20, 4);  
  lcd.setCursor(0,0);
  lcd.print("SRuang =");
  lcd.print(suhudht);
  lcd.println("*C ");
  delay(500); 
  lcd.setCursor(0, 1);
  lcd.print("SAir=");
  lcd.setCursor(6, 1);
  lcd.print(suhuDS18B20, 4);
  lcd.print((char)223);
  lcd.print("C"); 
  delay(500);   
  
  if(suhuDS18B20 > 50 ){
  digitalWrite(merah, HIGH);
  digitalWrite(kuning, LOW);
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Suhu Air Tinggi");
  lcd.setCursor(0, 1);
  lcd.print("");
  delay(1000);
   
  }  
  else if(suhuDS18B20 < 50 ){
  digitalWrite(kuning, HIGH);
  digitalWrite(merah, LOW);
}
}
