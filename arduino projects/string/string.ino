void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
String stringOne = "<HTML><HEAD><BODY>";
  int bodyTag = stringOne.indexOf("<BODY>");
   Serial.println("The index of the body tag in the string " + stringOne + " is " + bodyTag);
   Serial.println(bodyTag);
  }
