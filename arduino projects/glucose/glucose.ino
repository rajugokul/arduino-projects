#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include "DHT.h"            // dht library for humidity data reading

#define DHTPIN D6     // what digital pin we're connected to

#define DHTTYPE DHT11   // DHT 11  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);  //
 
int data=0;
int mapp;
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
      lcd.setCursor(0, 0);
      lcd.print("connecting....");
      delay(10); 
      Serial.println("Connecting to ");
      Serial.println(ssid);
      WiFi.begin(ssid, pass); 
      while (WiFi.status() != WL_CONNECTED) 
      {
      delay(500);
      Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi connected");
      }

void loop() {
//  database(); 
  float h = dht.readHumidity(); // CALLING DHT LIBRARY FUNCTION FOR READING HUMIDITY
  
  float t = dht.readTemperature();   
  lcd.clear();
  lcd.setCursor(0,1);
  
  lcd.println("TEMP: "+String(t)); // PRINT TEMP AVLUE
  
  
}
//void sms(){
//  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
//  delay(1000);  // Delay of 1000 milli seconds or 1 second
//  Serial.println("AT+CMGS=\"+919788391337\"\r"); // Replace x with mobile number
//  delay(1000);
//  Serial.println("blood glucose leve="+String(mapp));
//  delay(1000);
//  Serial.println((char)26);// ASCII code of CTRL+Z
//  delay(1000);
//}

void database(){
 if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
          {  
          Serial.println("server connected succesfully");
          String link = "http://inplanttrainingchennai.in/iot-projects/glucose/get.php?";
          link = link + "&s1=";
          link = link + String(mapp); 
          Serial.print("Requesting URL: ");
          Serial.println(link);
          client.print(String("GET ") + link + " HTTP/1.1\r\n" +"Host: " + server + "\r\n" +"Connection: close\r\n\r\n");
          }
          client.stop();
          mapp=0;
          Serial.println("Waiting...");
          delay(5000);
}
