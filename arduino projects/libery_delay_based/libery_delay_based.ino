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
   if(Serial.available()>0){
    a=Serial.read();
    Serial.println(a);
    if(a=='o'){
        digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, HIGH);
      
    }
      
       if(a=='c'){
      digitalWrite(motor3Pin1, HIGH); 
      digitalWrite(motor3Pin2, LOW);
       }
       
    if(a=='d'){//down ....................
     digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, HIGH);
 
    }
     if(a=='u'){//up ....................
     digitalWrite(motor4Pin1, HIGH); 
      digitalWrite(motor4Pin2, LOW);
 
    }
    if(a=='s'){
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
        digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
    }
    if(a=='A'){
      ////set the position
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(9000);
      ///top ..
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, HIGH); 
      digitalWrite(motor4Pin2, LOW);
      delay(5000);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      //set position above code
       //forword.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(2000);
       //left......
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(5000);
      //forward...........
       digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(1500);
      //stop....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      ///pick and up
       digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, HIGH);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(4500);
      ///arm down......
      digitalWrite(motor3Pin1, HIGH); 
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      delay(5000);
      ///pick......
      digitalWrite(motor4Pin1, HIGH); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(7000);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      ///revers left.....
       digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, HIGH);
      delay(7000);
      //revers.....
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(1500);
      //stop.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, LOW);
    }



    ////second book
    if(a=='B'){
      ////set the position
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(9000);
  
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, HIGH); 
      digitalWrite(motor4Pin2, LOW);
      delay(5000);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      //set position above code
       //forword.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(4000);
       //left......
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(5000);
      //forward after left.......
       digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(1000);
      //stop....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      ///pick and up
       digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, HIGH);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(6000);
      digitalWrite(motor3Pin1, HIGH); 
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      delay(7000);
      digitalWrite(motor4Pin1, HIGH); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(6000);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      //revers left.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, HIGH);
      delay(7000);
      //revers.....
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(4000);
      //stop.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, LOW);
    }


        ////third book
    if(a=='C'){
      ////set the position
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(9000);
  
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, HIGH); 
      digitalWrite(motor4Pin2, LOW);
      delay(5000);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      //set position above code
      //forword.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(6000);
       //left......
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(5000);
      //forward after left.......
       digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(1000);
      //stop....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      ///pick and up
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, HIGH);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(6000);
      digitalWrite(motor3Pin1, HIGH); 
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      delay(7000);
      digitalWrite(motor4Pin1, HIGH); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      delay(6000);
      digitalWrite(motor4Pin1, LOW); 
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(motor3Pin1, LOW); 
      digitalWrite(motor3Pin2, LOW);
      //revers left.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, HIGH);
      delay(7000);
      //revers.....
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(5000);
      //stop.....
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW); 
      digitalWrite(motor2Pin2, LOW);
    }
      
    }
}
