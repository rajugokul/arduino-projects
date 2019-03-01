#include <SoftwareSerial.h>  //Including the software serial library
SoftwareSerial esp8266(10,11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   
  esp8266.begin(9600); 
  
  esp8266.println("AT+RST\r\n");            //This command will reset module to default
   esp8266.println("AT+CWMODE=2\r\n");       // This will configure the mode as access point
   esp8266.println("AT+CIFSR\r\n");          // This will get ip address and will show it
   esp8266.println("AT+CIPMUX=1\r\n");       // This will configure the ESP8266 for multiple connections
   esp8266.println("AT+CIPSERVER=1,80\r\n"); // This will set the server on port 80
}
}

void loop() {
  // put your main code here, to run repeatedly:
if(esp8266.available()) // Checking that whether the esp8266 is sending a message or not (Software UART Data)
  {
    if(esp8266.find("ON"))
    { 
      digitalWrite(13,HIGH);
      delay(1000); 
}
}
}
