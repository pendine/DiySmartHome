#include <SoftwareSerial.h>

SoftwareSerial BTSerial(6,7);

boolean State=false;
char check[255];

void setup()
{
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  
  Serial.begin(9600);
  //BTSerial.begin(9600); 
  BTSerial.begin(9600); 
  Serial.println("ATCommand");
  Serial.println("GOOD");
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
        check = BTSerial.read();
        if(strcmp(check,"checkBt02")==0){
          Serial.println("Perfect Checking");
          if(State==ture){
            digitalWrite(3,HIGH);
            delay(50);
            digitalWrite(3,LOW);
            State!=State;
          }else{
            digitalWrite(4,HIGH);
            delay(50);
            digitalWrite(4,LOW);
            State!=State;
          }
        }
        
    }
}
