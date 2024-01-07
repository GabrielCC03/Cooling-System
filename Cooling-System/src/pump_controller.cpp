#include "pump_controller.h"

void PumpController_Update(float temperature) {
  // Control logic for pump activation based on temperature
  if (temperature > 50.0) {
    // Activate pump
    digitalWrite(PUMP_CONTROL_PIN, HIGH);
  } else {
    // Deactivate pump
    digitalWrite(PUMP_CONTROL_PIN, LOW);
  }
}
