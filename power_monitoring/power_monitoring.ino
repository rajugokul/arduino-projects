#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
const char* ssid     = "a"; //Wi-Fi SSID
const char* password = "12345678"; //Wi-Fi Password
char server[] = "www.inplanttrainingchennai.in";
WiFiClient client;
int a,count,volt;
float amps;
void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(D6,OUTPUT);
  WiFi.mode(WIFI_OFF);                    //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);                      //This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(ssid, password);               //Connect to your WiFi router
  Serial.println("");
  Serial.print("Connecting");
//  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
}
void loop(){
  digitalWrite(D6,HIGH);
//    digitalWrite(D6,LOW);

  a=analogRead(A0);
  delay(1000);
  Serial.println("raw data"+String(a));
  volt=map(a,0,10,1,5);
  amps=map(a,0,10,0.1,1);
  Serial.println("mai"+String(volt));
if(count==0){
  sms();
  delay(1000);
  count++;
}
}
void sms(){
 Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+917550074570\"\r"); // Replace x with mobile number
  delay(1000); 
  Serial.println("current and voltage level!!!");
  Serial.print("volt"+String(volt)+"amps"+String(amps));
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void Sending_To_DB()   //CONNECTING WITH MYSQL
{
  if (client.connect(server, 80)) {
    Serial.println("connected");
    String url = "http://inplanttrainingchennai.in/iot-projects/power-reading2/get.php?";
    url += "&s1=";
    url += volt; // volte
    url += "&s2=";
    url += amps; //current
    
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
}

