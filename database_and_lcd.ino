#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#include <SoftwareSerial.h>
SoftwareSerial myGsm(10,11);
int led1 = 13;
String Data = "";
String cpy = "";
char num;
String number="";
int count=0;
int add=0;
bool flag = false;


void setup()
{
myGsm.begin(9600);  
Serial.begin(9600);  
delay(500);
lcd.begin(16, 2);
lcd.print("hello, world!");
}
void loop(){
if (myGsm.available()>0) {
    char character = myGsm.read();
    if(character =='9'|| flag){
            Data = Data + character;
            add++;
            flag = true;
           }    
          else{
            Data = "";
          }
     if (add==12){
          Serial.print(Data);
          cpy=Data;
          Data = "";
          Serial.println();
          Serial.write("ring");
          count++;
          Serial.println(count);
          delay(100);  
           flag = false;          
          if(count==2){
            digitalWrite(led1,HIGH);
            Serial.println("motor on");
            myGsm.println("ATH0");
            Serial.println("Hang up......");
            delay(100);
            Serial.print(cpy);
            lcd.begin(16, 2);
            lcd.setCursor(0, 1);
            lcd.print(cpy);
            lcd.setCursor(1,0);
            lcd.print("ON!!");
            cpy="";
             check();
             myGsm.println("AT+HTTPPARA=\"URL\",\"http://10.0.0.24/test_iot/index.php?status=1\"");
             delay(1000);
             check_1();
            Data = "";                                                                              
        }else if(count>=3){
            Serial.println("motor off");
            digitalWrite(led1,LOW);
            myGsm.println("ATH0");
            Serial.println("Hang up.");
            delay(100);
            Serial.print(cpy);
            lcd.begin(16, 2);
            lcd.setCursor(0, 1);
            lcd.print(cpy);
            lcd.setCursor(1,0);
            lcd.print("OFF!!");
            cpy="";
            
             check();
             myGsm.println("AT+HTTPPARA=\"URL\",\"http://10.0.0.24/test_iot/index.php?status=2\"");
             delay(1000);
             check_1();
            Data="";
            count = 0;
        }
      add = 0;
     }
 }
}
void check(){
             myGsm.println();
             myGsm.println("AT");
             myGsm.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR,connection type is GPRS
             myGsm.println("AT+SAPBR=3,1,\"APN\",\"WWW\"");//setting the APN,2nd parameter empty works for all networks
             myGsm.println("AT+SAPBR=1,1");
             myGsm.println("AT+SAPBR=2,1");
             delay(1000);
             myGsm.println("AT+HTTPINIT"); //init the HTTP request
             myGsm.println("AT+HTTPPARA=\"CID\",1");
}
void check_1(){
             myGsm.println();
             myGsm.println("AT+HTTPACTION=0");//submit the GET request
             delay(5000);//the delay is important if the return datas are very large, the time required longer.
             myGsm.println("AT+HTTPREAD=0,20");// read the data from the website you access
             delay(3000);
             myGsm.println("");
             delay(1000);
             myGsm.println("AT+HTTPTERM");// terminate HTTP service
             delay(1000); 
}
