const int trigPin = 9;
const int echoPin = 10;
int sensorPin = A0;   
int sensorValue = 0; 
// defines variables
long duration;
int distance;
void setup() {
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("moisture data:");
  Serial.println(sensorValue);
  if(sensorValue<100){
    Serial.println("moisture detected!!!");
  }
  delay(300);
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}

