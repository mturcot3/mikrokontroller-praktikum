#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int redPW = 0;
int greenPW = 0;
int bluePW = 0;


void setup() {
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  pinMode(sensorOut, INPUT);

  Serial.begin(9600);
  

}
void loop() {

redPW = getRedPW();
delay(1000);


greenPW = getGreenPW();
delay(1000);


bluePW = getBluePW();
delay(1000);

Serial.println("Red PW= ");
Serial.println(redPW);
Serial.println("Green PW= ");
Serial.println(greenPW);
Serial.println("Blue PW= ");
Serial.println(bluePW);

}

int getRedPW(){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  int PW;
  PW = pulseIn(sensorOut,LOW);
  return PW;
}
int getGreenPW(){
    digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  int PW;
  PW = pulseIn(sensorOut,LOW);
  return PW;
}
int getBluePW(){
    digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  int PW;
  PW = pulseIn(sensorOut,LOW);
  return PW;


}