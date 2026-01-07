// Parameters
const int sensorPin = A5; // Pin connected to sensor

//Variables
int sensorVal; // Analog value from the sensor
long percentage;

void setup() {
  Serial.begin(9600);
}

void loop() {

  delay(300);
  
  sensorVal = analogRead(sensorPin);
  Serial.print("Medição: ");
  Serial.println(sensorVal);

  percentage = map(sensorVal, 0, 1023, 0, 100);
  Serial.print("Porcentagem: ");
  Serial.println(percentage);
  Serial.println("");
}