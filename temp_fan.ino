// Arduino: Temperature controlled fan using NTC thermistor
// Input: NTC on A0
// Output: LED on D13 simulating fan

const int thermistorPin = A0;
const int fanPin = 9;  // Use PWM pin (not D13, because D13 has no PWM)

// Constants for NTC
const float BETA = 3950;   // Beta coefficient of NTC (typical)
const float R0 = 10000;    // 10k ohm at 25°C
const float T0 = 298.15;   // 25°C in Kelvin

void setup() {
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT);
}

void loop() {
  int adcValue = analogRead(thermistorPin);

  // Convert ADC to resistance
  float R = 10000.0 * (1023.0 / adcValue - 1.0);

  // Convert resistance to temperature (Steinhart–Hart approx)
  float tempK = 1.0 / (1.0 / T0 + (1.0 / BETA) * log(R / R0));
  float tempC = tempK - 273.15;

  // Fan control logic
  if (tempC < 25) {
    analogWrite(fanPin, 0);
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.println(" °C | Fan: OFF");
  } 
  else if (tempC < 30) {
    analogWrite(fanPin, 128); // ~50% duty
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.println(" °C | Fan: 50%");
  } 
  else {
    analogWrite(fanPin, 255); // 100% duty
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.println(" °C | Fan: 100%");
  }

  delay(1000); // Update every second
}
