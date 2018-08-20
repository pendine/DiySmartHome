#include <SoftwareSerial.h>

char buffer[30];

SoftwareSerial BTSerial(D3, D4);   //bluetooth module
//SoftwareSerial BTSerial(6, 7);
// (Tx,Rx)
// Tx:Digital 2 Rx:Digital 3

void setup() {
  Serial.begin(9600);
  
  //hc-05 = 38400
  //BTSerial.begin(38400);
  //hc-06 = 9600
  //BTSerial.begin(9600);

  Serial.println("ATcommand");  //ATcommand Start
}

void loop() {
  if (BTSerial.available()){
    Serial.write(BTSerial.read());
  }
  if (Serial.available()){
    BTSerial.write(Serial.read());
  }
}
