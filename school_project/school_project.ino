 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
int sensorValue = 0;  // variable to store the value coming from the sensor
int count =0;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  sensorValue = digitalRead(A0);
  // turn the ledPin on
  Serial.println(sensorValue);
  delay(100);
 if (mySerial.available()>0)
   Serial.write(mySerial.read());

   if(sensorValue == 0 && count == 0){
    count=1;
    Serial.println("found data");
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919498031723\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("YOU HAVE RECEIVED A LETTER :)");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
else if(sensorValue==1&&count ==1){
      Serial.println("not found data");
count=0;
  
}
}

