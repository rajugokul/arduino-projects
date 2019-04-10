#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
const char* ssid     = "a"; //Wi-Fi SSID
const char* password = "12345678"; //Wi-Fi Password
char server[] = "www.inplanttrainingchennai.in";
WiFiClient client; 
int a,count;

void setup() {
  myservo.attach(D6);
  Serial.begin(9600);
  pinMode(D1,INPUT_PULLUP);
  pinMode(D2,INPUT_PULLUP);
  pinMode(D3,INPUT_PULLUP);
  pinMode(D4,INPUT_PULLUP);
  WiFi.mode(WIFI_OFF);                   
  delay(1000);
  WiFi.mode(WIFI_STA);                      
  WiFi.begin(ssid, password);       
  Serial.println("");
  Serial.print("Connecting");
// Wait for connection
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

void loop() {
  
  }

//sending data from db

void Sending_To_DB()   //CONNECTING WITH MYSQL
{
  if (client.connect(server, 80)) {
    Serial.println("connected");
    String url = "http://inplanttrainingchennai.in/iot-projects/coin-count/get.php?";
    url += "&s1=";
    url += payload; // qus
    url += "&s2=";
    url += count; // ans
    
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





//receiving data from db
void http_data()
{
  HTTPClient http;    //Declare object of class HTTPClient

  String  Link;

  Link = "http://inplanttrainingchennai.in/iot-projects/coin-count/light.json"; // http://inplanttrainingchennai.in/demosites/sowmi/module1/test.txt (avasara..)

  http.begin(Link);     //Specify request destination

  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.print("checking...");
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload


 if(payload>=1){
    ans();
 }
  http.end();  //Close connection
}



void ans(){
    a=digitalRead(D1);
    b=digitalRead(D2);
    c=digitalRead(D3);
    d=digitalRead(D4);
    Serial.println(a+b+c+d)
  if(a==0){
    count=1;
    Sending_To_DB(); 
  }
   if(b==0){
    count=2; 
    Sending_To_DB();
  }
   if(c==0){
    count=3; 
    Sending_To_DB();
  }
   if(d==0){
    count=4; 
    Sending_To_DB();
  }
  }
