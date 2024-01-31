//Mengukur nilai jarak benda padat dan berongga
/*#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pintriger = 13;
const int pinecho = 12;
long duration;
int distanceCm, distanceInch;

void setup() {
  lcd.begin();
  pinMode(pintriger, OUTPUT);
  pinMode(pinecho, INPUT);
 }

void loop() {
  digitalWrite(pintriger,LOW);
  delayMicroseconds(2);
  digitalWrite(pintriger,HIGH);
  delayMicroseconds(10);
 digitalWrite(pintriger,LOW);

  duration = pulseIn(pinecho,HIGH);
  distanceCm = duration*0.034/2;
  distanceInch = duration*0.0133/2;
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
 lcd.print(distanceCm);   
 lcd.print("cm");
 delay(5);
   lcd.setCursor(0,1);
 	    lcd.print("Jarak: ");
  	    lcd.print(distanceInch);
  	    lcd.print("inch");
 	    delay(5);
    }
*/
//Menyalakan LED dan Buzzer pada jarak tertentu
/*#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 13;
const int echoPin = 12;
const int LED1 = 2;
const int LED2 = 4;
const int LED3 = 7; 
const int buzzer = 9;
long durasi;
int jarak;

void setup() {
lcd.begin();
pinMode(trigPin, OUTPUT); 
pinMode(LED1, OUTPUT); 
pinMode(LED2, OUTPUT); 
pinMode(LED3, OUTPUT); 
pinMode(buzzer, OUTPUT);
pinMode(echoPin, INPUT);
 
Serial.begin(9600); 
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
durasi = pulseIn(echoPin, HIGH);
jarak = durasi * 0.034 / 2;
distanceInch = durasi*0.0133/2;  
      lcd.setCursor(0,0);
      lcd.print("Jarak: ");
      lcd.print(jarak);
      lcd.print("   cm");
      delay(1000);
      if (jarak >= 60){                
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(buzzer, LOW);
      delay(100);
      }
      else if (jarak > 25 && jarak < 60 ){   
      digitalWrite(LED2, HIGH);
      digitalWrite(LED1, LOW);
       digitalWrite(LED3, LOW);
       digitalWrite(buzzer, LOW);
       delay(100);
       }
       else if (jarak < 25){           
       digitalWrite(LED3, HIGH);
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED2, LOW);
       digitalWrite(LED1, LOW);
       delay(100);
       }
 } 
 */
