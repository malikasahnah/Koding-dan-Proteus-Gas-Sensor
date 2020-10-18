#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // LCD ADA DI PIN 13, 12, 11, 10, 9, 8
int GAS_SENSOR_LOW=3; // GAS SENSOR ADA DI PIN 3 
int GREEN_LED=5; // LED HIJAU ADA DI PIN 5
int RED_LED=4; // LED MERAH ADA DI PIN 4
void setup() {
  // put your setup code here, to run once:
pinMode(GAS_SENSOR_LOW, INPUT_PULLUP); // GAS SENSOR SEBAGAI INPUT 
pinMode(GREEN_LED,OUTPUT); // LED HIJAU SEBAGAI OUTPUT
pinMode(RED_LED,OUTPUT); // LED MERAH SEBAGAI OUTPUT
lcd.begin(20,4); //LCD DENGAN 20 KOLOM DAN 4 BARIS
lcd.setCursor(0,0); //AKAN MENAMPILKAN TEKS PADA KOLOM PERTAMA BARIS PERTAMA
lcd.print("SISTEM PENDETEKSI"); // CETAK TEKS
lcd.setCursor(0,1); //AKAN MENAMPILKAN TEKS PADA KOLOM PERTAMA BARIS KEDUA
lcd.print("ALKOHOL"); // CETAK TEKS
lcd.setCursor(0,2); //AKAN MENAMPILKAN TEKS PADA KOLOM PERTAMA BARIS KETIGA
lcd.print("TELEKOMUNIKASI PNJ"); // CETAK TEKS
delay(1500); //WAKTU DELAY 1.5 DETIK
}

void loop() {
  // put your main code here, to run repeatedly:
  int GAS_SENSOR_LOW_READ = digitalRead(GAS_SENSOR_LOW); //MEMBACA KONDISI GAS SENSOR
  if (GAS_SENSOR_LOW_READ == LOW) //KEADAAN JIKA LOW ATAU LOGIC 0
  {
    lcd.clear();
    lcd.setCursor(0, 3); // AKAN MENAMPILKAN TEKS PADA KOLOM PERTAMA BARIS KEEMPAT
    lcd.print("ALCOHOL NOT DETECTED"); //CETAK TEKS
    digitalWrite(GREEN_LED,HIGH); // LED HIJAU AKAN MENYALA
    digitalWrite(RED_LED,LOW); // LED MERAH AKAN MATI
    delay(30); // WAKTU DELAY 0.03 DETIK
  }
else 
{
    lcd.clear();
    lcd.setCursor(0, 3); // AKAN MENAMPILKAN TEKS PADA KOLOM PERTAMA BARIS KEEMPAT
    lcd.print("ALCOHOL DETECTED"); //CETAK TEKS
    digitalWrite(GREEN_LED,LOW); //LED HIJAU AKAN MATI
    digitalWrite(RED_LED,HIGH); // LED MERAH AKAN MENYALA
      delay(30); // WAKTU DELAY 0.03 DETIK
  }
}
