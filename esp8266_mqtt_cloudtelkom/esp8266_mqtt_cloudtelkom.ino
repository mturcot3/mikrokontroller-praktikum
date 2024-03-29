#include <Adafruit_Sensor.h> //Library for Adafruit sensors , we are using for DHT
//#include <DHT_U.h> //DHT library which uses some func from Adafruit Sensor library
#include <ESP8266WiFi.h> //library for using ESP8266 WiFi 
#include <PubSubClient.h> //library for MQTT
#include <ArduinoJson.h> //library for Parsing JSON

//defining Pins
//#define DHTPIN 5
#define LED D2

//DHT parameters
//#define DHTTYPE    DHT11     // DHT 11
//DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

//MQTT Credentials
const char* ssid = "hidden";//setting your ap ssid
const char* password = "22222222";//setting your ap psk
const char* mqttServer = "mqtt.telkomiot.id"; //MQTT URL
const char* mqttUserName = "18c8b13218fddb51";  // MQTT username
const char* mqttPwd = "18c8b13218f9f4e2";  // MQTT password
const char* clientID = "APP6583d45e9893e56961"; // client id username+0001
const char* topic = "v2.0/pubs/APP6583d45e9893e56961/DEV6583d4a79ae9145446"; //publish topic

//parameters for using non-blocking delay
unsigned long previousMillis = 0;
const long interval = 5000;

String msgStr = "";      // MQTT message buffer

float temp, hum;


//setting up wifi and mqtt client
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(clientID, mqttUserName, mqttPwd)) {
      Serial.println("MQTT connected");
      client.subscribe("api/command/37/#");
      Serial.println("Topic Subscribed");
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);  // wait 5sec and retry
    }

  }

}

//subscribe call back
void callback(char*topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  Serial.print("Message size :");
  Serial.println(length);
  Serial.println();
  Serial.println("-----------------------");

  StaticJsonDocument<256> doc; //read JSON data
  deserializeJson(doc, payload, length); //deserialise it
  JsonObject command = doc["command"]; //get the values of command parameter

  int command_parameters_led = command["parameters"]["led"]; //get value of led, which will be 1 or 0

  if (command_parameters_led == 1) {
    Serial.println("LED");
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}


void setup() {
  Serial.begin(9600);
  // Initialize device.
  //dht.begin();
  // get temperature sensor details.
 // sensor_t sensor;
 // dht.temperature().getSensor(&sensor);
 // dht.humidity().getSensor(&sensor);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  setup_wifi();

  client.setServer(mqttServer, 1883); //setting MQTT server
  client.setCallback(callback); //defining function which will be called when message is recieved.

}

void loop() {
  if (!client.connected()) { //if client is not connected
    reconnect(); //try to reconnect
  }
  client.loop();

  unsigned long currentMillis = millis(); //read current time

  if (currentMillis - previousMillis >= interval) { //if current time - last time > 5 sec
    previousMillis = currentMillis;

    //read temp and humidity
   // sensors_event_t event;
  //  dht.temperature().getEvent(&event);


   /* if (isnan(event.temperature)) {
      Serial.println(F("Error reading temperature!"));
    }
    else {
      Serial.print(F("Temperature: "));
      temp = event.temperature;
      Serial.print(temp);
      Serial.println(F("°C"));
    }
    // Get humidity event and print its value.
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity)) {
      Serial.println(F("Error reading humidity!"));
    }
    else {
      Serial.print(F("Humidity: "));
      hum = event.relative_humidity;
      Serial.print(hum);
      Serial.println(F("%"));
    }
*/
int temp = 20;
int hum = 70;
    msgStr = "{\"Project\": \"Monitoring Suhu\",\"By\": \"A. Miftahur Riziq\",\"notification\":{\"notification\": \"temperature\",\"parameters\":{\"temp\":" + String(temp) + ",\"humi\":" + String(hum) + "}}}";
    byte arrSize = msgStr.length() + 1;
    char msg[arrSize];

    Serial.print("PUBLISH DATA:");
    Serial.println(msgStr);
    msgStr.toCharArray(msg, arrSize);
    client.publish(topic, msg);
    msgStr = "";
    delay(50);

  }

}
