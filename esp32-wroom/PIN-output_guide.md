# ESP32-WROOM-32 GPIO Pinout & Developer Guide

> A practical reference for developers working with the ESP32-WROOM-32 module, covering GPIOs, power pins, ADC, DAC, communication interfaces, boot pins, and important hardware considerations.

---

## 📌 Introduction

The **ESP32-WROOM-32** is one of the most widely used ESP32 modules for IoT, embedded systems, robotics, automation, Bluetooth, and Wi-Fi projects.

One of the most important things to understand when developing with the ESP32 is its **GPIO pin configuration**.

Not every GPIO behaves the same way. Some pins are input-only, some are connected internally to flash memory, while others affect the boot process.

This guide provides a developer-friendly reference for selecting the correct GPIO for your project.

---

# 🔌 ESP32-WROOM-32 GPIO Overview

The ESP32 provides a large number of configurable GPIO pins.

| GPIO    | Common Function | Important Notes    |
| ------- | --------------- | ------------------ |
| GPIO 0  | Digital I/O     | Boot/strapping pin |
| GPIO 1  | UART TX         | Serial output      |
| GPIO 2  | Digital I/O     | Boot-related       |
| GPIO 3  | UART RX         | Serial input       |
| GPIO 4  | Digital I/O     | General purpose    |
| GPIO 5  | Digital I/O     | SPI CS / strapping |
| GPIO 12 | Digital I/O     | Strapping pin      |
| GPIO 13 | Digital I/O     | General purpose    |
| GPIO 14 | Digital I/O     | SPI CLK            |
| GPIO 15 | Digital I/O     | Strapping pin      |
| GPIO 16 | Digital I/O     | General purpose    |
| GPIO 17 | Digital I/O     | General purpose    |
| GPIO 18 | Digital I/O     | SPI CLK            |
| GPIO 19 | Digital I/O     | SPI MISO           |
| GPIO 21 | Digital I/O     | I²C SDA            |
| GPIO 22 | Digital I/O     | I²C SCL            |
| GPIO 23 | Digital I/O     | SPI MOSI           |
| GPIO 25 | Digital I/O     | DAC Channel 1      |
| GPIO 26 | Digital I/O     | DAC Channel 2      |
| GPIO 27 | Digital I/O     | General purpose    |
| GPIO 32 | Digital I/O     | ADC                |
| GPIO 33 | Digital I/O     | ADC                |
| GPIO 34 | Digital Input   | **Input only**     |
| GPIO 35 | Digital Input   | **Input only**     |
| GPIO 36 | Digital Input   | **Input only**     |
| GPIO 39 | Digital Input   | **Input only**     |

---

# ⚡ Power Pins

The development board normally exposes the following power-related pins:

| Pin        | Purpose               |
| ---------- | --------------------- |
| `VIN / 5V` | Board power input     |
| `3V3`      | 3.3V regulated supply |
| `GND`      | Ground                |
| `EN`       | Chip enable / reset   |

### ⚠️ Important

ESP32 GPIO pins operate at **3.3V logic**.

Do not connect a 5V digital signal directly to an ESP32 GPIO.

For 5V sensors or modules, use an appropriate:

* Logic-level converter
* Voltage divider
* 3.3V-compatible interface

---

# 🧠 GPIO Input-Only Pins

The following pins are **input-only**:

```text
GPIO 34
GPIO 35
GPIO 36
GPIO 39
```

This means they cannot be used for:

```cpp
digitalWrite()
```

or other output operations.

They are useful for:

* Analog sensors
* Buttons
* ADC measurements
* External digital signals

For example:

```cpp
#define SENSOR_PIN 34

void setup() {
    Serial.begin(115200);

    pinMode(SENSOR_PIN, INPUT);
}

void loop() {
    int value = digitalRead(SENSOR_PIN);

    Serial.println(value);

    delay(500);
}
```

---

# 🚀 Boot / Strapping Pins

Some GPIOs are sampled during the ESP32 boot process.

Important strapping pins include:

```text
GPIO 0
GPIO 2
GPIO 5
GPIO 12
GPIO 15
```

These pins should be used carefully when connecting external hardware.

For example, if an external circuit forces a boot-related GPIO into an unexpected state during startup, the ESP32 may:

* Fail to boot
* Enter download mode
* Behave differently after reset

### Developer Tip

