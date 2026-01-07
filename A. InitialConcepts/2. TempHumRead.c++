// Project to measure temperature and humidity using DHT11.

// ========= COMPONENTS =========
// - Arduino UNO
// - 4.7k Ohm Resistor (or 10kΩ)
// - DHT11 Sensor

// ========= DHT11 CONS =========
// - Pin 1 (VCC)  -> Arduino 5V
// - Pin 2 (DATA) -> Digital Pin 2
// - Pin 3 (NC)   -> Not used
// - Pin 4 (GND)  -> GND
// - Pull-up resistor 4.7kΩ (or 10kΩ) -> Between DATA (Digital Pin 2) and 5V

#include <DHT.h> // DHT Sensor Library (REQUIRES Adafruit_Sensor library)
#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE); // Passing the pin (DHTPIN) and sensor type (DHTTYPE) to the DHT object

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  Serial.println("");
  delay(1000);

  float t = dht.readTemperature(); // Temperature
  float h = dht.readHumidity();    // Humidity

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
}