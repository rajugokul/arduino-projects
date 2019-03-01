#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>



//initialize of ph variables

const char* ssid     = "a"; //Wi-Fi SSID
const char* password = "12345678"; //Wi-Fi Password

//const char* host = "192.185.129.109";

char server[] = "www.inplanttrainingchennai.in";
String str;
WiFiClient client;
void setup()
{


  Serial.begin(9600);
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
void loop()
{
    Sending_To_DB();

str="";
if(Serial.available()>0)
{
  char value=Serial.read();
  //Serial.write(data);
  str+=value;
  Serial.println(str);
  Sending_To_DB();
  delay(1000);
  
  }
}



void Sending_To_DB()   //CONNECTING WITH MYSQL
{
  if (client.connect(server, 80)) {
    Serial.println("connected");
    String url = "http://inplanttrainingchennai.in/iot-projects/hospital-iot/hms/get.php?";    
    url += "&s1=";
    url += str;
    url += "&s2=";
    url += str;
    url += "&s3=";
    url += 123456;

    
    // This will send the request to the server
    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");
  } 
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  client.stop();
}

