#include <Arduino.h>
#include "temperature_sensor.h"
#include "pump_controller.h"

void setup() {
  // Initialize temperature sensor
  TemperatureSensor_Init();

  // Set up pump control pin
  pinMode(PUMP_CONTROL_PIN, OUTPUT);
}

void loop() {
  // Read temperature from sensor
  float temperature = TemperatureSensor_Read();

  // Control logic: activate pump based on temperature
  PumpController_Update(temperature);
}
