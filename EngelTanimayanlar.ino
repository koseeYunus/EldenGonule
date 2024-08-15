#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

SoftwareSerial mySerial_git_mp3(10, 11); // RX, TX

byte ses = 30;                  //Baslangictaki ses ayari
boolean calma_durumu = true;    //bekletme (pause icin)

int dil=1;

int tekrar=0;
bool sag1, sag2, sag3, sag4, sag5, sag6, sag7, sag8, sag9, sag10, sag11, sag12 = 1;
bool sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11, sol12 = 1;


void setup () {
    Serial.begin (9600);

    lcd.begin();
    lcd.backlight();
    
    mySerial_git_mp3.begin (9600);
    mp3_set_serial (mySerial_git_mp3);    //Mp3 modulunun baslangic ayarlari
    delay(1000);
    mp3_set_volume (ses);                 // value 0~30
    delay(500);

    for(int i=22 ; i<46 ; i++){
        pinMode(i, INPUT_PULLUP);
    }

    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP); 
    pinMode(4, INPUT_PULLUP); 
 
}


void loop () {

    dilDegisimKontrol();

    dokunmatikSensorDegerOku();

    // 1 ise dil Turkce
    if(dil==1){
        TurkceKonus();   
    }
    // 2 ise dil Ingilizce
    else if(dil==2){
        IngilizceKonus();   
    }
    // 3 ise dil Ispanyolca
    else if(dil==3){
        IspanyolcaKonus();
    }
    else{
        lcdYaz("Dil", "Tanimlanamadi", " ", " ");
        Serial.println("Dil degiskeni tanimlanamadi !!! ");
    }

}

void dilDegisimKontrol(){
    //Dili Turkce Yapma
    if (digitalRead(2) == LOW) {    
        dil=1;
        mp3_play (501);
        lcdYaz("Dil","Turkce","Yapildi "," ");
        Serial.println("Dil Turkce Yapildi");
        delay(1500);
    }
    //Dili Ingilizce Yapma
    if (digitalRead(3) == LOW) {    
        dil=2;
        mp3_play (502);
        lcdYaz("The Language","Was Made in","English "," ");
        Serial.println("Dil Ingilizce Yapildi");
        delay(1500);
    }
    //Dili Ispanyolca Yapma
    if (digitalRead(4) == LOW) {    
        dil=3;
        mp3_play (503);
        lcdYaz("El Idioma","Se Hizo en","Espanol "," ");
        Serial.println("Dil İsponyalca Yapildi");
        delay(1500);
    }
}

void dokunmatikSensorDegerOku(){
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
  delay(1000);
}

