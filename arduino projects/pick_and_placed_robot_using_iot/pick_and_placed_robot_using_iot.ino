int motor1Pin1 = 4; // pin 2 on L293D IC
int motor1Pin2 = 5; // pin 7 on L293D IC
int motor2Pin1 = 6; // pin 1 on L293D IC
int motor2Pin2 = 7; // pin 10 on L293D IC
int motor3Pin1 = 8; // pin 15 on L293D IC
int motor3Pin2 = 9; // pin 9 on L293D IC
int motor4Pin1 = 10; // pin 2 on L293D IC
int motor4Pin2 = 11; // pin 7 on L293D IC
char data;

void setup() {
    pinMode(motor1Pin1, OUTPUT),pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT),pinMode(motor2Pin2, OUTPUT);
    pinMode(motor3Pin1, OUTPUT),pinMode(motor3Pin2, OUTPUT);
    pinMode(motor4Pin1, OUTPUT),pinMode(motor4Pin2, OUTPUT);
    Serial.begin(9600);
}
void loop() {
  
    if(Serial.available() > 0){     
      data = Serial.read(); 
      Serial.print(data);  
    }  
    
    if (data == 'F'){
      Forward();
     Serial.println("Go Forward");
    }
    
    else if (data == 'B'){
      Reverse();
      Serial.println("Go back");
      
    }
    
    else if (data == 'L'){
      Left();
     Serial.println("Go Left");
    }
    
    else if (data == 'R'){
      Right();
      Serial.println("Go Right");
    }
    
    else if (data == 'S'){
      Stop();
     Serial.println("STOP!");
    }
    
   
    else if (data == 'r'){
      Pick();
     Serial.println("Pick");
    }
    
    else if (data == 'p'){
      Place();
      Serial.println("Place");
    }
    
    else if (data == 'd'){
      Hold();
     Serial.println("Down");
    }
    
    else if (data == 'u'){
      Free();
      Serial.println("UP");
    }
    
}void Forward(){
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(2000);
}void Reverse(){
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(2000);
}void Left(){
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(2000);
}void Right(){
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(2000);
}void Pick(){
    digitalWrite(motor3Pin1, LOW); 
    digitalWrite(motor3Pin2, HIGH);
    digitalWrite(motor1Pin1, LOW); 
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor4Pin1, LOW);
    digitalWrite(motor4Pin2, LOW);
}
void Place(){
  digitalWrite(motor3Pin1, HIGH); 
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
}void Hold(){
  digitalWrite(motor4Pin1, LOW); 
  digitalWrite(motor4Pin2, HIGH);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
}void Free(){
  digitalWrite(motor4Pin1, HIGH); 
  digitalWrite(motor4Pin2, LOW);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
}void Stop(){    // Stop the motors

  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW); 
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
}
