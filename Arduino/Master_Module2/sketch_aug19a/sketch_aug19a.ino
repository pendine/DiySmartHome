#include "ESP8266.h"
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(6,7);
char buffer[255];
const char *ssid = "";
const char *password = ""

WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600); 
  Serial.print("bluetooth : ");
  Serial.println("GOOD");

  Serial.println("Wifi begin");
  Serial.print("Connecting WiFi name : ");
  Serial.print(ssid);
  delay(10);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  server.begin();
  printWifiStatus();
}

void loop()
{
  WiFiClient clinet = server.available();
  if(!client){
    return;
  }

  Serial.println("new Client");

  if(client.available()){
    while(client.available()){
      buffer=client.read();
    }
  }

  

//  check = BTSerial.read();
//  if(strcmp(check,"check")==0){
//    Serial.println("Perfect Checking");
//  }
    if(Serial.available()){
        BTSerial.write(Serial.read());
    }
    if(BTSerial.available()){
        Serial.write(BTSerial.read());
    }
}

char bufferCheck(){
  if(strcmp(buffer,"checkBt01")==0){
    BTSerial.write(buffer);
  }
  if(strcmp(buffer,"checkBt02")==0){
    BTSerial.write(buffer);
  }
}

void printWifiStatus(){
  IPAddress ip = WiFi.loaclIP();
  Serial.print("IP address: ");
  Serial.println(ip);
}

