
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

const char* ssid = "Rejoagung";
const char* password = "rizkaaja";

#define DHTPIN 27    

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);
//boolean state_t, state_h;

// inisialisasi Bot Token
#define BOTtoken "5861437332:AAE6rjcH2UyLY32Us56ao6GJKO195SJIzag"  // Bot Token dari BotFather

// chat id dari @myidbot
#define CHAT_ID "1554993424"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int botRequestDelay = 1000;
unsigned long lastTimeBotRan;



void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

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
      int t= dht.readTemperature();
      if (isnan(t)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
      }
      String suhu = "Status Suhu ";
      suhu += t;
      suhu +=" ⁰C\n";
      bot.sendMessage(chat_id, suhu, "");
    }
    
    if (text == "/Humidity") {
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

  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  
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