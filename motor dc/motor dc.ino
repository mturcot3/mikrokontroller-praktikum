#define dira 8
#define dirb 10
#define pwma 9
#define pwmb 11
void motor(int a, int b){
  if (a >= 0){
    digitalWrite(dira, 0);
    analogWrite(pwma, a);
  } else if (a < 0){
    digitalWrite(dira, 1);
    analogWrite(pwma, a+255);    
  }
  if (b >= 0){
    digitalWrite(dirb, 0);
    analogWrite(pwmb, b);
  } else if (a < 0){
    digitalWrite(dirb, 1);
    analogWrite(pwmb, b+255);    
  }
}
void setup() {
  // put your setup code here, to run once:
pinMode(dira, OUTPUT);
pinMode(dirb, OUTPUT);
// meyalakan motor saat ada kodisi terrtentu gunakn fungsi if
//motor(255,255); // maju kenceng satu kali karna di void setup
//delay(3000); // delay 3 detik
//motor(0,0); // untuk memeatikan motor
}
void loop() {
  // put your main code here, to run repeatedly:
//motor(255,255); // maju kenceng
//delay(3000); // delay 3 detik
//motor(0,0); // mati
//delay(1000); // delay 1 detik
//motor(-255, -255); // mundur kenceng
//delay(3000);
//motor(100,100); // maju pelan
//delay(3000); // delay 3 detik
//motor(0,0); // mati
//delay(1000); // delay 1 detik
//motor(-100, -100); // mundur pelan
}