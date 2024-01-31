#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLwxpVEKlU"
#define BLYNK_DEVICE_NAME "perawatan cabai cabai"
#define BLYNK_AUTH_TOKEN "4hTW_Wk1YYGI4UWhC5QMJTKxIZ27Izm_"
char auth[] = "4hTW_Wk1YYGI4UWhC5QMJTKxIZ27Izm_";
char ssid[] = "hidden";
char pass[] = "22222222";
//======= Library=============//

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Wire.h>         // adds I2C library 
#include <BH1750.h>       // adds BH1750 library file
#include <HCSR04.h>
//=====================================================//
//======Variabel temporary utk menampung data===========//
#define DHTPIN 14                        //DHHTPIN D5
#define DHTTYPE DHT11                    //TIPE DHT
DHT dht(DHTPIN, DHTTYPE);                
WidgetLCD lcd(V0);                       //WidgetLCD temperature dan humidity
WidgetLCD lcd2(V8);                       //WidgetLCD LIGHT dan Volume air
BH1750 lightMeter;
int lamp = 12;                            //PENDEKLARASIAN PIN UNTUK LAMPU D6
int fan = 13;                             //PENDEKLARASIAN PIN UNTUK fan D7
int pump = 15;                            //PENDEKLARASIAN PIN UNTUK pompa D8
#define trig D3
#define echo D4
HCSR04 hc(trig,echo);
BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  Wire.begin(D1, D2);
  // Initialize the I2C bus (BH1750 library doesn't do this automatically). On esp8266 devices you can select SCL and SDA pins using Wire.begin(D4, D3;
  lightMeter.begin();
  pinMode(lamp,OUTPUT); //OIN MODE
  pinMode(fan,OUTPUT); //OIN MODE
  pinMode(pump,OUTPUT); //OIN MODE     
//  digitalWrite(lamp,HIGH);//TEMPAT UNTUK MENSET KONDISI AWAL DARI KONDISI AWAL
  dht.begin();
  lcd.clear();
  lcd2.clear();
//  timer.setInterval(1000L, sendSensor);
   timer.setInterval(1000L, ultrasonik);
   timer.setInterval(1000L, loop);
   timer.setInterval(1000L, cahaya);  
}

void loop() {
  //HASIL DETEKSI DARI SENSOR KE SERIAL MONITOR
  /*  Serial.print("Humidity   : ");
    Serial.print(h);
    Serial.print(" % ");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
     
    Serial.print("Light Meter: ");
    Serial.print(lux);
    Serial.println(" lx");
    Serial.print("Volume: ");
    Serial.print(c);
    Serial.println(" ML");   
  */
  int h = dht.readHumidity();          //FUNGSI DARI LIBRARY DHT VARIABLE H
  int t = dht.readTemperature();
  if (t == 0) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  } 
  else if (t < 24){
    digitalWrite(fan,LOW);
    digitalWrite(lamp,HIGH); 
  }
  else if (t > 28) {
    digitalWrite(fan,HIGH);
    digitalWrite(lamp,LOW);   
  }
  else if (t>24 && t <28) {
    digitalWrite(fan,LOW);
    digitalWrite(lamp,LOW);    
  }
  lcd.print(0,0, "Temp     :");
  lcd.print(11,0,t);

  lcd.print(0,1, "Humidity :");
  lcd.print(11,1,h);

  Blynk.virtualWrite(V1, t);  // select virtual pin (v7) in blynk app
  Blynk.virtualWrite(V2, t);  // select virtual pin (v7) in blynk app
  Blynk.run();
  timer.run();
  //VIRTUAL PORT
  Blynk.virtualWrite(V0, t);
//  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V0, h);
//  Blynk.virtualWrite(V2, h);
//  Blynk.virtualWrite(V3, lux);
  Blynk.virtualWrite(V4, lamp);
  Blynk.virtualWrite(V5, fan);
  Blynk.virtualWrite(V6, pump);
//  Blynk.virtualWrite(V7, c);  // select virtual pin (v7) in blynk app  
  Blynk.virtualWrite(V8, cahaya);  
  Blynk.virtualWrite(V8, ultrasonik); 
}
void ultrasonik()
{
  int c = hc.dist();                      //FUNGSI DARI LIBRARY HC-SR04
  if ( c == 0 ) {
    Serial.println("Failed to read from ultrasonik sensor!");
    return;
  } 
  
  lcd2.print(0,1, "Volume :");
  lcd2.print(11,1,c);
  Blynk.virtualWrite(V7, c);  // select virtual pin (v7) in blynk app
}

void cahaya()
{
  float lux = lightMeter.readLightLevel(); //FUNGSI DARI LIBRARY BH 1750 
  if ( lux == 0 ) {
    Serial.println("Failed to read from cahaya sensor!");
    return;
  } 
  else if (lux < 100){
    digitalWrite(lamp,HIGH); 
  }
  else {
    digitalWrite(lamp,LOW);    
  }
  lcd2.print(0,0, "Light :");
  lcd2.print(8,0,lux);   
  Blynk.virtualWrite(V3, lux);  // select virtual pin (v7) in blynk app
}