#include <SoftwareSerial.h>

const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12
const byte MAX = 10;

const int SUCCESS_PIN = 2;
const int FAILURE_PIN = 3;
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  Serial.begin(1200);                       // Open serial port to computer
  HC12.begin(1200);                         // Open serial port to HC12
  pinMode(SUCCESS_PIN, OUTPUT);
  pinMode(FAILURE_PIN, OUTPUT);
}

void loop() {
  int success = 1;
  //send a lowercase a to the other one
  //Serial.println("Sending byte out");
  HC12.write('a');
  Serial.println("Transmitted");


  unsigned long time_start = millis();
  while (1){
    if (millis() - time_start > 5000){
      digitalWrite(FAILURE_PIN, HIGH);
      Serial.println("timeout");
      success = 0;
      break; 
    }

    if (HC12.read() == 'b'){
      digitalWrite(SUCCESS_PIN, HIGH);
      Serial.println("Success");
      break;
    }
  }



  delay(200);
  digitalWrite(SUCCESS_PIN, LOW);
  digitalWrite(FAILURE_PIN, LOW);
    
}
