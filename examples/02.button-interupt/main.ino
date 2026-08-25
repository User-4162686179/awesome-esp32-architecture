#define BUTTON_PIN 4
#define LED_PIN 2

volatile bool buttonPressed = false;

void IRAM_ATTR handleButton() {
    buttonPressed = true;
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(BUTTON_PIN),
        handleButton,
        FALLING
    );
}

void loop() {
    if (buttonPressed) {
        buttonPressed = false;

        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    }
}