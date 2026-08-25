# 🧠 ESP32 Architecture

> A developer-oriented guide to understanding how the ESP32 works internally — from CPU and memory to GPIO, peripherals, wireless communication, FreeRTOS, and boot.

---

## 📖 Table of Contents

- [Introduction](#-introduction)
- [What is an ESP32?](#-what-is-an-esp32)
- [High-Level Architecture](#-high-level-architecture)
- [CPU Architecture](#-cpu-architecture)
- [Memory Architecture](#-memory-architecture)
- [GPIO Architecture](#-gpio-architecture)
- [Peripheral System](#-peripheral-system)
- [Wireless Architecture](#-wireless-architecture)
- [Interrupt System](#-interrupt-system)
- [DMA](#-dma)
- [Timers](#-timers)
- [FreeRTOS](#-freertos)
- [Boot Process](#-boot-process)
- [Power Management](#-power-management)
- [Data Flow](#-data-flow)
- [ESP32 Architecture vs Microcontroller](#-esp32-architecture-vs-traditional-microcontroller)
- [Developer Mental Model](#-developer-mental-model)
- [Summary](#-summary)

---

# 🚀 Introduction

The ESP32 is more than a microcontroller with Wi-Fi.

It is a complete embedded computing platform containing:

- CPU
- SRAM
- ROM
- External Flash interface
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
- Wireless connectivity
- Hardware security
- DMA
- Interrupt controllers
- Low-power subsystems
- Real-time operating system support

A simplified view is:

```text
                         ESP32
                           │
       ┌───────────────────┼───────────────────┐
       │                   │                   │
      CPU                Memory             Wireless
       │                   │                   │
   ┌───┴───┐          ┌────┴────┐        ┌─────┴─────┐
   │       │          │         │        │           │
 Core 0  Core 1      SRAM      Flash    Wi-Fi      BLE
   │
   │
   └───────────────┐
                   │
              Interconnect
                   │
       ┌───────────┼────────────┐
       │           │            │
     GPIO      Peripherals    DMA
       │           │
       │     ┌─────┼──────────────┐
       │     │     │      │       │
      ADC   SPI   I²C   UART    PWM