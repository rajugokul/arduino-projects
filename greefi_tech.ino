#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//Our Wi-Fi ssdid and password
char* ssid = "vj_gokul"; //Put your Wi-Fi ssdid here
char* password = "Vijay@123"; //Your Wi-Fi Password
String light1 = "0";
String light2 = "0";
String light3 = "0";
String light4 = "0";
String light5 = "0";
String light6 = "0";
String fan1 = "0";
String fan2 = "0";
String fan3 = "0";
String fan4 = "0";



ESP8266WebServer server; //server variable

void setup() {
  initializePin(); //call function

  //Making Connection With netword
  WiFi.begin(ssid, password);
  
  Serial.begin(115200);
  Serial.print("Searching Connection");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.print("IP Address: "); //Show the IP Address to access your NodeMCU
  Serial.print(WiFi.localIP());
  
  serverSection();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();

}

void initializePin(){
  
      pinMode(D0, OUTPUT);
      pinMode(D1, OUTPUT);
      pinMode(D2, OUTPUT);
      pinMode(D3, OUTPUT);
      pinMode(D4, OUTPUT);
      pinMode(D5, OUTPUT);
      pinMode(D6, OUTPUT);
      pinMode(D7, OUTPUT);
      pinMode(D8, OUTPUT);
      pinMode(D9, OUTPUT);

      digitalWrite(D0, LOW);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
      digitalWrite(D3, LOW);
      digitalWrite(D4, LOW);
      digitalWrite(D5, LOW);
      digitalWrite(D6, LOW);
      digitalWrite(D7, LOW);
      digitalWrite(D8, LOW);
      digitalWrite(D9, LOW);
}

void serverSection(){
  server.on("/", []() {
    server.send(200, "text/html", "<!DOCTYPE html><html><meta charset='UTF-8'><head></head><body><h2>Sulkiflee's Room</h2><h3><a href='/light1'>ไฟห้อง</a></h3><br><h3><a href='/light2'>ไฟหน้ากระจก</a></h3><br><h3><a href='/light3'>ไฟเตียง</a></h3><br><h3><a href='/light4'>พัดลม</a></h3><br><h3><a href='/light5'>ไฟเตียง</a></h3><br><h3><a href='/light6'>ไฟเตียง</a></h3><br><h3><a href='/fan1'>ไฟเตียง</a></h3><br><h3><a href='/fan2'>ไฟเตียง</a></h3><br><h3><a href='/fan3'>ไฟเตียง</a></h3><br><h3><a href='/fan4'>ไฟเตียง</a></h3></body></html>");
  });

  server.on("/light1", light1_state);
  server.on("/light2", light2_state);
  server.on("/light3", light3_state);
  server.on("/light4", light4_state);
  server.on("/light5", light5_state);
  server.on("/light6", light6_state);
  server.on("/fan1", fan1_state);
  server.on("/fan2", fan2_state);
  server.on("/fan3", fan3_state);
  server.on("/fan4", fan4_state);

  server.on("/status", all_state);
  
  server.begin();
}

void light1_state(){
  if(light1 == "0"){
    light1 = "1";
    digitalWrite(D0, HIGH);
    server.send(200, "text/html", light1);
  }else{
    light1 = "0";
    digitalWrite(D0, LOW);
    server.send(200, "text/html", light1);
  }
}

void light2_state(){
  if(light2 == "0"){
    light2 = "1";
    digitalWrite(D1, HIGH);
    server.send(200, "text/html", light2);
  }else{
    light2 = "0";
    digitalWrite(D1, LOW);
    server.send(200, "text/html", light2);
  }
}

void light3_state(){
  if(light3 == "0"){
    light3 = "1";
    digitalWrite(D2, HIGH);
    server.send(200, "text/html", light3);
  }else{
    light3 = "0";
    digitalWrite(D2, LOW);
    server.send(200, "text/html", light3);
  }
}

void light4_state(){
  if(light4 == "0"){
    light4 = "1";
    digitalWrite(D3, HIGH);
    server.send(200, "text/html", light4);
  }else{
    light4 = "0";
    digitalWrite(D3, LOW);
    server.send(200, "text/html", light4);
  }
}

void light5_state(){
  if(light5 == "0"){
    light5 = "1";
    digitalWrite(D4, HIGH);
    server.send(200, "text/html", light5);
  }else{
    light5 = "0";
    digitalWrite(D4, LOW);
    server.send(200, "text/html", light5);
  }
}
void light6_state(){
  if(light6 == "0"){
    light6 = "1";
    digitalWrite(D5, HIGH);
    server.send(200, "text/html", light6);
  }else{
    light6 = "0";
    digitalWrite(D5, LOW);
    server.send(200, "text/html", light6);
  }
}
void fan1_state(){
  if(fan1 == "0"){
    fan1 = "1";
    digitalWrite(D6, HIGH);
    server.send(200, "text/html", fan1);
  }else{
    fan1 = "0";
    digitalWrite(D6, LOW);
    server.send(200, "text/html", fan1);
  }
}

void fan2_state(){
  if(fan2 == "0"){
    fan2 = "1";
    digitalWrite(D7, HIGH);
    server.send(200, "text/html", fan2);
  }else{
    fan2 = "0";
    digitalWrite(D7, LOW);
    server.send(200, "text/html", fan2);
  }
}
void fan3_state(){
  if(fan3 == "0"){
    fan3= "1";
    digitalWrite(D8, HIGH);
    server.send(200, "text/html", fan3);
  }else{
    fan3 = "0";
    digitalWrite(D8, LOW);
    server.send(200, "text/html", fan3);
  }
}
void fan4_state(){
  if(fan4 == "0"){
    fan4 = "1";
    digitalWrite(D9, HIGH);
    server.send(200, "text/html", fan4);
  }else{
    fan4 = "0";
    digitalWrite(D9, LOW);
    server.send(200, "text/html", fan4);
  }
}

void all_state(){
  server.send(200, "text/html", "{'l1':'"+light1+"','l2':'"+light2+"','l3':'"+light3+"','l4':'"+light4+"','l5':'"+light5+"','l6':'"+light6+"','f1':'"+fan1+"','f2':'"+fan2+"','f3':'"+fan3+"','f4':'"+fan4+"'}");
}


