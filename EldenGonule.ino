#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
byte ses = 30; //başlangıçtaki ses ayarımız
boolean calma_durumu = true;//bekletme (pause için)


SoftwareSerial mySerial_git_mp3(10, 11); // RX, TX

int dil=1;

string turkceCumleler[1000][4]={
  {"Merhaba" , " " , " " , " "},    // 1
  {"Nasilsin" , " " , " " , " "},   // 2
  {"Bugun" , "Ne " , "Yapacaksin " , "? "},   // 3
  {"Ise" , "Gidecegim " , " " , " "},   // 4
}

string ingilizceCumleler[1000][4]={
  {"Merhaba" , " " , " " , " "},    // 1
  {"Nasilsin" , " " , " " , " "},   // 2
  {"Bugun" , "Ne " , "Yapacaksin " , "? "},   // 3
  {"Ise" , "Gidecegim " , " " , " "},   // 4
}

string ispanyolcaCumleler[1000][4]={
  {"Merhaba" , " " , " " , " "},    // 1
  {"Nasilsin" , " " , " " , " "},   // 2
  {"Bugun" , "Ne " , "Yapacaksin " , "? "},   // 3
  {"Ise" , "Gidecegim " , " " , " "},   // 4
}


void setup () {
  lcd.begin();
  lcd.backlight();
  Serial.begin (9600);
  mySerial_git_mp3.begin (9600);
  mp3_set_serial (mySerial_git_mp3);    //Mp3 modülün başlangıç ayarları
  delay(1000);
  mp3_set_volume (ses);          // value 0~30
  delay(500);

  for(int i=22 ; i<46 ; i++){
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP); 
  pinMode(4, INPUT_PULLUP); 
 
}

void loop () {
  
  dilDegisim();

  dokunmatikSensorOku();

  // 1 ise dil Türkce
  if(dil==1){
    Seslendir(turkceCumleler, 0);
  }
  // 2 ise dil İngilizce
  else if(dil==2){
    Seslendir(ingilizceCumleler, 1000);
  }
  // 2 ise dil İspanyolca
  else if(dil==3){
    Seslendir(ispanyolcaCumleler, 2000);
  }
  else{
    Serial.println("Dil degiskeni tanımlanamadı !!! ");
  }
}

bool sag1, sag2, sag3, sag4, sag5, sag6, sag7, sag8, sag9, sag10, sag11, sag12 = 1;
bool sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11, sol12 = 1;

int tekrar=0;

void dilDegisim(){
  //Dili Turkce Yapma
  if (digitalRead(2) == LOW) {    
    dil=1;
    mp3_play (501);
    lcdYaz("Dil","Turkce","Yapildi "," ");
    Serial.println("Dil Turkce Yapildi");
  }
  //Dili İngilizce Yapma
  if (digitalRead(3) == LOW) {    
    dil=2;
    mp3_play (502);
    lcdYaz("The Language","Was Made in","English "," ");
    Serial.println("Dil Ingilizce Yapildi");
  }
  //Dili İspanyolca Yapma
  if (digitalRead(4) == LOW) {    
    dil=3;
    mp3_play (503);
    lcdYaz("El Idioma","Se Hizo en","Español "," ");
    Serial.println("Dil İsponyalca Yapildi");
  }
  delay(1500);
}

void dokunmatikSensorOku(){
  sag1, sag2, sag3, sag4, sag5, sag6, sag7, sag8, sag9, sag10, sag11, sag12 = 1;
  sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11, sol12 = 1;

  for(tekrar=0; tekrar<5000 ; tekrar++){
    sag1 = digitalRead(22);
    sag2 = digitalRead(23);
    sag3 = digitalRead(24);
    sag4 = digitalRead(25);
    sag5 = digitalRead(26);
    sag6 = digitalRead(27);
    sag7 = digitalRead(28);
    sag8 = digitalRead(29);
    sag9 = digitalRead(30);
    sag10 = digitalRead(31);
    sag11 = digitalRead(32);
    sag12 = digitalRead(33);

    sol1 = digitalRead(34);
    sol2 = digitalRead(35);
    sol3 = digitalRead(36);
    sol4 = digitalRead(37);
    sol5 = digitalRead(38);
    sol6 = digitalRead(39);
    sol7 = digitalRead(40);
    sol8 = digitalRead(41);
    sol9 = digitalRead(42);
    sol10 = digitalRead(43);
    sol11 = digitalRead(44);
    sol12 = digitalRead(45);
  }
}


int kombinasyon, sag, sol = 0;

void Seslendir(string Cumleler[1000][4] , int ses,){
  kombinasyon=0;

    for(sag=0 ; sag<12 ; sag++){
      for(sol=0 ; sol<12 ; sol++){
        if (sagDok[sag] == 0 && solDok[sol]==0) {    
          mp3_play (ses + kombinasyon);
          lcdYaz(Cumleler[kombinasyon][0], Cumleler[kombinasyon][1], Cumleler[kombinasyon][2], Cumleler[kombinasyon][3],);
          break;
        }
        kombinasyon+=1;
      }
    }

    for(sag=0 ; sag<12 ; sag++){
      if (sagDok[sag] == 0) {    
        mp3_play (ses + kombinasyon);
        lcdYaz(Cumleler[kombinasyon][0], Cumleler[kombinasyon][1], Cumleler[kombinasyon][2], Cumleler[kombinasyon][3],);
        break;
      }
      kombinasyon+=1;
    }
    for(sol=0 ; sol<12 ; sol++){
      if (solDok[sol] == 0) {    
        mp3_play (ses + kombinasyon);
        lcdYaz(Cumleler[kombinasyon][0], Cumleler[kombinasyon][1], Cumleler[kombinasyon][2], Cumleler[kombinasyon][3],);
        break;
      }
      kombinasyon+=1;
    }
   
  
}

void lcdYaz(String s1 , String s2 , String s3 , String s4){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(s1);
  lcd.setCursor(0,1);
  lcd.print(s2);
  lcd.setCursor(0,2);
  lcd.print(s3);
  lcd.setCursor(0,3);
  lcd.print(s4);
  delay(1500);
}