//Mengukur tinggi benda
/*#include <LiquidCrystal_I2C.h>   
LiquidCrystal_I2C lcd(0x27, 16, 2); 

#define ECHOPIN  12
#define TRIGPIN 13

int Led1 = 2;     
int Led2 = 4;     
int Led3 = 7;    
int buzzer = 9;
float jarak;
float batasJarak=89;
float tinggi;
void setup() {
 lcd.begin();    //memanggil lcd I2C
 lcd.backlight();
 pinMode(ECHOPIN, INPUT);
 pinMode(TRIGPIN, OUTPUT);
 pinMode(Led1, OUTPUT);
 pinMode(Led2, OUTPUT);
 pinMode(Led3, OUTPUT);
 pinMode(buzzer, OUTPUT);
 delay(2000);
 }
 void loop() {
 digitalWrite(TRIGPIN, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  long distance = pulseIn(ECHOPIN, HIGH);
  jarak = (distance * 0.034) / 2.0;
  tinggi= batasJarak-jarak;
  jarak= (distance/2)/29.1;
  lcd.setCursor(0, 0);
  lcd.print("Jarak :");
  lcd.setCursor(7, 0);
  lcd.print(jarak);
  lcd.print(" cm  ");
  lcd.setCursor(0, 1);
  lcd.print("Tinggi:");
  lcd.setCursor(7, 1);
  lcd.print(tinggi);
  lcd.print(" cm  ");
  delay(1000);
  }
*/
// seleksi tinggi badan
#include <LiquidCrystal.h>
#define ECHOPIN 10                            
#define TRIGPIN 11   
#define led1 8
#define led2 9

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int tdasar, sensor, tbadan;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Alat Pengukur");
  lcd.setCursor(2, 1);
  lcd.print(" Tinggi Badan");
  delay(2000);
  lcd.clear();
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  tdasar = 200;
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  int sensor = pulseIn(ECHOPIN, HIGH);        
  sensor = sensor/58;                        
  tbadan = tdasar - sensor;                    
  
      if((tbadan>=165)&&(tbadan<=200)){
          digitalWrite(led1, HIGH);
          digitalWrite(led2, LOW);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tinggi : "); 
          lcd.print(tbadan); 
          lcd.print(" cm");
          lcd.setCursor(0, 1);
          lcd.print("Anda Lolos");
          delay(1000);
      }
      else if((tbadan>0)&&(tbadan<165)){
          digitalWrite(led1, LOW);
          digitalWrite(led2, HIGH);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tinggi : "); 
          lcd.print(tbadan); 
          lcd.print(" cm");
          lcd.setCursor(0, 1);
          lcd.print("Anda Tidak Lolos");
          delay(1000);
      }
      else{
      
          lcd.clear();
          digitalWrite(led1, LOW);
          digitalWrite(led2, LOW);
      }
}*/
//pengukur tinggi badan
/*
#define ECHOPIN 7
#define TRIGPIN 8
int led = A5;
#include <LiquidCrystal.h>

LiquidCrystal lcd (6,5,4,3,2,1);
int H2,HT,H1;
void setup() {
  lcd.begin(16,2);
  lcd.print("Tinggi Badan");
  lcd.setCursor(0,1);
  lcd.print("TB=");

  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(led,OUTPUT);
  delay(1000);
  HT = 200;
}
void loop(){
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  int distance = pulseIn(ECHOPIN,HIGH);
  distance = distance/58;
  H2=HT-distance;
  lcd.setCursor(3,1);
  lcd.print(H2);
  lcd.print("cm");
  digitalWrite(led, HIGH);
  delay(1000);
}*/
// mengatur on delay dengan timer
/*#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 13;
const int echoPin = 12;
const int LED1 = 2;
const int LED2 = 4;
const int LED3 = 7; 
const int buzzer = 9;
long durasi;
int jarak;
int timer = 0;
void setup() {
lcd.init();
pinMode(trigPin, OUTPUT); 
pinMode(LED1, OUTPUT); 
pinMode(LED2, OUTPUT); 
pinMode(LED3, OUTPUT); 
pinMode(buzzer, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600); 
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
durasi = pulseIn(echoPin, HIGH);
jarak = durasi * 0.034 / 2;

      lcd.setCursor(0,0);
      lcd.print("Jarak: ");
      lcd.print(jarak);
      lcd.print("   cm");
      delay(1000);
      if (jarak > 300) {
      timer++; 
      lcd.clear(); 
      lcd.setCursor(0,1);
      lcd.print("time: ");
      lcd.print(timer);
      lcd.print("   s");
      delay(1000);
      }
      if (jarak < 300){
        timer = 0 ;
      lcd.setCursor(0,1);
      lcd.print("time: ");
      lcd.print(timer);
      lcd.print("   s");
      delay(1000);
      }
      if (timer >= 10){         
            
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(buzzer, LOW);
      delay(100);
      }
      else if (jarak > 25 && jarak < 60 ){   
      digitalWrite(LED2, HIGH);
      digitalWrite(LED1, LOW);
       digitalWrite(LED3, LOW);
       digitalWrite(buzzer, LOW);
       delay(100);
       }
       else if (jarak < 25){           
       digitalWrite(LED3, HIGH);
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED2, LOW);
       digitalWrite(LED1, LOW);
       delay(100);
       }
 } 
 */