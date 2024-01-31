//=====================================================//
/*          KELOMPOK 4
      Ahmad Miftahur Riziq (3.32.21.2.01)
      Haqqi
      mieftah
      tegar
*/
//=====================================================//
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLwxpVEKlU"
#define BLYNK_DEVICE_NAME "perawatan cabai cabai"
#define BLYNK_AUTH_TOKEN "4hTW_Wk1YYGI4UWhC5QMJTKxIZ27Izm_"
char auth[] = "4hTW_Wk1YYGI4UWhC5QMJTKxIZ27Izm_";
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
WidgetLCD lcd(V0);                       //WidgetLCD temperature dan humidity
WidgetLCD lcd2(V8);                      //WidgetLCD kondisi kipas dan Lampu
BH1750 lightMeter;
#define trig D2                          //triger HC-SR04 pin D2
#define echo D1                          //echo HC-SR04 pin D1
int tangki =20;                           // tangki panjang 20 cm

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
  int cm = t / 29 / 2;
  Serial.println(cm);
  int level= tangki - cm;
  if (level<0)
  level=0;
  level = map(level,0,tangki,0,100);     //map(value,from Low, from high, to Low, to High);
  //VIRTUAL PORT
  Blynk.virtualWrite(V7, level);
  Blynk.virtualWrite(V8, level);          // untuk menampilkan nilai di lcd2 blynk
  //menampilkan di serial monitor  
  Serial.print("Volume: ");
  Serial.print(level);
  Serial.println(" %");
  delay(100); 
  //menampilkan di lcd blynk
  lcd2.print(0,1, "Volume :");
  lcd2.print(11,1,level);
  lcd2.print(14,1, "%");        
  delay(100);
}
void cahaya()
{
  float lux = lightMeter.readLightLevel();                //FUNGSI DARI LIBRARY BH 1750 
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE_2);   // start measurment at 0.51x resolution. measurment time is approx 120 ms
  Wire.begin(D4, D3);                 , lux);                      // pin SDA (D4) dan SCL (D3) di BH1750
  Blynk.virtualWrite(V3                          // Virtual port
  Blynk.virtualWrite(V8, lux);                            // untuk menampilkan nilai di lcd2 blynk
  Blynk.virtualWrite(V0, lamp);
    //menampilkan di serial monitor
    Serial.print("Light Meter: ");
    Serial.print(lux);
    Serial.println(" lx");
    //menampilkan di lcd blynk    
    lcd2.print(0,0, "Light  : ");
    lcd2.print(8,0,lux);   
    lcd2.print(14,0, "lx");
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
  int h = dht.readHumidity();                          //FUNGSI DARI LIBRARY DHT VARIABLE H
  int t = dht.readTemperature();   
  //VIRTUAL PORT
  Blynk.virtualWrite(V0, fan);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  dht.begin();
    //HASIL DETEKSI DARI SENSOR KE SERIAL MONITOR
    Serial.print("Humidity   : ");
    Serial.print(h);
    Serial.print(" % ");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
   if (t > 1000 || h > 1000)      // karena sensor eror
   {
    digitalWrite(fan,HIGH);      // kondisi lainnya kipas mati 
    lcd.print(0,1, " Kipas Padam  ");   
    delay (100);  
    Serial.println("Failed to read from DHT sensor!");
   }
  if (t > 29 && t < 1000 || h < 25)
  {
    digitalWrite(fan,LOW);               // saat temperature diatas 29 atau humiditi dibawah 25 maka kipas akan menyala 
    lcd.print(0,1, " Kipas Menyala");   //MENAMPILKAN HASIL PADA APLIKASI BLINK   
    delay (100);    
  }    
 else
  {
    digitalWrite(fan,HIGH);    // kondisi lainnya kipas mati 
    lcd.print(0,1, " Kipas Padam  ");   
    delay (100);   
  }     
  delay (1000);  
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
  lcd2.clear();
  
  timer.setInterval(100L, waterlevel);
  timer.setInterval(1000L, cahaya);
  timer.setInterval(1000L, suhu); 
   
}

void loop() {

  Blynk.run();
  timer.run();

}  
 

