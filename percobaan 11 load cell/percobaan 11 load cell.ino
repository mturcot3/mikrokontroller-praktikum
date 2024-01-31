
#include "HX711.h" //memasukan library HX711
#include <LiquidCrystal_I2C.h>
//uint8_t DOUT = 6;
//uint8_t CLK = 12;
//HX711 scale;
LiquidCrystal_I2C lcd(0x27,16,2);
#define DOUT  A0 //mendefinisikan pin arduino yang terhubung dengan pin DT module HX711
#define CLK  A1 //mendefinisikan pin arduino yang terhubung dengan pin SCK module HX711

HX711 scale(DOUT, CLK);

float calibration_factor = -108000; //nilai kalibrasi ( sesuaikan dari hasil nilai percobaan program sebelumnya

void setup() {
  Serial.begin(9600);
  Serial.println("Memulai program kalibrasi pada sensor berat");
  Serial.println("Pastikan tidak ada beban diatas sensor");
  delay(5000);
  scale.set_scale();
  scale.tare(); // auto zero / mengenolkan pembacaan berat

  long zero_factor = scale.read_average(); //membaca nilai output sensor saat tidak ada beban
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);

  lcd.begin();
  lcd.backlight();
}

void loop() {

  scale.set_scale(calibration_factor); //sesuaikan hasil pembacaan dengan nilai kalibrasi

  Serial.print("Berat: ");
  Serial.print(scale.get_units(), 1);
  Serial.println(" kg");


  lcd.setCursor(0,0);
  lcd.print("Berat = ");
  lcd.print(scale.get_units(), 1);
  lcd.setCursor(13,0);
  lcd.print("kg");
  
  delay(500);

  lcd.clear();
}
// program kalibrasi load cell
/*#include "HX711.h"
#define DOUT  A0
#define CLK  A1
HX711 scale(DOUT, CLK);
float calibration_factor = -108;
int GRAM;

void setup() {
  Serial.begin(9600);
  Serial.println("tekan a,s,d,f untuk menaikan calibration_factor ke 10,100,1000,10000");
  Serial.println("tekan z,x,c,v untuk menurunkan calibration_factor ke 10,100,1000,10000");
  Serial.println("Tekan T untuk Tare");
  scale.set_scale();
  scale.tare();
  long zero_factor = scale.read_average();
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
  delay(1000);
}

void loop() {
  scale.set_scale(calibration_factor);
  GRAM = scale.get_units(), 4;
  Serial.print("Reading: ");
  Serial.print(GRAM);
  Serial.print(" Gram");
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();

  if (Serial.available()) {
    char temp = Serial.read();
    if (temp == '+' || temp == 'a')
      calibration_factor += 0.1;
    else if (temp == '-' || temp == 'z')
      calibration_factor -= 0.1;
    else if (temp == 's')
      calibration_factor += 10;
    else if (temp == 'x')
      calibration_factor -= 10;
    else if (temp == 'd')
      calibration_factor += 100;
    else if (temp == 'c')
      calibration_factor -= 100;
    else if (temp == 'f')
      calibration_factor += 1000;
    else if (temp == 'v')
      calibration_factor -= 1000;
    else if (temp == 't')
      scale.tare();
  }
}
*/