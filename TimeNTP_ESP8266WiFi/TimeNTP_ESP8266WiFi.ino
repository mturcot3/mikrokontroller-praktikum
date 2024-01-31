#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <time.h>

const char *wifiSSID = "YOUR-SSID";
const char *password = "YOUR-PASS";

/**
 * 
 *  Time Setting
 * 
 * 
 * */
void setTime(int timezone)
{
  // Synchronize time useing SNTP. This is necessary to verify that
  // the TLS certificates offered by the server are currently valid.
  Serial.print("[TIME] : Setting time using SNTP \n");

  //UNIX TIMESTAMP UTC = Total seconds from 1970
  configTime(timezone * 3600, 0, "id.pool.ntp.org");
  time_t now = time(nullptr);
  while (now < 1000)
  {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.printf("\n[TIME] : Current time: %s \n", asctime(&timeinfo));
}

/**
 * 
 *  Connecting to WiFi
 * 
 * 
 * */
void connectToWifi(const char *ssid, const char *pass)
  {
    Serial.printf("[WiFi] : Connecting to %s \n", ssid);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.printf("[WiFi] : Connected to %s \n", ssid);
    Serial.print("[WiFi] : IP ");
    Serial.println(WiFi.localIP());
  }

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  connectToWifi(wifiSSID, password);
  setTime(7);

  //Timer Using SNTP
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  time_t now = time(nullptr);
  struct tm* p_timeinfo = localtime(&now);
  Serial.printf("[NOW]  : Time = %s \n", asctime(p_timeinfo));
  
  if((p_timeinfo->tm_hour == 11) && (p_timeinfo->tm_min == 6)) {
    Serial.print(F("[DEBUG] : Turn ON"));
    digitalWrite(LED_BUILTIN, LOW);
  }

  if((p_timeinfo->tm_hour == 11) && (p_timeinfo->tm_min == 7)) {
    Serial.println(F("[DEBUG] : Turn OFF"));
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(1000);
}