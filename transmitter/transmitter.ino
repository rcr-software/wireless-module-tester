#include <SoftwareSerial.h>

const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12
const byte MAX = 10;
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  Serial.begin(1200);                       // Open serial port to computer
  HC12.begin(1200);                         // Open serial port to HC12
}

byte count = 0;
void loop() {
  //send bytes from 0 to MAX
  while (count < MAX){
      HC12.write(count);
      count++;
  }

  //wait up to a second for reciever to reply
  int time_start = millis();
  while (time_start < 1000){
    if (HC12.available() > 0){
      break;
    }
  }

  //if we get data in before timeout, print it to Serial
  while (HC12.available() > 0){
    Serial.write(HC12.read());
  }

  //wait a second or two before doing it again
  delay(1700);

  
}
