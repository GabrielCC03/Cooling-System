#include <Arduino.h> // Include the Arduino core library

// Define pins
const int ledPin = 13; // Define the LED pin
const int pressurePin = PA0; // Define Pressure Sensor Pin - For blue-pill use: PA0 - For Nucleo use: A0
const int tempPin = PA1; // Define Temperature Sensor Pin - For blue-pill use: PA1 - For Nucleo use: A1
const int flowmeterPin = PB0; // Define Flowmeter Sensor Pin - For blue-pill use: PB0  - For Nucleo use: D0
const int interruptPin = 0; // Define interrupt pin

// Define Pressure Sensor constants
const float voltageRange = 5.0;  // Voltage range of the analog input (in volts)
const float pressureRange = 60.0;  // Pressure range of the sensor (in PSI)

// Define Temperature Sensor constants
const float temperatureRange = 100.0;  // Temperature range of the sensor (in degrees Celsius)

// Define flowmeter constants
float calibrationFactor = 4.5;
float flowRate;


void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initialize the Pressure Sensor pin as an input
  pinMode(pressurePin, INPUT);

  // Initialize the Temperature Sensor pin as an input
  pinMode(tempPin, INPUT);

  // Initialize the Flowmeter Sensor pin as an input
  pinMode(flowmeterPin, INPUT);

  // Start serial communication
  Serial.begin(9600);

}

// Pressure Sensor Functions
void pressureSensor(){
  /**
   * @brief 
   * Implement the pressure sensor logic here
   * 116CP31-M04S2-50 Pressure Sensor
   */

  // Read the analog value from the pressure sensor
  int sensorValue = analogRead(pressurePin);

  // Convert the analog value to voltage
  float voltage = (sensorValue * voltageRange) / 1023.0;

  // Convert the voltage to pressure
  float pressure = (voltage * pressureRange) / voltageRange;

  // Print the pressure value to the serial monitor
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" PSI");

}

// Temperature Sensor Functions
void temperatureSensor(){
  /**
   * @brief 
   * Implement the temperature sensor logic here
   * Temperature Sensor connected to 116CP31-M04S2-50 Pressure Sensor
   */

  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(tempPin);

  // Convert the analog value to voltage
  float voltage = (sensorValue * voltageRange) / 1023.0;

  // Convert the voltage to temperature
  float temperature = (voltage - 0.5) / voltageRange;

  // Print the temperature value to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

}

// Flowmeter Functions
void flowmeter(){

  /**
   * @brief 
   * Implement the flowmeter sensor logic here
   * YF-S201 Flowmeter
   */
	
  int sensorValue = analogRead(flowmeterPin);  // Read the analog value from the flowmeter
  flowRate = map(sensorValue, 0, 1023, 0, 10);  // Map the analog value to the desired flow rate range
  
  // Print the flow rate to the serial monitor
  Serial.print("Flow rate: ");
  Serial.print(flowRate);
  Serial.println(" L/min");

  

}

void loop() {

  /**
   * @brief Take readings from the sensors and display them on the serial monitor every 3 seconds
   * 
   */

  digitalWrite(ledPin, HIGH); // Turn on the LED
  // Turn on the sensors
  digitalWrite(pressurePin, HIGH);
  digitalWrite(tempPin, HIGH);
  digitalWrite(flowmeterPin, HIGH);

  temperatureSensor(); // Call the temperature sensor function  
  pressureSensor(); // Call the pressure sensor function
  flowmeter();  // Call the flowmeter function

  digitalWrite(ledPin, LOW); // Turn off the LED
  delay(3000); // Delay for 3 seconds

}
