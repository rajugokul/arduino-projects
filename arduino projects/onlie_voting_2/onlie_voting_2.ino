#include <LiquidCrystal.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9);
SoftwareSerial portTwo(12, 13);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
unsigned long int count;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int id=0;
int select,fng,tag=0;
int party=0;
int a,b,c,d,e;
int u1=0,u2=0,u3=0,u4=0,u5=0;
int lis1=0,lis2=0,lis3=0,lis4=0,lis5=0;
String num=" ";
int permission=0;
void setup() {
  Serial.begin(9600);
  portTwo.begin(9600);
  finger.begin(57600);
//  pinMode(13,OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(A4,INPUT_PULLUP);
//  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("welcome");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SHOW ur ID..");
  
//  if (finger.verifyPassword()) {
//    Serial.println("Found fingerprint sensor!");
//  } else {
//    Serial.println("Did not find fingerprint sensor :(");
//    while (1) { delay(1); }
//  }
//
//  finger.getTemplateCount();
//  Serial.print("total temp:"+String(finger.templateCount)); 
//  

}

void loop() {
portTwo.listen();
while(portTwo.available()==0);
while(portTwo.available()>0)
{
  String S = portTwo.readString();
//  Serial.println(S);
  delay(2000);
  if(S =="2100858FBE95" && lis1==0)
  {
    lis1=1;
    num="9092300715";
    tag=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u1");
    delay(2000);
    S="";
  }
 
  
   
if(S =="210085F01D49" && lis2==0)
  {
    u2++;
    lis2=1;
    num="9092300715";
    tag=2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u2");
        delay(2000);
        S="";

  }


if(S =="2100864A0BE6" && lis3==0)
  {
    lis3=1;
    num="9092300715";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u3");
        delay(2000);
    tag=3;
    S="";

  }


if(S =="45003C5AFEDD" && lis4==0)
  {
    lis4=1;
    num="9092300715";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u4");
        delay(2000);
    tag=4;
        S="";

  }

if(S =="45003C55DFF3" && lis5==0)
  {
    lis5=1;
    num="9092300715";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u5");
        delay(2000);
    tag=5;
        S="";

  }

  else if(S =="2100858FBE95" && lis1==1||S =="210085F01D49" && lis2==1||S =="2100864A0BE6" && lis3==1||S =="45003C5AFEDD" && lis4==1||S =="45003C55DFF3" && lis5==1){
    tag=0;
    S="";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ACCESS DENIED!!");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("welcome");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("show ur id!!!");
  }
  
  portTwo.end();
}

while(tag==1 ||tag==2 || tag == 3 || tag == 4 || tag == 5 ){
 
while(portTwo.available()==0 && select==0)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("auth finger..");
  delay(100);
  mySerial.begin(57600);
  getFingerprintIDez();
//  lcd.print("fng"+String(fng)); 

delay(100);
}
if(select==1){
  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Found"); 
   lcd.print(finger.fingerID); 
   delay(2000);
   permission=4;
  break; 
}
}
while(permission == 4){
  lcd.setCursor(0,0);
  lcd.print("select ur party***");
  a=digitalRead(A0);
  b=digitalRead(A1);
  c=digitalRead(A2);
  d=digitalRead(A3);
  e=digitalRead(A4);
  delay(500);
  if(a==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DMK");
  party=1;
  delay(2000);
 }
 if(b==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ADMK");
  party=2;
  delay(2000);
 }
 if(c==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BJP");
  party=3;
  delay(2000);
 }
 if(d==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AMMK");
  party=4;
  delay(2000);
 }
 if(e==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NOTA");
  party=5;
  delay(2000);
 }
  Serial.println(party); 

 if(party>0){
   sms();
   
  break;
 }
}
}

///////////////////
void sms(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("send sms");
  portTwo.begin(9600);
  portTwo.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  portTwo.println("AT+CMGS=\"+91"+num+"\"\r"); // Replace x with mobile number
  delay(1000); 
  portTwo.println(" you have successfully registered your vote ");
  delay(100);
  portTwo.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("****THANK YOU**** ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("welcome");
  party=0;
  permission =0;
  select=0;
  
}


// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.println("ok");
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  int fng=finger.fingerID;
  Serial.println("fng"+String(fng)); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
if(1){
//  Serial.println("hai");
}
else {
     lcd.clear();
  lcd.setCursor(0,0);
    lcd.print("not valid!!");
    delay(2000);
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("welcome");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("show ur id!!");
  
  }


    //u1
    if(fng==1 && num=="9750840125"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("user 1 verified!!");
    delay(2000);
    select=1;
  }
//u2
  if(fng==2 && num=="7871343591"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("user 2 verified!!");
    delay(2000);
    select=1;

  }
//u3
  if(fng==3 && num=="9442558637"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("user 3 verified!!");
    delay(2000);
    select=1;

  }

//u4
  if(fng==4 && num=="8072319671"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("user 4 verified!!");
    delay(2000);
    select=1;

  }

//u5
  if(fng==5 && num=="9080569883"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("user 5 verified!!");
    delay(2000);
    select=1;

  } 

  
  return finger.fingerID; 
}


