/*
 * 
 * accelerometer sensor A0
 * heart beat A1
 * rfid module 
 * D3 - scl
 * D4 - sda
 * dht11
 * temp,prss,heart,rfid,step count
 */


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h>
int sensorValue = 0;  // variable to store the value coming from the sensor

#include <Ticker.h>
Ticker tickerOSWatch;
Ticker Rfid;
unsigned long int i;
#define OSWATCH_RESET_TIME 30
// #include <SoftwareSerial.h>
//SoftwareSerial myserial(13,15);
unsigned long int pres,prev;
unsigned long int axis;
unsigned long int analog_x;
unsigned long int count;
unsigned long int steps;
unsigned long int join(unsigned long int,unsigned long int,unsigned long int,unsigned long int);
const char* ssid     = "a"; //Wi-Fi SSID
const char* password = "12345678"; //Wi-Fi Password

//const char* host = "192.185.129.109";

char server[] = "www.1croreads.com";
String buff;
WiFiClient client;
static int pf = 0;
unsigned long int t;
unsigned long int pressure;
unsigned long int mapp;
unsigned long int rfid_data_cloud;

static unsigned long last_loop;

void ICACHE_RAM_ATTR osWatch(void) {
  unsigned long t = millis();
  unsigned long last_run = abs(t - last_loop);
  if (last_run >= (OSWATCH_RESET_TIME * 1000)) {
    // save the hit here to eeprom or to rtc memory if needed
    Serial.println("nan");
    // ESP.restart();  // normal reboot
    //ESP.reset();  // hard reset
  }
  
}

void printdata()
{
  Serial.println("buffoo");
}

//=======================================================================
//                    Power on setup
//=======================================================================



void setup()
{
//  SPI.begin();
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
  last_loop = millis();
  tickerOSWatch.attach_ms(((OSWATCH_RESET_TIME / 3) * 1000), osWatch);

}

//=======================================================================
//                    Main Program Loop
//=======================================================================


void loop()
{
int sensorValue = analogRead(A0);
int mapp = map(sensorValue ,0,1023,60,75);
float voltage = sensorValue * (5.0 / 1023.0);
 if(voltage> 4.2)
  {
    Serial.print("pulse rate:");
    Serial.println(mapp);
  }
Serial.println("ONLINE MONITORING:");
print_value();
//http_data();


  delay(2000);  //GET Data at every 3 seconds

}


void Sending_To_DB()   //CONNECTING WITH MYSQL
{
  if (client.connect(server, 80)) {
    Serial.println("connected");
    String url = "http://1croreads.com/test-gas/get.php?";

    url += "&s1=";
    url += t; // temperature
    url += "&s2=";
    url += pressure; // pressure
    url += "&s3=";
    url += mapp; //heartbeat
    url += "&s4=";
    url += steps; //rfid
     url += "&s5=";
    url += rfid_data_cloud; //walking step count
    url += "&s6=";
    url += mapp;

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




void print_value()
{
  
do
{
Serial.println("*************");
delay(1000);  
}while(Serial.available()==0);

unsigned long int arr[11];
  if(Serial.available()>0)
  {
   unsigned long int a = Serial.read(); // a[0] i read on here so it contains...?

    if(a=='t')
    {
      Serial.println("temperature : ");
      for(i=1;i<5;i++)
    {
      arr[i]=Serial.read();
      delay(300);
    }
    Serial.write(arr[1]);
    delay(100);
    Serial.write(arr[2]);
    delay(100);
    Serial.write(arr[3]);
    delay(100);
    Serial.write(arr[4]);
    delay(100);
    Serial.println("");
    Serial.print("temp");
    unsigned long int a = arr[1]-0x30;
    unsigned long int b = arr[2]-0x30;
    unsigned long int c = arr[3]-0x30;
    unsigned long int d = arr[4]-0x30;
    mapp = join(a,b,c,d);
   delay(500);
    }

    else if(a=='h')
    {
      Serial.println("humidity");
      for(i=1;i<5;i++)
    {
      arr[i]=Serial.read();
      delay(300);
    }
    Serial.write(arr[1]);
    delay(100);
    Serial.write(arr[2]);
    delay(100);
    Serial.write(arr[3]);
    delay(100);
    Serial.write(arr[4]);
    delay(100);
    Serial.println("");
    Serial.print("TEMPERATURE DATA UPLOADING TO CLOUD.... ");
    unsigned long int a = arr[1]-0x30;
    unsigned long int b = arr[2]-0x30;
    unsigned long int c = arr[3]-0x30;
    unsigned long int d = arr[4]-0x30;
    t = join(a,b,c,d);
    delay(500);
    }


    else if(a=='g')
    {
      Serial.println("gas value");
      for(i=1;i<5;i++)
    {
      arr[i]=Serial.read();
      delay(300);
    }
    Serial.write(arr[1]);
    delay(100);
    Serial.write(arr[2]);
    delay(100);
    Serial.write(arr[3]);
    delay(100);
    Serial.write(arr[4]);
    delay(100);
    Serial.println("");
    Serial.print("gas");
    unsigned long int a = arr[1]-0x30;
    unsigned long int b = arr[2]-0x30;
    unsigned long int c = arr[3]-0x30;
    unsigned long int d = arr[4]-0x30;
    pressure = join(a,b,c,d);
    delay(500);
    }

else if(a=='w')
    {
      Serial.println("Wit");
      for(i=1;i<5;i++)
    {
      arr[i]=Serial.read();
      delay(300);
    }
    Serial.write(arr[1]);
    delay(100);
    Serial.write(arr[2]);
    delay(100);
    Serial.write(arr[3]);
    delay(100);
    Serial.write(arr[4]);
    delay(100);
    Serial.println("");
    Serial.print("weight");
    unsigned long int a = arr[1]-0x30;
    unsigned long int b = arr[2]-0x30;
    unsigned long int c = arr[3]-0x30;
    unsigned long int d = arr[4]-0x30;
    steps = join(a,b,c,d);
    delay(500);
    }
    

 else if(a=='*')
    {
      Serial.println("RED");
      rfid_data_cloud =1;
      
    }

    else if(a=='#')
    {
      Serial.println("Blue");
      rfid_data_cloud =2;
      
    }


    else if(a=='$')
    {
      Serial.println("green");
      rfid_data_cloud =3;
      
    }

  Sending_To_DB(); 
  
}
 
}

unsigned long int join(unsigned long int seven,unsigned long int eight ,unsigned long int nine,unsigned long int ten)
{
unsigned  long int value ;
 value = (seven*1000)+(eight*100)+(nine*10)+(ten*1);
 return(value);
 }
