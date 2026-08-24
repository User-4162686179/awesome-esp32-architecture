# ESP32-C6 GPIO & Pin Output Developer Guide

> A practical reference for the ESP32-C6-WROOM-1 covering GPIOs, ADC, USB, SPI, I²C, UART, wireless connectivity, Thread, Zigbee, and hardware design.

---

## 🚀 Introduction

The **ESP32-C6** is a low-power RISC-V based ESP32 SoC designed for modern connected IoT systems.

Its major advantage is the combination of:

```text
Wi-Fi 6
Bluetooth LE
IEEE 802.15.4
Thread
Zigbee
RISC-V
USB Serial/JTAG
```

The ESP32-C6-WROOM-1 module provides **23 GPIOs** and integrates the ESP32-C6 SoC, SPI flash, crystal oscillator, and antenna.

---
<p align="center">
  <img
    src="./Pinoutput.png"
    alt="ESP32-C5-WROOM-1 Pinout Blueprint"
    width="1000"
  />
</p>

# 🧠 ESP32-C6 Architecture

```text
                         ESP32-C6
                            │
          ┌─────────────────┼─────────────────┐
          │                 │                 │
       RISC-V CPU         Memory           Wireless
          │                 │                 │
          │            ┌────┴────┐      ┌─────┴──────┐
          │            │         │      │            │
          │           ROM      SRAM   Wi-Fi 6    802.15.4
          │                                  │         │
          │                                BLE      Thread
          │                                           │
          │                                         Zigbee
          │
      Peripherals
          │
   ┌──────┼───────────────────────────────┐
   │      │       │       │       │       │
 GPIO   SPI     I²C     UART     USB     ADC
 PWM    I²S     RMT     JTAG    CAN/TWAI
```

The ESP32-C6 uses a **single-core 32-bit RISC-V processor running up to 160 MHz**. The WROOM-1 module provides 512 KB HP SRAM and 16 KB LP SRAM, with flash options up to 16 MB depending on variant.

---

# 📡 Wireless Architecture

ESP32-C6 is designed around modern low-power wireless connectivity.

```text
                     ESP32-C6
                         │
          ┌──────────────┼──────────────┐
          │              │              │
       Wi-Fi 6         BLE 5         802.15.4
          │              │              │
          │              │        ┌─────┴─────┐
          │              │      Thread      Zigbee
          │
      2.4 GHz
```

### Wi-Fi

ESP32-C6 supports:

```text
2.4 GHz Wi-Fi 6
802.11ax
802.11b/g/n
```

Important Wi-Fi 6 features include:

* OFDMA
* Target Wake Time
* Beamforming
* High-density network support
* Station mode
* SoftAP
* Station + SoftAP

### Bluetooth

The module supports Bluetooth LE 5.3.

### 802.15.4

ESP32-C6 supports:

```text
IEEE 802.15.4
     │
     ├── Thread
     └── Zigbee
```

This makes the C6 especially useful for:

* Smart-home devices
* Matter devices
* Thread networks
* Zigbee networks
* Low-power sensor nodes

---

# 🔌 ESP32-C6-WROOM-1 Pinout

The ESP32-C6-WROOM-1 has **29 physical module pins**, including power and ground connections, and exposes **23 GPIOs**.

```text
                     ESP32-C6-WROOM-1

              ┌─────────────────────────┐
              │        ESP32-C6         │
              │                         │
 GND ─────────┤ 1                    28 ├──── GND
 3V3 ─────────┤ 2                    27 ├──── GPIO2
 EN ──────────┤ 3                    26 ├──── GPIO3
 GPIO4 ───────┤ 4                    25 ├──── TX0 / GPIO16
 GPIO5 ───────┤ 5                    24 ├──── RX0 / GPIO17
 GPIO6 ───────┤ 6                    23 ├──── GPIO15
 GPIO7 ───────┤ 7                    22 ├──── NC
 GPIO0 ───────┤ 8                    21 ├──── GPIO23
 GPIO1 ───────┤ 9                    20 ├──── GPIO22
 GPIO8 ───────┤10                    19 ├──── GPIO21
 GPIO10 ──────┤11                    18 ├──── GPIO20
 GPIO11 ──────┤12                    17 ├──── GPIO19
 GPIO12 ──────┤13                    16 ├──── GPIO18
 GPIO13 ──────┤14                    15 ├──── GPIO9
              └─────────────────────────┘
```

This follows the official ESP32-C6-WROOM-1 pin definition table.

