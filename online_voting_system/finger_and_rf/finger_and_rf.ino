#include <LiquidCrystal.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
SoftwareSerial portTwo(8, 9);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
unsigned long int count;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int id=0;
int tag=0;
int party=0;
int a,b,c,d,e;
int permission=0;
void setup() {
  Serial.begin(9600);
  portTwo.begin(9600);
  finger.begin(57600);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(A4,INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("welcome");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SHOW ur ID..");
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("total temp:"+String(finger.templateCount)); 
  

}

void loop() {
portTwo.listen();
while(portTwo.available()==0);
while(portTwo.available()>0)
{
  String S = portTwo.readString();
  Serial.println(S);
  delay(2000);
  if(S =="5500B4469433")
  {
    tag=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u1");
  }
   
if(S =="5500785D5020")
  {
    tag=2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u2");
  }


if(S =="5500B3C5587B")
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u3");
    tag=3;
  }


if(S =="0000A6A9949B")
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u4");
    tag=4;
  }

if(S =="5500B44D64C8")
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("u5");
    tag=5;
  }
  portTwo.end();
}

Serial.println(finger.fingerID);
Serial.println("");
while(tag==1 ||tag==2 || tag == 3 || tag == 4 || tag == 5 ){
 
while(portTwo.available()==0 && finger.fingerID <= 0)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("auth fninger..");
  delay(100);
mySerial.begin(57600);
getFingerprintIDez();

delay(100);
}
if(finger.fingerID >0){
  id=finger.fingerID;
     lcd.clear();
    lcd.setCursor(0,0);
   lcd.print("Found"); lcd.print(finger.fingerID); 
   permission=4;
  break;
}
}
while(permission == 4){
  a=digitalRead(A0);
  b=digitalRead(A1);
  c=digitalRead(A2);
  d=digitalRead(A3);
  e=digitalRead(A4);
 Serial.println(a+b+c+d+e); 
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
  lcd.println("CONGRASS");
  party=2;
  delay(2000);
 }
 if(c==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TDMK");
  party=3;
  delay(2000);
 }
 if(d==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println("ADMK");
  party=4;
  delay(2000);
 }
 if(e==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PJP");
  party=5;
  delay(2000);
 }
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
  lcd.println("send sms");
  portTwo.begin(9600);
  portTwo.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  portTwo.println("AT+CMGS=\"+919788391337\"\r"); // Replace x with mobile number
  delay(1000); 
  portTwo.println("voting data usr="+String(id)+"finger id="+String(tag)+"party="+party);
  delay(100);
  portTwo.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("****THANK YOU**** ");
}


//////////////////

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}



