void setup() 
{
Serial.begin(9600);
pinMode(13,OUTPUT);
}
void loop() 
{
  int sensorValue =analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);        
  if(voltage > 1)
 {
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  } 
}


