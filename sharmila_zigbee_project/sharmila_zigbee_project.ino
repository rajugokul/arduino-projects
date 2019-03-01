#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 =5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool flag=false;
char data;
int count,add=0;
String str,sound="";
void setup() {
        lcd.begin(16,2);
        Serial.begin(9600);
        lcd.setCursor(0, 0);
        lcd.print("connecting....");
        delay(3000);
        lcd.clear();


}

void loop() {
  if(Serial.available()>0){
   lcd.setCursor(0, 0); 
data=(Serial.read());
if(data=='G'||count<=4){
  count=count+1;
  str=str+data;
  add=0;
  lcd.print(str); 
}
if(data=='S'||add<=4){
  add=add+1;
  count=0;
  sound=sound+data;
  lcd.print(sound);
}
delay(100);

if(data=='#'){
  str="";
  flag=false;
  lcd.clear();
  delay(1000);
}
  }
}
