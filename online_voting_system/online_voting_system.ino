#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int a,b,c,d,e;
int permission=0;
String rf_data ="";
const int RX1 = 8;
const int TX1 = 9;
const int RX2 = 10;
const int TX2 = 11;
SoftwareSerial SoftSerialOne(RX1,TX1);
SoftwareSerial mySerial(RX2,TX2);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
void setup() {
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(A4,INPUT_PULLUP);
  pinMode(RX1, INPUT);
  pinMode(RX2, INPUT);
  pinMode(TX1, OUTPUT);
  pinMode(TX2, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("welcome");
  finger.begin(57600);
  delay(5000);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { 
      delay(1); 
      }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");

}

void loop(void) {
  getFingerprintIDez();
  a=digitalRead(A0);
  b=digitalRead(A1);
  c=digitalRead(A2);
  d=digitalRead(A3);
  e=digitalRead(A4);
  
  if(permission==0){
      lcd.setCursor(0,0);
      lcd.print("show ur id!!");
      SoftSerialOne.begin(9600);
  
  if(SoftSerialOne.available()>0){
      lcd.setCursor(0,1);
//      lcd.print(SoftSerialOne.readString());
      rf_data=SoftSerialOne.readString();
      lcd.print(rf_data);
      Serial.println(rf_data);
  }
  }
  //usr 1...........
  
  if(rf_data=="5500B4469433"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("user 1");
      permission=1;
  rf_data="";
  SoftSerialOne.end();
}

//usr 2................
if(rf_data=="5500785D5020"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("usr 2");
      permission=1;
  rf_data="";
  SoftSerialOne.end();
}

//usr 3.................
if(rf_data=="5500B44D64C8"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("usr 3");
      permission=1;
  rf_data="";
  SoftSerialOne.end();
}

//usr 4.............
if(rf_data=="5500B3C5587B"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("usr 4");
      permission=1;
  rf_data="";
  SoftSerialOne.end();
}

//usr 5.................
if(rf_data=="0000A6A9949B"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("usr 5");
      permission=1;
  rf_data="";
  SoftSerialOne.end();
}
if(permission==1){
//  SoftSerialTwo.begin(9600);
 getFingerprintIDez();
// SoftSerialTwo.end();
     
}
}
uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
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
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
  
}

