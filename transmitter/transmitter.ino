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
  
  HC12.write(count);
  if (char(count) == MAX){
    count = 0;
    HC12.write(count);
    delay(1000);

  }
  
  count++;
}
