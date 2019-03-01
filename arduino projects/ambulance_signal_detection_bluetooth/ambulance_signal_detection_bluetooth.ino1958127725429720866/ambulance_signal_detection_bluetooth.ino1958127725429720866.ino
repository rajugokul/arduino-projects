int motor1Pin1 = 4; // pin 2 on L293D IC
int motor1Pin2 = 5; // pin 7 on L293D IC
int motor2Pin1 = 6; // pin 1 on L293D IC
int motor2Pin2 = 7; // pin 10 on L293D IC
int motor3Pin1 = 8; // pin 15 on L293D IC
int motor3Pin2 = 9; // pin 9 on L293D IC
int motor4Pin1 = 10; // pin 2 on L293D IC
int motor4Pin2 = 11; // pin 7 on L293D IC
char a;
void setup() {
   pinMode(motor1Pin1, OUTPUT),pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT),pinMode(motor2Pin2, OUTPUT);
    pinMode(motor3Pin1, OUTPUT),pinMode(motor3Pin2, OUTPUT);
    pinMode(motor4Pin1, OUTPUT),pinMode(motor4Pin2, OUTPUT);
    Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
   Serial.println("hai");
   if(Serial.available()>0){
    a=Serial.read();
    Serial.println(a);
    if(a=='F'){
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      
      digitalWrite(motor3Pin1, HIGH); 
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);
      
    }
      
       if(a=='B'){
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);
       }
       
    if(a=='L'){//down ....................
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);
 
    }
     if(a=='R'){//up ....................
    digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      
      digitalWrite(motor3Pin1, HIGH); 
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, LOW);
      
 
    }
    if(a=='S'){
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
    }
   }
}
