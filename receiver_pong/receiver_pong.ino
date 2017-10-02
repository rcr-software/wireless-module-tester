#include <SoftwareSerial.h>

const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12
const byte MAX = 10;
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  Serial.begin(1200);
  HC12.begin(1200);
}

unsigned long time_sent = millis();
void loop() {
  while (HC12.available() <=0){
    ;//wait
  }
  while (HC12.available() > 0){
    if (HC12.peek() == 'a'){
      Serial.println(millis() - time_sent);
      HC12.read();
      //Serial.println("***Recived ping***");
      HC12.write('b');
      time_sent = millis();
      //Serial.println("Send reply");
      } else{
      //Serial.print("recieved garbage: ");
      //Serial.println((char)HC12.read());
      HC12.read();
    }
  }
}
