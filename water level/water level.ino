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

//=====================================================//
//======Variabel temporary utk menampung data===========//

#define trig D2
#define echo D1
int besar = 20;                           // besar tanki air 20 cm
BlynkTimer timer;

void water() {
  digitalWrite (trig, LOW);
  delayMicroseconds(2);
  digitalWrite (trig, HIGH);
  delayMicroseconds(10);  
  long t = pulseIn (echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  long level = besar - cm;
if (level < 0)
level = 0;
level = map(level, 0, besar-3, 0, 100);
Blynk.virtualWrite(V0, level);
}
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  timer.setInterval(10L, water);
}

void loop() {

  //HASIL DETEKSI DARI SENSOR KE SERIAL MONITOR

  Blynk.run();
  timer.run();
}  
/*
int depth =20;

BlynkTimer timer;
 
void waterlevel()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  long level= depth-cm;
  if (level<0)
  level=0;
  level = map(level,0,depth-3,0,100);
  Blynk.virtualWrite(V0, level);
}

 
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, waterlevel);
  
}

void loop()
{
 
  Blynk.run();
  timer.run();
  }
*/  
