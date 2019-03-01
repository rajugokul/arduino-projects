/*
 * 
 * Aim: 
 *   To control the vehicle motion using bluetooth1 (hc-05).
 *   
 *   while reaching at speed breaker  the speed should low even we  
 *   give accelerate from the bluetooth
 *   
 *   The speed of the vehicle should be controlled from  another 
 *   bluetooth module (control).
 *   
 * 
 * 
 * A0 ---- ir sensor 
 * 
int m1a = 4;    // motor1 a
int m1b = 5;
int m2a = 6;
int m2b = 7;
int m3a = 8;
int m3b = 9;
int m4a = 10;
int m4b = 11;    // motor4 b


bluetooth1(hc -05) ----> 0 pin of arduino

bluetooth 2(control) ----> 3 pin of arduino 



components :
1 arduino uno
2 bluetooth
2 12v dc motor , motor driver 1 , dummy wheel 2 , chaisel , ir receiver module  1
ir led 5

 * 
 */

# include <SoftwareSerial.h>
SoftwareSerial rxer(2,3);

int count;
int m1a = 4;
int m1b = 5;
int m2a = 6;
int m2b = 7;


int m3a = 8;
int m3b = 9;
int m4a = 10;
int m4b = 11;



char val;
int i;
int a,b,c;
byte speed_char;
int delay_char;
void setup() 
{
Serial.begin(9600);
rxer.begin(9600);
pinMode(A0,INPUT);
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin

pinMode(m3a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m3b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m4a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m4b, OUTPUT);  // Digital pin 13 set as output Pin
}
long duration, distance;
void loop()
{
a=analogRead(A0);
float volt = a*(5.0/1023.0);
//Serial.print("VOLTAGE :");
//Serial.println(volt);
 
 if(rxer.available() > 0)
  {
  speed_char = rxer.read();
  Serial.println("YOUR SPEED IS NOW CONTROLLED... ");
 // Serial.write(speed_char);
  //Serial.println("");
  delay(100);
  
 if(speed_char =='A')
 {
  Serial.println(" 10 % SPEED REDUCED..");
  
  //delay(2000);
  delay_char = 70;
 }
 else if(speed_char =='B')
 {
  Serial.println(" 20 % SPEED REDUCED..");
  delay_char = 40;
 }

 else if(speed_char =='C')
 {
  Serial.println(" 30 % SPEED REDUCED..");
  delay_char = 20;
 }

 else if(speed_char =='D')
 {
  Serial.println(" 40 % SPEED REDUCED..");
  delay_char = 10;
 }

//delay(500);
 
 }
 
  if(Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  
  if(volt<1 && val == 'F')
  {
    Serial.println(" CALLING LOW SPEED FUNCTION..");
    pwmvalue();
     
     delay(1000);
    
  }
  
 
  if( val == 'F'  && volt > 3) // Forward
    {
      Serial.println("MOVING FORWARD..");
    //  delay(500);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW); 
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW); 
      
    }
  else if(val == 'B' && volt > 3) // Backward
    {
      Serial.println("MOVING BACKWARD..");
      // delay(1000);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);

      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }
  
    else if(val == 'R' &&  volt > 3) //RIGHT
    {
     Serial.println("MOVING LEFTWARD..");
    //delay(1000);
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);

    digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW);
    }
    else if(val == 'L' &&   volt > 3) //LEFT
    {
      Serial.println("MOVING RIGHTWARD..");
    //delay(1000);
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 

    digitalWrite(m3a, HIGH);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, HIGH);
    digitalWrite(m4b, LOW); 
    
    }
    
  else if(val == 'S') //Stop
    {
     // Serial.println("STOP VEHICLE..");
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 

 digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW); 


    
    }
    
}

}

void pwmvalue()
{
  
for(i=0;i<7;i++)
{
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 


    digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW); 


    
    delay(delay_char);


    
    digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);

       digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
      delay(100);//5000 = 5000/100 = 50
      count++; 
       delay(delay_char);
}
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 

      digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW); 
 Serial.end();
    Serial.begin(9600);

}

// 
