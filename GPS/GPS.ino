#include "nmea_parser.hpp"

#define BAUD_RATE   115200

NMEA_Parser parser;

void setup() {
  Serial.begin(BAUD_RATE);  // outgoing messages
  Serial2.begin(BAUD_RATE); // incoming messages
}

void serialEvent2() {
  bool newData = false;
  char c;
  
  while(Serial2.available()) {
    c = Serial2.read();
    newData |= parser.encode(c);
  }
  
  if(newData) {
    double latitude = parser.getLatitude();
    double longitude = parser.getLongitude();
    double altitude = parser.getAltitude();

    Serial.print("latitude: ");
    Serial.print(latitude, 8);
    Serial.print("\tlongitude: ");
    Serial.print(longitude, 8);
    Serial.print("\taltitude: ");
    Serial.print(altitude, 8);
    Serial.print("\n");
  }
}

void loop() {}
