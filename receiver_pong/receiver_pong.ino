#include <SoftwareSerial.h>

const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12
const byte MAX = 10;

const int SUCCESS_PIN = 2;

SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  Serial.begin(1200);
  HC12.begin(1200);
  pinMode(SUCCESS_PIN, OUTPUT);

}

unsigned long time_sent = millis();
void loop() {
  while (HC12.available() <=0){
    ;//wait
  }
  while (HC12.available() > 0){
    if (HC12.peek() == 'a'){
      digitalWrite(SUCCESS_PIN, HIGH);
      Serial.println(millis() - time_sent);
      HC12.read();
      //Serial.println("***Recived ping***");
      HC12.write('b');
      time_sent = millis();
      //Serial.println("Send reply");
      } else{
      //Serial.pr      digitalWrite(SUCCESS_PIN, HIGH);
int("recieved garbage: ");
      //Serial.println((char)HC12.read());
      HC12.read();
    }
  }
  delay(200);
  digitalWrite(SUCCESS_PIN, LOW);
}
