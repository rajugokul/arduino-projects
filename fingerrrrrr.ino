#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13);
SoftwareSerial mygsm(10,11);

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int count=0;
int a,b,c,d,e;
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
   mygsm.begin(9600); 
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
  // set the data rate for the sensor serial port
  finger.begin(57600);
  lcd.begin(16, 2);
  lcd.print("put on ur thump");
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) {
    delay(1); 
   }
  }
  Serial.println("Waiting for valid finger...");
}

void loop()                     // run over and over again
{
  getFingerprintIDez();
  delay(50);            //don't ned to run this at full speed.
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
  

  return finger.fingerID;
}
     

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  
  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) 
  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)
  return -1 ;
  
  
  // sample models...........
  
   else if (finger.fingerID==1 && a==0)
  {
    count++;
    a++;
    lcd.setCursor(0, 0);
    lcd.print("  vijay gokul :)   ");
    vote();
    mygsm.println("vijay gokul !!! ur vote will be registered... :)");
    valid();
//    check();
//    mygsm.println("AT+HTTPPARA=\"URL\",\"http://114.29.237.25:8002/my_test/vj.php?name=vijaygokul&address=veppadai,sakthi nagar\"");
//    delay(1000);
//    check_1();
  }

  else if (finger.fingerID==1 && a>=1)
  {
    Serial.println("already exist!!"); 
    lcd.setCursor(0, 0);
    lcd.print("  vijay gokul ):   ");     
    call();
   
   

  }
   else if (finger.fingerID==2 && b==0)
  {
    count++;
    b++;
    lcd.setCursor(0, 0);
    lcd.print("    jeeva :)       ");
    vote();
    mygsm.println("jeeva !!! ur vote will be registered... :)");
    valid();
//    check();
//    mygsm.println("AT+HTTPPARA=\"URL\",\"http://114.29.237.25:8002/my_test/vj.php?name=jeeva&address=munipan kovil,palakkapalayam\"");
//    delay(1000);
//    check_1();
  }

  else if (finger.fingerID==2 && b>=1)
  {
    Serial.println("already exist :)"); 
    lcd.setCursor(0, 0);
    lcd.print("     jeeva ):      ");     
     call();
  }
 else if (finger.fingerID==13 && c==0)
  {
    count++;
    c++;
    lcd.setCursor(0, 0);
    lcd.print("      vicky :)     ");
    vote();
    mygsm.println("vicky !!! ur vote willbe registered... :)");
    valid();
    check();
    mygsm.println("AT+HTTPPARA=\"URL\",\"http://114.29.237.25:8002/my_test/vj.php?name=vicky&address=kumarapalayam,  colony\"");
    delay(1000);
    check_1();
  }
 else if (finger.fingerID==13 && c>=1)
  {
    Serial.println("already exist :)"); 
    lcd.setCursor(0, 0);
    lcd.print("      vicky ):     ");     
     call();
  }

 else if (finger.fingerID==14 && d==0)
  {
    count++;
    d++;
    lcd.setCursor(0, 0);
    lcd.print("      asar :)     ");
    vote();
    mygsm.println("asar !!! ur vote will be registered... :)");
    valid();
     check();
    mygsm.println("AT+HTTPPARA=\"URL\",\"http://114.29.237.25:8002/my_test/vj.php?name=asar&address=tcodu, nagar\"");
    delay(1000);
    check_1();
  }
 else if (finger.fingerID==14 && d>=1)
  {
    Serial.println("already exist :)"); 
    lcd.setCursor(0, 0);
    lcd.print("      asar ):      ");     
    call();
  }

//   else if (finger.fingerID==8 && e==0)
//  {
//    count++;
//    e++;
//    lcd.setCursor(0, 0);
//    lcd.print("    krishnan :)   ");
//    vote();
//    mygsm.println("krishnan !!! ur vote will be registered... :)");
//    valid();
////     check();
////    mygsm.println("AT+HTTPPARA=\"URL\",\"http://114.29.237.25:8002/my_test/vj.php?name=krishnan&address=veppadai,sakthi nagar\"");
////    delay(1000);
////    check_1();
//  }
// else if (finger.fingerID==12 && e>=1)
//  {
//    lcd.setCursor(0, 0);
//    lcd.print("    krishnan ):   ");     
//    call();
//  }



  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence);
  Serial.println("success!!!");
  lcd.setCursor(0, 1);
  lcd.print(count);
  delay(1000);
  return finger.fingerID; 
}

void call()
{
  lcd.setCursor(3, 1);
     lcd.print("alrdy exist!!");
     delay(2000);
     lcd.setCursor(3, 1);
     lcd.print("                   ");
}
 void vote(){
  
  mygsm.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mygsm.println("AT+CMGS=\"+919788391337\"\r");
    delay(1000);  
 }
void valid(){
  delay(100);
    mygsm.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void check(){
             mygsm.println();
             mygsm.println("AT");
             mygsm.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
             mygsm.println("AT+SAPBR=3,1,\"APN\",\"WWW\"");
             mygsm.println("AT+SAPBR=1,1");
             mygsm.println("AT+SAPBR=2,1");
             delay(1000);
             mygsm.println("AT+HTTPINIT");
             mygsm.println("AT+HTTPPARA=\"CID\",1");
}
void check_1(){
             mygsm.println();
             mygsm.println("AT+HTTPACTION=0");
             delay(5000);
             mygsm.println("AT+HTTPREAD=0,20");
             delay(3000);
             mygsm.println("");
             delay(1000);
             mygsm.println("AT+HTTPTERM");
             delay(1000); 
}

