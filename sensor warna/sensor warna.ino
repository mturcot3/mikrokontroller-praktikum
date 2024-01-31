#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int redMin = 5;
int redMax = 214;
int greenMin = 5;
int greenMax = 238;
int blueMin = 4;
int blueMax = 254;

int redPW = 0;
int greenPW = 0;
int bluePW = 0;

int redValue;
int greenValue;
int blueValue;


void setup() {
  // put your setup code here, to run once:
    
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);

pinMode(sensorOut, INPUT);

digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
redPW = getRedPW();
redValue = map(redPW, redMin, redMax, 255, 0);
delay(1000);
greenPW = getGreenPW();
greenValue = map(greenPW, greenMin, greenMax, 255, 0);
delay(1000);
bluePW = getBluePW();
blueValue = map(bluePW, blueMin, blueMax, 255, 0);
delay(1000);
Serial.println("Red = ");
Serial.println(redValue);
Serial.println("Green = ");
Serial.println(greenValue);
Serial.println("Blue = ");
Serial.println(blueValue);
}

int getRedPW(){
digitalWrite(S2, LOW);
digitalWrite(S3, LOW);
int PW;
PW = pulseIn(sensorOut, LOW);
return PW;
}

int getGreenPW(){
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);
int PW;
PW = pulseIn(sensorOut, LOW);
return PW;
}

int getBluePW(){
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);
int PW;
PW = pulseIn(sensorOut, LOW);
return PW;
}
