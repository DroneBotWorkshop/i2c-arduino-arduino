/*
  I2C Master Demo
  i2c-master-demo.ino
  Demonstrate use of I2C bus
  Master sends character and gets reply from Slave
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Define Slave answer size
#define ANSWERSIZE 5

void setup() {

  // Initialize I2C communications as Master
  Wire.begin();

  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}

void loop() {
  delay(50);
  Serial.println("Write data to slave");

  // Write a charatre to the Slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(0);
  Wire.endTransmission();

  Serial.println("Receive data");

  // Read response from Slave
  // Read back 5 characters
  Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);

  // Add characters to string
  String response = "";
  while (Wire.available()) {
    char b = Wire.read();
    response += b;
  }

  // Print to Serial Monitor
  Serial.println(response);
}
