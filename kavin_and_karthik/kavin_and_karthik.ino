//database connectivity
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
const char* ssid     = "a"; //Wi-Fi SSID
const char* password = "12345678"; //Wi-Fi Password
char server[] = "www.inplanttrainingchennai.in";

WiFiClient client;


//fingerprint module
#include <Adafruit_Fingerprint.h>
SoftwareSerial mySerial(D3, D4);//pin D3-RX and pin D4-TX
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

//lcd module
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int a,b,c,d,e;
int count,button,enter;
String drink,cs1,cs2,cs3,cs4,cs5,tcs,un="";
int amt1,amt2,amt3,amt4,amt5,tamt;

void setup()
{
      Serial.begin(9600);
      finger.begin(57600);
      lcd.begin();
      lcd.backlight();
      lcd.setCursor(0,0);
      lcd.print("    welcome     ");
      delay(3000);
      lcd.setCursor(0,0);
      lcd.print("preparing..");
      delay(3000);
      pinMode(D5,INPUT_PULLUP);
      pinMode(D6,INPUT_PULLUP);
      pinMode(D7,INPUT_PULLUP);

              WiFi.mode(WIFI_OFF);                    //Prevents reconnection issue (taking too long to connect)
              delay(1000);
              WiFi.mode(WIFI_STA);                      //This line hides the viewing of ESP as wifi hotspot
              WiFi.begin(ssid, password);               //Connect to your WiFi router
              Serial.println("");
              Serial.print("Connecting");
              // Wait for connection
                        while (WiFi.status() != WL_CONNECTED)
                        {
                        delay(500);
                        Serial.print(".");
                        lcd.setCursor(0,0);
                        lcd.print("Network...!!");
                        lcd.setCursor(0,1);
                        lcd.print("connecting   ):");
                        }
                        
                        //If connection successful show IP address in serial monitor
                        lcd.setCursor(0,1);
                        lcd.print("connected   (:");
                        delay(3000);
                        Serial.println("");
                        Serial.print("Connected to ");
                        Serial.println(ssid);
                        Serial.print("IP address: ");
                        Serial.println(WiFi.localIP());

}
void loop(){
  if(enter==0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Insert ur finger");
      getFingerprintIDez(); 
  }
      while(button==1){
        btn();
        delay(50);
      }
}   

void btn(){
      a=digitalRead(D5);
      b=digitalRead(D6);
      c=digitalRead(D7);
      Serial.println(a);
      Serial.println(b);
      Serial.println(c);
      delay(50);
      if(count==0){
       lcd.clear();
lcd.setCursor(0,0);
lcd.print("select the cases");
lcd.setCursor(0,1);
lcd.print("!!!!!!");
 
        
      }
if(a==0){
  count++;
  delay(1000);
}
if(count==1){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("drink and drive");
lcd.setCursor(0,1);
lcd.print("fine =500");
delay(50);
}
if(count==1 && b==0){  
cs1="drink and drive==500:";
amt1=500;
  lcd.setCursor(10,1);
  lcd.print("-added");
  delay(1000);
}

if(count==2){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("without helmet");
lcd.setCursor(0,1);
lcd.print("fine =200");
delay(50);
}

if(count==2 && b==0){  
cs2="without helmet==200:";
amt2=200;
  lcd.setCursor(10,1);
  lcd.print("-added");
  delay(1000);
}


if(count==3){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Tribles");
lcd.setCursor(0,1);
lcd.print("fine =500");
delay(50);
}

if(count==3 && b==0){  
cs3="Tribles==200:";
amt3=200;
  lcd.setCursor(10,1);
  lcd.print("-added");
  delay(1000);
}

if(count==4){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Without  licence");
lcd.setCursor(0,1);
lcd.print("fine =300");
delay(50);
}

if(count==4 && b==0){  
cs4="Without licence==300:";
amt4=200;
  lcd.setCursor(10,1);
  lcd.print("-added");
  delay(1000);
}

if(count==5){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Insurence exp.");
lcd.setCursor(0,1);
lcd.print("fine =400");
delay(50);
}
if(count==5 && b==0){  
cs5="Insurence exp.==400:";
amt5=400;
  lcd.setCursor(10,1);
  lcd.print("-added");
  delay(1000);
}
if(count==6){
count=1;  
}

////total data...
if(c==0){
  tamt=amt1+amt2+amt3+amt4+amt5;
  tcs=cs1+cs2+cs3+cs4+cs5;
  Serial.println("total  fine amount:"+String(tamt));
  Serial.println("total case:"+tcs);
 sms();
 Sending_To_DB();
 
}

}


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
   match();
  return finger.fingerID; 
}
/////id and name function....................

void match(){
 if(1){
 }
  else{
    lcd.setCursor(0,1);
    lcd.print("did not match");
    button=0;
  }
  if(finger.fingerID==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Vijaygokul");
    delay(3000);
    un="vijaygokul";
    enter,button=1; 
    
  }
  if(finger.fingerID==2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Jeeva");
   Serial.println("Jeeva");
   delay(3000);
    un="Jeeva";
    enter,button=1; 
  }
   if(finger.fingerID==3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("kavin");
   Serial.println("kavin");
   delay(3000);
   un="kavin";
   enter,button=1; 
 }
   if(finger.fingerID==4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("karthik");
   Serial.println("karthik");
   delay(3000);
   un="karthik";
    enter,button=1;  
  }
   if(finger.fingerID==5){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ganesh");
    un="ganesh";
    delay(3000);
   Serial.println("ganesh");
   
    enter,button=1; 
  }
  
}



    
void sms(){
  for(int i=0;i<3;i++){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sending sms..");
    
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(2000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919600404610\"\r"); // Replace x with mobile number
  delay(2000);
//  Serial.println("hai da tha");
  Serial.println("Fine amount details!!!\n"+tcs+"total amount="+String(tamt));
  delay(2000);
  Serial.println("location:::www.google.com.ph/maps/place/11.4371448,77.8804216");
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(2000);
  }
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("sms sended!!!");
}





void Sending_To_DB()   //CONNECTING WITH MYSQL
{
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("sending to DB....");
    delay(3000);
  if (client.connect(server, 80)) {
    Serial.println("connected");
    String url = "http://inplanttrainingchennai.in/iot-projects/online-voting-system/get.php?";
    url += "&s1=";
    url += un; // number of cases....
    url +="&s2=";
    url +=tcs;
    url +="&s4=www.google.com.ph/maps/place/11.4371448,77.8804216";
    url +="&s3=";
    url +=tamt;
    
    // This will send the request to the server
    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  client.stop();
  
  count=0;
    button=0;
    enter=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("process complted");
    delay(3000);
}
