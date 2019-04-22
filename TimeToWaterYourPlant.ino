const int WATER_ERROR_SOIL_RED_LED = 11;
const int DRY_SOIL_YELLOW_LED = 12;
const int HUMID_SOIL_GREEN_LED = 13;

const char SENSOR_PIN = A0; // A0 is analog

const int COMMON_DELAY_MILLIS = 1000;

void setup() {
  
  // Setup LEDs
  setupLEDs();

  // Reading input from A0.
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  
}

void loop() {
  
  int sensorValue = analogRead(SENSOR_PIN);
  Serial.print("Sensor reading is: "); Serial.println(sensorValue);

  turnOffAllLEDs();
  delay(COMMON_DELAY_MILLIS);

  if (sensorValue >= 1000) {
    turnOnLED(WATER_ERROR_SOIL_RED_LED);
    Serial.println("Sensor is not in the Soil or DISCONNECTED");
  }

  if (sensorValue < 1000 && sensorValue >= 600) {
    turnOnLED(DRY_SOIL_YELLOW_LED);
    Serial.println("Soil is dry");
  }

  if (sensorValue < 600 && sensorValue >= 370) {
    turnOnLED(HUMID_SOIL_GREEN_LED);
    Serial.println("Soil is humid");
  }

  if (sensorValue < 370) {
    turnOnLED(WATER_ERROR_SOIL_RED_LED);
    Serial.println("Sensor in water");
  }

  delay(COMMON_DELAY_MILLIS);

}

void setupLEDs() {
  pinMode(HUMID_SOIL_GREEN_LED, OUTPUT);
  pinMode(DRY_SOIL_YELLOW_LED, OUTPUT);
  pinMode(WATER_ERROR_SOIL_RED_LED, OUTPUT);
}

void turnOnLED(int led) {
  digitalWrite(led, HIGH);
}

void turnOffAllLEDs() {
  digitalWrite(HUMID_SOIL_GREEN_LED, LOW);
  digitalWrite(DRY_SOIL_YELLOW_LED, LOW);
  digitalWrite(WATER_ERROR_SOIL_RED_LED, LOW);
}
