#include <SoftwareSerial.h>

const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12
const byte MAX = 10;
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  Serial.begin(1200);                       // Open serial port to computer
  HC12.begin(1200);                         // Open serial port to HC12
}

void loop() {

  //send a lowercase a to the other one
  //Serial.println("Sending byte out");
  HC12.write('a');

  unsigned long time_start = millis();
  while (HC12.available() <= 0){
    if (millis() - time_start > 2000){
      //Serial.println("timeout");
      break; 
    }
  }

  while (HC12.available() > 0){
    if (HC12.read() == 'b'){
      //Serial.println("***Recived reply***");
    } else{
      //Serial.println("recieved garbage...");
    }
  }
}
