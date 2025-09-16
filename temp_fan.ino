// Temperature Controlled Fan Simulation with LED on D13
// NTC 10k on A0, LED on D13 (fan simulation)

const int sensorPin = A0;
const int fanPin = 13;

// NTC parameters (approx values for 10k thermistor)
const float BETA = 3950;    // Beta parameter
const float T0 = 298.15;    // Reference temp (25°C in Kelvin)
const float R0 = 10000;     // Resistance at 25°C (10k)

void setup() {
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT);
}

void loop() {
  int analogValue = analogRead(sensorPin);

  // Convert ADC to resistance
  float R = 10000.0 * (1023.0 / analogValue - 1.0);

  // Steinhart-Hart equation
  float temperatureK = 1.0 / (1.0/T0 + (1.0/BETA) * log(R/R0));
  float temperatureC = temperatureK - 273.15;

  // Fan Control
  if (temperatureC < 25) {
    digitalWrite(fanPin, LOW);  // Fan OFF
    Serial.print("Temp: "); Serial.print(temperatureC);
    Serial.println(" °C | Fan OFF");
  } 
  else if (temperatureC >= 25 && temperatureC < 30) {
    // Simulate 50% PWM by blinking
    digitalWrite(fanPin, HIGH);
    delay(500);
    digitalWrite(fanPin, LOW);
    delay(500);
    Serial.print("Temp: "); Serial.print(temperatureC);
    Serial.println(" °C | Fan 50% (Simulated Blink)");
  } 
  else {
    digitalWrite(fanPin, HIGH);  // Fan ON full speed
    Serial.print("Temp: "); Serial.print(temperatureC);
    Serial.println(" °C | Fan 100%");
  }

  delay(200);
}