void TurkceKonus(){
    // sag1 == 0 kombinasyonlari
    if (sag1 == 0 && sol1==0) {    
      mp3_play (25);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol2==0) {    
      mp3_play (26);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol3==0) {    
      mp3_play (27);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol4==0) {    
      mp3_play (28);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag1 == 0 && sol5==0) {    
      mp3_play (29);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag1 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz(" "," "," "," ");
    }

    // Sag2 == 0 kombinasyonlari
    else if (sag2 == 0 && sol1==0) {    
      mp3_play (37);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol2==0) {    
      mp3_play (38);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol3==0) {    
      mp3_play (39);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol4==0) {    
      mp3_play (40);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag2 == 0 && sol5==0) {    
      mp3_play (41);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol6==0) {    
      mp3_play (42);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag2 == 0 && sol7==0) {    
      mp3_play (43);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol8==0) {    
      mp3_play (44);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol9==0) {    
      mp3_play (45);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol10==0) {    
      mp3_play (46);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol11==0) {    
      mp3_play (47);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol12==0) {    
      mp3_play (48);
      lcdYaz(" "," "," "," ");
    }

    // sag3 == 0 kontrol
    else if (sag3 == 0 && sol1==0) {    
      mp3_play (49);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol2==0) {    
      mp3_play (50);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol3==0) {    
      mp3_play (51);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol4==0) {    
      mp3_play (52);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag3 == 0 && sol5==0) {    
      mp3_play (53);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol6==0) {    
      mp3_play (54);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag3 == 0 && sol7==0) {    
      mp3_play (55);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol8==0) {    
      mp3_play (56);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol9==0) {    
      mp3_play (57);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol10==0) {    
      mp3_play (58);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol11==0) {    
      mp3_play (59);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol12==0) {    
      mp3_play (60);
      lcdYaz(" "," "," "," ");
    }

    // sag4 == 0 kombinayonlari
    else  if (sag4 == 0 && sol1==0) {    
      mp3_play (61);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol2==0) {    
      mp3_play (62);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol3==0) {    
      mp3_play (63);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol4==0) {    
      mp3_play (64);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag4 == 0 && sol5==0) {    
      mp3_play (65);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol6==0) {    
      mp3_play (66);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag4 == 0 && sol7==0) {    
      mp3_play (67);
      lcdYaz(" ",""," "," ");
    }
    else if (sag4 == 0 && sol8==0) {    
      mp3_play (68);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol9==0) {    
      mp3_play (69);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol10==0) {    
      mp3_play (70);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol11==0) {    
      mp3_play (71);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol12==0) {    
      mp3_play (72);
      lcdYaz(" "," "," "," ");
    }

    // sag5 == 0 kombinasyonlari
    else if (sag5 == 0 && sol1==0) {    
      mp3_play (73);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol2==0) {    
      mp3_play (74);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol3==0) {    
      mp3_play (75);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol4==0) {    
      mp3_play (76);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag5 == 0 && sol5==0) {    
      mp3_play (77);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol6==0) {    
      mp3_play (78);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag5 == 0 && sol7==0) {    
      mp3_play (79);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol8==0) {    
      mp3_play (80);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol9==0) {    
      mp3_play (81);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol10==0) {    
      mp3_play (82);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol11==0) {    
      mp3_play (83);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol12==0) {    
      mp3_play (84);
      lcdYaz(" "," "," "," ");
    }

    // sag6 == 0 kombinasyonlari
    else if (sag6 == 0 && sol1 == 0) {    
        mp3_play(85);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol2 == 0) {    
        mp3_play(86);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol3 == 0) {    
        mp3_play(87);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol4 == 0) {    
        mp3_play(88);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol5 == 0) {    
        mp3_play(89);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol6 == 0) {    
        mp3_play(90);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol7 == 0) {    
        mp3_play(91);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol8 == 0) {    
        mp3_play(92);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol9 == 0) {    
        mp3_play(93);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol10 == 0) {    
        mp3_play(94);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol11 == 0) {    
        mp3_play(95);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol12 == 0) {    
        mp3_play(96);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag7 == 0 kombinasyonlari
    else if (sag7 == 0 && sol1 == 0) {    
        mp3_play(97);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol2 == 0) {    
        mp3_play(98);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol3 == 0) {    
        mp3_play(99);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol4 == 0) {    
        mp3_play(100);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol5 == 0) {    
        mp3_play(101);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol6 == 0) {    
        mp3_play(102);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol7 == 0) {    
        mp3_play(103);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol8 == 0) {    
        mp3_play(104);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol9 == 0) {    
        mp3_play(105);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol10 == 0) {    
        mp3_play(106);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol11 == 0) {    
        mp3_play(107);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol12 == 0) {    
        mp3_play(108);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag8 == 0 kombinasyonlari
    else if (sag8 == 0 && sol1 == 0) {    
        mp3_play(109);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol2 == 0) {    
        mp3_play(110);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol3 == 0) {    
        mp3_play(111);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol4 == 0) {    
        mp3_play(112);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol5 == 0) {    
        mp3_play(113);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol6 == 0) {    
        mp3_play(114);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol7 == 0) {    
        mp3_play(115);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol8 == 0) {    
        mp3_play(116);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol9 == 0) {    
        mp3_play(117);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol10 == 0) {    
        mp3_play(118);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol11 == 0) {    
        mp3_play(119);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol12 == 0) {    
        mp3_play(120);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag9 == 0 kombinasyonlari
    else if (sag9 == 0 && sol1 == 0) {    
        mp3_play(121);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol2 == 0) {    
        mp3_play(122);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol3 == 0) {    
        mp3_play(123);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol4 == 0) {    
        mp3_play(124);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol5 == 0) {    
        mp3_play(125);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol6 == 0) {    
        mp3_play(126);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol7 == 0) {    
        mp3_play(127);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol8 == 0) {    
        mp3_play(128);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol9 == 0) {    
        mp3_play(129);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol10 == 0) {    
        mp3_play(130);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol11 == 0) {    
        mp3_play(131);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol12 == 0) {    
        mp3_play(132);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag10 == 0 kombinasyonlari
    else if (sag10 == 0 && sol1 == 0) {    
        mp3_play(133);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol2 == 0) {    
        mp3_play(134);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol3 == 0) {    
        mp3_play(135);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol4 == 0) {    
        mp3_play(136);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol5 == 0) {    
        mp3_play(137);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol6 == 0) {    
        mp3_play(138);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol7 == 0) {    
        mp3_play(139);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol8 == 0) {    
        mp3_play(140);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol9 == 0) {    
        mp3_play(141);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol10 == 0) {    
        mp3_play(142);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol11 == 0) {    
        mp3_play(143);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol12 == 0) {    
        mp3_play(144);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag11 == 0 kombinasyonlari
    else if (sag11 == 0 && sol1 == 0) {    
        mp3_play(145);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol2 == 0) {    
        mp3_play(146);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol3 == 0) {    
        mp3_play(147);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol4 == 0) {    
        mp3_play(148);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol5 == 0) {    
        mp3_play(149);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol6 == 0) {    
        mp3_play(150);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol7 == 0) {    
        mp3_play(151);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol8 == 0) {    
        mp3_play(152);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol9 == 0) {    
        mp3_play(153);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol10 == 0) {    
        mp3_play(154);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol11 == 0) {    
        mp3_play(155);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol12 == 0) {    
        mp3_play(156);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag12 == 0 kombinasyonlari
    else if (sag12 == 0 && sol1 == 0) {    
        mp3_play(157);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol2 == 0) {    
        mp3_play(158);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol3 == 0) {    
        mp3_play(159);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol4 == 0) {    
        mp3_play(160);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol5 == 0) {    
        mp3_play(161);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol6 == 0) {    
        mp3_play(162);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol7 == 0) {    
        mp3_play(163);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol8 == 0) {    
        mp3_play(164);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol9 == 0) {    
        mp3_play(165);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol10 == 0) {    
        mp3_play(166);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol11 == 0) {    
        mp3_play(167);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol12 == 0) {    
        mp3_play(168);
        lcdYaz(" ", " ", " ", " ");
    }


    // Tekli Dokunus kombinasyonlari
    else if (sag1 == 0) {    
      mp3_play (1);
      lcdYaz("Istiyorum",""," "," ");
    }

    else if (sag2 == 0) {    
      mp3_play (2);
      lcdYaz("Evet","",""," ");
    }

    else if (sag3 == 0) {    
      mp3_play (3);
      lcdYaz("Hayir","",""," ");
    }

    else if (sag4 == 0) {    
      mp3_play (4);
      lcdYaz("Selamun","Aleykum",""," ");
    }

    else if (sag5 == 0) {    
      mp3_play (5);
      lcdYaz("Nasilsin","",""," ");
    }

    else if (sag6 == 0) {    
      mp3_play (6);
      lcdYaz("Ne","Yapiyorsun",""," ");
    }

    else if (sag7 == 0) 
    {    
      mp3_play (7);
      lcdYaz("Nereye","Gidiyorsun","?"," ");
    }

    else if (sag8 == 0) 
    {    
      mp3_play (8);
      lcdYaz("Bir","Dakika",""," ");
    }

    else if (sag9 == 0) 
    {    
      mp3_play (9);
      lcdYaz("Ne ","Zaman","?"," ");
    }

    else if (sag10 == 0) 
    {    
      mp3_play (10);
      lcdYaz("Allah'a","Emanet"," "," ");
    }

    else if (sag11 == 0) 
    {    
      mp3_play (11);
      lcdYaz("Kac","",""," ");
    }

    else if (sag12 == 0) 
    {    
      mp3_play (12);
      lcdYaz("Gel","",""," ");
    }

    else if (sol1 == 0) {    
      mp3_play (13);
      lcdYaz("Git","",""," ");
    }

    else if (sol2 == 0) {    
      mp3_play (14);
      lcdYaz("Ozur","Dilerim"," "," ");
    }

    else if (sol3 == 0) {    
      mp3_play (15);
      lcdYaz("Tesekkur","Ederim",""," ");
    }

    else if (sol4 == 0) {    
      mp3_play (16);
      lcdYaz("Insallah",""," "," ");
    }

    else if (sol5 == 0) {    
      mp3_play (17);
      lcdYaz("Memleket",""," "," ");
    }

    else if (sol6 == 0) 
    {    
      mp3_play (18);
      lcdYaz("Kolay","","  ","");
    }

    else if (sol7 == 0) 
    {    
      mp3_play (1071);
      lcdYaz("Zor","","","");
    }

    else if (sol8 == 0) 
    {    
      mp3_play (20);
      lcdYaz("Var","","","");
    }

    else if (sol9 == 0) 
    {    
      mp3_play (21);
      lcdYaz("Yok","",""," ");
    }

    else if (sol10 == 0) 
    {    
      mp3_play (22);
      lcdYaz("Bitti ",""," "," ");
    }

    else if (sol11 == 0) 
    {    
      mp3_play (23);
      lcdYaz("Basla","","","");
    }

    else if (sol12 == 0) 
    {    
      mp3_play (24);
      lcdYaz("Tekrar","",""," ");
    }
    else {
        lcdYaz("Turkce", "Seslendirme", "Tanimlanamadi", " ");
        Serial.println("Turkce Seslendirme Taninamadi ??? ");
    }

}

void IngilizceKonus(){
    // sag1 == 0 kombinasyonlari
    if (sag1 == 0 && sol1==0) {    
      mp3_play (25);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol2==0) {    
      mp3_play (26);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol3==0) {    
      mp3_play (27);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol4==0) {    
      mp3_play (28);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag1 == 0 && sol5==0) {    
      mp3_play (29);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag1 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz(" "," "," "," ");
    }

    // Sag2 == 0 kombinasyonlari
    else if (sag2 == 0 && sol1==0) {    
      mp3_play (37);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol2==0) {    
      mp3_play (38);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol3==0) {    
      mp3_play (39);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol4==0) {    
      mp3_play (40);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag2 == 0 && sol5==0) {    
      mp3_play (41);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol6==0) {    
      mp3_play (42);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag2 == 0 && sol7==0) {    
      mp3_play (43);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol8==0) {    
      mp3_play (44);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol9==0) {    
      mp3_play (45);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol10==0) {    
      mp3_play (46);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol11==0) {    
      mp3_play (47);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol12==0) {    
      mp3_play (48);
      lcdYaz(" "," "," "," ");
    }

    // sag3 == 0 kontrol
    else if (sag3 == 0 && sol1==0) {    
      mp3_play (49);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol2==0) {    
      mp3_play (50);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol3==0) {    
      mp3_play (51);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol4==0) {    
      mp3_play (52);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag3 == 0 && sol5==0) {    
      mp3_play (53);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol6==0) {    
      mp3_play (54);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag3 == 0 && sol7==0) {    
      mp3_play (55);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol8==0) {    
      mp3_play (56);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol9==0) {    
      mp3_play (57);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol10==0) {    
      mp3_play (58);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol11==0) {    
      mp3_play (59);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol12==0) {    
      mp3_play (60);
      lcdYaz(" "," "," "," ");
    }

    // sag4 == 0 kombinayonlari
    else  if (sag4 == 0 && sol1==0) {    
      mp3_play (61);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol2==0) {    
      mp3_play (62);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol3==0) {    
      mp3_play (63);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol4==0) {    
      mp3_play (64);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag4 == 0 && sol5==0) {    
      mp3_play (65);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol6==0) {    
      mp3_play (66);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag4 == 0 && sol7==0) {    
      mp3_play (67);
      lcdYaz(" ",""," "," ");
    }
    else if (sag4 == 0 && sol8==0) {    
      mp3_play (68);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol9==0) {    
      mp3_play (69);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol10==0) {    
      mp3_play (70);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol11==0) {    
      mp3_play (71);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol12==0) {    
      mp3_play (72);
      lcdYaz(" "," "," "," ");
    }

    // sag5 == 0 kombinasyonlari
    else if (sag5 == 0 && sol1==0) {    
      mp3_play (73);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol2==0) {    
      mp3_play (74);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol3==0) {    
      mp3_play (75);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol4==0) {    
      mp3_play (76);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag5 == 0 && sol5==0) {    
      mp3_play (77);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol6==0) {    
      mp3_play (78);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag5 == 0 && sol7==0) {    
      mp3_play (79);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol8==0) {    
      mp3_play (80);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol9==0) {    
      mp3_play (81);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol10==0) {    
      mp3_play (82);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol11==0) {    
      mp3_play (83);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol12==0) {    
      mp3_play (84);
      lcdYaz(" "," "," "," ");
    }

    // sag6 == 0 kombinasyonlari
    else if (sag6 == 0 && sol1 == 0) {    
        mp3_play(85);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol2 == 0) {    
        mp3_play(86);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol3 == 0) {    
        mp3_play(87);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol4 == 0) {    
        mp3_play(88);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol5 == 0) {    
        mp3_play(89);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol6 == 0) {    
        mp3_play(90);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol7 == 0) {    
        mp3_play(91);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol8 == 0) {    
        mp3_play(92);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol9 == 0) {    
        mp3_play(93);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol10 == 0) {    
        mp3_play(94);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol11 == 0) {    
        mp3_play(95);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol12 == 0) {    
        mp3_play(96);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag7 == 0 kombinasyonlari
    else if (sag7 == 0 && sol1 == 0) {    
        mp3_play(97);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol2 == 0) {    
        mp3_play(98);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol3 == 0) {    
        mp3_play(99);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol4 == 0) {    
        mp3_play(100);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol5 == 0) {    
        mp3_play(101);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol6 == 0) {    
        mp3_play(102);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol7 == 0) {    
        mp3_play(103);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol8 == 0) {    
        mp3_play(104);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol9 == 0) {    
        mp3_play(105);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol10 == 0) {    
        mp3_play(106);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol11 == 0) {    
        mp3_play(107);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol12 == 0) {    
        mp3_play(108);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag8 == 0 kombinasyonlari
    else if (sag8 == 0 && sol1 == 0) {    
        mp3_play(109);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol2 == 0) {    
        mp3_play(110);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol3 == 0) {    
        mp3_play(111);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol4 == 0) {    
        mp3_play(112);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol5 == 0) {    
        mp3_play(113);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol6 == 0) {    
        mp3_play(114);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol7 == 0) {    
        mp3_play(115);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol8 == 0) {    
        mp3_play(116);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol9 == 0) {    
        mp3_play(117);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol10 == 0) {    
        mp3_play(118);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol11 == 0) {    
        mp3_play(119);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol12 == 0) {    
        mp3_play(120);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag9 == 0 kombinasyonlari
    else if (sag9 == 0 && sol1 == 0) {    
        mp3_play(121);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol2 == 0) {    
        mp3_play(122);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol3 == 0) {    
        mp3_play(123);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol4 == 0) {    
        mp3_play(124);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol5 == 0) {    
        mp3_play(125);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol6 == 0) {    
        mp3_play(126);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol7 == 0) {    
        mp3_play(127);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol8 == 0) {    
        mp3_play(128);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol9 == 0) {    
        mp3_play(129);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol10 == 0) {    
        mp3_play(130);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol11 == 0) {    
        mp3_play(131);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol12 == 0) {    
        mp3_play(132);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag10 == 0 kombinasyonlari
    else if (sag10 == 0 && sol1 == 0) {    
        mp3_play(133);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol2 == 0) {    
        mp3_play(134);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol3 == 0) {    
        mp3_play(135);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol4 == 0) {    
        mp3_play(136);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol5 == 0) {    
        mp3_play(137);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol6 == 0) {    
        mp3_play(138);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol7 == 0) {    
        mp3_play(139);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol8 == 0) {    
        mp3_play(140);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol9 == 0) {    
        mp3_play(141);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol10 == 0) {    
        mp3_play(142);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol11 == 0) {    
        mp3_play(143);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol12 == 0) {    
        mp3_play(144);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag11 == 0 kombinasyonlari
    else if (sag11 == 0 && sol1 == 0) {    
        mp3_play(145);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol2 == 0) {    
        mp3_play(146);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol3 == 0) {    
        mp3_play(147);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol4 == 0) {    
        mp3_play(148);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol5 == 0) {    
        mp3_play(149);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol6 == 0) {    
        mp3_play(150);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol7 == 0) {    
        mp3_play(151);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol8 == 0) {    
        mp3_play(152);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol9 == 0) {    
        mp3_play(153);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol10 == 0) {    
        mp3_play(154);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol11 == 0) {    
        mp3_play(155);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol12 == 0) {    
        mp3_play(156);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag12 == 0 kombinasyonlari
    else if (sag12 == 0 && sol1 == 0) {    
        mp3_play(157);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol2 == 0) {    
        mp3_play(158);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol3 == 0) {    
        mp3_play(159);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol4 == 0) {    
        mp3_play(160);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol5 == 0) {    
        mp3_play(161);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol6 == 0) {    
        mp3_play(162);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol7 == 0) {    
        mp3_play(163);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol8 == 0) {    
        mp3_play(164);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol9 == 0) {    
        mp3_play(165);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol10 == 0) {    
        mp3_play(166);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol11 == 0) {    
        mp3_play(167);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol12 == 0) {    
        mp3_play(168);
        lcdYaz(" ", " ", " ", " ");
    }


    // Tekli Dokunus kombinasyonlari
    else if (sag1 == 0) {    
      mp3_play (1001);
      lcdYaz("I want",""," "," ");
    }

    else if (sag2 == 0) {    
      mp3_play (1002);
      lcdYaz("Yes","","","");
    }

    else if (sag3 == 0) {    
      mp3_play (1003);
      lcdYaz("No","","","");
    }

    else if (sag4 == 0) {    
      mp3_play (1004);
      lcdYaz("Peace be","With you",""," ");
    }

    else if (sag5 == 0) {    
      mp3_play (1005);
      lcdYaz("How","are","you","?");
    }

    else if (sag6 == 0) {    
      mp3_play (1006);
      lcdYaz("What are","you doing","?"," ");
    }

    else if (sag7== 0) 
    {    
      mp3_play (1007);
      lcdYaz("Where are","you","going","?");
    }

    else if (sag8 == 0) 
    {    
      mp3_play (1008);
      lcdYaz("Just a","minute","","");
    }

    else if (sag9 == 0) 
    {    
      mp3_play (1009);
      lcdYaz("When","","","");
    }

    else if (sag10 == 0) 
    {    
      mp3_play (1010);
      lcdYaz("Trust in","Allah"," "," ");
    }

    else if (sag11 == 0) 
    {    
      mp3_play (1011);
      lcdYaz("How","Many",""," ");
    }

    else if (sag12 == 0) 
    {    
      mp3_play (1012);
      lcdYaz("Come","",""," ");
    }

    //İkinci El
    else if (sol1 == 0) 
    {    
      mp3_play (1013);
      lcdYaz("Go",""," "," ");

    }

    else if (sol2 == 0) 
    {    
      mp3_play (1014);
      lcdYaz("I'm sorry","",""," ");
    }

    else if (sol3 == 0) 
    {    
      mp3_play (1015);
      lcdYaz("Thank","you",""," ");
    }
    else if (sol4 == 0) 
    {    
      mp3_play (1016);
      lcdYaz("God","willing"," "," ");
    }

    else if (sol5 == 0) 
    {    
      mp3_play (1017);
      lcdYaz("Hometown","",""," ");
    }

    else if (sol6 == 0) 
    {    
      mp3_play (1018);
      lcdYaz("Easy","","","");
    }

    else if (sol7 == 0) 
    {    
      mp3_play (1019);
      lcdYaz("Difficult",""," "," ");
    }

    else if (sol8 == 0) 
    {    
      mp3_play (1020);
      lcdYaz("There","is",""," ");
    }

    else if (sol9 == 0) 
    {    
      mp3_play (1021);
      lcdYaz("No","",""," ");
    }

    else if (sol10 == 0) 
    {    
      mp3_play (1022);
      lcdYaz("It's","over",""," ");
    }

    else if (sol11 == 0) 
    {    
      mp3_play (1023);
      lcdYaz("Start","",""," ");
    }

    else if (sol12 == 0) 
    {    
      mp3_play (1024);
      lcdYaz("Again","","","");

    }
    else {
      Serial.println("Ingilizce sozcuk tanimlanamadi ???");
    }

}

void IspanyolcaKonus(){
    // sag1 == 0 kombinasyonlari
    if (sag1 == 0 && sol1==0) {    
      mp3_play (25);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol2==0) {    
      mp3_play (26);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol3==0) {    
      mp3_play (27);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol4==0) {    
      mp3_play (28);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag1 == 0 && sol5==0) {    
      mp3_play (29);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol6==0) {    
      mp3_play (30);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag1 == 0 && sol7==0) {    
      mp3_play (31);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol8==0) {    
      mp3_play (32);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol9==0) {    
      mp3_play (33);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol10==0) {    
      mp3_play (34);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol11==0) {    
      mp3_play (35);
      lcdYaz(" "," "," "," ");
    }
    else if (sag1 == 0 && sol12==0) {    
      mp3_play (36);
      lcdYaz(" "," "," "," ");
    }

    // Sag2 == 0 kombinasyonlari
    else if (sag2 == 0 && sol1==0) {    
      mp3_play (37);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol2==0) {    
      mp3_play (38);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol3==0) {    
      mp3_play (39);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol4==0) {    
      mp3_play (40);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag2 == 0 && sol5==0) {    
      mp3_play (41);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol6==0) {    
      mp3_play (42);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag2 == 0 && sol7==0) {    
      mp3_play (43);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol8==0) {    
      mp3_play (44);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol9==0) {    
      mp3_play (45);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol10==0) {    
      mp3_play (46);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol11==0) {    
      mp3_play (47);
      lcdYaz(" "," "," "," ");
    }
    else if (sag2 == 0 && sol12==0) {    
      mp3_play (48);
      lcdYaz(" "," "," "," ");
    }

    // sag3 == 0 kontrol
    else if (sag3 == 0 && sol1==0) {    
      mp3_play (49);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol2==0) {    
      mp3_play (50);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol3==0) {    
      mp3_play (51);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol4==0) {    
      mp3_play (52);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag3 == 0 && sol5==0) {    
      mp3_play (53);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol6==0) {    
      mp3_play (54);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag3 == 0 && sol7==0) {    
      mp3_play (55);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol8==0) {    
      mp3_play (56);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol9==0) {    
      mp3_play (57);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol10==0) {    
      mp3_play (58);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol11==0) {    
      mp3_play (59);
      lcdYaz(" "," "," "," ");
    }
    else if (sag3 == 0 && sol12==0) {    
      mp3_play (60);
      lcdYaz(" "," "," "," ");
    }

    // sag4 == 0 kombinayonlari
    else  if (sag4 == 0 && sol1==0) {    
      mp3_play (61);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol2==0) {    
      mp3_play (62);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol3==0) {    
      mp3_play (63);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol4==0) {    
      mp3_play (64);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag4 == 0 && sol5==0) {    
      mp3_play (65);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol6==0) {    
      mp3_play (66);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag4 == 0 && sol7==0) {    
      mp3_play (67);
      lcdYaz(" ",""," "," ");
    }
    else if (sag4 == 0 && sol8==0) {    
      mp3_play (68);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol9==0) {    
      mp3_play (69);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol10==0) {    
      mp3_play (70);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol11==0) {    
      mp3_play (71);
      lcdYaz(" "," "," "," ");
    }
    else if (sag4 == 0 && sol12==0) {    
      mp3_play (72);
      lcdYaz(" "," "," "," ");
    }

    // sag5 == 0 kombinasyonlari
    else if (sag5 == 0 && sol1==0) {    
      mp3_play (73);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol2==0) {    
      mp3_play (74);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol3==0) {    
      mp3_play (75);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol4==0) {    
      mp3_play (76);
      lcdYaz(" "," "," "," ");
    }    
    else if (sag5 == 0 && sol5==0) {    
      mp3_play (77);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol6==0) {    
      mp3_play (78);
      lcdYaz(" "," "," "," ");
    } 
    else if (sag5 == 0 && sol7==0) {    
      mp3_play (79);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol8==0) {    
      mp3_play (80);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol9==0) {    
      mp3_play (81);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol10==0) {    
      mp3_play (82);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol11==0) {    
      mp3_play (83);
      lcdYaz(" "," "," "," ");
    }
    else if (sag5 == 0 && sol12==0) {    
      mp3_play (84);
      lcdYaz(" "," "," "," ");
    }

    // sag6 == 0 kombinasyonlari
    else if (sag6 == 0 && sol1 == 0) {    
        mp3_play(85);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol2 == 0) {    
        mp3_play(86);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol3 == 0) {    
        mp3_play(87);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol4 == 0) {    
        mp3_play(88);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol5 == 0) {    
        mp3_play(89);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol6 == 0) {    
        mp3_play(90);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol7 == 0) {    
        mp3_play(91);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol8 == 0) {    
        mp3_play(92);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol9 == 0) {    
        mp3_play(93);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol10 == 0) {    
        mp3_play(94);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol11 == 0) {    
        mp3_play(95);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag6 == 0 && sol12 == 0) {    
        mp3_play(96);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag7 == 0 kombinasyonlari
    else if (sag7 == 0 && sol1 == 0) {    
        mp3_play(97);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol2 == 0) {    
        mp3_play(98);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol3 == 0) {    
        mp3_play(99);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol4 == 0) {    
        mp3_play(100);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol5 == 0) {    
        mp3_play(101);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol6 == 0) {    
        mp3_play(102);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol7 == 0) {    
        mp3_play(103);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol8 == 0) {    
        mp3_play(104);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol9 == 0) {    
        mp3_play(105);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol10 == 0) {    
        mp3_play(106);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol11 == 0) {    
        mp3_play(107);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag7 == 0 && sol12 == 0) {    
        mp3_play(108);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag8 == 0 kombinasyonlari
    else if (sag8 == 0 && sol1 == 0) {    
        mp3_play(109);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol2 == 0) {    
        mp3_play(110);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol3 == 0) {    
        mp3_play(111);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol4 == 0) {    
        mp3_play(112);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol5 == 0) {    
        mp3_play(113);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol6 == 0) {    
        mp3_play(114);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol7 == 0) {    
        mp3_play(115);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol8 == 0) {    
        mp3_play(116);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol9 == 0) {    
        mp3_play(117);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol10 == 0) {    
        mp3_play(118);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol11 == 0) {    
        mp3_play(119);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag8 == 0 && sol12 == 0) {    
        mp3_play(120);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag9 == 0 kombinasyonlari
    else if (sag9 == 0 && sol1 == 0) {    
        mp3_play(121);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol2 == 0) {    
        mp3_play(122);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol3 == 0) {    
        mp3_play(123);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol4 == 0) {    
        mp3_play(124);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol5 == 0) {    
        mp3_play(125);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol6 == 0) {    
        mp3_play(126);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol7 == 0) {    
        mp3_play(127);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol8 == 0) {    
        mp3_play(128);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol9 == 0) {    
        mp3_play(129);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol10 == 0) {    
        mp3_play(130);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol11 == 0) {    
        mp3_play(131);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag9 == 0 && sol12 == 0) {    
        mp3_play(132);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag10 == 0 kombinasyonlari
    else if (sag10 == 0 && sol1 == 0) {    
        mp3_play(133);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol2 == 0) {    
        mp3_play(134);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol3 == 0) {    
        mp3_play(135);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol4 == 0) {    
        mp3_play(136);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol5 == 0) {    
        mp3_play(137);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol6 == 0) {    
        mp3_play(138);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol7 == 0) {    
        mp3_play(139);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol8 == 0) {    
        mp3_play(140);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol9 == 0) {    
        mp3_play(141);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol10 == 0) {    
        mp3_play(142);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol11 == 0) {    
        mp3_play(143);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag10 == 0 && sol12 == 0) {    
        mp3_play(144);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag11 == 0 kombinasyonlari
    else if (sag11 == 0 && sol1 == 0) {    
        mp3_play(145);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol2 == 0) {    
        mp3_play(146);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol3 == 0) {    
        mp3_play(147);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol4 == 0) {    
        mp3_play(148);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol5 == 0) {    
        mp3_play(149);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol6 == 0) {    
        mp3_play(150);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol7 == 0) {    
        mp3_play(151);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol8 == 0) {    
        mp3_play(152);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol9 == 0) {    
        mp3_play(153);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol10 == 0) {    
        mp3_play(154);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol11 == 0) {    
        mp3_play(155);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag11 == 0 && sol12 == 0) {    
        mp3_play(156);
        lcdYaz(" ", " ", " ", " ");
    }

    // sag12 == 0 kombinasyonlari
    else if (sag12 == 0 && sol1 == 0) {    
        mp3_play(157);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol2 == 0) {    
        mp3_play(158);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol3 == 0) {    
        mp3_play(159);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol4 == 0) {    
        mp3_play(160);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol5 == 0) {    
        mp3_play(161);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol6 == 0) {    
        mp3_play(162);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol7 == 0) {    
        mp3_play(163);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol8 == 0) {    
        mp3_play(164);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol9 == 0) {    
        mp3_play(165);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol10 == 0) {    
        mp3_play(166);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol11 == 0) {    
        mp3_play(167);
        lcdYaz(" ", " ", " ", " ");
    }
    else if (sag12 == 0 && sol12 == 0) {    
        mp3_play(168);
        lcdYaz(" ", " ", " ", " ");
    }

    // Tekli Dokunus kombinasyonlari
    else if (sag1 == 0) {    
      mp3_play (2001);
      lcdYaz("Quiero",""," "," ");
    }

    else if (sag2 == 0) {    
      mp3_play (2002);
      lcdYaz("Si","","","");
    }

    else if (sag3 == 0) {    
      mp3_play (2003);
      lcdYaz("No","","","");
    }

    else if (sag4 == 0) {    
      mp3_play (2004);
      lcdYaz("La paz","sea contigo",""," ");
    }

    else if (sag5 == 0) {    
      mp3_play (2005);
      lcdYaz("Como estas","","","");
    }

    else if (sag6 == 0) {    
      mp3_play (2006);
      lcdYaz("Que estas","haciendo ","?"," ");
    }

    else if (sag7 == 0) 
    {    
      mp3_play (2007);
      lcdYaz("a donde","vas","","");
    }

    else if (sag8 == 0) 
    {    
      mp3_play (2008);
      lcdYaz("Solo un","minuto",""," ");
    }

    else if (sag9 == 0) 
    {    
      mp3_play (2009);
      lcdYaz("Cuando","",""," ");
    }

    else if (sag10 == 0) 
    {    
      mp3_play (2010);
      lcdYaz("Confia en","Allah"," "," ");
    }

    else if (sag11 == 0) 
    {    
      mp3_play (2011);
      lcdYaz("Cuantos","","?"," ");
    }

    else if (sag12 == 0) 
    {    
      mp3_play (2012);
      lcdYaz("Ven","",""," ");
    }

    //İkinci El
    else if (sol1 == 0) 
    {    
      mp3_play (2013);
      lcdYaz("Ve",""," "," ");
    }

    else if (sol2 == 0) 
    {    
      mp3_play (2014);
      lcdYaz("Lo","siento","?"," ");
    }

    else if (sol3 == 0) 
    {    
      mp3_play (2015);
      lcdYaz("Gracias","",""," ");
    }
    else if (sol4 == 0) 
    {    
      mp3_play (2016);
      lcdYaz("Si dios","quiere"," "," ");
    }

    else if (sol5 == 0) 
    {    
      mp3_play (2017);
      lcdYaz("Ciudad","natal",""," ");
    }

    else if (sol6 == 0) 
    {    
      mp3_play (2018);
      lcdYaz("Facil","",""," ");
    }

    else if (sol7 == 0) 
    {    
      mp3_play (2019);
      lcdYaz("Difficil",""," "," ");
    }

    else if (sol8 == 0) 
    {    
      mp3_play (2020);
      lcdYaz("hay","",""," ");
    }

    else if (sol9 == 0) 
    {    
      mp3_play (2021);
      lcdYaz("No","",""," ");
    }

    else if (sol10 == 0) 
    {    
      mp3_play (2022);
      lcdYaz("Se acabo",""," "," ");
    }

    else if (sol11 == 0) 
    {    
      mp3_play (2023);
      lcdYaz("inicio","",""," ");
    }

    else if (sol12 == 0) 
    {    
      mp3_play (2024);
      lcdYaz("De nuevo","",""," ");
    }  
    else {
      Serial.println("Ispanyolca dili tanimlanamadi ???");
    } 

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
      Serial.println(". Parca oynatildi ");
    }
    play+=1;
  }
}