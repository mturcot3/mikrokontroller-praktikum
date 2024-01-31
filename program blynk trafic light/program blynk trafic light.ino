//=====================================================//
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6c7fsfqqx"
#define BLYNK_TEMPLATE_NAME "smart traffict light"
#define BLYNK_AUTH_TOKEN "_XEtbggUsWcPw_ZSotQXcyN1lTFTbVPN"
char auth[] = "_XEtbggUsWcPw_ZSotQXcyN1lTFTbVPN";
char ssid[] = "hidden";
char pass[] = "22222222";
//======= Library=============//

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define trig1 5                          //triger HC-SR04 pin D2
#define echo1 18                          //echo HC-SR04 pin D1
#define trig2 19                          //triger HC-SR04 pin D2
#define echo2 21                          //echo HC-SR04 pin D1
//Traffic light one 
#define red1 15
#define yellow1 2
#define green1 4
//Traffic light Two 
#define red2 20
#define yellow2 18
#define green2 19
WidgetLCD lcd(V32);                       //WidgetLCD temperature dan humidity
WidgetLED led1(V0);
WidgetLED led2(V1);
WidgetLED led3(V2);
WidgetLED led4(V3);
WidgetLED led5(V4);
WidgetLED led6(V5);
BlynkTimer timer;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  pinMode(trig1, OUTPUT);                   //Output pin MODE triger HC-SR04
  pinMode(echo1, INPUT);                    //input pin MODE echo HC-SR04
  pinMode(trig2, OUTPUT);                   //Output pin MODE triger HC-SR04
  pinMode(echo2, INPUT);                    //input pin MODE echo HC-SR04

  pinMode(red1,INPUT);
  pinMode(yellow1,INPUT);
  pinMode(green1,INPUT);
  pinMode(red2,INPUT);
  pinMode(yellow2,INPUT);
  pinMode(green2,INPUT);
  


  lcd.clear(); 
}

void loop()
{
digitalWrite(green1,HIGH);
digitalWrite(red2,HIGH);
delay(10000);
digitalWrite(red1,LOW);
digitalWrite(yellow1,LOW);
digitalWrite(yellow2,LOW);
digitalWrite(green2,LOW);

digitalWrite(red2,LOW);
digitalWrite(green1,LOW);  
digitalWrite(yellow1,HIGH);
digitalWrite(yellow2,HIGH);
delay(5000);
digitalWrite(yellow1,LOW);
digitalWrite(yellow2,LOW);
digitalWrite(red1,LOW);
digitalWrite(red2,LOW);
digitalWrite(green2,LOW);

digitalWrite(red1,HIGH);
digitalWrite(green2,HIGH);
delay(10000);
digitalWrite(red1,LOW);
digitalWrite(green2,LOW);
digitalWrite(yellow1,LOW);
digitalWrite(green1,LOW);
digitalWrite(red2,LOW);
digitalWrite(yellow2,LOW);

//if (red1 == HIGH){
//led1.on(); 
//  Serial.println("Failed to read from DHT sensor!");    
//}else {
//led1.off();
//}
Blynk.virtualWrite(V0, digitalRead(red1));
Blynk.virtualWrite(V1, digitalRead(yellow1));
Blynk.virtualWrite(V2, digitalRead(green1));
Blynk.virtualWrite(V3, digitalRead(red2));
Blynk.virtualWrite(V4, digitalRead(yellow2));
Blynk.virtualWrite(V5, digitalRead(green2));
  Blynk.run();
  timer.run();
}
