#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#include <SoftwareSerial.h>
SoftwareSerial myGsm(10,11);
String value = "data in arduino";
void setup()
{
myGsm.begin(9600);  
Serial.begin(9600);  
delay(500);
lcd.begin(16, 2);
lcd.print("hello, world!");

}
void loop(){
             Serial.println(value);
             check();
             lcd.setCursor(0, 0);
             lcd.print("link hittted");
             myGsm.println("AT+HTTPPARA=\"URL\",\"http://114.29.237.25:8002/my_test/vj.php?name=vijaygokul&address=\""+value);
             delay(1000);
             check_1();
}
            

void check(){
             lcd.setCursor(0, 1);
             lcd.print("conn est....");
             myGsm.println();
             myGsm.println("AT");
             myGsm.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR,connection type is GPRS
             myGsm.println("AT+SAPBR=3,1,\"APN\",\"WWW\"");//setting the APN,2nd parameter empty works for all networks
             myGsm.println("AT+SAPBR=1,1");
             myGsm.println("AT+SAPBR=2,1");
             delay(1000);
             myGsm.println("AT+HTTPINIT"); //init the HTTP request
             myGsm.println("AT+HTTPPARA=\"CID\",1");
}
void check_1(){
             lcd.setCursor(0, 1);
             lcd.print("conn close....");
             myGsm.println();
             myGsm.println("AT+HTTPACTION=0");//submit the GET request
             delay(5000);//the delay is important if the return datas are very large, the time required longer.
             myGsm.println("AT+HTTPREAD=0,20");// read the data from the website you access
             delay(3000);
             myGsm.println("");
             delay(1000);
             myGsm.println("AT+HTTPTERM");// terminate HTTP service
             delay(1000); 
}
