int button1Pin = A0;
int button2Pin = A1;
int button3Pin = A2;
int button4Pin = A3;
int button5Pin = A4;
int button6Pin = A5;

int buttonBilgi = 13;    //kasadaki para adedi
int buttonBilgi2 = 10;   //kalan hizmet adedi

int kirmiziPin = 7;
int yesilPin = 6;

boolean buttonDurum1 = 0;
boolean buttonDurum2 = 0;
boolean buttonDurum3 = 0;
boolean buttonDurum4 = 0;
boolean buttonDurum5 = 0;
boolean buttonDurum6 = 0;

int kasaBesTlAdedi = 20;
int kasaOnTlAdedi = 20;
int kasaYirmiTlAdedi = 10;
int kasaElliTlAdedi = 30;
int kasaYuzTlAdedi = 5;

int besTlAdedi = 0;
int onTlAdedi = 0;
int yirmiTlAdedi = 0;
int elliTlAdedi = 0;
int yuzTlAdedi = 0;
int button6Sayac = 0;

int kasaBakiye = kasaBesTlAdedi * 5 + kasaOnTlAdedi * 10 + kasaYirmiTlAdedi * 20 + kasaElliTlAdedi * 50 + kasaYuzTlAdedi * 100;
int bakiye = 0;
int tutar = 0;
int paraUstu;

int kopuklemeAdet = 30;
int yikamaAdet = 50;
int kurulamaAdet = 100;
int cilalamaAdet = 20;

int kopuklemeSayac = 0;
int yikamaSayac = 0;
int kurulamaSayac = 0;
int cilalamaSayac = 0;

boolean button1Durum = 0;
boolean button2Durum = 0;
boolean button3Durum = 0;
boolean button4Durum = 0;
boolean button5Durum = 0;
boolean button6Durum = 0;

boolean buttonBilgi2Durum = 0;

boolean basildiMi = false;
long randomSayi;

int kalan, bolum;

#include <LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {  
    pinMode(button1Pin, INPUT);
    pinMode(button2Pin, INPUT);
    pinMode(button3Pin, INPUT);
    pinMode(button4Pin, INPUT);
    pinMode(button5Pin, INPUT);
    pinMode(button6Pin, INPUT);
    
    pinMode(buttonBilgi, INPUT);
    pinMode(buttonBilgi2, INPUT);
    
    pinMode(yesilPin, OUTPUT);
    pinMode(kirmiziPin, OUTPUT);

    Serial.begin(9600);

    lcd.begin(16, 2);
    
}

