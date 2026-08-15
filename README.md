<div align="center">

# The ESP32 Developer Handbook 🧠💻

**Maintained by [Abhay Haswani]**

> *From cube turns to code lines.*

</div>

<br>

The ESP32 is no longer just a single microcontroller; it is a massive silicon ecosystem...




## 1. The Silicon: Choosing the Right ESP32
Using an ESP32-S3 for a simple battery-powered sensor is overkill, while trying to run a camera project on an ESP32-C3 is a dead end. Here is the modern breakdown:

| Chip Family | Architecture | Key Feature | Best For |
| :--- | :--- | :--- | :--- |
| **ESP32 (Classic)** | Xtensa Dual-Core (240 MHz) | Bluetooth Classic & BLE | Legacy projects, audio streaming. |
| **ESP32-S2** | Xtensa Single-Core | Native USB-OTG | USB devices, ultra-low deep sleep. |
| **ESP32-S3** | Xtensa Dual-Core | AI Vector Acceleration | Edge AI, machine vision, voice recognition. |
| **ESP32-C3** | RISC-V Single-Core | Ultra-Low Power & Cost | Simple IoT nodes, battery-powered sensors. |
| **ESP32-C6** | RISC-V Single-Core | Wi-Fi 6, Zigbee, Thread | Smart Home, Matter-compatible devices. |
| **ESP32-H2** | RISC-V Single-Core | No Wi-Fi (Zigbee/Thread only)| Mesh networks, low-power nodes. |
| **ESP32-P4** | RISC-V Dual-Core (400 MHz) | Hardware H.264 (No Wireless)| Multimedia, fluid HMI displays. |

---

## 2. The Frameworks: Writing the Code
Which environment should you use?

*   **Arduino Core:** Best for rapid prototyping, hardware testing, and leveraging massive community libraries. 
*   **ESP-IDF (Espressif IoT Development Framework):** The gold standard for production. Uses FreeRTOS for complex multitasking, fine-grained memory management, and secure boot.
*   **MicroPython / CircuitPython:** Best for educational tools, rapid data processing, and simple scripts without compilation delays.

---

## 3. Edge Use Cases & Code Templates
This repository contains standalone code templates for advanced edge computing scenarios. Navigate to the respective folders for source code and wiring diagrams.

*   📂 `/local-web-server`: Serve an interactive UI to a tablet via SoftAP without cloud dependencies.
*   📂 `/ble-hid-controller`: Map custom physical matrices (like Rubik's cubes) to Bluetooth keyboard strokes.
*   📂 `/wearable-optics`: Lightweight I2C/SPI display drivers for AR/smart glasses.
*   📂 `/edge-ai-vision`: Basic object classification using the ESP32-S3's vector instructions.

---

## 👨‍💻 About the Author

**[Abhay Haswani]** | *From cube turns to code lines.*

I specialize in hardware-software integration, focusing on building systems that bridge the physical and digital worlds. My work revolves around turning complex mechanical interactions into seamless digital inputs, and pushing the limits of what microcontrollers can do at the edge. 

This repository is a curated collection of the architectures, frameworks, and use cases I've explored—ranging from mapping non-traditional physical controllers to Bluetooth HID, to developing local-first server environments.

*   **GitHub:** [User-4162686179](https://github.com/User-4162686179)
*   **LinkedIn:** [Abhay Haswani](https://linkedin.com/in/abhay-haswani-235493254)


---