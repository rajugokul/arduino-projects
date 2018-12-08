#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>

//weight sensor
#include <HX711.h>
const int SCALE_DOUT_PIN = D4;
const int SCALE_SCK_PIN = D3;
#define calibration_factor -13107.0
HX711 scale(SCALE_DOUT_PIN, SCALE_SCK_PIN);

//color sensor 
const int s0 = D5;  
const int s1 = D6;  
const int s2 = D7;  
const int s3 = D8;  
const int out = D1;   
 
int red = 0;  
int green = 0;  
int blue = 0; 



//DHT SENSOR INITIALIZATION
#include "DHT.h"
#define DHTPIN D2
#define DHTTYPE DHT11
float temp, humid;
DHT dht(DHTPIN, DHTTYPE, 11);

int gasValue;
float bufftemp = 0, buffhum = 0,wit =0;
#define gas A0

const char* ssid     = "DLK TECHNOLOGIES"; //Wi-Fi SSID
const char* password = "!@12345DLK"; //Wi-Fi Password

//const char* host = "192.185.129.109";

char server[] = "www.1croreads.com";
String buff;
WiFiClient client;
String  pump =""; // pump received from Android device


void setup()
{
//weight data
// scale.set_scale(calibration_factor);// <- set here calibration factor!!!
  scale.tare();

  //color sensor
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
 
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);
  
  //other data
  pinMode(gas, INPUT);
 
  Serial.begin(115200);
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
  print_value();
  gas_sensor();
  weight();
  color();
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
 
 
  if (red < blue && red < green && red < 20)
  {  
   Serial.println(" - (Red Color)");  
 
  }  
 
  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)");  
 
  }  
 
  else if (green < red && green < blue)  
  {  
   Serial.println(" - (Green Color)");  
 
  }  
  else{
  Serial.println();  
  }
  delay(300);   
 
  
 
} 


void Sending_To_DB()   //CONNECTING WITH MYSQL
{
  if (client.connect(server, 80)) {
    Serial.println("connected");
    String url = "http://1croreads.com/test-gas/get.php?";
    
    url += "&s1=";
    url += temp;
    url += "&s2=";
    url += humid;
    url += "&s3=";
    url += gasValue;
    url += "s4=";
    url += wit;
    //Serial.println(level);
    //url += rfid;
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



//FUNCTION OF SENSOR

void print_value()
{
  //float temp, humid;
  temp = dht.readTemperature();
  humid = dht.readHumidity();
  if (String(temp) == "nan" && String(humid) == "nan")
  {
    temp = bufftemp;
    humid = buffhum;
    Serial.print("buff");
  }
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println();
  Serial.print("Humidity: ");
  Serial.print(humid);
  Serial.println();
  delay(1000);
  Sending_To_DB();
}
void gas_sensor()
{
      //int gasValue;
      gasValue=analogRead(gas);
      Serial.print("gas value: ");
      Serial.print(gasValue);
      Serial.println();
      delay(500);
      Sending_To_DB();
  }

  void weight(){
//      float wit = scale.get_units()*100;
       Serial.print("grm:");
//      Serial.print(wit);
      Serial.println();
      delay(500);
      Sending_To_DB();

  }

void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