If your project randomly stops booting after connecting a sensor, display, relay, or other module, check whether the module is connected to a **strapping pin**.

---

# 💾 GPIO 6–11 — Avoid Using Them

GPIOs:

```text
GPIO 6
GPIO 7
GPIO 8
GPIO 9
GPIO 10
GPIO 11
```

are normally connected to the ESP32's internal SPI flash.

They should generally **not be used as normal GPIO pins**.

Using them incorrectly can cause:

* Boot failures
* Crashes
* Flash communication problems
* Unstable operation

For normal applications, simply avoid these GPIOs.

---

# 📡 I²C Pins

The conventional I²C configuration is:

```text
GPIO 21 → SDA
GPIO 22 → SCL
```

Example:

```cpp
#include <Wire.h>

#define SDA_PIN 21
#define SCL_PIN 22

void setup() {
    Wire.begin(SDA_PIN, SCL_PIN);
}

void loop() {
}
```

I²C is commonly used for:

* OLED displays
* Temperature sensors
* IMUs
* RTC modules
* GPIO expanders
* Environmental sensors

---

# 🔄 SPI Pins

A commonly used VSPI configuration is:

| Signal | GPIO |
| ------ | ---: |
| SCLK   |   18 |
| MISO   |   19 |
| MOSI   |   23 |
| CS     |    5 |

Example:

```cpp
#define SPI_SCK  18
#define SPI_MISO 19
#define SPI_MOSI 23
#define SPI_CS   5
```

SPI is useful for:

* SD cards
* TFT displays
* Flash memory
* RFID readers
* High-speed sensors

---

# 🔊 DAC Pins

The ESP32 provides two built-in DAC outputs:

```text
GPIO 25 → DAC Channel 1
GPIO 26 → DAC Channel 2
```

These can be useful for generating simple analog waveforms and audio-related applications.

Example:

```cpp
#define DAC_PIN 25

void setup() {
}

void loop() {
    for (int value = 0; value < 256; value++) {
        dacWrite(DAC_PIN, value);
        delay(2);
    }
}
```

---

# 📊 ADC Pins

ESP32 provides multiple ADC-capable GPIOs.

Common ADC pins include:

```text
GPIO 32
GPIO 33
GPIO 34
GPIO 35
GPIO 36
GPIO 39
```

Example:

```cpp
#define ADC_PIN 34

void setup() {
    Serial.begin(115200);
}

void loop() {
    int value = analogRead(ADC_PIN);

    Serial.println(value);

    delay(500);
}
```

ADC pins are commonly used with:

* Potentiometers
* Light sensors
* Analog temperature sensors
* Joysticks
* Voltage measurement circuits

---

# 📶 UART Pins

The ESP32 provides hardware UART interfaces.

The default UART0 pins are:

```text
GPIO 1 → TX
GPIO 3 → RX
```

These pins are commonly used for:

* Serial debugging
* Programming
* GPS modules
* GSM modules
* Serial sensors

Example:

```cpp
void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println("ESP32 UART Test");

    delay(1000);
}
```

### ⚠️ Developer Note

GPIO 1 and GPIO 3 are commonly used by the USB-to-Serial interface on development boards.

Using them for external hardware can interfere with serial monitoring or programming.

---

# 💡 PWM

ESP32 supports hardware PWM through its LEDC peripheral.

PWM can be used for:

* LED brightness
* Motor speed control
* Servo control
* Buzzer applications

Example:

```cpp
#define LED_PIN 25

void setup() {
    ledcAttach(LED_PIN, 5000, 8);
}

void loop() {
    ledcWrite(LED_PIN, 128);

    delay(1000);

    ledcWrite(LED_PIN, 0);

    delay(1000);
}
```

> PWM-capable GPIO selection depends on the ESP32 variant and framework version. Always verify the API and board variant you are using.

---

# 🔐 Internal Pull-Up / Pull-Down

Many ESP32 GPIOs support internal pull-up and pull-down resistors.

For example:

```cpp
#define BUTTON_PIN 27

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {

    if (digitalRead(BUTTON_PIN) == LOW) {
        Serial.println("Button Pressed");
    }
}
```

With `INPUT_PULLUP`, the button can be connected between the GPIO and GND.

```text
ESP32 GPIO 27
       |
       |
     Button
       |
      GND
```

---

# 🛡️ GPIO Selection Cheat Sheet

