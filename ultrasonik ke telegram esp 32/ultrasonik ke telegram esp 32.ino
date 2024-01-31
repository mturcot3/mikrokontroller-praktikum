#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

const char* ssid = "hidden";
const char* password = "22222222";
#define trig 15                          //triger HC-SR04 pin D15
#define echo 2                          //echo HC-SR04 pin D2


// Uncomment the type of sensor in use:
//define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

//DHT dht(DHTPIN, DHTTYPE);
//boolean state_t, state_h;

// inisialisasi Bot Token
#define BOTtoken "6045596391:AAF2weQAOaNccRS7c5GGWWE0MaK4E14YTCs"  // Bot Token dari BotFather

// chat id dari @myidbot
#define CHAT_ID "1840057835"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int t = pulseIn(echo, HIGH);
  int cm = t * 0.034 / 2;

  for (int i=0; i<numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);    
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;
  
    if (text == "/start") {
      String control = "Selamat Datang, " + from_name + ".\n";
      control += "Gunakan Commands Di Bawah Untuk Monitoring DHT11\n\n";
      control += "/Temperatur Untuk Monitoring Suhu \n";
      control += "/Humidity Untuk Monitoring Kelembapan \n";
      bot.sendMessage(chat_id, control, "");
    
    }

    if (text == "/Temperatur") {

      if (isnan(cm)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
      }
      String suhu = "Status Suhu ";
      suhu += cm;
      suhu +=" ⁰Cm\n";
      bot.sendMessage(chat_id, suhu, "");
    }
  if (cm < 10)  {
bot.sendMessage(chat_id, "pelanggaran");    
  }    
  else {
bot.sendMessage(chat_id, "");    
  }     
    
   /* if (text == "/Humidity") {
      int h= dht.readHumidity();
      if (isnan(h)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
      }
      String lembab = "Status Kelembapan ";
      lembab += h;
      lembab +=" %Rh\n";
      bot.sendMessage(chat_id, lembab, "");
    }
*/
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(trig, OUTPUT);                   //Output pin MODE triger HC-SR04
  pinMode(echo, INPUT);                    //input pin MODE echo HC-SR04

  
  // Koneksi Ke Wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
      
    }
    lastTimeBotRan = millis();
    
  }

}