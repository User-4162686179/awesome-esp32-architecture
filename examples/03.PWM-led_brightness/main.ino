#define LED_PIN 2

void setup() {
    ledcAttach(LED_PIN, 5000, 8);
}

void loop() {
    for (int brightness = 0; brightness <= 255; brightness++) {
        ledcWrite(LED_PIN, brightness);
        delay(5);
    }

    for (int brightness = 255; brightness >= 0; brightness--) {
        ledcWrite(LED_PIN, brightness);
        delay(5);
    }
}