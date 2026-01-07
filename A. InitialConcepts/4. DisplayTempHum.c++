// Project to display temperature and humidity using a DHT11 sensor on a 16x2 LCD.

// ========= COMPONENTS =========
// - Arduino UNO
// - DHT11 Temperature and Humidity Sensor
// - 16x2 LCD Display (HD44780 compatible)
// - 10k Potentiometer (LCD contrast)
// - 4.7kΩ or 10kΩ Resistor (DHT pull-up)
// - Jumper Wires

// ========= DHT11 CONNECTIONS =========
// - VCC  -> 5V
// - DATA -> Digital Pin 8
// - GND  -> GND
// - Pull-up resistor between DATA and 5V

// ========= LCD CONNECTIONS (4-BIT MODE) =========
// - Pin 1  (VSS) -> GND
// - Pin 2  (VDD) -> 5V
// - Pin 3  (V0)  -> Potentiometer middle pin
// - Pin 4  (RS)  -> Digital Pin 12
// - Pin 5  (RW)  -> GND
// - Pin 6  (E)   -> Digital Pin 11
// - Pin 7  (D0)  -> Not connected
// - Pin 8  (D1)  -> Not connected
// - Pin 9  (D2)  -> Not connected
// - Pin 10 (D3)  -> Not connected
// - Pin 11 (D4)  -> Digital Pin 5
// - Pin 12 (D5)  -> Digital Pin 4
// - Pin 13 (D6)  -> Digital Pin 3
// - Pin 14 (D7)  -> Digital Pin 2
// - Pin 15 (A)   -> 5V (Backlight)
// - Pin 16 (K)   -> GND (Backlight)

#include <LiquidCrystal.h>
#include <DHT.h>

// ========= PARAMETERS =========
#define DHTPIN 8
#define DHTTYPE DHT11

// ========= OBJECTS =========
DHT dht(DHTPIN, DHTTYPE);

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Initialize LCD (16 columns, 2 rows)
  lcd.begin(16, 2);

  // Initialize DHT11 sensor
  dht.begin();
}

void loop() {

  delay(500);

  // Read temperature and humidity values
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  // Clear LCD screen
  lcd.clear();

  // Display temperature on the first row
  lcd.setCursor(2, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  // Display humidity on the second row
  lcd.setCursor(2, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");
}