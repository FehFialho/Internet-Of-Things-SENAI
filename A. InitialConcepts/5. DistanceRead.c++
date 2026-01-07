// Project to measure distance using an ultrasonic sensor (HC-SR04).

// ========= COMPONENTS =========
// - Arduino UNO
// - Ultrasonic Sensor (HC-SR04)
// - Jumper Wires

// ========= ULTRASONIC SENSOR CONNECTIONS =========
// - VCC     -> 5V
// - TRIG    -> Digital Pin 8
// - ECHO    -> Digital Pin 9
// - GND     -> GND

#include <Ultrasonic.h>

// ========= PARAMETERS =========
#define TRIGGER_PIN 8
#define ECHO_PIN    9

// ========= OBJECTS =========
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("Reading ultrasonic sensor data...");
}

void loop() {

  delay(1000);

  // Get distance measurement
  long microseconds = ultrasonic.timing();
  float distanceCM = ultrasonic.convert(microseconds, Ultrasonic::CM);
  float distanceIN = ultrasonic.convert(microseconds, Ultrasonic::IN);

  // Display distance values
  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.print(" cm | ");
  Serial.print(distanceIN);
  Serial.println(" in");
}