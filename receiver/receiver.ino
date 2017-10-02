#include <SoftwareSerial.h>

const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12
const byte MAX = 10;
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  Serial.begin(1200);
  HC12.begin(1200);
}

void loop() {
  while (HC12.available() <=0){
    ;//wait
  }
  Serial.println("recieved data");
  //start when serial is available 
  byte data_in[MAX];
  int i = 0;
  int last_read_time = millis();
  //loop until it takes too long to get data
  while (millis() - last_read_time < 100) {
    //loop while there is data in the serial buffer
    while (HC12.available() > 0){
      //read data into data_in array
      data_in[i++] = HC12.read();
      Serial.println(data_in[i-1]);
      //update timeout
      last_read_time = millis();
    }

  }
  HC12.flush();
  while (HC12.available() > 0){
    HC12.read();
    Serial.print("f");
  }
  
  Serial.println("Send all that data back");
  //send all that data back
  for (int j = 0; j < MAX; j++){
    Serial.print(data_in[j]);
    Serial.print(",");
    HC12.write(data_in[j]);
  }
  Serial.println();
}
