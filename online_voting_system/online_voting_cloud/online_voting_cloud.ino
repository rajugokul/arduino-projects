#include <SoftwareSerial.h>

// define the digital pins to use as RX and TX for two
// software serial connections
const int RX1 = 8;
const int TX1 = 9;
const int RX2 = 10;
const int TX2 = 11;

// create SoftwareSerial objects
SoftwareSerial SoftSerialOne(RX1,TX1);
SoftwareSerial SoftSerialTwo(RX2,TX2);

void setup(void) {
// setup the software serial pins
pinMode(RX1, INPUT);
pinMode(RX2, INPUT);
pinMode(TX1, OUTPUT);
pinMode(TX2, OUTPUT);
Serial.begin(9600);
}

void loop(void) {
SoftSerialOne.begin(9600); // begin communication on the first 
// software serial channel
SoftSerialOne.print("Hello World1"); // send something
SoftSerialOne.end(); // end communication on the first software
// serial channel
SoftSerialTwo.begin(9600); // begin communication on the second 
// software serial channel
SoftSerialTwo.write("Hello World2"); // send something
SoftSerialTwo.end(); // end communication on the second software
// serial channel
}
