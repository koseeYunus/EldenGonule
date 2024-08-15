#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
byte ses = 30;                  // Basalangicta ses yuksekligi


SoftwareSerial mySerial_git_mp3(10, 11); // RX, TX

int dil=1;

string turkceCumleler[1000][4]={
  {"Merhaba" , " " , " " , " "},    // 1
  {"Nasilsin" , " " , " " , " "},   // 2
  {"Bugun" , "Ne " , "Yapacaksin " , "? "},   // 3
  {"Ise" , "Gidecegim " , " " , " "},   // 4
}
string turkceCumleler[50][4] = {
  {"Merhaba" , " " , " " , " "},   // 1
  {"Evet" , " " , " " , " "},   // 2
  {"Hayir" , " " , " " , " "},   // 3
  {"Su" , " " , " " , " "},   // 4
  {"Yemek" , " " , " " , " "},   // 5
  {"Tuvalet" , " " , " " , " "},   // 6
  {"Yardim" , " " , " " , " "},   // 7
  {"Lutfen" , " " , " " , " "},   // 8
  {"Tesekkur" , " " , " " , " "},   // 9
  {"Uzgun" , " " , " " , " "},   // 10
  {"Aciyor" , " " , " " , " "},   // 11
  {"Sicak" , " " , " " , " "},   // 12
  {"Soguk" , " " , " " , " "},   // 13
  {"Basim" , "agriyor" , " " , " "},   // 14
  {"Yorgunum" , " " , " " , " "},   // 15
  {"Mutlu" , " " , " " , " "},   // 16
  {"Uzgun" , " " , " " , " "},   // 17
  {"Korkuyorum" , " " , " " , " "},   // 18
  {"Sakin" , "ol" , " " , " "},   // 19
  {"Anliyor" , "musun" , " " , " "},   // 20
  {"Ne" , "zaman" , " " , " "},   // 21
  {"Nerede" , " " , " " , " "},   // 22
  {"Kim" , " " , " " , " "},   // 23
  {"Neden" , " " , " " , " "},   // 24
  {"Hangi" , " " , " " , " "},   // 25
  {"Yapmaliyim" , " " , " " , " "},   // 26
  {"Beni" , "birak" , " " , " "},   // 27
  {"Dur" , " " , " " , " "},   // 28
  {"Devam" , "et" , " " , " "},   // 29
  {"Bekle" , " " , " " , " "},   // 30
  {"Ac" , " " , " " , " "},   // 31
  {"Kapat" , " " , " " , " "},   // 32
  {"Eve" , "gitmek" , "istiyorum" , " "},   // 33
  {"Disari" , "cikmak" , "istiyorum" , " "},   // 34
  {"Yardimci" , "olur" , "musun" , " "},   // 35
  {"Bu" , "nedir" , " " , " "},   // 36
  {"Istiyorum" , " " , " " , " "},   // 37
  {"Istemiyorum" , " " , " " , " "},   // 38
  {"Lutfen" , "biraz" , "bekle" , " "},   // 39
  {"Buradayim" , " " , " " , " "},   // 40
  {"Gorusuruz" , " " , " " , " "},   // 41
  {"Gecmis" , "olsun" , " " , " "},   // 42
  {"Adim" , " " , " " , " "},   // 43
  {"Senin" , "adin" , " " , " "},   // 44
  {"Kim" , "bilmek" , "istiyorum" , " "},   // 45
  {"Saat" , "kac" , " " , " "},   // 46
  {"Gidebilir" , "miyim" , " " , " "},   // 47
  {"Gelebilir" , "misin" , " " , " "},   // 48
  {"Odev" , "yapmak" , "istiyorum" , " "},   // 49
  {"Film" , "izlemek" , "istiyorum" , " "},   // 50
};


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
  mp3_set_serial (mySerial_git_mp3);    //Mp3 modulu baslangic ayarlari
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

  // 1 ise dil Turkce
  if(dil==1){
    Seslendir(turkceCumleler, 0);
  }
  // 2 ise dil Ingilizce
  else if(dil==2){
    Seslendir(ingilizceCumleler, 1000);
  }
  // 3 ise dil Ispanyolca
  else if(dil==3){
    Seslendir(ispanyolcaCumleler, 2000);
  }
  else{
    lcdYaz("Dil", "Degiskeni", "Tanimlanamadi", "" , "");
    Serial.println("Dil degiskeni tanimlanamadi !!! ");
  }
}


void dilDegisim(){
  //Dili Turkce Yapma
  if (digitalRead(2) == LOW) {    
    dil=1;
    mp3_play (999);
    lcdYaz("Dil","Turkce","Yapildi "," ");
    Serial.println("Dil Turkce Yapildi");
  }
  //Dili Ingilizce Yapma
  if (digitalRead(3) == LOW) {    
    dil=2;
    mp3_play (1999);
    lcdYaz("The Language","Was Made in","English "," ");
    Serial.println("Dil Ingilizce Yapildi");
  }
  //Dili Ispanyolca Yapma
  if (digitalRead(4) == LOW) {    
    dil=3;
    mp3_play (2999);
    lcdYaz("El Idioma","Se Hizo en","Español "," ");
    Serial.println("Dil İsponyalca Yapildi");
  }
  delay(1500);
}

bool sagDok[12] = [1,1,1,1,1,1,1,1,1,1,1,1];
bool solDok[12] = [1,1,1,1,1,1,1,1,1,1,1,1];

int tekrar, say = 0;

void dokunmatikSensorOku(){

  for(say=0; say<12; say++){
    sagDok[say] = 1;
    solDok[say] = 1;
  }

  for(tekrar=0; tekrar<5000 ; tekrar++){

    for(say=0; say<12; say++){
      sagDok[say] = digitalRead(22+say);
      solDok[say] = digitalRead(34+say);
    }
 
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