// program menampilkan hasil pir sensor ke lcd i2c
/*
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pinsensor = 13;
int R = 2;
int G = 3;
int B = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode (pinsensor, INPUT);
  pinMode (R, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (B, OUTPUT);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pinsensor) == HIGH) {
    lcd.clear();
     lcd.setCursor(2,0);
    lcd.print("Ada gerakan");
    delay(500);
 
    digitalWrite(R, HIGH);
    delay(500);
    digitalWrite(G, LOW);
    delay(500);
    digitalWrite(B, LOW);
    delay(500);
   
  }
else if (digitalRead(pinsensor) == LOW) {
  lcd.clear();
    lcd.setCursor(2,0);
  lcd.print("Tidak ada");
  lcd.setCursor(4,1);
  lcd.print("gerakan");
  delay(500);
    digitalWrite(R, LOW);
    delay(500);
    digitalWrite(G, HIGH);
    delay(500);
    digitalWrite(B, LOW);
    delay(500);
  
  }
}
*/
/*
//  program menyalakan led rgb saat pir mendeteksi atau tidak
int pinSensor = 13;
int R = 2;
int G = 3;
int B = 4;

void setup() {
  pinMode (pinSensor, INPUT);
  pinMode (R, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (B, OUTPUT);

}

void loop() {
  if (digitalRead(pinSensor) == HIGH) {
    digitalWrite(R, HIGH);
    delay(500);
    digitalWrite(G, HIGH);
    delay(500);
    digitalWrite(B, HIGH);
    delay(500);
  }
else if (digitalRead(pinSensor) == LOW) {
    digitalWrite(R, LOW);
    delay(500);
    digitalWrite(G, LOW);
    delay(500);
    digitalWrite(B, LOW);
    delay(500);
  }
}
*/
/*
// program dari web
int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(500);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(500);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
*/
/* Membuat Saklar Otomatis Menggunakan Sensor PIR dengan Arduino 
Dev: teknisibali // Date: 29/11/2019 // www.teknisibali.com */
 
int pinPIR = 2;     //pin Out PIR 
int pinRELAY = 4;   //pin IN relay
int statusPIR = 0;  //variabel untuk menampung status sensor
 
void setup(){
  
pinMode(pinPIR, INPUT);     //pengaturan pin PIR sebagai input
pinMode(pinRELAY, OUTPUT);  //pengaturan pin relay sebagai output
Serial.begin(9600);         //pengaturan baud rate untuk komunikasi serial sebesar 9600bps
}
void loop(){
 
statusPIR = digitalRead(pinPIR);
if (statusPIR ==HIGH) {            //jika sensor membaca gerakan maka relay akan aktif
 
digitalWrite(pinRELAY, HIGH);
Serial.println("ADA GERAKAN DELAY 10 DETIK");
delay(10000); //Diberikan waktu tunda 10 detik
}
else {
digitalWrite(pinRELAY, LOW);       //jika sensor tidak membaca gerakan maka relay akan off
Serial.println("TIDAK ADA GERAKAN");
}
}