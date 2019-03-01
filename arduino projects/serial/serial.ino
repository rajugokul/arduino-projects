void setup() 
{
Serial.begin(9600);
pinMode(13,OUTPUT);
}
void loop() 
{    
if (Serial.available() > 0) 
{
  char inByte = Serial.read();
if(inByte == 'a')
{
Serial.write("Hello");
}
else if(inByte == 'b')
{
  Serial.println("IN WRITE FUNCTION");
  write();
}
}
}
void write()
{
   int sensorValue = digitalRead(6);
  Serial.println(sensorValue);
  //delay(1);        
  if(sensorValue=='0')
 {
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  } 
}

