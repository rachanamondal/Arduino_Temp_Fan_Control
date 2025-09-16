# Arduino Temperature Controlled Fan

This project uses a 10k NTC thermistor on A0 and a DC fan (simulated with LED/PWM on Pin 9).  
The fan speed is controlled based on temperature:

- **Temp < 25°C** → Fan OFF  
- **25°C ≤ Temp < 30°C** → Fan 50% speed  
- **Temp ≥ 30°C** → Fan 100% speed  

### Components:
- Arduino Uno  
- 10k NTC Thermistor + 10k Resistor (voltage divider)  
- DC Fan (or LED for simulation)  

### Code
See `temp_fan.ino`

### Output (Serial Monitor)
Displays live temperature and fan state every second.
