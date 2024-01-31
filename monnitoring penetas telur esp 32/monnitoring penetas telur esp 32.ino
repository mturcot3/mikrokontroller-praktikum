#define BLYNK_TEMPLATE_ID "TMPLNNI7R_Hr"
#define BLYNK_DEVICE_NAME "incubator ayam"
#define BLYNK_AUTH_TOKEN "QotchjjR6COiJ7OdapxfWTn-X2dhTsJK"

#define BLYNK_PRINT Serial
#include <WiFi.h> 
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);//Setting alamat I2C dan ukuran LCD
#define yl 26                           //Pin Sensor yl
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 35
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensor(&oneWire);
float suhuDS18B20; 

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "hidden";  // type your wifi name
char pass[] = "22222222";  // type your wifi password

BlynkTimer timer;

#define buzzer 4
#define relayA 15
#define relayB 2
LiquidCrystal_I2C lcd(0x27, 16, 2);
void dssend(){
  sensor.setResolution(10);
  sensor.requestTemperatures();  
  suhuDS18B20 = sensor.getTempCByIndex(0);  
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  else{
  Serial.println(suhuDS18B20, 2);    
  lcd.setCursor(0,0);
  lcd.print("S Ruang =");
  lcd.setCursor(10, 0);
  lcd.print(suhuDS18B20, 2);
  lcd.print((char)223);
  lcd.print("C");  
    delay(500);
    
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, suhuDS18B20);


  /*  if(t <= 29){
      digitalWrite(relayA, LOW);
      digitalWrite(relayB, LOW);
    }
    else if(t >=31){
      digitalWrite(relayA, HIGH);
      digitalWrite(relayB, HIGH);
    }
    */
}


/*void asapSensor(){
  int asap = analogRead(MQ2);


  if (isnan(asap)) {
    Serial.println("gagal membaca sensor MQ-02");
    return;
  }
 
  Blynk.virtualWrite(V2, asap);
  
  Serial.println("Gas Sensor: ");
  Serial.print(asap);
  Serial.println("\t");
  
  delay(500);

  if (asap > 1500){
    Blynk.email("fajarsaldian25@gmail.com", "Alert", "asap terdeteksi!!");
    Blynk.logEvent("smoke_alert","Asap terdeteksi");
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }
}

void gerak(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration*0.034/2;

  Serial.println("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm");
  delay(500);

  if (distanceCm < 40){
    digitalWrite(buzzer, HIGH);
    Blynk.email("fajarsaldian25@gmail.com", "Alert", "asap terdeteksi!!");
    Blynk.logEvent("menetas","ayam sudah lahir");
  }
  else{
    digitalWrite(buzzer, LOW);
  }

}
*/
void setup() {
  Serial.begin(9600); 
  lcd.begin(); 
/*  pinMode(MQ2, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relayA, OUTPUT);
  pinMode(relayB, OUTPUT);
*/
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, dssend);
 // timer.setInterval(100L, asapSensor);
 // timer.setInterval(100L, gerak);
}
void loop() {
  Blynk.run();
  timer.run();

}