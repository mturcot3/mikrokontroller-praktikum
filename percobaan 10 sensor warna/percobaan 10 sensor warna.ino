//Kalibrasi sensor TCS 3200
/*
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int redPW = 0;
int greenPW = 0;
int bluePW = 0;


void setup() {
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  pinMode(sensorOut, INPUT);

  Serial.begin(9600);
  

}
void loop() {

redPW = getRedPW();
delay(1000);


greenPW = getGreenPW();
delay(1000);


bluePW = getBluePW();
delay(1000);

Serial.println("Red PW= ");
Serial.println(redPW);
Serial.println("Green PW= ");
Serial.println(greenPW);
Serial.println("Blue PW= ");
Serial.println(bluePW);

}

int getRedPW(){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  int PW;
  PW = pulseIn(sensorOut,LOW);
  return PW;
}
int getGreenPW(){
    digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  int PW;
  PW = pulseIn(sensorOut,LOW);
  return PW;
}
int getBluePW(){
    digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  int PW;
  PW = pulseIn(sensorOut,LOW);
  return PW;

}
*/
//Mengetahui nilai R,G,B pada tiap warna kertas
/*
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int redMin = 5;
int redMax = 214;
int greenMin = 5;
int greenMax = 238;
int blueMin = 4;
int blueMax = 254;

int redPW = 0;
int greenPW = 0;
int bluePW = 0;

int redValue;
int greenValue;
int blueValue;


void setup() {
  // put your setup code here, to run once:
    
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);

pinMode(sensorOut, INPUT);

digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
redPW = getRedPW();
redValue = map(redPW, redMin, redMax, 255, 0);
delay(1000);
greenPW = getGreenPW();
greenValue = map(greenPW, greenMin, greenMax, 255, 0);
delay(1000);
bluePW = getBluePW();
blueValue = map(bluePW, blueMin, blueMax, 255, 0);
delay(1000);
Serial.println("Red = ");
Serial.println(redValue);
Serial.println("Green = ");
Serial.println(greenValue);
Serial.println("Blue = ");
Serial.println(blueValue);
}

int getRedPW(){
digitalWrite(S2, LOW);
digitalWrite(S3, LOW);
int PW;
PW = pulseIn(sensorOut, LOW);
return PW;
}

int getGreenPW(){
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);
int PW;
PW = pulseIn(sensorOut, LOW);
return PW;
}

int getBluePW(){
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);
int PW;
PW = pulseIn(sensorOut, LOW);
return PW;
   
}
*/
// mendeteksi warna kertas
/*
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

 #define r 10
 #define g 11
 #define b 12
// Calibration Values
// Get these from Calibration Sketch
 
int redMin = 17; // Red minimum value
int redMax = 222; // Red maximum value
int greenMin = 19; // Green minimum value
int greenMax = 247; // Green maximum value
int blueMin = 14; // Blue minimum value
int blueMax = 196; // Blue maximum value
 
// Variables for Color Pulse Width Measurements
 
int redPW = 0;
int greenPW = 0;
int bluePW = 0;
 
// Variables for final Color values
 
int redValue;
int greenValue;
int blueValue;
 
void setup() {
 
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  
  // Set Frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);


  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  // Setup Serial Monitor
  Serial.begin(9600);
   lcd.begin();
   lcd.backlight();
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(r, red_light_value);
  analogWrite(g, green_light_value);
  analogWrite(b, blue_light_value);
 }
 void tampil()
 {
  
  lcd.setCursor(0,0);
  lcd.print("R=");
  lcd.print(redValue);
  
  lcd.setCursor(6,0);
  lcd.print("G=");
  lcd.print(greenValue);

  lcd.setCursor(12,0);
  lcd.print("B=");
  lcd.print(blueValue);
 }

 void warna()
 {
  
  if(redValue > greenValue && redValue > blueValue)
  {
      
      lcd.setCursor(0,1);
      lcd.print("WARNA MERAH");
       RGB_color(255,0,0); 
       
  }
  if(greenValue > redValue && greenValue > blueValue)
  {
    
      lcd.setCursor(0,1);
      lcd.print("WARNA HIJAU");
     RGB_color(0,255,0);
     
  }
  if(blueValue > redValue && blueValue > greenValue)
  {
      
      lcd.setCursor(0,1);
      lcd.print("WARNA BIRU");
     RGB_color(0,0,255); 
     
  }
  if(blueValue < redValue && blueValue < greenValue)
  {
      
      lcd.setCursor(0,1);
      lcd.print("WARNA KUNING");
     RGB_color(252,249,239); 
     
  }
  if(blueValue < redValue && blueValue < greenValue)
  {
      
      lcd.setCursor(0,1);
      lcd.print("WARNA COKLAT");
     RGB_color(255,215,0); 
     
  }
  if(blueValue == redValue && blueValue == greenValue)
  {
      
      lcd.setCursor(0,1);
      lcd.print("WARNA PUTIH");
     RGB_color(255,255,255); 
   
  }
  if(blueValue == redValue == greenValue)
  {
      
      lcd.setCursor(0,1);
      lcd.print("WARNA HITAM");
     RGB_color(0,0,0); 
  
  }
 }
void loop() {
  lcd.clear();
warna();
  tampil();
  // Read Red value
  redPW = getRedPW();
  // Map to value from 0-255
  redValue = map(redPW, redMin,redMax,255,0);
  // Delay to stabilize sensor
  delay(500);
  
  // Read Green value
  greenPW = getGreenPW();
  // Map to value from 0-255
  greenValue = map(greenPW, greenMin,greenMax,255,0);
  // Delay to stabilize sensor
  delay(500);
  
  // Read Blue value
  bluePW = getBluePW();
  // Map to value from 0-255
  blueValue = map(bluePW, blueMin,blueMax,255,0);
  // Delay to stabilize sensor
  delay(500);
  
  // Print output to Serial Monitor
  Serial.print("Red = ");
  Serial.print(redValue);
  Serial.print(" - Green = ");
  Serial.print(greenValue);
  Serial.print(" - Blue = ");
  Serial.println(blueValue);
  
  
}
 
 
// Function to read Red Pulse Widths
int getRedPW() {
 
  // Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
 
}
 
// Function to read Green Pulse Widths
int getGreenPW() 
{
 
  // Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
 
}
 
// Function to read Blue Pulse Widths
int getBluePW() 
{
 
  // Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}
*/
//program mendetekdi rgb dari web 
//Developer: Mohd Qhairul Bakri
//Tarikh: 3 Jan 2019
/*
#define s0 4
#define s1 5
#define s2 6
#define s3 7
#define sensorOut 8

int frequency = 0;

void setup() 
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);

  Serial.begin(9600);
}

void loop() 
{
//mod bacaan merah
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  frequency = pulseIn(sensorOut, LOW); //membaca frekuensi pada pin 8
  Serial.print("R=");
  Serial.print(frequency);
  Serial.print(" ");
  delay(100);
  
//mod bacaan hijau
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  frequency = pulseIn(sensorOut, LOW); //membaca frekuensi pada pin 8
  Serial.print("G=");
  Serial.print(frequency);
  Serial.print(" ");
  delay(100);

//mod bacaan biru
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  frequency = pulseIn(sensorOut, LOW); //membaca frekuensi pada pin 8
  Serial.print("B=");
  Serial.print(frequency);
  Serial.println(" ");
  delay(1000);
}
*/
/*
    Sensor Pin S0 -> Arduino Pin D8
    Sensor Pin S1 -> Arduino Pin D7
    Sensor Pin S2 -> Arduino Pin D6
    Sensor Pin S3 -> Arduino Pin D5
    Sensor Pin OUT -> Arduino Pin D4

#define S0_PIN 5
#define S1_PIN 4
#define S2_PIN 7
#define S3_PIN 6
#define OUT_PIN  8
void setup()
{
  // Set the S0, S1, S2, S3 Pins as Output
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);
  //Set OUT_PIN as Input
  pinMode(OUT_PIN, INPUT);
  // Set Pulse Width scaling to 20%
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, LOW);
  // Enabl UART for Debugging
  Serial.begin(9600);
}
void loop()
{
  int r, g, b;
  r = process_red_value();
  delay(200);
  g = process_green_value();
  delay(200);
  b = process_blue_value();
  delay(200);
  Serial.print("r = ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print("g = ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print("b = ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println();
  if (r < 42)
  {
    Serial.println("Colour Pink");
  }
  else if (g < 63)
  {
    Serial.println("Colour Green");
  }
  else if (r < 64)
  {
    Serial.println("Colour Red");
  }
}
int process_red_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, LOW);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_green_value()
{
  digitalWrite(S2_PIN, HIGH);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_blue_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
*/