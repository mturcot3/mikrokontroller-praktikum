
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
