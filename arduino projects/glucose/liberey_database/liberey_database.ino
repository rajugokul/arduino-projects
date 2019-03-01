#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(D0, D1); // RX, TX
const char* ssid     = "a"; //Wi-Fi SSID
const char* password = "12345678"; //Wi-Fi Password

//const char* host = "192.185.129.109";

char server[] = "www.inplanttrainingchennai.in";
WiFiClient client;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
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
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP

}
void loop(){
   http_data();
}
void http_data()
{
  HTTPClient http;    //Declare object of class HTTPClient

  String  Link;

  Link = "http://inplanttrainingchennai.in/iot-projects/library/light2.json"; // http://inplanttrainingchennai.in/demosites/sowmi/module1/test.txt (avasara..)

  http.begin(Link);     //Specify request destination

  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.print("checking...");
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload); 
  mySerial.println(payload);//Print request response payload
  http.end();  //Close connection
}
