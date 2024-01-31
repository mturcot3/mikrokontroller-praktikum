void setup() {
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}
void loop() {
digitalWrite(0,HIGH);
delay(500);
digitalWrite(0,LOW);
digitalWrite(1,HIGH);
delay(500);
digitalWrite(1,LOW);
digitalWrite(2,HIGH);
delay(500);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
delay(500);
digitalWrite(3,LOW);
}
