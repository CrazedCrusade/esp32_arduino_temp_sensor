#include <Wire.h>
#include <M2M_LM75A.h>

// Create an instance of the LM75A sensor
M2M_LM75A lm75a;

// Define the GPIO pin for the signal
#define SIGNAL_PIN 2

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(115200);

  // Initialize the I²C bus
  Wire.begin(); // Default I²C pins for ESP32: SDA = GPIO21, SCL = GPIO22

  pinMode(SIGNAL_PIN, OUTPUT); // Initialize the signal pin as OUTPUT
}

void loop() {
  // Read temperature from the LM75A sensor
  float temperature = lm75a.getTemperature();

  // Print temperature to the Serial Monitor
  if (temperature >= 25 && temperature <= 80) {
    digitalWrite(SIGNAL_PIN, HIGH);
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" °C");
  } else {
      digitalWrite(SIGNAL_PIN, LOW);
      Serial.print("OUT OF RANGE: ");
      Serial.print(temperature);
      Serial.println(" °C");
  }

  // Wait 2 seconds before the next reading
  delay(2000);
}

