#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLZLDLKsLp"
#define BLYNK_DEVICE_NAME "monitor cabai"
#define BLYNK_AUTH_TOKEN "C5L_u5M_kBCecskSQqwEujH-eA6bsdyI"
char auth[] = "C5L_u5M_kBCecskSQqwEujH-eA6bsdyI";
char ssid[] = "hidden";
char pass[] = "22222222";
//======= Library=============//

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <DHT.h>

//============================//
#define DHTTYPE DHT11 //inisialisasi type sensor DHT
#define DHTPin D5 //inisialisasi pin Din DHT
DHT dht(DHTPin, DHTTYPE); //maping konfig sensor DHT
#define lamp D6 //insialisasi pin OUT lampu
#define fan D7 //inisialisai pin OUT kipas
#define pump D8 //inisialisasi pin OUT pompa

//=====================================================//

BlynkTimer timer; //konfig varibel timer
WidgetRTC rtc; //konfig variabel rtc
//======Variabel temporary utk menampung data===========//
int lampstate = 0;
int pumpstate = 0;
int fanstate = 0;
int virtualSwitch;
float h ; // variabel temporary utk menampung data
float t ; // varibel temporary utk menampung data
const int trigPin = D3; //inisialisasi pin triger ultrasonik
const int echoPin = D4; //inisialisasi pin echo ultrasonik
//========varibel temporary utk menampung data======//
long duration;
int distance;
int tinggi_air;
int lightIntensity;
//===============================================//
int period1 = 1000; //variabel utk data millis
unsigned long time_now1 = 0;
BLYNK_WRITE(V6)
{
 virtualSwitch = param.asInt(); // assigning incoming value from pin V6 to a variable
}
void clockDisplay() // sub-program "clockDisplay" utk menampilkan waktu
{
 int t_send = int(t);
 int h_send = int(h);
 String currentTime = String(hour()) + ":" + minute() + ":" + second(); //varibel currentTime menampung data JAM, MENIT, DETIK
 String currentDate = String(day()) + "-" + month() + "-" + year(); //varibel currentDate menampung data HARI, BULAN, TAHUN
 Serial.print("Current time: ");
 Serial.print(currentTime);
 Serial.print(" ");
 Serial.print(currentDate);
 Serial.println();
 /* command for LED ICON on BLYNK APP */
 if(lampstate == 1){
 Blynk.virtualWrite(V4, 1023);
 }else{
 Blynk.virtualWrite(V4, 0);
 }
 if(pumpstate == 1){
 Blynk.virtualWrite(V7, 1023);
 }else{
 Blynk.virtualWrite(V7, 0);
 }
 if(fanstate == 1){
 Blynk.virtualWrite(V8, 1023);
 }else{
 Blynk.virtualWrite(V8, 0);
 }
 /* writing value on virtual pin BLYNK APP */
 Blynk.virtualWrite(V5, currentTime);
 Blynk.virtualWrite(V6, currentDate) ;
 Blynk.virtualWrite(V0, t_send);
 Blynk.virtualWrite(V1, h_send);
 Blynk.virtualWrite(V2, tinggi_air);
 Blynk.virtualWrite(V3, lightIntensity); 
 }
BLYNK_CONNECTED() {
 // Synchronize time on connection
 rtc.begin();
}
void setup()
{
 pinMode(trigPin, OUTPUT); //set trigPin as OUTPUT
 pinMode(echoPin, INPUT); //set echoPin as INPUT
 pinMode(lamp, OUTPUT); //set lamp pin as OUTPUT
 pinMode(fan, OUTPUT); //set fan pin as OUPUT
 pinMode(pump, OUTPUT); //set pump pin as OUTPUT

 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass); //conecting to inet and BLYNK APP
 while (!Blynk.connected()){
 delay(250);
 Serial.print(".");
 }
 setSyncInterval(100 * 60); // Sync interval in seconds (10 minutes)
 timer.setInterval(1000L, clockDisplay); //set interval for sending value to BLYNK APP
}
void loop()
{
 h = dht.readHumidity(); //variable h reading Humdity value
 t = dht.readTemperature(); //vaiablet reading Temperature value

 if (isnan(h) || isnan(t)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }
 if( t > 33){ //command to automaticly operate fan
 fanstate = 1;
 }else{
 fanstate = 0;
 }
 Blynk.run(); //running conectivity with BLYNK APP
 timer.run(); //running timer 
  while (!Blynk.connected()){ // re-connect with inet and BLYNK APP when sometimes get lose
 Blynk.begin(auth, ssid, pass);
 Serial.print(".");
 delay(250);
 }
 ultrasonik(); //calling sub-program ultrasonik
 sensor_LDR(); //calling sub-program sensor_LDR
 pump_state(); //calling sub=program pump_state
 output(); //calling sub-program output
}
void ultrasonik(){ // sub-program ultrasonik
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH); //read value for duration variable as pulseIN from echoPIN
 distance = duration*0.034/2; //convert the pulseIn to distance (cm)
 tinggi_air = 100 - ((100/20)*(distance - 5)); //convert the distance reading to percentage (%)
}
void sensor_LDR(){
 int sensorValue = analogRead(A0); // read the input on analog pin 0
 float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
 lightIntensity = voltage*20; // convert voltage rading to percentage
 if (lightIntensity < 10){
 lampstate = 1;
 }else if(lightIntensity > 80){
 lampstate = 0;
 }
 if(millis() > time_now1 + period1){
 time_now1 = millis();
 Serial.println(voltage); // print out the value you read
 Serial.print("Voltage :");
 Serial.println (voltage); // print out the value you read
  Serial.print("Value :");
 Serial.println(sensorValue);
 Serial.print("Light Intensity : ");
 Serial.println(lightIntensity);
 Serial.print("Distance :" );
 Serial.println(distance);
 }
}
void pump_state(){ //sub-program pump_state
 int jam = int(hour()); //reading value HOUR
 int menit = int(minute()); //reading value MINUTE
/* command to automaticly operate pump every minute */
 if((menit >= 20 && menit <= 25) || virtualSwitch == 1){
 pumpstate = 1;
 }else{
 pumpstate = 0;
 }
/* command to automaticly operate pump every hour */
 /* if((jam == 16 && menit >=0 && menit <= 1) || virtualSwitch == 1){
 pumpstate = 1;
 }else{
 pumpstate = 0;
 }*/

}
void output(){ // sub-program output
 /* command to operate output */
 if(lampstate == 1){
 digitalWrite(lamp, LOW);
 }else{
 digitalWrite(lamp, HIGH);
 }
 if(pumpstate == 1){
 digitalWrite(pump, LOW);
 }else{
 digitalWrite(pump, HIGH);
 }
 if(fanstate == 1){
 digitalWrite(fan, LOW);
 }else{
 digitalWrite(fan, HIGH);
 }
}