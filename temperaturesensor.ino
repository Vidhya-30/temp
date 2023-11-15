const int sensorPin = A0;  // LM35 sensor connected to Analog pin A0
const int ledPin = 13;    // Onboard LED connected to digital pin 13

const int belowInterval = 250;  // Blink interval when temperature is below 30 degrees Celsius (in loops)
const int aboveInterval = 500;  // Blink interval when temperature is above 30 degrees Celsius (in loops)

int temperatureLimit = 30;  // Temperature threshold in degrees Celsius

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  // Read the temperature from the LM35 sensor
  int temperature = readTemperature();

  // Check if the temperature is below the threshold
  if (temperature < temperatureLimit) {
    blinkLED(belowInterval);
  } 
  // Check if the temperature is above the threshold
  else if (temperature >= temperatureLimit) {
    blinkLED(aboveInterval);
  }
}

int readTemperature() {
  // Read the analog value from the LM35 sensor
  int sensorValue = analogRead(sensorPin);

  // Convert the analog value to temperature in degrees Celsius
  float temperature = (sensorValue * 0.48876);

  return (int)temperature;
}

void blinkLED(int interval) {
  static unsigned long loopCount = 0;  // will store the loop count at the last LED update

  // Check if the specified interval has passed since the last LED update
  if (loopCount % interval == 0) {
    // Toggle the LED state
    if (digitalRead(ledPin) == HIGH) {
      digitalWrite(ledPin, LOW);
    } else {
      digitalWrite(ledPin, HIGH);
    }
  }

  // Increment the loop count, and avoid overflow
  loopCount = (loopCount == 1000000) ? 0 : loopCount + 1;
}

