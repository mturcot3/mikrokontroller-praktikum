//Libraries Untuk Modul LCD dan I2C
//=====================================================//
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6c7fsfqqx"
#define BLYNK_TEMPLATE_NAME "smart traffict light"
#define BLYNK_AUTH_TOKEN "5CMPntZgX4R2MfyHNQVsSfmsvDUDzGt5"
char auth[] = "5CMPntZgX4R2MfyHNQVsSfmsvDUDzGt5";
char ssid[] = "hidden";
char pass[] = "22222222";
//======= Library=============//

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>  
#include <LiquidCrystal_I2C.h> 
//LiquidCrystal_I2C lcd(0x27, 16, 2);
WidgetLCD lcd(V6);                       //WidgetLCD temperature dan humidity
WidgetLCD lcd2(V7);
WidgetLCD lcd3(V8);
WidgetLCD lcd4(V9);
#define pinBuzzer 5
#define pinLedMerah 15
#define pinLedKuning 2
#define pinLedHijau 4
#define pinLedMerah2 26
#define pinLedKuning2 27
#define pinLedHijau2 14

// Untuk Sensor Ultrasonik
#define trig 13
#define echo 12
#define trig2 33
#define echo2 32

// Sensor LDR
#define ldrPin 34
#define lamp 22
const float gama = 0.7;
const float rl10 = 50;
long durasi, jarak, durasi2, jarak2;

int delayMerah = 500;
int delayMerah2 = 500;
int delayKuning = 100;
int delayKuning2 = 100;
int delayHijau = 500;
int delayHijau2 = 500;
int totalPelanggaran = 0;
int totalPelanggaran2 = 0;
int jarakStandar = 10;
 //  BLYNK_WRITE(V0) {
 // digitalWrite(pinLedMerah, param.asInt());    // kontrol manual pump di blynk
 //  } 

BlynkTimer timer;
void setup() {
  Blynk.begin(auth,ssid,pass);  
  Serial.begin(9600);       // digunakan untuk komunikasi Serial dengan komputer  
//  lcd.begin();   // iInit the LCD for 16 chars 2 lines
  pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echo, INPUT);     // set pin echo menjadi INPUT
  pinMode(trig2, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echo2, INPUT);     // set pin echo menjadi INPUT
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinLedMerah, OUTPUT);
  pinMode(pinLedKuning, OUTPUT);
  pinMode(pinLedHijau, OUTPUT);
  pinMode(pinLedMerah2, OUTPUT);
  pinMode(pinLedKuning2, OUTPUT);
  pinMode(pinLedHijau2, OUTPUT);
  digitalWrite(lamp, HIGH);              // kondisi awal supaya relay mati  
  lcd.clear();
  lcd2.clear();
  lcd3.clear();
  lcd4.clear();  
//  timer.setInterval(10L, LDR); 
}

void loop() {
  lampu();
  LDR();
  Blynk.run();  

}

void lampu() {
  // Lampu merah menyala
 cekJarak("merah");  
  digitalWrite(pinLedMerah, HIGH);
  digitalWrite(pinLedMerah2, LOW);
  digitalWrite(pinLedHijau2, HIGH);
  digitalWrite(pinLedHijau, LOW);
  LDR();
  // Selama lampu merah menyala
  // Harus dicek jarak secara realtime
  cekJarak("merah");
//  delay(delayMerah);
  digitalWrite(pinLedHijau2, LOW);
  digitalWrite(pinLedKuning, LOW);
  digitalWrite(pinLedKuning2, HIGH);
  LDR();
//  cekJarak2("kuning2");
delay(delayKuning2);
  LDR();
  digitalWrite(pinLedHijau, HIGH);
  digitalWrite(pinLedMerah, LOW);
  digitalWrite(pinLedKuning2, LOW);
  // Lampu Hijau menyala selama 5 detik
  digitalWrite(pinLedMerah2, HIGH);
  LDR();
  cekJarak2("merah2");
//  digitalWrite(pinLedHijau, HIGH);
  delay(delayHijau);
  LDR();
  // Lampu Hijau dimatikan
  // Persiapan menuju lampu kuning
  digitalWrite(pinLedMerah2, HIGH);
  digitalWrite(pinLedKuning, HIGH);
  digitalWrite(pinLedKuning2, LOW);
  digitalWrite(pinLedHijau, LOW);
  LDR();
 // cekJarak("kuning");
  delay(delayKuning);
  LDR();
  digitalWrite(pinLedMerah2, LOW);
  digitalWrite(pinLedHijau, LOW);
  digitalWrite(pinLedKuning, LOW);
  digitalWrite(pinLedHijau2, HIGH);
  digitalWrite(pinLedMerah, HIGH);  
  cekJarak("merah"); 
  LDR(); 
  cekJarak("merah");
//  updateLCD();
//  updateLCD2();    

 // timer.run();   
    // Menyalakan Lampu kuning
  // Persiapan MenujuLampuHijau
  //digitalWrite(pinLedKuning, HIGH);
  // Lampu kuning tetap ga boleh ada yg nerobos
  //cekJarak("kuning");

}
void buzzerOn() {
  digitalWrite(pinBuzzer, HIGH);
//  totalPelanggaran = totalPelanggaran + 1;
  lcd3.print(0,0, "buzzer1:");
  lcd3.print(8,0, "ON   ");  
  //updateLCD();  
}

void buzzerOff() {
  digitalWrite(pinBuzzer, LOW);
  lcd3.print(0,0, "buzzer1:");
  lcd3.print(8,0, "OFF   ");
}
void buzzerOn2() {
  digitalWrite(pinBuzzer, HIGH);
//  totalPelanggaran2 = totalPelanggaran2 + 1;
  lcd3.print(0,1, "buzzer2:");
  lcd3.print(8,1, "ON   ");
 // updateLCD2();
}

