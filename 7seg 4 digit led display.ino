#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
int a,b=0;
int flag=0, flag1=0,deciSeconds;
void setup() {
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,OUTPUT);
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);
}

void loop() {
  a=digitalRead(A0);
  b=digitalRead(A1);
//  Serial.println(b);
  static unsigned long timer = millis();
//  static int deciSeconds = 0;
//  Serial.println(a);
  if (millis() - timer >= 100) {
    timer += 100;

   if(b==0&&flag1==0){
    deciSeconds=400;
       flag1=1;
   }
    if(flag1 == 1){
          deciSeconds--;
          if(deciSeconds<30){
            digitalWrite(A2,HIGH);
          }
          else{
            digitalWrite(A2,LOW);
          }
          if(deciSeconds==0){
            flag1=0;
          }
    Serial.println(deciSeconds);
    sevseg.setNumber(deciSeconds, 1);
    }


    
    if(a==0&&flag==0){
       deciSeconds=600;
       flag=1;
    
       } 
       if(flag == 1){
          deciSeconds--;
           if(deciSeconds<30){
            digitalWrite(A2,HIGH);
          }
          else{
            digitalWrite(A2,LOW);
          }
          if(deciSeconds==0){
            flag=0;
          }
         
    Serial.println(deciSeconds);
    sevseg.setNumber(deciSeconds, 1);
       }
//Serial.println(deciSeconds);
    
//    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
//      deciSeconds=0;
//    }
    
  }
  sevseg.refreshDisplay(); // Must run repeatedly

}


/// END ///