void loop() {
    int button1State = digitalRead(button1Pin);
    int button2State = digitalRead(button2Pin);
    int button3State = digitalRead(button3Pin);
    int button4State = digitalRead(button4Pin);
    int button5State = digitalRead(button5Pin);
    int button6State = digitalRead(button6Pin);
    
    int buttonBilgiState = digitalRead(buttonBilgi);
    int buttonBilgi2State = digitalRead(buttonBilgi2);
    
    lcd.setCursor(0, 0); 

    //kasa para adedini gösterme
    if(buttonBilgiState == HIGH)
    {
        lcd.print("5 tl: ");
        lcd.print(kasaBesTlAdedi);
        lcd.print("  10 tl: ");
        lcd.print(kasaOnTlAdedi);
        lcd.print("  20 tl: ");
        lcd.print(kasaYirmiTlAdedi);

        lcd.setCursor(0, 1);   
        lcd.print("50 tl: ");
        lcd.print(kasaElliTlAdedi);
        lcd.print("  100 tl: ");
        lcd.print(kasaYuzTlAdedi);    
    }

    //kalan hizmet adedini gösterme
    if(buttonBilgi2State == HIGH && buttonBilgi2Durum == 0)
    {
      Serial.print("1, kopukleme, ");
      Serial.print(kopuklemeAdet);
      Serial.println(" ,15 TL");
      Serial.print("2, yikama, ");
      Serial.print(yikamaAdet);
      Serial.println(" ,10 TL");
      Serial.print("3, kurulama, ");
      Serial.print(kurulamaAdet);
      Serial.println(" ,5 TL");
      Serial.print("4, cilalama: ");
      Serial.print(cilalamaAdet);
      Serial.println(" ,50 TL");
      Serial.println("");
      buttonBilgi2Durum = 1;
    }
    if(buttonBilgi2State == LOW)
    {
      buttonBilgi2Durum = 0;
    }


    //para yükleme kısmı 

    if(button6Sayac == 0)
    {
      //1. buton
      if(button1State == HIGH && buttonDurum1 == 0)
      {
        besTlAdedi++;
        kasaBesTlAdedi++;
        buttonDurum1 = 1;
      }
      if (button1State == LOW)
      {
        buttonDurum1 = 0;
      }

      //2. buton
      if(button2State == HIGH && buttonDurum2 == 0)
      {
        onTlAdedi++;
        kasaOnTlAdedi++;
        buttonDurum2 = 1;
      }
      if (button2State == LOW)
      {
        buttonDurum2 = 0;
      }


      //3. buton
      if(button3State == HIGH && buttonDurum3 == 0)
      {
        yirmiTlAdedi++;
        kasaYirmiTlAdedi++;
        buttonDurum3 = 1;
      }
      if (button3State == LOW)
      {
        buttonDurum3 = 0;
      }


      //4. buton
      if(button4State == HIGH && buttonDurum4 == 0)
      {
        elliTlAdedi++;
        kasaElliTlAdedi++;
        buttonDurum4 = 1;
      }
      if (button4State == LOW)
      {
        buttonDurum4 = 0;
      }


      //5. buton
      if(button5State == HIGH && buttonDurum5 == 0)
      {
        yuzTlAdedi++;
        kasaYuzTlAdedi++;
        buttonDurum5 = 1;
      }
      if (button5State == LOW)
      {
        buttonDurum5 = 0;
      }


      //6. buton
      if(button6State == HIGH && basildiMi == false)
      {
        bakiye = besTlAdedi * 5 + onTlAdedi * 10 + yirmiTlAdedi * 20 + elliTlAdedi * 50 + yuzTlAdedi * 100;
        button6Sayac++;
        lcd.clear();
        lcd.print(bakiye);
        lcd.print(" TL para attiniz"); 
        delay(3000);
        lcd.clear();      
      // buttonDurum6 = 1;
      }  
    }



    //hizmet seçme
    if (button6Sayac)
    {
      //1. buton
      if(button1State == HIGH && button1Durum == 0)
      {
        kopuklemeSayac++;
        kopuklemeAdet--;
        if(kopuklemeAdet < 0)
        { 
          lcd.clear();
          lcd.setCursor(0, 0);   
          lcd.print("kopukleme");
          lcd.setCursor(0, 1);
          lcd.print("hizmeti kalmadi"); 
          kopuklemeAdet++;  
          kopuklemeSayac--;
        }
        basildiMi = true;
        button1Durum = 1;
      }
      if (button1State == LOW)
      {
        button1Durum = 0;
      }


      //2. buton
      if(button2State == HIGH && button2Durum == 0)
      {
        yikamaSayac++;
        yikamaAdet--;
        if(yikamaAdet < 0)
        { 
          lcd.clear();
          lcd.setCursor(0, 0);   
          lcd.print("yikama");
          lcd.setCursor(0, 1);
          lcd.print("hizmeti kalmadi"); 
          yikamaAdet++;  
          yikamaSayac--;
        }
        basildiMi = true;
        button2Durum = 1;
      }
      if (button2State == LOW)
      {
        button2Durum = 0;
      }


      //3. buton
      if(button3State == HIGH && button3Durum == 0)
      {
        kurulamaSayac++;
        kurulamaAdet--;
        if(kurulamaAdet < 0)
        { 
          lcd.clear();
          lcd.setCursor(0, 0);   
          lcd.print("kurulama");
          lcd.setCursor(0, 1);
          lcd.print("hizmeti kalmadi");   
          kurulamaAdet++;
          kurulamaSayac--;
        }
        basildiMi = true;
        button3Durum = 1;
      }
      if (button3State == LOW)
      {
        button3Durum = 0;
      }


      //4. buton
      if(button4State == HIGH && button4Durum == 0)
      {
        cilalamaSayac++;
        cilalamaAdet--;
        if(cilalamaAdet < 0)
        { 
          lcd.clear();
          lcd.setCursor(0, 0);   
          lcd.print("cilalama");
          lcd.setCursor(0, 1);
          lcd.print("hizmeti kalmadi");   
          cilalamaAdet++;
          cilalamaSayac--;
        }
        basildiMi = true;
        button4Durum = 1;
      }
      if (button4State == LOW)
      {
        button4Durum = 0;
      }


      //5. buton
      if(button5State == HIGH && button5Durum == 0)
      {
        kopuklemeAdet += kopuklemeSayac;
        yikamaAdet += yikamaSayac;
        kurulamaAdet += kurulamaSayac;
        cilalamaAdet += cilalamaSayac;
        
        kopuklemeSayac = 0;
        yikamaSayac = 0;
        kurulamaSayac = 0;
        cilalamaSayac = 0;
        
        basildiMi = true;
        button5Durum = 1;
      }
      if (button5State == LOW)
      {
        button5Durum = 0;
      }


      //6. buton
      if(button6State == HIGH && basildiMi == true)
      {
        tutar = kopuklemeSayac * 15 + yikamaSayac * 10 + kurulamaSayac * 5 + cilalamaSayac * 50;
        paraUstu = bakiye-tutar;

        if(paraUstu < 0)
        {
          kasaBesTlAdedi -= besTlAdedi;
          kasaOnTlAdedi -= onTlAdedi;
          kasaYirmiTlAdedi -= yirmiTlAdedi;
          kasaElliTlAdedi -= elliTlAdedi;
          kasaYuzTlAdedi -= yuzTlAdedi;

          kopuklemeAdet += kopuklemeSayac;
          yikamaAdet += yikamaSayac;
          kurulamaAdet += kurulamaSayac;
          cilalamaAdet += cilalamaSayac;

          kopuklemeSayac = 0;
          yikamaSayac = 0;
          kurulamaSayac = 0;
          cilalamaSayac = 0;
          
          lcd.clear();
          lcd.setCursor(0, 0); 
          lcd.print("Bakiye yetersiz");
          lcd.setCursor(0, 1); 
          lcd.print("Para iade edildi");
        }

        else
        {
          lcd.clear();
          randomSayi = random(1, 5);
        

          //para sıkışması durumu
          if (randomSayi == 2)
          {
            kasaBesTlAdedi -= besTlAdedi;
            kasaOnTlAdedi -= onTlAdedi;
            kasaYirmiTlAdedi -= yirmiTlAdedi;
            kasaElliTlAdedi -= elliTlAdedi;
            kasaYuzTlAdedi -= yuzTlAdedi;
  
            kopuklemeAdet += kopuklemeSayac;
            yikamaAdet += yikamaSayac;
            kurulamaAdet += kurulamaSayac;
            cilalamaAdet += cilalamaSayac;
            lcd.print("Para sikisti");
            
            digitalWrite(kirmiziPin, HIGH);
            delay(2000);
            digitalWrite(kirmiziPin, LOW);
          }
          else
          {
            if(paraUstu / 100 > kasaYuzTlAdedi)
              bolum = kasaYuzTlAdedi;
            else
              bolum = paraUstu / 100;
            kasaYuzTlAdedi -= bolum;
    
            kalan = paraUstu - (bolum * 100);
        
            if(kalan / 50 > kasaElliTlAdedi)
                bolum = kasaElliTlAdedi;
            else
                bolum = kalan / 50;
            kasaElliTlAdedi -= bolum;
        
            kalan = kalan - (bolum * 50);
        
            if(kalan / 20 > kasaYirmiTlAdedi)
                bolum = kasaYirmiTlAdedi;
            else
                bolum = kalan / 20;
            kasaYirmiTlAdedi -= bolum;
        
            kalan = kalan - (bolum * 20);
        
            if (kalan / 10 > kasaOnTlAdedi)
                bolum = kasaOnTlAdedi;
            else
                bolum = kalan / 10;
            kasaOnTlAdedi -= bolum;
        
            kalan = kalan - (bolum * 10);
        
            if (kalan / 5 > kasaBesTlAdedi)
            {
              lcd.print("bakiye yetersiz");
              kasaBesTlAdedi -= besTlAdedi;
              kasaOnTlAdedi -= onTlAdedi;
              kasaYirmiTlAdedi -= yirmiTlAdedi;
              kasaElliTlAdedi -= elliTlAdedi;
              kasaYuzTlAdedi -= yuzTlAdedi; 

              kopuklemeAdet += kopuklemeSayac;
              yikamaAdet += yikamaSayac;
              kurulamaAdet += kurulamaSayac;
              cilalamaAdet += cilalamaSayac;
              
              kopuklemeSayac = 0;
              yikamaSayac = 0;
              kurulamaSayac = 0;
              cilalamaSayac = 0;
            }
                
            else
            {
              bolum = kalan / 5;
              kasaBesTlAdedi -= bolum;
              lcd.print("Para Ustu");
              lcd.setCursor(0, 1);
              lcd.print(paraUstu);  
              lcd.print(" TL");
            }
              
            digitalWrite(yesilPin, HIGH);
            delay(2000);
            digitalWrite(yesilPin, LOW);
          }
          
        }
        basildiMi = false;
      }
      if (button6State == LOW)
      {
        basildiMi = true;
      }
      
    }
    
}