When designing a new ESP32 project, this is a useful starting point:

### ✅ Good General-Purpose GPIOs

```text
GPIO 4
GPIO 13
GPIO 16
GPIO 17
GPIO 18
GPIO 19
GPIO 21
GPIO 22
GPIO 23
GPIO 25
GPIO 26
GPIO 27
GPIO 32
GPIO 33
```

### ⚠️ Use Carefully

```text
GPIO 0
GPIO 2
GPIO 5
GPIO 12
GPIO 15
```

These have boot/strapping considerations.

### ❌ Avoid for General GPIO

```text
GPIO 6
GPIO 7
GPIO 8
GPIO 9
GPIO 10
GPIO 11
```

These are normally associated with SPI flash.

### 📥 Input Only

```text
GPIO 34
GPIO 35
GPIO 36
GPIO 39
```

---

# 🧩 Example Project Pin Assignment

Suppose you are building a small IoT monitoring device containing:

* OLED display
* Temperature sensor
* Push button
* Status LED
* Buzzer

A possible configuration could be:

| Component          | ESP32 GPIO |
| ------------------ | ---------: |
| OLED SDA           |    GPIO 21 |
| OLED SCL           |    GPIO 22 |
| Temperature Sensor |    GPIO 32 |
| Push Button        |    GPIO 27 |
| Status LED         |    GPIO 25 |
| Buzzer             |    GPIO 26 |

This keeps the design relatively simple and avoids the flash-connected GPIOs.

---

# 🛠️ Recommended GPIO Selection Strategy

Before assigning a GPIO to a component:

### 1. Identify the signal type

Ask whether the component requires:

```text
Digital Input
Digital Output
Analog Input
PWM
I²C
SPI
UART
```

### 2. Check GPIO restrictions

Verify whether the selected GPIO is:

* Input-only
* Boot/strapping related
* Connected to flash
* Already used by another peripheral

### 3. Check voltage levels

Make sure the connected device uses compatible logic levels.

### 4. Test boot behavior

After connecting external hardware:

```text
Power ON
   ↓
ESP32 Boot
   ↓
Peripheral Initialization
   ↓
Application Start
```

If the ESP32 fails during boot, inspect the GPIO states of connected hardware.

---

# 📋 Quick Reference

```text
I²C
SDA  → GPIO 21
SCL  → GPIO 22

SPI
SCK  → GPIO 18
MISO → GPIO 19
MOSI → GPIO 23
CS   → GPIO 5

UART0
TX   → GPIO 1
RX   → GPIO 3

DAC
DAC1 → GPIO 25
DAC2 → GPIO 26

ADC
GPIO 32
GPIO 33
GPIO 34
GPIO 35
GPIO 36
GPIO 39
```

---

# ⚠️ Common Mistakes

### Mistake 1 — Connecting 5V directly to GPIO

```text
5V Sensor ───────> ESP32 GPIO ❌
```

Use proper level shifting when required.

### Mistake 2 — Using GPIO 6–11

These pins are normally associated with the ESP32 flash interface.

### Mistake 3 — Using GPIO 34–39 as outputs

These pins are input-only.

### Mistake 4 — Ignoring boot pins

A connected peripheral can change the boot state of the ESP32.

### Mistake 5 — Using UART pins without considering Serial

GPIO 1 and GPIO 3 may already be used for programming and serial debugging.

---

# 📚 Final Takeaway

The ESP32-WROOM-32 is extremely flexible, but **GPIOs are not interchangeable in every situation**.

A good hardware design should always consider:

```text
GPIO Capability
       +
Boot Requirements
       +
Peripheral Requirements
       +
Voltage Levels
       +
Current Requirements
       ↓
Reliable ESP32 Design
```

Understanding these restrictions before wiring your circuit can prevent many common problems such as boot failures, unstable peripherals, incorrect sensor readings, and damaged hardware.

---

## ⭐ Quick Rule

> **Don't choose an ESP32 GPIO just because it is available. Choose it based on what the GPIO is capable of doing.**

---

## 📖 Useful Resources

* ESP32-WROOM-32 Datasheet
* ESP32 Technical Reference Manual
* ESP-IDF Documentation
* Arduino-ESP32 Documentation

---

## 🤝 Contributing

Found an error or want to add more information?

Feel free to open an issue or submit a pull request.

Contributions, corrections, and practical examples are welcome.

---
