#include <SoftwareSerial.h>

const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12
const byte MAX = 10;
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  Serial.begin(1200);
  HC12.begin(1200);
}

int start = 0;
byte currentByte = MAX;
byte lastByte = MAX;

void loop() {

  while (HC12.available() > 0) {
    lastByte = currentByte;
    currentByte = HC12.read();
    //Serial.print(currentByte);
    //Serial.print(", ");

    if (currentByte < lastByte){
      //Serial.println();
      //Serial.print("Bytes: ");Serial.print(currentByte);Serial.print(" ");Serial.println(lastByte);
      //Serial.print("time: ");
      Serial.println(millis()-start);
      start = millis();
    }
  }
}