---

# 📋 ESP32-C6-WROOM-1 GPIO Reference

|   GPIO | Alternate Functions                    | Notes           |
| -----: | -------------------------------------- | --------------- |
|  GPIO0 | XTAL_32K_P / ADC1_CH0                  | ADC             |
|  GPIO1 | XTAL_32K_N / ADC1_CH1                  | ADC             |
|  GPIO2 | LP UART / ADC1_CH2 / FSPIQ             | ADC / SPI       |
|  GPIO3 | LP UART / ADC1_CH3                     | ADC             |
|  GPIO4 | MTMS / LP UART RX / ADC1_CH4 / FSPIHD  | **Strapping**   |
|  GPIO5 | MTDI / LP UART TX / ADC1_CH5 / FSPIWP  | **Strapping**   |
|  GPIO6 | MTCK / LP I²C SDA / ADC1_CH6 / FSPICLK | ADC / I²C / SPI |
|  GPIO7 | MTDO / LP I²C SCL / FSPID              | I²C / SPI       |
|  GPIO8 | General GPIO                           | Digital         |
|  GPIO9 | General GPIO                           | Digital         |
| GPIO10 | General GPIO                           | Digital         |
| GPIO11 | General GPIO                           | Digital         |
| GPIO12 | USB_D-                                 | USB             |
| GPIO13 | USB_D+                                 | USB             |
| GPIO15 | General GPIO                           | Digital         |
| GPIO16 | UART0 TX / FSPICS0                     | UART / SPI      |
| GPIO17 | UART0 RX / FSPICS1                     | UART / SPI      |
| GPIO18 | SDIO_CMD / FSPICS2                     | SPI/SDIO        |
| GPIO19 | SDIO_CLK / FSPICS3                     | SPI/SDIO        |
| GPIO20 | SDIO_DATA0 / FSPICS4                   | SPI/SDIO        |
| GPIO21 | SDIO_DATA1 / FSPICS5                   | SPI/SDIO        |
| GPIO22 | SDIO_DATA2                             | Digital         |
| GPIO23 | SDIO_DATA3                             | Digital         |

---

# 📊 ADC

ESP32-C6 provides ADC capability across GPIO0–GPIO6.

```text
GPIO0 → ADC1_CH0
GPIO1 → ADC1_CH1
GPIO2 → ADC1_CH2
GPIO3 → ADC1_CH3
GPIO4 → ADC1_CH4
GPIO5 → ADC1_CH5
GPIO6 → ADC1_CH6
```

The ESP-IDF GPIO documentation confirms the ADC mapping and identifies GPIO4 and GPIO5 as strapping pins.

---

# ⚠️ Strapping Pins

ESP32-C6 has important boot/strapping considerations.

The current ESP-IDF GPIO documentation identifies:

```text
GPIO4
GPIO5
```

as strapping pins.

Therefore, if connecting:

* Buttons
* Relays
* Sensors
* External pull-ups
* External pull-downs

to these pins, make sure the connected hardware does not force an incorrect boot state.

---

# 🔄 SPI

ESP32-C6 provides flexible SPI routing.

Common functions include:

```text
GPIO2  → FSPIQ
GPIO4  → FSPIHD
GPIO5  → FSPIWP
GPIO6  → FSPICLK
GPIO16 → FSPICS0
GPIO17 → FSPICS1
GPIO18 → FSPICS2
GPIO19 → FSPICS3
GPIO20 → FSPICS4
GPIO21 → FSPICS5
```

The GPIO Matrix allows peripheral signals to be routed through configurable GPIOs.

---

# 📡 I²C

ESP32-C6 supports I²C and low-power I²C.

A useful low-power mapping is:

```text
GPIO6 → LP_I2C_SDA
GPIO7 → LP_I2C_SCL
```

This is different from the traditional ESP32-WROOM-32 default:

```text
GPIO21 → SDA
GPIO22 → SCL
```

Therefore, do not blindly copy pin assignments between ESP32 generations.

The C6-WROOM-1 datasheet specifically lists GPIO6 and GPIO7 with LP-I²C functions.

---

# 📶 UART

ESP32-C6-WROOM-1 exposes UART0 through:

```text
GPIO16 → U0TXD
GPIO17 → U0RXD
```

These pins can also be multiplexed with SPI chip-select functions.

---

# 🔌 USB

One of the major advantages of ESP32-C6 is its USB support.

```text
GPIO12 → USB_D-
GPIO13 → USB_D+
```

