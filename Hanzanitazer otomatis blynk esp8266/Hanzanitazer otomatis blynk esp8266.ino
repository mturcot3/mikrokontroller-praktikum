#include <Adafruit_MLX90614.h>

#include <Adafruit_MiniMLX90614.h>

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLPpkNZleJ"
#define BLYNK_DEVICE_NAME "PERAWATAN CABAI"
#define BLYNK_AUTH_TOKEN "ZRLR2H60S7ChENewGaQcAu1eyv0zG3sg"
char auth[] = "ZRLR2H60S7ChENewGaQcAu1eyv0zG3sg";
char ssid[] = "hidden";
char pass[] = "22222222";
#include <ESP8266WiFi.h>         // adds esp8266 wifi library file
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>                // adds I2C library 
#define trig D2                          //triger HC-SR04 pin D2
#define echo D1                          //echo HC-SR04 pin D1
int tangki = 15;                           // tangki panjang 15 cm
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  pinMode(trig, OUTPUT);                   //Output pin MODE triger HC-SR04
  pinMode(echo, INPUT);                    //input pin MODE echo HC-SR04
 while (!Serial);

  Serial.println("Adafruit MLX90614 test");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };

  Serial.print("Emissivity = "); Serial.println(mlx.readEmissivity());
  Serial.println("================================================");
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
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
void lmx()
{
    Wire.begin(D4, D3);  
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  delay(500);
