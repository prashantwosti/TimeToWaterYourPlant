int HUMID_SOIL_GREEN_LED = 13;
int DRY_SOIL_YELLOW_LED = 12;
int WATER_ERROR_SOIL_RED_LED = 11;

int COMMON_DELAY_MILLIS = 1000;

void setup() {
  // Setup LEDs
  pinMode(HUMID_SOIL_GREEN_LED, OUTPUT);
  pinMode(DRY_SOIL_YELLOW_LED, OUTPUT);
  pinMode(WATER_ERROR_SOIL_RED_LED, OUTPUT);

  // Read Analog input from A0 port
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int SensorValue = analogRead(A0); //take a sample
  Serial.print("Sensor value is: "); Serial.print(SensorValue);
  Serial.println(""); 
  
  turnOffAllLEDs();
  
  delay(COMMON_DELAY_MILLIS);
  if (SensorValue >= 1000) {
    digitalWrite(WATER_ERROR_SOIL_RED_LED, HIGH);
    Serial.println("Sensor is not in the Soil or DISCONNECTED");
  }
  if (SensorValue < 1000 && SensorValue >= 600) {
    digitalWrite(DRY_SOIL_YELLOW_LED, HIGH);
    Serial.println("Soil is DRY");
  }
  if (SensorValue < 600 && SensorValue >= 370) {
    digitalWrite(HUMID_SOIL_GREEN_LED, HIGH);
    Serial.println("Soil is HUMID");
  }
  if (SensorValue < 370) {
    digitalWrite(WATER_ERROR_SOIL_RED_LED, HIGH);
    Serial.println("Sensor in WATER");
  }
  
  delay(COMMON_DELAY_MILLIS);
  
}

void turnOffAllLEDs() {
  digitalWrite(HUMID_SOIL_GREEN_LED, LOW);
  digitalWrite(DRY_SOIL_YELLOW_LED, LOW);
  digitalWrite(WATER_ERROR_SOIL_RED_LED, LOW);
  }