The USB Serial/JTAG controller can be used for:

* Serial communication
* JTAG debugging
* Development
* Firmware flashing
* Debugging without a separate USB-to-UART bridge

---

# 🔐 Security

ESP32-C6 provides hardware security capabilities suitable for connected devices.

These include:

```text
Secure Boot
Flash Encryption
AES
SHA
RSA
ECC
HMAC
True Random Number Generator
Digital Signature
```

---

# ⚡ Power

ESP32-C6-WROOM-1 operates from a 3.0–3.6 V supply, with 3.3 V being the typical operating voltage.

Module power pins:

```text
3V3 → Power
GND → Ground
EN  → Enable / Reset
```

### ⚠️ GPIO voltage

Do not directly connect 5 V logic to ESP32-C6 GPIO.

```text
5V logic ───── GPIO ❌

3.3V logic ─── GPIO ✅
```

Use level shifting when required.

---

# 🧩 GPIO Matrix

The ESP32-C6 uses a highly configurable GPIO Matrix.

```text
             SPI
              │
             I²C
              │
             UART
              │
             PWM
              │
             RMT
              │
              ▼
        ┌──────────────┐
        │  GPIO MATRIX  │
        └──────┬───────┘
               │
       ┌───────┼────────┐
       │       │        │
     GPIO6   GPIO16   GPIO23
```

This allows developers to design around PCB constraints instead of being forced into a rigid peripheral pin assignment.

---

# 🏠 Matter / Thread / Zigbee

The ESP32-C6 is particularly interesting for smart-home development.

```text
                    ESP32-C6
                       │
             ┌─────────┴─────────┐
             │                   │
          Wi-Fi 6             802.15.4
             │                   │
             │             ┌─────┴─────┐
             │           Thread     Zigbee
             │             │
             └─────────────┤
                           │
                         Matter
```

Potential applications:

* Smart switches
* Smart lighting
* Sensors
* Door/window sensors
* Home automation
* Thread border devices
* Matter endpoints

The C6-WROOM-1 datasheet lists Wi-Fi 6, Bluetooth LE, Zigbee 3.0, and Thread 1.3 support.

---

# 🛠️ Recommended GPIO Strategy

Before assigning a GPIO:

```text
Identify peripheral
        ↓
Check alternate functions
        ↓
Check strapping restrictions
        ↓
Check USB requirements
        ↓
Check SPI/flash usage
        ↓
Check ADC requirements
        ↓
Check voltage
        ↓
Assign GPIO
```

---

# 💡 Example IoT Node

```text
                       ESP32-C6
                           │
            ┌──────────────┼──────────────┐
            │              │              │
           ADC             I²C           USB
            │              │              │
        Sensor          OLED/IMU       Debugging
            │
            └──────────────┐
                           │
                        Wi-Fi 6
                           │
                         MQTT
                           │
                      Local Server
```

---

# 🚨 Common Mistakes

### ❌ Assuming WROOM-32 pins are identical

They are not.

For example:

```text
Original ESP32:
I²C commonly → GPIO21 / GPIO22

ESP32-C6:
LP I²C → GPIO6 / GPIO7
```

The peripheral system and GPIO mapping have changed between generations.

---

### ❌ Ignoring GPIO4/GPIO5

These are strapping pins on ESP32-C6.

---

### ❌ Treating USB pins as ordinary GPIO

GPIO12 and GPIO13 have USB D−/D+ alternate functions.

---

### ❌ Confusing SoC GPIO count with module GPIO count

The ESP32-C6 SoC provides **31 physical GPIOs (GPIO0–GPIO30)**, while the ESP32-C6-WROOM-1 module exposes **23 GPIOs**.

---

# 📚 Official References

* [ESP32-C6 Series Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf)
* [ESP32-C6-WROOM-1 Datasheet](https://documentation.espressif.com/esp32-c6-wroom-1_wroom-1u_datasheet_en.html)
* [ESP32-C6 GPIO Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c6/api-reference/peripherals/gpio.html)

---

# ⭐ Summary

ESP32-C6 is an excellent choice when a project needs:

```text
RISC-V
   +
Wi-Fi 6
   +
Bluetooth LE
   +
Thread
   +
Zigbee
   +
USB Serial/JTAG
   +
Low-power IoT
```

Its combination of Wi-Fi 6 and IEEE 802.15.4 makes it particularly valuable for modern smart-home, Matter, Thread, Zigbee, and low-power IoT systems.
