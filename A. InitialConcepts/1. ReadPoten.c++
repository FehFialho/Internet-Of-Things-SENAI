// ========== COMPONENTS ==========
// - Arduino UNO
// - B10K potentiometer
// ================================

// Parameters
const int sensorPin = A5; // Pin connected to the potentiometer

// Variables
int sensorVal;      // Analog value read from the potentiometer
long percentage;    // Value converted to percentage

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, OUTPUT);
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