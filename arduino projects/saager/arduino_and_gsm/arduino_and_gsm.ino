#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

void setup()

{
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module 

  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)

  delay(100); 
}

void loop()
{
int sensorVal = digitalRead(5);
if (sensorVal == HIGH) {
    digitalWrite(6, HIGH);
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode

  delay(1000);  // Delay of 1000 milli seconds or 1 second

  mySerial.println("AT+CMGS=\"+917348991976\"\r"); // Replace x with mobile number

  delay(1000);

  mySerial.println("heart beat Level is > 100 \n");// The SMS text you want to send
  delay( 100);

  mySerial.println((char)26);// ASCII code of CTRL+Z

  delay(1000);
  } else {
    digitalWrite(6, LOW);
  }
}



