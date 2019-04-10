#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include  <TinyGPS++.h>
float latitude,longitude;
TinyGPSPlus gps;
#include "DHT.h"            // dht library for humidity data reading

#define DHTPIN D6     // what digital pin we're connected to

#define DHTTYPE DHT11   // DHT 11  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);  //
 
int data=0;
int mapp;
float t;

const int rs = D0, en = D1, d4 = D2, d5 = D3, d6 = D4, d7 = D5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const char *ssid =  "c";     // replace with your wifi ssid and wpa2 key
const char *pass =  "12345678";
const char* server = "www.inplanttrainingchennai.in";

WiFiClient client;
int  a,b,c,d;

void setup() {
      dht.begin();
      lcd.begin(16,2);
      Serial.begin(9600);
      pinMode(D7,INPUT_PULLUP);
      pinMode(A0,INPUT);
      lcd.setCursor(0, 0);
      lcd.print("connecting....");
//      delay(10); 
//      Serial.println("Connecting to ");
//      Serial.println(ssid);
//      WiFi.begin(ssid, pass); 
//      while (WiFi.status() != WL_CONNECTED) 
//      {
//      delay(500);
//      Serial.print(".");
//      }
//      Serial.println("");
//      Serial.println("WiFi connected");
//      }
}

void loop() {
//  database(); 
a=digitalRead(D7);
b=analogRead(A0);
b = map(b, 0, 1023, 70,85);
Serial.println(b);
if(b<80){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(b);
  
}
//Serial.println(a);
if(a==0){
  sms(); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("EMERGENCY!!!!!");  
}
  float h = dht.readHumidity(); // CALLING DHT LIBRARY FUNCTION FOR READING HUMIDITY
  
  float t = dht.readTemperature();   
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMP: "+String(t)); // PRINT TEMP AVLUE
  lcd.setCursor(0,1);
  lcd.print("HUM : "+String(h));
  delay(500);

while (Serial.available() > 0)
    delay(1);
    if (gps.encode(Serial.read()))
    delay(50);
      displayInfo(); 
}


void sms(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("send sms..");
  Serial.println("AT+CMGF=1");    
  delay(1000); 
  Serial.println("AT+CMGS=\"+919788391337\"\r"); 
  delay(1000); 
  Serial.println("OUR location :");
  Serial.print("www.google.com.ph/maps/place/"); 
  Serial.print(gps.location.lat(), 6);
  Serial.print(",");
  Serial.print(gps.location.lng(), 6);
  delay(100);
  Serial.println((char)26);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("send sms..");
}

void database(){
 if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
          {  
          Serial.println("server connected succesfully");
          String link = "http://inplanttrainingchennai.in/iot-projects/glucose/get.php?";
          link = link + "&s1=";
          link = link + String(b); 
          Serial.print("Requesting URL: ");
          Serial.println(link);
          client.print(String("GET ") + link + " HTTP/1.1\r\n" +"Host: " + server + "\r\n" +"Connection: close\r\n\r\n");
          }
          delay(1);
          client.stop();
          Serial.println("Waiting...");
          delay(5000);
}

void displayInfo()
{

  if (gps.location.isValid())
  {
    delay(1);
     lcd.clear();
     lcd.setCursor(0,0);
    lcd.print("gps data");
    delay(1);
    lcd.print(gps.location.lat(), 6);
//    Serial.print(F(","));
    lcd.setCursor(0,1);
    lcd.print(gps.location.lng(), 6);
    delay(1000);
  }
}
