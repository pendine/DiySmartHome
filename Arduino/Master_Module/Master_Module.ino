#include <SoftwareSerial.h>

SoftwareSerial BTSerial(6,7);
char check[255];
const char *ssid = "";
const char *password = ""

WiFiClient client;
//WiFiServer server(80);
void setup()
{
  Serial.begin(9600);
  //BTSerial.begin(9600); 
  BTSerial.begin(9600); 
  Serial.println("ATCommand");
  Serial.println("GOOD");

  WiFi.disconnect(ture);
  delay(10);
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{

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

char ClientCheck(){
  while(client.available()){
    
  }
}

