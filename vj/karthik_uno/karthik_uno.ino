void split(unsigned long int);
#include <HX711.h>
const int SCALE_DOUT_PIN = 4;
const int SCALE_SCK_PIN = 3;
#define calibration_factor -13107.0
HX711 scale(SCALE_DOUT_PIN, SCALE_SCK_PIN);

//color sensor 
const int s0 = 5;  
const int s1 = 6;  
const int s2 = 7;  
const int s3 = 8;  
const int out =9;   
 
unsigned long int red = 0;  
unsigned long int green = 0;  
unsigned long int blue = 0; 



//DHT SENSOR INITIALIZATION
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
unsigned long int temp, humid;
DHT dht(DHTPIN, DHTTYPE);

unsigned long int gasValue;
unsigned long int bufftemp = 0, buffhum = 0,wit =0;
#define gas A0

//const char* host = "192.185.129.109";

char server[] = "www.1croreads.com";
String buff;
//WiFiClient client;
String  pump =""; // pump received from Android device


void setup()
{
//weight data
  scale.set_scale(calibration_factor);// <- set here calibration factor!!!
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
 
  Serial.begin(9600);
//  WiFi.mode(WIFI_OFF);                    //Prevents reconnection issue (taking too long to connect)
//  delay(1000);
//  WiFi.mode(WIFI_STA);                      //This line hides the viewing of ESP as wifi hotspot
//  WiFi.begin(ssid, password);               //Connect to your WiFi router
//  Serial.println("");
//  Serial.print("Connecting");
//  // Wait for connection
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    delay(500);
//    Serial.print(".");
//  }

  //If connection successful show IP address in serial monitor
//  Serial.println("");
//  Serial.print("Connected to ");
//  Serial.println(ssid);
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}


void loop()
{
  print_value();
  gas_sensor();
  weight();
  color();
  Serial.println();
  Serial.print('r');  
  split(red);  
  Serial.print('g');  
  split(green);  
  Serial.print('b');  
  split(blue);  
 
 
  if (red < blue && red < green && red < 20)
  {  
   Serial.print('*');  
 
  }  
 
  else if (blue < red && blue < green)   
  {  
   Serial.print('#');  
 
  }  
 
  else if (green < red && green < blue)  
  {  
   Serial.print('$');  
 
  }  
  else{
  
  }
  delay(300);   
 
  
 
} 


//void Sending_To_DB()   //CONNECTING WITH MYSQL
//{
//  if (client.connect(server, 80)) {
//    Serial.println("connected");
//    String url = "http://1croreads.com/test-gas/get.php?";
//    
//    url += "&s1=";
//    url += temp;
//    url += "&s2=";
//    url += humid;
//    url += "&s3=";
//    url += gasValue;
//    url += "s4=";
//    url += wit;
//    //Serial.println(level);
//    //url += rfid;
//    // This will send the request to the server
//    Serial.print("Requesting URL: ");
//    Serial.println(url);
//    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//                 "Host: " + server + "\r\n" +
//                 "Connection: close\r\n\r\n");
//  } 
//  else {
//    // if you didn't get a connection to the server:
//    Serial.println("connection failed");
//  }
//  client.stop();
//}



//FUNCTION OF SENSOR

void print_value()
{
  //float temp, humid;
  temp = dht.readTemperature();
  humid = dht.readHumidity();
  Serial.print('t');
  split(temp);
  Serial.print('h');
  split(humid);
  delay(1000);
//  Sending_To_DB();
}
void gas_sensor()
{
      //int gasValue;
      gasValue=analogRead(gas);
      Serial.print('g');
      split(gasValue);
      delay(500);
//      Sending_To_DB();
  }

  void weight(){
      float wit = scale.get_units()*100;
       Serial.print('w');
       split(wit);
      delay(500);
//      Sending_To_DB();

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



void split(unsigned long int x)
{
unsigned long int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10;
unsigned long int remainder;
unsigned long int num;
unsigned long int joined_value;
  
  num = x;
  

    
    d4 = num%10;   //  reminder = 4
    num = num/10;         // num = 123
  
d3 = num%10;   //  reminder = 3
    num = num/10;         // num = 12
  
d2 = num%10;   //  reminder = 2
    num = num/10;         // num = 1
  
d1 = num%10;   //  reminder = 1
    num = num/10;         // num = 0




Serial.write(d1+0x30);
Serial.write(d2+0x30);
Serial.write(d3+0x30);
Serial.write(d4+0x30);

Serial.println("");

delay(300);

}
