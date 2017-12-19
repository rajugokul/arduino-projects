#include<EEPROM.h>
#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int led1 = 13;
String Data = "";
String D = "";
String Data1 = "";
String num = "";
String num1 = "";
String str = "";
int count=0;
int led2 = 4;
int resetPin = 8;
int i= 1;
int c=0;
char character;
bool flag = false;
bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;
bool flag6= false;
int add=0;
int eeAddress = 0; 
void setup()
{
 mySerial.begin(9600);   
 Serial.begin(9600);
 delay(100);
 lcd.begin(16, 2);
 lcd.print("preparing...");
 delay(1000);
 lcd.setCursor(0, 0);
 lcd.print("Ready....");
 delay(1000);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 mySerial.begin(9600);
 Serial.begin(9600);
 digitalWrite(resetPin, HIGH);
 delay(200);  
 pinMode(resetPin, OUTPUT);
 Serial.println("reset");        
 mySerial.println("AT+CMGF=1");
 mySerial.println("AT+CNMI=2,2,0,0,0\r");
 mySerial.println("AT+CMGD=1,4");
}


void loop()
{
if (mySerial.available()>0){
     
     if(Data1 == "LIP"){
       Data1 = "";
       flag2 = false;
     }
 char character = mySerial.read();
    if(character=='R'|| flag){
     Data = Data + character;
     flag = true;
    }
    if(character =='l'|| flag2 || character =='l'){
           Data1 = Data1 + character;
           flag2 = true;
     }     
    if(character =='9'|| flag3){
       num.concat(character);
       add++;
       flag3 = true;
      }
      if(character =='z'||character =='Z'||flag4){
        D = Data1 + character;       
       flag4= true; 
     }
       
      if(D =="z"||D =="Z"||flag5||flag6)
      { 
          if(D=="Z"||D=="z"){
            D="";
            flag6=false;  
          }
          
            str.concat(D);
            c++;
            flag5= true;
      }
       
      if(c == 15){
         Serial.println(str);
         Serial.println("retrive number");
         EEPROM.put(eeAddress,str);
         Serial.println("str value!!!!");
        Serial.println(EEPROM.get(eeAddress,str));
         str= "";
         D="";
         add = 0;
         flag4=false;
      }
         
    if(add == 12){
         Serial.println("num Value!!");
//          Serial.println(num);
          num1=num;
//         lcd.begin(16, 2);
//         lcd.setCursor(0, 1);
//         lcd.print(num);
//         lcd.setCursor(1, 0);
//         lcd.print("Ring...");
//         lcd.setCursor(8, 0);
//         lcd.print(count);
         num = "";
         Data1="";
         add = 0;
         flag3 = false;  
      }
      str.trim();
     Serial.println("num1 *"+num1+"*"+"str *"+str+"*");
     if (Data == "RING" && num1 == str ){
           Data1 = "";      
           Data="";
           num = "";
           num1="";
           Serial.write("ring");
           count++;
           Serial.println(count);
           delay(50);  
           flag = false;                
           if(count==2){
           lcd.setCursor(10, 0);
           lcd.print("ON!!");
           digitalWrite(led1,HIGH);
           Serial.println("motor on");
           mySerial.println("ATH0"); 
           delay(1000);           
           Data1 = "";                        
        }
         else if(count>=5){
           lcd.setCursor(10, 0);
           lcd.print("OFF!!");
          Serial.println("motor off");
           digitalWrite(led1,LOW);
           mySerial.println("ATH0");
           delay(1000);
           count = 0;
           Data1 = "";      
     }
  }

  
         if(Data1 =="m1 on" || Data1 =="L1 on"){
           lcd.setCursor(1, 0);
         lcd.print("Msg---->ON");
           Serial.println(Data1);
           digitalWrite(led1,HIGH);
           digitalWrite(led2,HIGH);
           lcd.setCursor(0, 1);
           count=2;
           Data1 ="";
           flag2 = false;
        } else if(Data1 =="l1 off" || Data1 =="L1 off"){
          lcd.setCursor(1, 0);
         lcd.print("Msg---->OFF");
           Serial.println(Data1);
           digitalWrite(led1,LOW);
           digitalWrite(led2,LOW);
           count=0;
           Data1 ="";
           flag2 = false;
         } else if(Data1 =="l1t " || Data1 =="L1t " || flag1 ){
           flag1 = true;
                     if( i == 1 ){
                         i++;
                       }else{
                         flag1 = false;
                         flag2 = false;
                         while(1){
                             Serial.println(Data1);
                             Data ="";
                             verify((int)character);
                             Serial.println("IM out");
                             digitalWrite(resetPin, LOW);
                             break;
                         }
                        }
             }

}
}
bool verify(int a){
    Serial.println(a);
int count = (a-48)*1000;
   while(1){
      Serial.println(count);
      if (mySerial.available()>0){
           char character = mySerial.read();
            if(character =='+'){
               return false;
             }
      }
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
   delay(count);
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   delay(count);
   }
 }
