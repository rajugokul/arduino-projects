const int trigPin = 2;
const int echoPin = 3;
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
int a;
void setup() 
{
Serial.begin(9600);
pinMode(A0,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
pinMode(m3a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m3b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m4a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m4b, OUTPUT);  // Digital pin 13 set as output Pin
Serial.begin(9600);
}


void loop()
{

while(count<=50)
 {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW);
    delay(100);
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




  
/*  digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW); 
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
      //delay(2000); 
  */
}
}
