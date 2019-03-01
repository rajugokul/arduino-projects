int gas=0;
int sound=0;
void setup() {
Serial.begin(9600);
pinMode(A4,INPUT);
pinMode(A5,INPUT);

}

void loop() {
gas=analogRead(A4);
sound=analogRead(A5);
Serial.println("G"+String(gas)+"s"+String(sound));

/*Serial.print('G');
Serial.println(gas);
Serial.print('S');
Serial.println(sound);

Serial.println("");

*/

delay(500);

}
