#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

const char* ssid = "hidden";
const char* password = "22222222";
#define trigPin 15                          //triger HC-SR04 pin D15
#define echoPin 2                          //echo HC-SR04 pin D2
// inisialisasi Bot Token
#define BOTtoken "6045596391:AAF2weQAOaNccRS7c5GGWWE0MaK4E14YTCs"  // Bot Token dari BotFather

// chat id dari @myidbot
#define CHAT_ID "1840057835"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int const buzzPin = 12;
const int LED1 = 13;

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(buzzPin, OUTPUT);
pinMode(LED1 , OUTPUT);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "Wifi Connected!", "");
  bot.sendMessage(CHAT_ID, "System has Started!!", "");

}
void loop()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int t = pulseIn(echoPin, HIGH);
  int cm = t * 0.034 / 2;
if (cm <= 10 && cm>= 0) {
digitalWrite(buzzPin, HIGH);
digitalWrite(LED1, HIGH);
bot.sendMessage(CHAT_ID, "ALERT! MOTION DETECTED!!", "");

} else {
digitalWrite(buzzPin, LOW);
digitalWrite(LED1, LOW);
}

}
