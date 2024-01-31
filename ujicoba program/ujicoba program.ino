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

//=====================================================//
//======Variabel temporary utk menampung data===========//
#define DHTPIN 14                        //DHHTPIN D5
#define DHTTYPE DHT11                    //TIPE DHT
#define lamp D6
#define fan D7
#define pump D8
DHT dht(DHTPIN, DHTTYPE);                
WidgetLCD lcd(V0);                       //WidgetLCD temperature dan humidity
WidgetLCD lcd2(V8);                       //WidgetLCD LIGHT dan Volume air
BH1750 lightMeter;
//int lamp = 12;                            //PENDEKLARASIAN PIN UNTUK LAMPU D6
//int fan = 13;                             //PENDEKLARASIAN PIN UNTUK fan D7
//int pump = 15;                            //PENDEKLARASIAN PIN UNTUK pompa D8
#define trig D2
#define echo D1
int depth =20;                    // tanki 20 cm
BLYNK_WRITE(V6) {
  digitalWrite(pump, param.asInt()); // manual pump
}
BLYNK_WRITE(V4) {
  digitalWrite(lamp, param.asInt()); // lampu
  }
BLYNK_WRITE(V5) {
  digitalWrite(fan, param.asInt()); // fan
}
BlynkTimer timer;
void waterlevel()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int t = pulseIn(echo, HIGH);
  int cm = t / 29 / 2;
  Serial.println(cm);
  int level= depth-cm;
  if (level<0)
  level=0;
  level = map(level,0,depth-3,0,100);
  Blynk.virtualWrite(V7, level);
  Blynk.virtualWrite(V8, level);
  Serial.print("Volume: ");
  Serial.print(level);
  Serial.println(" %"); 
  lcd2.print(0,1, "Volume :");
  lcd2.print(11,1,level);
  lcd2.print(14,1, "%");        
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  Wire.begin(D4, D3);
  // Initialize the I2C bus (BH1750 library doesn't do this automatically). On esp8266 devices you can select SCL and SDA pins using Wire.begin(D4, D3;
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE_2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);  
  pinMode(D6, OUTPUT); //OIN MODE lampu
  pinMode(D7, OUTPUT); //OIN MODE fan
  pinMode(pump, OUTPUT); //OIN MODE pompa   
  digitalWrite(lamp,HIGH);//TEMPAT UNTUK MENSET KONDISI AWAL DARI KONDISI AWAL
  digitalWrite(fan,HIGH);

  dht.begin();
  lcd.clear();
  lcd2.clear();
  timer.setInterval(10L, waterlevel);
}

void loop() {
  int h = dht.readHumidity();          //FUNGSI DARI LIBRARY DHT VARIABLE H
  int t = dht.readTemperature();
  float lux = lightMeter.readLightLevel(); //FUNGSI DARI LIBRARY BH 1750 
  //HASIL DETEKSI DARI SENSOR KE SERIAL MONITOR
    Serial.print("Humidity   : ");
    Serial.print(h);
    Serial.print(" % ");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
     
    Serial.print("Light Meter: ");
    Serial.print(lux);
    Serial.println(" lx");
  

  Blynk.run();
  timer.run();
  //VIRTUAL PORT
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V2, h);
  Blynk.virtualWrite(V3, lux);
  Blynk.virtualWrite(V4, lamp);
  Blynk.virtualWrite(V5, fan);
//  Blynk.virtualWrite(V6, pump); 
  Blynk.virtualWrite(V8, lux);  
 
  //delay(1000);  
  //MENAMPILKAN HASIL DETEKSI SENDOR PADA APLIKASI BLINK
  lcd.print(0,0, "Temp     :");
  lcd.print(11,0,t);

  lcd.print(0,1, "Humidity :");
  lcd.print(11,1,h);

  lcd2.print(0,0, "Light :");
  lcd2.print(8,0,lux);  

  //KONDISI
if (t<24)
{
    digitalWrite(fan,HIGH);   
  }
else if (t>28)
  {
    digitalWrite(fan,LOW);    
  }    
else if (lux < 50)
  {
    digitalWrite(lamp,LOW);    
  }    
else if (lux > 50)
  {
    digitalWrite(lamp,HIGH);    
  } 
else 
{
    digitalWrite(fan,LOW);
    digitalWrite(lamp,LOW);    
  }  
}

  //if(lux<50){
  //  digitalWrite(lamp,HIGH);    
  //} 
//  else if(t>28 || lux>50){
//    digitalWrite(fan,LOW);
//    digitalWrite(lamp,LOW);
//  }

/*
if (t<24)
{
    digitalWrite(fan,LOW);
    digitalWrite(lamp,HIGH);    
  }
else if (t>28)
  {
    digitalWrite(fan,HIGH);    
  }  
else if (lux < 100)
  {
    digitalWrite(lamp,HIGH);    
  }
else 
{
    digitalWrite(fan,LOW);
    digitalWrite(lamp,LOW);    
  }

IF BERSARANG
  if(t<24){
    digitalWrite(fan,LOW);
    digitalWrite(lamp,HIGH);    
  }
  else
  {
      if(t>28)  
      {
       digitalWrite(fan,HIGH);
       digitalWrite(lamp,LOW);    
      }
      else
      {
          if(lux<100)
          {
          digitalWrite(lamp,HIGH);    
          }              
         else   
          {
          digitalWrite(fan,LOW);
          digitalWrite(lamp,LOW);               
          }
              
      }      

  }    
  */
