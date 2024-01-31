const int sensor = A1;
int tempc;
//float tempf;
float vout;
float adc;
const int trigPin = 8;
const int echoPin = 9;
long durasi;
int jarak;
void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
}

void loop()
{
  adc = analogRead(sensor);
  vout = adc / 1023 * 5;
  tempc = vout * 100;
// tempf = (tempc * 1.8) + 32;

  // Program HC SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034 / 2;

//  Serial.print("Suhu (Celcius)= ");
  Serial.print(tempc);
  Serial.println(",");

  Serial.println(jarak);
 /* Serial.print("Suhu (Fahrenheit)= ");
  Serial.print(tempf);
  Serial.println(" °F");
  Serial.println(" ");
  delay(100);
*/  
}