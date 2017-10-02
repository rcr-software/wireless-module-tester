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
  //send bytes from 0 to MAX
  Serial.println("data out:");
  byte count = 0;

  while (count < MAX){
      HC12.write(count);
      Serial.print(count);
      Serial.print(". ");
      count++;
  }
  Serial.println();

  //wait up to a second for reciever to reply
  int time_start = millis();
  while (millis()- time_start < 1000){
    Serial.print("w");
    if (HC12.available() > 0){
      Serial.println();
      Serial.println("Got reply");
      break;
    }
  }
  Serial.println();
  Serial.print("waited: ");
  Serial.println(millis()-time_start);


  //if we get data in before timeout, print it to Serial
  Serial.println("Data received:");
  int data_count = 0;
  while (HC12.available() > 0){
    
    Serial.print((byte)HC12.read());
    Serial.print(", ");

    ++data_count;
    if (data_count > MAX){
      HC12.flush();
      break;
    }
  }
  while (HC12.available() > 0){
    HC12.read();
    Serial.print("f");
  }
  Serial.println();
  Serial.println();

  //wait a second or two before doing it again
  delay(2000);

  
}
