/*
  I2C Slave Control Demo
  i2c-slave-demo-control.ino
  Demonstrate use of I2C bus
  Receives potentimeter position data
  Controls LED blink rate
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Define LED Pin
int LED = 13;

// Variable for received data
int rd;

// Variable for blink rate
int br;

void setup() {

  pinMode(LED, OUTPUT);

  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);

  // Function to run when data received from master
  Wire.onReceive(receiveEvent);

  // Setup Serial Monitor
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");/*
  I2C Slave Control Demo
  i2c-slave-demo-control.ino
  Demonstrate use of I2C bus
  Receives potentimeter position data
  Controls LED blink rate
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

  // Include Arduino Wire library for I2C
#include <Wire.h>

  // Define Slave I2C Address
#define SLAVE_ADDR 9

  // Define LED Pin
  int LED = 13;

  // Variable for received data
  int rd;

  // Variable for blink rate
  int br;

  void setup() {

    pinMode(LED, OUTPUT);

    // Initialize I2C communications as Slave
    Wire.begin(SLAVE_ADDR);

    // Function to run when data received from master
    Wire.onReceive(receiveEvent);

    // Setup Serial Monitor
    Serial.begin(9600);
    Serial.println("I2C Slave Demonstration");
  }

  void receiveEvent() {
    // read one character from the I2C
    rd = Wire.read();
    // Print value of incoming data
    Serial.println(rd);

  }
  void loop() {
    delay(50);

    // Calculate blink value
    br = map(rd, 1, 255, 100, 2000);

    digitalWrite(LED, HIGH);
    delay(br);
    digitalWrite(LED, LOW);
    delay(br);

  }
