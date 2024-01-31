//=====================================================//
/*          KELOMPOK 4
      Ahmad Miftahur Riziq             (3.32.21.2.01)
      Muhammad Haqqi Munazilmi Al-Asri (3.32.21.2.13)
      Miefta Alifannisa Baraseto       (3.32.21.2.11)
      Zulfananda Tegar Santoso         (3.32.21.2.25)
*/
//=====================================================//
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLPpkNZleJ"
#define BLYNK_DEVICE_NAME "PERAWATAN CABAI"
#define BLYNK_AUTH_TOKEN "ZRLR2H60S7ChENewGaQcAu1eyv0zG3sg"
char auth[] = "ZRLR2H60S7ChENewGaQcAu1eyv0zG3sg";
char ssid[] = "hidden";
char pass[] = "22222222";
//======= Library=============//
#include <ESP8266WiFi.h>         // adds esp8266 wifi library file
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>                 // adds DHT 11 library file
#include <Wire.h>                // adds I2C library 
#include <BH1750.h>              // adds BH1750 library file
//======Variabel temporary utk menampung data===========//
#define DHTPIN 14                        //DHHTPIN D5
#define DHTTYPE DHT11                    //TIPE DHT
#define lamp D6                          //lamppin D6
#define fan D7                           //fanpin D7
#define pump D8                          //pumppin D8
DHT dht(DHTPIN, DHTTYPE);                
WidgetLCD lcd(V0);                       //WidgetLCD kondisi kipas dan Lampu
BH1750 lightMeter;
#define trig D2                          //triger HC-SR04 pin D2
#define echo D1                          //echo HC-SR04 pin D1
int tangki = 15;                           // tangki panjang 15 cm

   BLYNK_WRITE(V6) {
  digitalWrite(pump, param.asInt());    // kontrol manual pump di blynk
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
  int cm = t *0.034/2;
  Serial.println(cm);
  int level= tangki - cm;
  if (level<0)
  level=0;
  level = map(level,0,tangki- 2,0,100); //map(value,from Low, from high, to Low, to High);
  //VIRTUAL PORT
  Blynk.virtualWrite(V7, level);
  //menampilkan di serial monitor  
  Serial.print("Volume: ");
  Serial.print(level);
  Serial.println(" %");
  delay(100); 
  if(level < 25){
   // Blynk.email("projeksensorinstrumen@gmail.com", "Alert", "Level Air dibawah 25 persen!");
    Blynk.logEvent("water_level_alret","Level Air dibawah 25 persen!");
    Serial.print("Level Air dibawah 25 persen!");
  }
}
void cahaya()
{
  float lux = lightMeter.readLightLevel();                //FUNGSI DARI LIBRARY BH 1750 
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE_2);   // start measurment at 0.51x resolution. measurment time is approx 120 ms
  Wire.begin(D4, D3);                                     // pin SDA (D4) dan SCL (D3) di BH1750
  Blynk.virtualWrite(V3, lux);                            // Virtual port
  Blynk.virtualWrite(V0, lamp);
    //menampilkan di serial monitor
    Serial.print("Light Meter: ");
    Serial.print(lux);
    Serial.println(" lx");
   if (lux < 20)
  {
    digitalWrite(lamp,LOW);                              // saat lux dibawah 50 maka lampu akan menyala 
    lcd.print(0,0, " lampu Menyala");
    delay (100);       
  }    
 else
  {
    digitalWrite(lamp,HIGH);                            // lampu akan mati 
    lcd.print(0,0, " lampu Padam  ");   
    delay (100);
  }     
}
void suhu()
{
  float h = dht.readHumidity();             //FUNGSI DARI LIBRARY DHT VARIABLE H
  float t = dht.readTemperature();   
  //VIRTUAL PORT
  Blynk.virtualWrite(V0, fan);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  dht.begin();
    //HASIL DETEKSI DARI SENSOR KE SERIAL MONITOR
    if (isnan (h) || isnan (t)){      // periksa pembacaan sensor ketika tidak terbaca
    Serial.print("Failed to read from sensor!");
    }      
    else{
    Serial.print("Humidity   : ");
    Serial.print(h);
    Serial.print(" % ");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
    }    

  if (t > 29  || h < 29)
  {
    digitalWrite(fan,LOW);               // saat temperature diatas 29 atau humiditi dibawah 29 maka kipas akan menyala 
    lcd.print(0,1, " Kipas Menyala");   //MENAMPILKAN HASIL PADA APLIKASI BLINK   
    delay (100);    
  }    
 else
  {
    digitalWrite(fan,HIGH);    // kondisi lainnya kipas mati 
    lcd.print(0,1, " Kipas Padam  ");   
    delay (100);   
  }     
  delay (100);  
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  pinMode(trig, OUTPUT);                   //Output pin MODE triger HC-SR04
  pinMode(echo, INPUT);                    //input pin MODE echo HC-SR04
  pinMode(D6, OUTPUT);                     //Output pin MODE lamp
  pinMode(D7, OUTPUT);                    //Output pin MODE fan
  pinMode(pump, OUTPUT);                  //Output pin MODE pompa   
    
  digitalWrite(pump, HIGH);              // kondisi awal supaya relay mati
  digitalWrite(lamp, HIGH);              // kondisi awal supaya relay mati
  digitalWrite(fan, HIGH);              // kondisi awal supaya relay mati
  
  lcd.clear(); 
  
  timer.setInterval(100L, waterlevel);
  timer.setInterval(100L, cahaya);
  timer.setInterval(100L, suhu); 
   
}

void loop() {

  Blynk.run();
  timer.run();

}  
 

