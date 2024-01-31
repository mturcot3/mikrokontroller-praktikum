//Menampilkan nilai ADC, tegangan, dan kecerahan sensor LDR di LCD
/*#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ldr = A3;
float tegangan;
int adc;
int kecerahan;
int nilaildr;
void setup() {
lcd.begin();
Serial.begin(9600);
}

void loop() {
adc = analogRead(ldr);
nilaildr = 1023 - adc;
tegangan = (adc*5.0)/1023;
kecerahan = map(adc,0,1023,100,0);

lcd.setCursor(0, 0);
lcd.print("ADC=");
lcd.print(adc);
lcd.setCursor(10,0);
lcd.print("V=");
lcd.print(tegangan);
lcd.setCursor(0,1);
lcd.print("Kecerahan= ");
lcd.print(kecerahan);
lcd.setCursor(15,0);
lcd.print("%");
delay(100);
 }
*/ 
//Menampilkan tingkat kecerahan dan kekeruhan
#include <LiquidCrystal_I2C.h>     
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ldr = A3;
float tegangan;
int adc;
int kecerahan;
int nilaildr;
const int LED1 = 2;
const int LED2 = 4;
int buzzer = 7;

void setup() {
  lcd.begin();
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  adc = analogRead(ldr);
  nilaildr = 1023 - adc;
  tegangan = (adc*5.0)/1023;
  kecerahan = map(adc,0,1023,100,0);

  lcd.setCursor(0, 1);
  lcd.print("Tingkat=");
  lcd.setCursor(0,0);
  lcd.print("Kecerahan= ");
  lcd.print(kecerahan);
  lcd.setCursor(15,0);
  lcd.print("%");
  delay(100);

  if (kecerahan >= 60){                
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(8,1);
    lcd.println(" JERNIH  ");
    delay(100);
  }
  else if (kecerahan > 35 && kecerahan < 60 ){            
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(8,1);
    lcd.println(" KERUH  ");
    delay(100);
  }
  else if (kecerahan < 35){         
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(8,1);
    lcd.println(" KOTOR  ");
    delay(100);
  }
  
    delay(1000);
    lcd.clear();

  }
/* Cara Program Sensor Cahaya LDR 
Dev: teknisibali // Date: 11/11/2019 // www.teknisibali.com 

int sensorPin = A5;
int sensorValue = 0;

void setup (){

  Serial.begin(9600); // Inisialisasi Port serial
  pinMode(7, OUTPUT); // LED sebagai output

}

  void loop(){
    sensorValue=analogRead(sensorPin); //Membaca nilai analog dari pin A5
    Serial.println (sensorValue); //Mencetak hasil pada monitor serial
    float voltage =sensorValue * (5.0/1023.0);
    Serial.println(voltage);

      if(voltage<=1){ //Ambang batas yang saya gunakan disini adalah bernilai 1
        digitalWrite (7, HIGH);}
      else{
        digitalWrite(7, LOW);
      }
    delay(1000); //Memberi jeda selama 1 detik
}*/