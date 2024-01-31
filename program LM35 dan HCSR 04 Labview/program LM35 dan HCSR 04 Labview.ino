const int sensor = A1;
int suhu;
//float tempf;
float vout;
float adc;
const int trigPin = 3;
const int echoPin = 8;
int led1=5;
int led2=9;
long durasi;
int jarak;
void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
  
}

void loop()
{
  adc = analogRead(sensor);
  vout = adc / 1023 * 5;
  suhu = vout * 100;
// tempf = (tempc * 1.8) + 32;

  // Program HC SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034 / 2;

if (suhu >= 25 && jarak < 25){  
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
delay(100);
}

else if (suhu <25 && jarak >25){
  
digitalWrite(led2, HIGH);
digitalWrite(led1, LOW);
delay(100);
}  

//  Serial.print("Suhu (Celcius)= ");
  Serial.print(suhu);
  Serial.println(",");

  Serial.println(jarak);
 /* Serial.print("Suhu (Fahrenheit)= ");
  Serial.print(tempf);
  Serial.println(" °F");
  Serial.println(" ");
  delay(100);
*/  
}