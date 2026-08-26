# 🧠 ESP32 Architecture

> A developer-oriented guide to understanding how the ESP32 ecosystem works internally — from CPU and memory to GPIO, peripherals, wireless communication, interrupts, DMA, FreeRTOS, boot, and power management.

---

## 📖 Table of Contents

- [Introduction](#-introduction)
- [What is an ESP32?](#-what-is-an-esp32)
- [ESP32 Architecture Overview](#-esp32-architecture-overview)
- [SoC Architecture](#-soc-architecture)
- [CPU Architecture](#-cpu-architecture)
- [Memory Architecture](#-memory-architecture)
- [System Interconnect](#-system-interconnect)
- [GPIO Architecture](#-gpio-architecture)
- [Peripheral System](#-peripheral-system)
- [Wireless Architecture](#-wireless-architecture)
- [Interrupt System](#-interrupt-system)
- [DMA](#-dma)
- [Timers](#-timers)
- [FreeRTOS](#-freertos)
- [Boot Process](#-boot-process)
- [Security Architecture](#-security-architecture)
- [Power Management](#-power-management)
- [Data Flow](#-data-flow)
- [ESP32 Software Architecture](#-esp32-software-architecture)
- [ESP-IDF Architecture](#-esp-idf-architecture)
- [Arduino vs ESP-IDF](#-arduino-vs-esp-idf)
- [ESP32 vs Traditional Microcontrollers](#-esp32-vs-traditional-microcontrollers)
- [Developer Mental Model](#-developer-mental-model)
- [Architecture by ESP32 Family](#-architecture-by-esp32-family)
- [Summary](#-summary)

---

# 🚀 Introduction

The ESP32 is more than a microcontroller with Wi-Fi.

It is a family of **System-on-Chips (SoCs)** designed for embedded computing, wireless communication, IoT, automation, AI, multimedia, and low-power applications.

Depending on the ESP32 variant, the chip may contain:

- CPU
- SRAM
- ROM
- Flash interface
- PSRAM interface
- GPIO
- ADC
- DAC on supported variants
- PWM
- Timers
- SPI
- I²C
- UART
- I²S
- USB on supported variants
- Wi-Fi
- Bluetooth / BLE
- IEEE 802.15.4 on supported variants
- Camera interfaces on supported variants
- Display interfaces on supported variants
- DMA
- Interrupt controllers
- Hardware cryptography
- Secure boot
- Flash encryption
- Low-power subsystem

> ⚠️ **Important:** Not every ESP32 chip contains every peripheral or wireless technology.

For example:

```text
ESP32
    │
    ├── Wi-Fi
    ├── Bluetooth Classic
    └── BLE

ESP32-C6
    │
    ├── Wi-Fi 6
    ├── BLE
    └── IEEE 802.15.4

ESP32-H2
    │
    ├── BLE
    ├── Thread
    └── Zigbee

ESP32-P4
    │
    ├── High-performance processing
    ├── AI
    ├── Camera
    └── Display