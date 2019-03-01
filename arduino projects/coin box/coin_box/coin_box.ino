#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>
const int rs = D0, en = D1, d4 = D2, d5 = D3, d6 = D4, d7 = D5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int a,b,c;
int total=0,one=0,two=0,three=0;
int onn=0,to=0,th=0;

const char *ssid =  "c";     // replace with your wifi ssid and wpa2 key
const char *pass =  "12345678";
const char* server = "www.inplanttrainingchennai.in";
WiFiClient client;
void setup() {
Serial.begin(9600); 
pinMode(D6,INPUT_PULLUP);
pinMode(D7,INPUT_PULLUP);
pinMode(D8,INPUT_PULLUP);
    lcd.begin(16,2);
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
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("connected");
    delay(3000);
    Serial.println("WiFi connected");
    }

void loop() {
 a=digitalRead(D6);
 b=digitalRead(D7);
 c=digitalRead(D8);
 if(a==LOW){
  one=one+1;
  onn++;
  delay(50);
 }
 if(b==LOW){
  two=two+2;
  to++;
  delay(50);
 }
 if(c==LOW){
  three=three+10;
  th++;
  delay(50);
 }
 lcd.setCursor(0,0);
 lcd.print("one=");
 lcd.print(onn);
 lcd.print("two=");
 lcd.print(to);
 lcd.print("ten=");
 lcd.print(th); 
total=one+two+three;
lcd.setCursor(0,1);
lcd.print("total=");
lcd.print(total);
database();
}

void database(){
 if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
          {  
          Serial.println("server connected succesfully");
          String link = "http://inplanttrainingchennai.in/iot-projects/sa-sathya-priya/get.php?";
          link = link + "&s1=";
          link = link + onn;
          link = link + "&s2=";
          link = link + to;
          link = link + "&s3=";
          link = link + th;
          link = link + "&s4=";
          link = link + total;
          
          Serial.print("Requesting URL: ");
          Serial.println(link);
          client.print(String("GET ") + link + " HTTP/1.1\r\n" +"Host: " + server + "\r\n" +"Connection: close\r\n\r\n");
          }
          client.stop();
          Serial.println("Waiting...");
          delay(2000);
}
