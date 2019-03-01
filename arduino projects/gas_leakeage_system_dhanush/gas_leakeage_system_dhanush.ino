#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int a=0;

void setup() {
      pinMode(12,OUTPUT);
      pinMode(13,OUTPUT);
      Serial.begin(9600);
      lcd.begin(16, 2);
      lcd.print("*****welcome*****");
      delay(3000);
      lcd.setCursor(0,1);
      lcd.print("gas monitor sys.."); 
      delay(5000);
      lcd.clear();
      }

void loop() {
  a=analogRead(A0);
  a=a-400;
  lcd.setCursor(0, 0);
  lcd.print("NORMAL STATE :)");
  delay(100);
  if(a>1){
    lcd.setCursor(0, 1);
    lcd.print(a);
    delay(100);
  }
  
  if(a>100){
    lcd.print("gas was leaking..");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("exhaust fan on");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("main power cut");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALART!!!!!!");
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    sms();sss
    delay(5000);
  }
  else{
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
  }
  
}

void sms(){
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919788391337\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("!!!ALART!!! \n gas leakage detected!!");
  delay(1000);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
 
