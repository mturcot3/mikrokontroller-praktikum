/*
unsigned int inputPin[] = {2,3,4,5}; // mengubah pin 2, 3, 4, 5 sebagai inputPin
unsigned int ledPin[] = {10,11,12,13}; // mengubah pin 10, 11, 12, 13 sebagai ledPin

void setup() 
{
//Sebuah Variable global yang disimpan pada awal program di fungstion setup(). serta Sebuah variable ini di deklarasikan pada saat block function atau block statement pengulangan, dan hanya dapat di gunakan pada block yang bersangkutan.

 for(int indeks = 0; indeks < 4; indeks++) 
 { 
 pinMode(ledPin[indeks], OUTPUT); //mengubah ledPin sebagai OUTPUT
 pinMode(inputPin[indeks], INPUT); //mengubah inputPin sebagai INPUT
 
 digitalWrite(inputPin[indeks],HIGH); 
 //membaca dan memberi status inputPin dengan indeks sesuai dengan nilainya.
 } 
} 

void loop() 
{ 
 for(int indeks = 0; indeks < 4; indeks++) 
 { 
 int val = digitalRead(inputPin[indeks]); //membaca nilai dari indeks
 if (val == LOW) // cek switch yang ditekan 
 { 
 digitalWrite(ledPin[indeks], HIGH); //bila switch ditekan maka menyala
 } 
 else 
 { 
 digitalWrite(ledPin[indeks], LOW); //apabila tidak ada maka mati
 } 
 } 
}
*/
/*int outputPin10 = 10;
int outputPin11 = 11;
int outputPin12 = 12;
int outputPin13 = 13;
 
int inputPin2 = 2; // tombol untuk LED 10
int inputPin3 = 3; // tombol untuk LED 11
int inputPin4 = 4; // tombol untuk LED 12
int inputPin5 = 5; // tombol untuk LED 13
 
int kondisiInputPin2 = 0; //kondisi awal tombol 0 = mati
int kondisiInputPin3 = 0; //kondisi awal tombol 0 = mati
int kondisiInputPin4 = 0; //kondisi awal tombol 0 = mati
int kondisiInputPin5 = 0; //kondisi awal tombol 0 = mati
 
void setup()
// memberikan status pin menjadi output atau input
{
   pinMode(outputPin10, OUTPUT);
   pinMode(outputPin10, OUTPUT);
   pinMode(outputPin10, OUTPUT);
   pinMode(outputPin10, OUTPUT);
 
   pinMode(inputPin2, INPUT);
   pinMode(inputPin3, INPUT);
   pinMode(inputPin4, INPUT);
   pinMode(inputPin5, INPUT);
}
 
void loop()
{
   kondisiInputPin2 = digitalRead(inputPin2);
   kondisiInputPin3 = digitalRead(inputPin3);
   kondisiInputPin4 = digitalRead(inputPin4);
   kondisiInputPin5 = digitalRead(inputPin5);
  
   if (kondisiInputPin2 == HIGH) // jika tombol pin 2 ditekan
   {
      digitalWrite(outputPin10, HIGH); // LED pin 10 menyala
   }
   else if (kondisiInputPin3 == HIGH) // jika tombol pin 3 ditekan
   {
      digitalWrite(outputPin11, HIGH); // LED pin 11 menyala
   }
   else if (kondisiInputPin4 == HIGH) // jika tombol pin 4 ditekan
   {
      digitalWrite(outputPin12, HIGH); // LED pin 12 menyala
   }
   else if (kondisiInputPin5 == HIGH) // jika tombol pin 5 ditekan
   {
      digitalWrite(outputPin13, HIGH); // LED pin 13 menyala
   }
   else
   {
      digitalWrite(outputPin10,LOW); // LED pin 10 mati
      digitalWrite(outputPin11,LOW); // LED pin 11 mati
      digitalWrite(outputPin12,LOW); // LED pin 12 mati
      digitalWrite(outputPin13,LOW); // LED pin 13 mati
   }
}
*/
/*int pinLed = 3; //Membuat variabel untuk LED
int pinBtn = 4; // Membuat variabel untuk Button
 
void setup() {
 pinMode(pinLed, OUTPUT); // variabel pinLed menjadi output
 pinMode(pinBtn, INPUT_PULLUP); // variabel pinBtn menjadi input
}
 
void loop() {
 
  // variabel statusBtn menyimpan nilai dari hasil pembacaan pinBtn
  int  statusBtn = digitalRead(pinBtn);
 
  // Ketika push button tidak ditekan nilainya HIGH/1
  if(statusBtn == HIGH)
    {
      digitalWrite(pinLed, LOW);
    } else {
      digitalWrite(pinLed, HIGH);
    }
}
*/