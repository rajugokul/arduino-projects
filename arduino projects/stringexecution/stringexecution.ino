void setup() {
  // put your setup code here, to run once:
pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  // put your main code here, to run repeatedly:

String str="hai how are you";
if (str.find("else"))
{

digitalWrite(LED_BUILTIN, HIGH);
}
else
{
  digitalWrite(LED_BUILTIN, LOW);
}
}
