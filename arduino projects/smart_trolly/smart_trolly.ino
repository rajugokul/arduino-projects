#include <LiquidCrystal.h>
const int rs = 8 , en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String data=" ";
String tt=" ";
int O=0;
int num=0;
int count=0;
int count1=0;
int count3=0;
int count4=0;
int con=0;
int c=0;
int add=0;
int add1=0;
int a=0;
int a1=0;
int amount =3000;
String v=" ";
String v1=" ";
String v3=" ";
String v4=" ";
String D="";
int t,t1,t3,t4;
void setup() {
      Serial.begin(9600);
      lcd.begin(16, 2);
      lcd.print("$$$ WELCOME $$$");
}

void loop() {
   
  if(Serial.available()>0){
    data=Serial.readString();
    Serial.println(data);
    
 /////start u1
  if(data=="4A007BAF3AA4"){
    add1++;
    Serial.println(add1);
    data=" ";
  }
   if (add1==1 && a1==0){
    a1=1;
    tt="9791123480";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u1=9791123480");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("use now!!!!");

  }
  /// start u2
  if(data=="4A007BF92BE3" ){
    add++;
    Serial.println(add);
    data=" ";
  }
  if (add==1 && a==0){
    a=1;
    tt="9789475331";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u2=9789475331");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("use now!!!!");

  }
  if(add==1 && a==1||add1==1 && a1==1){
    
  if(data=="4B004052174E"){
     lcd.clear();
     lcd.setCursor(0, 1);
     count++;
     data=" ";
     if(count==1){
    lcd.print("LAYS $=30");
     v=("#LAYS -&=30");
    }
    if(count==2){
      lcd.print("remove LAYS");
      v=" ";
      count=0;
    } 
    }

  if(data=="0000A732E075"){
     lcd.clear();
     lcd.setCursor(0, 1);
     count1++;
      if(count1==1){
    lcd.print("BOOST-$=250");
     v1=("BOOST-$=250");
     t1=250;
    }
    if(count1==2){
      lcd.print("remove BOOST");
      v1=" ";
      count1=0;
      t1=0;
    } 
     
  }

        if(data=="00009FBB0622"){
        lcd.clear();
        lcd.setCursor(0, 1);
        count3++;
        data=" ";
        if(count3==1){
        lcd.print("CHOCO-$=50");
        v3=("CHOCO-$=50");
        t3=50;
        }
        if(count3==2){
        lcd.print("remove CHOCO");
        v3=" ";
        count3=0;
        } 
        
        
        }
if(data=="0000A03B9F04"){
   lcd.clear();
     lcd.setCursor(0, 1);
     count4++;
    data=" ";
   if(count4==1){
    lcd.print("MUNCH-$=30");
     v4=("MUNCH-$=30");
     t4=30;
    }
    if(count4==2){
      lcd.print("remove MUNCH");
      v4=" ";
      count4=0;
      t4=0;
    } 
}
  }
  if(add==2 ||add1==2){
      O=t+t1+t3+t4;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("bill="+String(O));
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("main bln="+String(amount));
    c=amount-O;
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rem bln="+String(c));
    delay(2000);
    add=0;
    add1=0;
    data=" ";
    smstemplate();
  }
  }
}

void smstemplate(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("processing....");
  D=(String(O));
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+91"+tt+"\"\r"); // Replace x with mobile number
  delay(1000);
//  Serial.println("hai....");
  Serial.println("UR BILL list@\n"+v+"  "+v1+"  "+v3+" "+v4+"\nTOTAL AMOUNT="+D+"");
  delay(1000);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  v=" ";
  v1=" ";
  v3=" ";
  v4=" ";
  D=" ";
  a=0;
  count=0;
  count1=0;
  count3=0;
  count4=0;
  t=0;
  t1=0;
  t3=0;
  t4=0;
  delay(4000);
  smstemmplate1();
}
void smstemmplate1(){
  Serial.println("AT+CMGF=1");   
  delay(1000);  
  Serial.println("AT+CMGS=\"+91"+tt+"\"\r"); 
  delay(1000); 
  Serial.println("main balance="+String(amount)+"\nUR Bill="+String(O)+"\nRemaining balance="+String(c));
  delay(1000);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  amount=3000;
  c=0;
  O=0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("sended----(:");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("$$$ WELCOME $$$");
}

