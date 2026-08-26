#define SENSOR_PIN 34

void setup() {
    Serial.begin(115200);
}

void loop() {
    int value = analogRead(SENSOR_PIN);

    Serial.print("ADC: ");
    Serial.println(value);

    delay(500);
}