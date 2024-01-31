//Menampilkan nilai suhu tubuh di LCD
/*
#include <LiquidCrystal_I2C.h> 
#include <OneWire.h> 
#include <DallasTemperature.h> 
#define ONE_WIRE_BUS 2  
LiquidCrystal_I2C lcd(0x27, 16, 2); 

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensor(&oneWire);
float suhuDS18B20; 

void setup(void)
{
  lcd.begin();
  lcd.backlight();
}

void loop(void)
{
  //sensor.setResolution(11);  
  sensor.setResolution(10);
  //sensor.setResolution(11);
 // sensor.setResolution(12);
  sensor.requestTemperatures();  
  suhuDS18B20 = sensor.getTempCByIndex(0);  

  //Serial.println(suhuDS18B20, 1);  
  Serial.println(suhuDS18B20, 2);  
  //Serial.println(suhuDS18B20, 3);  
  //Serial.println(suhuDS18B20, 4);  

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu = ");
  lcd.setCursor(7, 0);
  lcd.print(suhuDS18B20, 4);
  lcd.print((char)223);
  lcd.print("C"); 
  delay(500);   

}
*/
//Mengetahui nilai suhu dengan bantuan solder panas dan menampilkan hasil pembacaan di LCD
/*#include <LiquidCrystal_I2C.h> 
#include <OneWire.h> 
#include <DallasTemperature.h> 
#define ONE_WIRE_BUS 6  
LiquidCrystal_I2C lcd(0x27, 16, 2); 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensor(&oneWire); 
float suhuDS18B20;
float suhuDS18B20b; 

void setup(void)
{
  lcd.begin();
  lcd.backlight();

}

void loop(void)
{
  //sensor.setResolution(9); 
  //sensor.setResolution(10);
  //sensor.setResolution(11);
  sensor.setResolution(12);
  sensor.requestTemperatures();  
  suhuDS18B20 = sensor.getTempCByIndex(0); 
  suhuDS18B20b = sensor.getTempCByIndex(1); 

  //Serial.println(suhuDS18B20, 1); 
  //Serial.println(suhuDS18B20, 2); 
  //Serial.println(suhuDS18B20, 3);  
  Serial.println(suhuDS18B20, 4);  
  Serial.println(suhuDS18B20b, 4);

  lcd.setCursor(0, 0);
  lcd.print("Suhu 1 = ");
  lcd.setCursor(8, 0);
  lcd.print(suhuDS18B20, 1);
  lcd.print((char)223);
  lcd.print("C"); 
  delay(1000);  

  lcd.setCursor(0, 1);
  lcd.print("Suhu 2 = ");
  lcd.setCursor(8, 1);
  lcd.print(suhuDS18B20b, 1);
  lcd.print((char)223);
  lcd.print("C"); 
  delay(1000);  
}
*/

