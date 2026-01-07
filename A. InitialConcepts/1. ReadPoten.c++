// Project to measure analog value and percentage using a potentiometer.

// ========= COMPONENTS =========
// - Arduino UNO
// - B10K Potentiometer

// ========= POTENTIOMETER CONNECTIONS =========
// - Pin 1       -> Arduino 5V
// - Middle Pin  -> Analog Pin A5
// - Pin 3       -> GND

// ========= PARAMETERS =========
const int sensorPin = A5; // Pin connected to the potentiometer (Middle Pin)

// ========= VARIABLES =========
int sensorVal;      // Analog value read from the potentiometer
long percentage;    // Value converted to percentage

void setup() {
  Serial.begin(9600);
}

void loop() {

  delay(300);

  sensorVal = analogRead(sensorPin);
  Serial.print("Measurement: ");
  Serial.println(sensorVal);

  percentage = map(sensorVal, 0, 1023, 0, 100);
  Serial.print("Percentage: ");
  Serial.println(percentage);
  Serial.println("");
}
