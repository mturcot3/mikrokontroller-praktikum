#include <WiFi.h>
#include <ArduinoJson.h>
#include <CTBot.h>
CTBot pelanggaranBot ;
String ssid = "hidden";
String password = "22222222";
#define trig 15                          //triger HC-SR04 pin D15
#define echo 2                          //echo HC-SR04 pin D2
#define relay 5
#define buzz 12
// inisialisasi Bot Token
#define BOTtoken "6045596391:AAF2weQAOaNccRS7c5GGWWE0MaK4E14YTCs"  // Bot Token dari BotFather

// chat id dari @myidbot
const int CHAT_ID = 1840057835;

void setup() {
  Serial.begin(115200);
  pinMode(trig, OUTPUT);                   //Output pin MODE triger HC-SR04
  pinMode(echo, INPUT);                    //input pin MODE echo HC-SR04
  pinMode(relay, OUTPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(relay, LOW);
  digitalWrite(buzz, LOW);
  pelanggaranBot.wifiConnect(ssid, password);
  pelanggaranBot.setTelegramToken(BOTtoken);

// uji apakah sudah terkoneksi
  if (pelanggaranBot.testConnection())
    {        
      Serial.println("Terkoneksi");
      
    }      
  else {
    Serial.println("tidak terkoneksi");
      }

  }

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int t = pulseIn(echo, HIGH);
  int cm = t * 0.034 / 2;
  Serial.println("cm =");
  Serial.println(cm);
  if (cm < 10)  {
  pelanggaranBot.sendMessage(CHAT_ID, "pelanggaran");    
  }    
  else {
  pelanggaranBot.sendMessage(CHAT_ID, ""); 
  }  
  delay (500); 
  
TBMessage msg;

  if (pelanggaranBot.getNewMessage(msg))
  {
    if (msg.text.equalsIgnoreCase("/relayOn"))
    {
      Serial.println("Mengirim pesan ke Telegram...");
      digitalWrite(relay, HIGH);
      pelanggaranBot.sendMessage(msg.sender.id, "Relay ON");
    }
    else if (msg.text.equalsIgnoreCase("/relayOff"))
    {
      Serial.println("Mengirim pesan ke Telegram...");
      digitalWrite(relay, LOW);
      pelanggaranBot.sendMessage(msg.sender.id, "Relay OFF");
    }
    else if (msg.text.equalsIgnoreCase("/buzzOn"))
    {
      Serial.println("Mengirim pesan ke Telegram...");
      digitalWrite(buzz, HIGH);
      pelanggaranBot.sendMessage(msg.sender.id, "Buzzer ON");
    }
    else if (msg.text.equalsIgnoreCase("/buzzOff"))
    {
      Serial.println("Mengirim pesan ke Telegram...");
      digitalWrite(buzz, LOW);
      pelanggaranBot.sendMessage(msg.sender.id, "Buzzer Off");
    }

    else if (msg.text.equalsIgnoreCase("/kondisi"))
    {
      Serial.println("Mengirim pesan ke Telegram...");
      
      String welcome = "Status saat ini.\n";
      welcome += "Relay : ";
      boolean a = digitalRead(relay);
      if (a)welcome += "ON.\n";
      else welcome += "OFF.\n";

      welcome += "Buzzer : ";
      boolean b = digitalRead(buzz);
      if (b)welcome += "ON.\n";
      else welcome += "OFF.\n";
      pelanggaranBot.sendMessage(msg.sender.id, welcome);
    }
    else if (msg.text.equalsIgnoreCase("/start"))
    {
      Serial.println("Mengirim pesan ke Telegram...");

      String balasan;
      balasan = (String)"Welcome " + msg.sender.username + (String)".\n" +
                (String)"/relayOn : untuk mengaktifkan relay.\n" +
                (String)"/relayOff : untuk nonaktifkan relay.\n" +
                (String)"/BuzzOn : untuk mengaktifkan buzzer.\n" +
                (String)"/BuzzOff : untuk nonaktifkan buzzer.\n" +
                (String)"/sensor : untuk menampilkan data sensor.\n" +
                (String)"/kondisi : cek kondisi saat ini.";
      pelanggaranBot.sendMessage(msg.sender.id, balasan);
    }
    else
    {
      Serial.println("Mengirim pesan ke Telegram...");
      String balasan;
      balasan = (String)"Pesan tidak ada!\n" +
                (String)"Silahkan cek kembali dengan\n" +
                (String)"mengirim pesan /start.";
      pelanggaranBot.sendMessage(msg.sender.id, balasan);
    }
  }
  delay(500);
}