void buzzerOff2() {
  digitalWrite(pinBuzzer, LOW);
  lcd3.print(0,1, "buzzer2:");
  lcd3.print(8,1, "OFF   ");
}


/*void updateLCD() {
//  lcd.setCursor(0,0);
  lcd.print(0,1, "pelanggaran:");
//  lcd.setCursor(0,1);
  lcd.print(13,1, totalPelanggaran);
  lcd.print(16,1, "");
  delay (1000);
}
void updateLCD2() {
//  lcd.setCursor(0,0);
  lcd2.print(0,1, "pelanggaran:");
//  lcd.setCursor(0,1);
  lcd2.print(13,1, totalPelanggaran2);
  lcd2.print(16,1, "");
  delay (1000);
}
*/
void cekJarak(String warna) {
  int warnaFix;
    LDR();
   // program dibawah ini agar trigger memancarakan suara ultrasonic]
   if (warna == "merah"){
    int delayMerahFix = round(delayMerah/24);
    warnaFix = delayMerahFix;
   } else if (warna == "kuning") {
    int delayKuningFix = round(delayKuning/16);
    warnaFix = delayKuningFix;
   }
    int t=0;
    int batas = warnaFix-2;
    while (t<warnaFix) {
          digitalWrite(trig, LOW);
          delayMicroseconds(8);
          digitalWrite(trig, HIGH);
          delayMicroseconds(8);
          digitalWrite(trig, LOW);
          delayMicroseconds(8);
      
          durasi= pulseIn(echo, HIGH);  // menerima suara ultrasonic
          jarak= (durasi/2) / 29.1;     // mengubah durasi menjadi jarak (cm)
  //        if (isnan(jarak)) {
 //   Serial.println("Failed to read from HCSR sensor!");
   // return;}
          Blynk.virtualWrite(V9, jarak); 
          Serial.print("Jarak : ");
          Serial.print(jarak);        // menampilkan jarak pada Serial Monitor  
          Serial.println(" cm ");
        //menampilkan di lcd blynk    
        //  lcd.print(0,0, "Jarak : ");
        //  lcd.print(8,0,jarak);   
        //  lcd.print(12,0, "cm");
        if (jarak < jarakStandar && t<batas) {
          buzzerOn();          
          lcd.print(0,0, "Ada Pelanggaran"); 
Blynk.logEvent("pelanggaran","ADA PELANGGARAN DI JALUR 1");    
delay(100);
                      }
        if (jarak > jarakStandar || t>batas) {
          buzzerOff();
          lcd.print(0,0, "Aman BOS        ");   
          delay(100);
        }
        t=t+1;
    }
}      
void cekJarak2(String warna2) {
  int warna2Fix;
    LDR();
   // program dibawah ini agar trigger memancarakan suara ultrasonic]
   if (warna2 == "merah2"){
    int delayMerah2Fix = round(delayMerah2/24);
    warna2Fix = delayMerah2Fix;
   } else if (warna2 == "kuning2") {
    int delayKuning2Fix = round(delayKuning2/16);
    warna2Fix = delayKuning2Fix;
   }

    int t2=0;
    int batas2 = warna2Fix-2;
    while (t2<warna2Fix) {
          digitalWrite(trig2, LOW);
          delayMicroseconds(8);
          digitalWrite(trig2, HIGH);
          delayMicroseconds(8);
          digitalWrite(trig2, LOW);
          delayMicroseconds(8);
      
          durasi2= pulseIn(echo2, HIGH);  // menerima suara ultrasonic
          jarak2= (durasi2/2) / 29.1;     // mengubah durasi menjadi jarak (cm)
          Serial.print("Jarak2 : ");
          Serial.print(jarak2);        // menampilkan jarak pada Serial Monitor  
          Serial.println(" cm ");

        if (jarak2 < jarakStandar && t2<batas2) {
          buzzerOn2();
          lcd2.print(0,0, "Ada Pelanggaran2"); 
Blynk.logEvent("pelanggaran","ADA PELANGGARAN DI JALUR 2");   
       delay(100);
        }
        if (jarak2 > jarakStandar || t2>batas2) {
          buzzerOff2();
          lcd2.print(0,0, "Aman BOS        "); 
delay(100);          
        }
        t2=t2+1;
    }
}
void LDR(){
 // put your main code here, to run repeatedly:
  //delay(10); // this speeds up the simulation
  int nilaiLDR = analogRead(ldrPin);
  nilaiLDR = map(nilaiLDR, 4095, 0, 1024, 0); //mengubah nilai pembacaan sensor LDR dari nilai ADC arduino menjadi nilai ADC ESP32
  float voltase = nilaiLDR / 1024.*5;
  float resistansi = 2000 * voltase / (1-voltase/5);
  float kecerahan = pow(rl10*1e3*pow(10,gama)/resistansi,(1/gama));
  Serial.print("Kecerahan = ");
  Serial.println(kecerahan);
  Blynk.virtualWrite(V4, kecerahan);
  Blynk.virtualWrite(V9, lamp);    
   if (kecerahan < 25)
  {
    digitalWrite(lamp,LOW);                              // saat lux dibawah 50 maka lampu akan menyala 
    lcd4.print(0,0, " lampu Menyala");
    delay (100);       
  }    
 else
  {
    digitalWrite(lamp,HIGH);                            // lampu akan mati 
    lcd4.print(0,0, " lampu Padam  ");   
    delay (100);
  }   
}
