#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
const char* ssid     = "a"; //Wi-Fi SSID
const char* password = "12345678"; //Wi-Fi Password
char server[] = "www.inplanttrainingchennai.in";
WiFiClient client;

#include <Servo.h> 
Servo myservo;   
int a,count;

void setup() {
  myservo.attach(D6);
  Serial.begin(9600);
  pinMode(D7,INPUT);
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

void loop() {
  a=digitalRead(D7);
  Serial.println(a);
  http_data();
  if(a==0){
    count++;
    delay(1000);
    Sending_To_DB();
  }
  }

//sending data from db

void Sending_To_DB()   //CONNECTING WITH MYSQL
{
  if (client.connect(server, 80)) {
    Serial.println("connected");
    String url = "http://inplanttrainingchennai.in/iot-projects/coin-count/get.php?";
    url += "&s1=";
    url += count; // temperatur
    
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


  if (!payload.compareTo("{\"light\": \"off\"}"))      // "light1-" ,off
  {
    Serial.println("off");
    Serial.println("LED IS ONN NOW ");
    myservo.write(0);
    
  }
  if (!payload.compareTo("{\"light\": \"on\"}"))
  {

 Serial.println("onn");
   // waits for the servo to get there    
  myservo.write(180);   // sets the servo at 180 degree position    
    Serial.println("LED  IS OFF NOW ");
  }
  http.end();  //Close connection
}
