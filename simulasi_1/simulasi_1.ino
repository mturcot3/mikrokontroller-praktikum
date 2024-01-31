int ON = 10;
int OFF = 7;
int led = 3;

void setup() {
  pinMode(ON, INPUT_PULLUP);
  pinMode(OFF, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}
void loop() {
  if(digitalRead(ON) == 0){
    digitalWrite(led, HIGH);
  }

  if(digitalRead(OFF) == 0) {
    digitalWrite(led, LOW);
  }
}
