int a=0;
int b=0;
void setup() {
 Serial.begin(9600);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
}

void loop() {
a=analogRead(A0);
b=analogRead(A1);
Serial.println("light 1=="+String(a)); 
Serial.println("light 2=="+String(b));
if(a<=25){
  digitalWrite(2,LOW); 
}
else{
  digitalWrite(2,HIGH);
}
if(b<=25){
  digitalWrite(3,LOW);
}
else{
  digitalWrite(3,HIGH);
}
delay(10);
}
