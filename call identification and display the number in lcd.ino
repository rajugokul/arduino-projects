#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int led1 = 13;
int resetPin = 8;
String Data = "";
int count=0;
const int ledPin= 12;
int value=0;
int i = 1;
int j= 1;
bool flag = false;
const int inputPin= 5;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("welcome to gsm!");
  delay(5000);
  lcd.setCursor(0, 1);
  lcd.print("start now.......");
  pinMode(ledPin, OUTPUT);
pinMode(inputPin, INPUT);
  delay(100);

}


void loop()
{
 if (mySerial.available()>0)
 {
     char character = mySerial.read();
         if( flag || character =='R')
         {
          Data.concat(character);
          flag = true;
         }
          if(Data=="RING")
           {
       Data="";
      Serial.write("success!!!");
      count++;
      Serial.println(count);
      delay(100);
     flag=false;
  if(count==2)
 {
                                        digitalWrite(led1,HIGH);
                                        Serial.println("motor on");
                                         mySerial.println("ATH0");;
                                        Serial.println("Hang up.");
                                        delay(1000);
                                         lcd.begin(16, 2);
                                        lcd.setCursor(0, 1);
                                        lcd.print("on!!!");
                                        Serial.println("motor on");
                                        
//                                       mySerial.println("AT+CMGF=1"); 
//                                        delay(1000);
//                                       mySerial.println("AT+CMGS=\"+919788391337\"\r"); 
//                                       delay(1000);
//                                        mySerial.println("        gsm  \n    Moter on!! ");
//                                       delay(100);
//                                       mySerial.println((char)26);
//                                       delay(1000);

 }
else if(count>=5){
                                         Serial.println("motor off");
                                        digitalWrite(led1,LOW);
                                         mySerial.println("ATH0");;
                                        Serial.println("Hang up.");
                                        delay(1000);
                                         lcd.begin(16, 2);
                                         lcd.setCursor(0, 1);
                                        lcd.print("off!!!");
//                                        mySerial.println("AT+CMGF=1");   
//                                        delay(1000);  
//                                       mySerial.println("AT+CMGS=\"+919788391337\"\r"); 
//                                       delay(1000);
//                                     mySerial.println("        gsm  \n    Moter off!! \n \n  Thank you!!");
//                                      delay(100);
//                                     mySerial.println((char)26);
//                                     delay(1000);
                                        count = 0;

} 
}
           }

}
