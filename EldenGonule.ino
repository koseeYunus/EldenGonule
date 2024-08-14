#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
byte ses = 30; //başlangıçtaki ses ayarımız
boolean calma_durumu = true;//bekletme (pause için)


SoftwareSerial mySerial_git_mp3(10, 11); // RX, TX

int dil=1;

int[] sesler = [1,2,3]


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

void loop () {
  
  dilDegisim();

  dokunmatikSensorOku();


  // 1 ise dil Türkce
  if(dil==1){

    

  }

  // 2 ise dil İngilizce
  else if(dil==2){

    if (sag1 == 0) {    
      mp3_play (101);
      lcdYaz("I want",""," "," ");
    }

    else if (sag2 == 0) {    
      mp3_play (102);
      lcdYaz("Yes","","","");
    }

    else if (sag3 == 0) {    
      mp3_play (103);
      lcdYaz("No","","","");
    }

    else if (sag4 == 0) {    
      mp3_play (104);
      lcdYaz("Peace be","With you",""," ");
    }

    else if (sag5 == 0) {    
      mp3_play (105);
      lcdYaz("How","are","you","?");
    }

    else if (sag6 == 0) {    
      mp3_play (106);
      lcdYaz("What are","you doing","?"," ");
    }

    else if (sag7== 0) 
    {    
      mp3_play (107);
      lcdYaz("Where are","you","going","?");
    }

    else if (sag8 == 0) 
    {    
      mp3_play (108);
      lcdYaz("Just a","minute","","");
    }

    else if (sag9 == 0) 
    {    
      mp3_play (109);
      lcdYaz("When","","","");
    }

    else if (sag10 == 0) 
    {    
      mp3_play (110);
      lcdYaz("Trust in","Allah"," "," ");
    }

    else if (sag11 == 0) 
    {    
      mp3_play (111);
      lcdYaz("How","Many",""," ");
    }

    else if (sag12 == 0) 
    {    
      mp3_play (112);
      lcdYaz("Come","",""," ");
    }

    //İkinci El
    else if (sol1 == 0) 
    {    
      mp3_play (113);
      lcdYaz("Go",""," "," ");

    }

    else if (sol2 == 0) 
    {    
      mp3_play (114);
      lcdYaz("I'm sorry","",""," ");
    }

    else if (sol3 == 0) 
    {    
      mp3_play (115);
      lcdYaz("Thank","you",""," ");
    }
    else if (sol4 == 0) 
    {    
      mp3_play (116);
      lcdYaz("God","willing"," "," ");
    }

    else if (sol5 == 0) 
    {    
      mp3_play (117);
      lcdYaz("Hometown","",""," ");
    }

    else if (sol6 == 0) 
    {    
      mp3_play (118);
      lcdYaz("Easy","","","");
    }

    else if (sol7 == 0) 
    {    
      mp3_play (119);
      lcdYaz("Difficult",""," "," ");
    }

    else if (sol8 == 0) 
    {    
      mp3_play (120);
      lcdYaz("There","is",""," ");
    }

    else if (sol9 == 0) 
    {    
      mp3_play (121);
      lcdYaz("No","",""," ");
    }

    else if (sol10 == 0) 
    {    
      mp3_play (122);
      lcdYaz("It's","over",""," ");
    }

    else if (sol11 == 0) 
    {    
      mp3_play (123);
      lcdYaz("Start","",""," ");
    }

    else if (sol12 == 0) 
    {    
      mp3_play (124);
      lcdYaz("Again","","","");

    }
    else {
      Serial.println("Ingilizce sozcuk tanimlanamadi ???");
    }

  }

  // 3 ise dil İspanyolca
  else if(dil==3){

    if (sag1 == 0) {    
      mp3_play (201);
      lcdYaz("Quiero",""," "," ");
    }

    else if (sag2 == 0) {    
      mp3_play (202);
      lcdYaz("Si","","","");
    }

    else if (sag3 == 0) {    
      mp3_play (203);
      lcdYaz("No","","","");
    }

    else if (sag4 == 0) {    
      mp3_play (204);
      lcdYaz("La paz","sea contigo",""," ");
    }

    else if (sag5 == 0) {    
      mp3_play (205);
      lcdYaz("Como estas","","","");
    }

    else if (sag6 == 0) {    
      mp3_play (206);
      lcdYaz("Que estas","haciendo ","?"," ");
    }

    else if (sag7 == 0) 
    {    
      mp3_play (1071);
      lcdYaz("a donde","vas","","");
    }

    else if (sag8 == 0) 
    {    
      mp3_play (208);
      lcdYaz("Solo un","minuto",""," ");
    }

    else if (sag9 == 0) 
    {    
      mp3_play (209);
      lcdYaz("Cuando","",""," ");
    }

    else if (sag10 == 0) 
    {    
      mp3_play (210);
      lcdYaz("Confia en","Allah"," "," ");
    }

    else if (sag11 == 0) 
    {    
      mp3_play (211);
      lcdYaz("Cuantos","","?"," ");
    }

    else if (sag12 == 0) 
    {    
      mp3_play (212);
      lcdYaz("Ven","",""," ");
    }

    //İkinci El
    else if (sol1 == 0) 
    {    
      mp3_play (213);
      lcdYaz("Ve",""," "," ");
    }

    else if (sol2 == 0) 
    {    
      mp3_play (214);
      lcdYaz("Lo","siento","?"," ");
    }

    else if (sol3 == 0) 
    {    
      mp3_play (215);
      lcdYaz("Gracias","",""," ");
    }
    else if (sol4 == 0) 
    {    
      mp3_play (216);
      lcdYaz("Si dios","quiere"," "," ");
    }

    else if (sol5 == 0) 
    {    
      mp3_play (217);
      lcdYaz("Ciudad","natal",""," ");
    }

    else if (sol6 == 0) 
    {    
      mp3_play (218);
      lcdYaz("Facil","",""," ");
    }

    else if (sol7 == 0) 
    {    
      mp3_play (219);
      lcdYaz("Difficil",""," "," ");
    }

    else if (sol8 == 0) 
    {    
      mp3_play (220);
      lcdYaz("hay","",""," ");
    }

    else if (sol9 == 0) 
    {    
      mp3_play (221);
      lcdYaz("No","",""," ");
    }

    else if (sol10 == 0) 
    {    
      mp3_play (222);
      lcdYaz("Se acabo",""," "," ");
    }

    else if (sol11 == 0) 
    {    
      mp3_play (223);
      lcdYaz("inicio","",""," ");
    }

    else if (sol12 == 0) 
    {    
      mp3_play (224);
      lcdYaz("De nuevo","",""," ");
    }  
    else {
      Serial.println("Ispanyolca dili tanimlanamadi ???");
    } 

  }
  else{
    Serial.println("Dil degiskeni tanımlanamadı !!! ");
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

void kisaMetod(){
  int play=1;
  for(int i=22 ; i<47 ; i++)
  {
    if (digitalRead(i) == 0) 
    { 
      mp3_play (play);
      delay(2000);
      Serial.print(play);
      Serial.println(". Parça oynatıldı ");
    }
    play+=1;
  }
}

string turkceCumleler[1000][4]={
  {"Merhaba" , " " , " " , " "},    // 1
  {"Nasilsin" , " " , " " , " "},   // 2
  {"Bugun" , "Ne " , "Yapacaksin " , "? "},   // 3
  {"Ise" , "Gidecegim " , " " , " "},   // 4
}

void TurkceKonus(string Cumleler[1000][4] , int Ses){
  if (sag1 == 0 && sol1==0) {    
      mp3_play (ses + 0);
      lcdYaz(Cumleler[0][0], Cumleler[0][1], Cumleler[0][2], Cumleler[0][3],);
    }
    else if (sag1 == 0 && sol2==0) {    
      mp3_play (ses + 1);
      lcdYaz(Cumleler[1][0], Cumleler[1][1], Cumleler[1][2], Cumleler[1][3],);
    }
    else if (sag1 == 0 && sol3==0) {    
      mp3_play (ses + 2);
      lcdYaz(Cumleler[2][0], Cumleler[2][1], Cumleler[2][2], Cumleler[2][3],);
    }
    else if (sag1 == 0 && sol4==0) {    
      mp3_play (ses + 3);
      lcdYaz(Cumleler[3][0], Cumleler[3][1], Cumleler[3][2], Cumleler[3][3],);
    }    
    else if (sag1 == 0 && sol5==0) {    
      mp3_play (ses + 4);
      lcdYaz(Cumleler[4][0], Cumleler[4][1], Cumleler[4][2], Cumleler[4][3],);
    }
    int kombinasyon=0;
    for(int sag=0 ; sag<12 ; sag++){
      for(int sol=0 ; sol<12 ; sol++){
        if (sagDok[sag] == 0 && solDok[sol]==0) {    
          mp3_play (ses + kombinasyon);
          lcdYaz(Cumleler[kombinasyon][0], Cumleler[kombinasyon][1], Cumleler[kombinasyon][2], Cumleler[kombinasyon][3],);
          break;
        }
        kombinasyon+=1;
      }
    }

    else if (sag1 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz("altı","dokunus","altı "," ");
    } 
    else if (sag1 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz("yedi","dokunus","yedi "," ");
    }
    else if (sag1 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz("sekiz","dokunus","sekiz "," ");
    }
    else if (sag1 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz("dokuz","dokunus","dokuz "," ");
    }
    else if (sag1 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz("on","dokunus","on "," ");
    }
    else if (sag1 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz("onbir","dokunus","onbir "," ");
    }
    else if (sag1 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz("oniki","dokunus","oniki "," ");
    }

    else if (sag2 == 0 && sol1==0) {    
      mp3_play (25);
      lcdYaz("Bir","2dokunus","Bir "," ");
    }
    else if (sag2 == 0 && sol2==0) {    
      mp3_play (26);
      lcdYaz("Iki","2dokunus","Iki "," ");
    }
    else if (sag2 == 0 && sol3==0) {    
      mp3_play (27);
      lcdYaz("Uc","2dokunus","Uc "," ");
    }
    else if (sag2 == 0 && sol4==0) {    
      mp3_play (28);
      lcdYaz("dort","2dokunus","dort "," ");
    }    
    else if (sag2 == 0 && sol5==0) {    
      mp3_play (29);
      lcdYaz("bes","2dokunus","bes "," ");
    }
    else if (sag2 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz("altı","2dokunus","altı "," ");
    } 
    else if (sag2 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz("yedi","2dokunus","yedi "," ");
    }
    else if (sag2 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz("sekiz","2dokunus","sekiz "," ");
    }
    else if (sag2 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz("dokuz","2dokunus","dokuz "," ");
    }
    else if (sag2 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz("on","2dokunus","on "," ");
    }
    else if (sag2 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz("onbir","2dokunus","onbir "," ");
    }
    else if (sag2 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz("oniki","2dokunus","oniki "," ");
    }

    else if (sag3 == 0 && sol1==0) {    
      mp3_play (25);
      lcdYaz("Bir","3dokunus","Bir "," ");
    }
    else if (sag3 == 0 && sol2==0) {    
      mp3_play (26);
      lcdYaz("Iki","3dokunus","Iki "," ");
    }
    else if (sag3 == 0 && sol3==0) {    
      mp3_play (27);
      lcdYaz("Uc","3dokunus","Uc "," ");
    }
    else if (sag3 == 0 && sol4==0) {    
      mp3_play (28);
      lcdYaz("dort","3dokunus","dort "," ");
    }    
    else if (sag3 == 0 && sol5==0) {    
      mp3_play (29);
      lcdYaz("bes","3dokunus","bes "," ");
    }
    else if (sag3 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz("altı","3dokunus","altı "," ");
    } 
    else if (sag3 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz("yedi","3dokunus","yedi "," ");
    }
    else if (sag3 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz("sekiz","3dokunus","sekiz "," ");
    }
    else if (sag3 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz("dokuz","3dokunus","dokuz "," ");
    }
    else if (sag3 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz("on","3dokunus","on "," ");
    }
    else if (sag3 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz("onbir","3dokunus","onbir "," ");
    }
    else if (sag3 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz("oniki","3dokunus","oniki "," ");
    }


    else  if (sag4 == 0 && sol1==0) {    
      mp3_play (25);
      lcdYaz("Bir","4dokunus","Bir "," ");
    }
    else if (sag4 == 0 && sol2==0) {    
      mp3_play (26);
      lcdYaz("Iki","4dokunus","Iki "," ");
    }
    else if (sag4 == 0 && sol3==0) {    
      mp3_play (27);
      lcdYaz("Uc","4dokunus","Uc "," ");
    }
    else if (sag4 == 0 && sol4==0) {    
      mp3_play (28);
      lcdYaz("dort","4dokunus","dort "," ");
    }    
    else if (sag4 == 0 && sol5==0) {    
      mp3_play (29);
      lcdYaz("bes","4dokunus","bes "," ");
    }
    else if (sag4 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz("altı","4dokunus","altı "," ");
    } 
    else if (sag4 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz("yedi","4dokunus","yedi "," ");
    }
    else if (sag4 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz("sekiz","4dokunus","sekiz "," ");
    }
    else if (sag4 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz("dokuz","4dokunus","dokuz "," ");
    }
    else if (sag4 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz("on","4dokunus","on "," ");
    }
    else if (sag4 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz("onbir","4dokunus","onbir "," ");
    }
    else if (sag4 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz("oniki","4dokunus","oniki "," ");
    }


    else if (sag5 == 0 && sol1==0) {    
      mp3_play (25);
      lcdYaz("Bir","5dokunus","Bir "," ");
    }
    else if (sag5 == 0 && sol2==0) {    
      mp3_play (26);
      lcdYaz("Iki","5dokunus","Iki "," ");
    }
    else if (sag5 == 0 && sol3==0) {    
      mp3_play (27);
      lcdYaz("Uc","5dokunus","Uc "," ");
    }
    else if (sag5 == 0 && sol4==0) {    
      mp3_play (28);
      lcdYaz("dort","5dokunus","dort "," ");
    }    
    else if (sag5 == 0 && sol5==0) {    
      mp3_play (29);
      lcdYaz("bes","5dokunus","bes "," ");
    }
    else if (sag5 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz("altı","5dokunus","altı "," ");
    } 
    else if (sag5 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz("yedi","5dokunus","yedi "," ");
    }
    else if (sag5 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz("sekiz","5dokunus","sekiz "," ");
    }
    else if (sag5 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz("dokuz","5dokunus","dokuz "," ");
    }
    else if (sag5 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz("on","5dokunus","on "," ");
    }
    else if (sag5 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz("onbir","5dokunus","onbir "," ");
    }
    else if (sag5 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz("oniki","5dokunus","oniki "," ");
    }

    // ...

    else if (sag1 == 0) {    
      mp3_play (144);
      lcdYaz("Istiyorum",""," "," ");
    }

    else if (sag2 == 0) {    
      mp3_play (145);
      lcdYaz("Evet","",""," ");
    }

    else if (sag3 == 0) {    
      mp3_play (146);
      lcdYaz("Hayir","",""," ");
    }

    else if (sag4 == 0) {    
      mp3_play (147);
      lcdYaz("Selamun","Aleykum",""," ");
    }

    else if (sag5 == 0) {    
      mp3_play (148);
      lcdYaz("Nasilsin","",""," ");
    }

    else if (sag6 == 0) {    
      mp3_play (149);
      lcdYaz("Ne","Yapiyorsun",""," ");
    }

    else if (sag7 == 0) 
    {    
      mp3_play (150);
      lcdYaz("Nereye","Gidiyorsun","?"," ");
    }

    else if (sag8 == 0) 
    {    
      mp3_play (151);
      lcdYaz("Bir","Dakika",""," ");
    }

    else if (sag9 == 0) 
    {    
      mp3_play (152);
      lcdYaz("Ne ","Zaman","?"," ");
    }

    else if (sag10 == 0) 
    {    
      mp3_play (153);
      lcdYaz("Allah'a","Emanet"," "," ");
    }

    else if (sag11 == 0) 
    {    
      mp3_play (154);
      lcdYaz("Kac","",""," ");
    }

    else if (sag12 == 0) 
    {    
      mp3_play (155);
      lcdYaz("Gel","",""," ");
    }

    //İkinci El
    else if (sol1 == 0) {    
      mp3_play (156);
      lcdYaz("Git","",""," ");
    }

    else if (sol2 == 0) {    
      mp3_play (158);
      lcdYaz("Ozur","Dilerim"," "," ");
    }

    else if (sol3 == 0) {    
      mp3_play (159);
      lcdYaz("Tesekkur","Ederim",""," ");
    }

    else if (sol4 == 0) {    
      mp3_play (160);
      lcdYaz("Insallah",""," "," ");
    }

    else if (sol5 == 0) {    
      mp3_play (161);
      lcdYaz("Memleket",""," "," ");
    }

    else if (sol6 == 0) 
    {    
      mp3_play (162);
      lcdYaz("Kolay","","  ","");
    }

    else if (sol7 == 0) 
    {    
      mp3_play (163);
      lcdYaz("Zor","","","");
    }

    else if (sol8 == 0) 
    {    
      mp3_play (164);
      lcdYaz("Var","","","");
    }

    else if (sol9 == 0) 
    {    
      mp3_play (165);
      lcdYaz("Yok","",""," ");
    }

    else if (sol10 == 0) 
    {    
      mp3_play (166);
      lcdYaz("Bitti ",""," "," ");
    }

    else if (sol11 == 0) 
    {    
      mp3_play (167);
      lcdYaz("Basla","","","");
    }

    else if (sol12 == 0) 
    {    
      mp3_play (168);
      lcdYaz("Tekrar","",""," ");
    }
    else {
      Serial.println("Turkce Seslendirme Taninamadı ??? ");
    }
}