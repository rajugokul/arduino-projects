#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 =5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char data;
String str;
int count=0;
bool flag1=false;
bool flag2=false;

String S1="";

void setup() {
 lcd.begin(16,2);
        Serial.begin(9600);
        lcd.setCursor(0, 0);
        lcd.print("connecting....");
//        delay(3000);
        lcd.clear();
}

byte rxer;
void loop() {
if(Serial.available()>0)
{
do
{
   rxer = Serial.read();
}while(rxer!='G');

S1 = Serial.readString();

Serial.println("Gas :"+S1);
Serial.available() = 0;
}
}