/*//program dari dosen
#include <LiquidCrystal_I2C.h> // Memanggil library LCD
#include <OneWire.h> //Memanggil library OneWire yang diperlukan sebagai dependensi library Dallas Temperature
#include <DallasTemperature.h> // Memanggil library Dallas Temperature
#define ONE_WIRE_BUS 2  // Menempatkan PIN hasil pembacaan sensor DS18B20 pada PIN 2. 
   //Disebut One Wire karena kita bisa menempatkan sensor DS18B20 lain pada PIN yang sama  
LiquidCrystal_I2C lcd(0x27, 16, 2); // Mengatur alamat LCD dan dimensi LCD, yaitu 20 kolom dan 4 baris

OneWire oneWire(ONE_WIRE_BUS); //Membuat variabel oneWire berdasarkan PIN yang telah didefinisikan
DallasTemperature sensor(&oneWire); //Membuat variabel untuk menyimpan hasil pengukuran
float suhuDS18B20; //deklarasi variable suhu DS18B20 dengan jenis data float

void setup(void)
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("POLINES");
  lcd.setCursor(0, 1);
  lcd.print("JAYA");
  Serial.begin(9600); //Menginisiasikan setup kecepatan komunikasi
  sensor.begin();      //Menginisiasikan sensor One-Wire DS18B20
  delay(2000);
}

void loop(void)
{
  //sensor.setResolution(9);  // Sebelum melakukan pengukuran, atur resolusinya
  //sensor.setResolution(10);
  //sensor.setResolution(11);
  sensor.setResolution(12);
  sensor.requestTemperatures();  // Perintah konversi suhu
  suhuDS18B20 = sensor.getTempCByIndex(0);  //Membaca data suhu dari sensor #0 dan mengkonversikannya ke nilai Celsius
  // suhuDS18B20 = (suhuDS18B20*9/5) + 32;
  // suhuDS18B20 = suhuDS18B20 = 273.15;
  //Serial.println(suhuDS18B20, 1);  //Presisi 1 digit
  //Serial.println(suhuDS18B20, 2);  //Presisi 2 digit
  //Serial.println(suhuDS18B20, 3);  //Presisi 3 digit
  Serial.println(suhuDS18B20, 4);  //Presisi 4 digit
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(6, 0);
  lcd.print(suhuDS18B20, 4);
  lcd.print((char)223);
  lcd.print("C"); 
  delay(1000);    //delay 1 detik (1000 miliseconds)
}
*/
//ds18b20 with lcd i2c
/* DS18B20 1-Wire digital temperature sensor with 16x2 I2C LCD and Arduino example code. More info: https://www.makerguides.com */
/*
// Include the required Arduino libraries:
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// Define to which pin of the Arduino the 1-Wire bus is connected:
#define ONE_WIRE_BUS 2

// Create a new instance of the oneWire class to communicate with any OneWire device:
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library:
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Degree symbol:
byte Degree[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  // Start up the library:
  sensors.begin();
  // Start the LCD and turn on the backlight:
  lcd.begin();
  lcd.backlight();
  // Create a custom character:
  lcd.createChar(0, Degree);
}

void loop() {
  // Send the command for all devices on the bus to perform a temperature conversion:
  sensors.requestTemperatures();

  // Fetch the temperature in degrees Celsius for device index:
  float tempC = sensors.getTempCByIndex(0); // the index 0 refers to the first device

  // Print the temperature on the LCD;
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print(tempC);
  lcd.write(0); // print the custom character
  lcd.print("C");

  // Wait 1 second:
  delay(1000);
}
*/
/* DS18B20 1-Wire digital temperature sensor with Arduino example code. More info: https://www.makerguides.com */
/*
// Include the required Arduino libraries:
#include <OneWire.h>
#include <DallasTemperature.h>

// Define to which pin of the Arduino the 1-Wire bus is connected:
#define ONE_WIRE_BUS 2

// Create a new instance of the oneWire class to communicate with any OneWire device:
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library:
DallasTemperature sensors(&oneWire);

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Start up the library:
  sensors.begin();
}

void loop() {
  // Send the command for all devices on the bus to perform a temperature conversion:
  sensors.requestTemperatures();

  // Fetch the temperature in degrees Celsius for device index:
  float tempC = sensors.getTempCByIndex(0); // the index 0 refers to the first device
  // Fetch the temperature in degrees Fahrenheit for device index:
  float tempF = sensors.getTempFByIndex(0);

  // Print the temperature in Celsius in the Serial Monitor:
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");

  // Print the temperature in Fahrenheit
  Serial.print(tempF);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("F");

  // Wait 1 second:
  delay(1000);
}*/
/* Multiple DS18B20 1-Wire digital temperature sensors with Arduino example code. More info: https://www.makerguides.com */
/*
// Include the required Arduino libraries:
#include <OneWire.h>
#include <DallasTemperature.h>


// Define to which pin of the Arduino the 1-Wire bus is connected:
#define ONE_WIRE_BUS 2

// Create a new instance of the oneWire class to communicate with any OneWire device:
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library:
DallasTemperature sensors(&oneWire);

int deviceCount = 0;
float tempC;
float tempF;

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Start up the library:
  sensors.begin();

  // Locate the devices on the bus:
  Serial.println("Locating devices...");
  Serial.print("Found ");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount);
  Serial.println(" devices");
}

void loop() {
  // Send the command for all devices on the bus to perform a temperature conversion:
  sensors.requestTemperatures();

  // Display temperature from each sensor
  for (int i = 0;  i < deviceCount;  i++) {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" : ");
    tempC = sensors.getTempCByIndex(i);
    tempF = sensors.getTempFByIndex(i);
    Serial.print(tempC);
    Serial.print(" \xC2\xB0"); // shows degree symbol
    Serial.print("C  |  ");
    Serial.print(tempF);
    Serial.print(" \xC2\xB0"); // shows degree symbol
    Serial.println("F");
  }

  Serial.println();
  delay(1000);
}
*/
//adress finder ds18b20
/* Multiple DS18B20 1-Wire digital temperature sensors with Arduino example code. More info: https://www.makerguides.com */
/*
// Include the required Arduino libraries:
#include <OneWire.h>
#include <DallasTemperature.h>

// Define to which pin of the Arduino the 1-Wire bus is connected:
#define ONE_WIRE_BUS 2

// Create a new instance of the oneWire class to communicate with any OneWire device:
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library:
DallasTemperature sensors(&oneWire);

// Create variables:
int deviceCount = 0; // variable to store the number of devices connected
DeviceAddress deviceAddress; // variable to store the device address

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Start up the library:
  sensors.begin();

  // Locate the devices on the bus:
  Serial.println("Locating devices...");
  Serial.print("Found ");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount);
  Serial.println(" devices");

  Serial.println("Printing addresses...");
  for (int i = 0;  i < deviceCount;  i++) {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" : ");
    sensors.getAddress(deviceAddress, i);
    printAddress(deviceAddress);
  }
}

void loop() {
}

void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    Serial.print("0x");
    if (deviceAddress[i] < 0x10) {
      Serial.print("0");
    }
    Serial.print(deviceAddress[i], HEX);
    if (i < 7) {
      Serial.print(", ");
    }
  }
  Serial.println();
}
*/
//Read sensors by address Arduino example code
/* Read multiple DS18B20 1-Wire digital temperature sensors by address. More info: https://www.makerguides.com */
/*
// Include the required Arduino libraries:
#include <OneWire.h>
#include <DallasTemperature.h>

// Define to which pin of the Arduino the 1-Wire bus is connected:
#define ONE_WIRE_BUS 2

// Create a new instance of the oneWire class to communicate with any OneWire device:
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library:
DallasTemperature sensors(&oneWire);

// Addresses of DS18B20 sensors connected to the 1-Wire bus
byte sensor1[8] = {0x28, 0x18, 0xB4, 0x49, 0x0C, 0x00, 0x00, 0x7C};
byte sensor2[8] = {0x28, 0xCC, 0x19, 0x49, 0x0C, 0x00, 0x00, 0xBB};
byte sensor3[8] = {0x28, 0x19, 0xEF, 0x48, 0x0C, 0x00, 0x00, 0x21};

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Start up the library:
  sensors.begin();
}

void loop() {
  // Send the command for all devices on the bus to perform a temperature conversion:
  sensors.requestTemperatures();

  Serial.print("Sensor 1: ");
  printTemperature(sensor1); // call the printTemperature function with the address of sensor1 as input
  Serial.print("Sensor 2: ");
  printTemperature(sensor2);
  Serial.print("Sensor 3: ");
  printTemperature(sensor3);

  Serial.println(); // prints an empty line
  delay(1000);
}

void printTemperature(DeviceAddress address) {
  // Fetch the temperature in degrees Celsius for device address:
  float tempC = sensors.getTempC(address);
  // Fetch the temperature in degrees Fahrenheit for device address:
  float tempF = sensors.getTempF(address);
  Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");

  // Print the temperature in Fahrenheit
  Serial.print(tempF);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("F");
}*/