# 🏷️ IoT-Enabled RFID Automated Attendance & Access Control System

> A secure, contactless attendance logging and gate access system that reads unique UID tags via RFID, validates user credentials, and logs real-time attendance status to an online database.

[![Status](https://img.shields.io/badge/Status-Completed-emerald?style=for-the-badge)]()
[![MCU](https://img.shields.io/badge/MCU-NodeMCU_ESP8266_/_ESP32-blue?style=for-the-badge)]()

---

## 🎯 Overview & Mission Objective
Manual roll calls and traditional mechanical registers are inefficient. This system automates attendance tracking by requiring users to tap an RFID keychain or card. The microcontroller instantly scans the UID, cross-references authorized access, provides visual/audio feedback (LCD + Buzzer), and pushes the timestamped record over Wi-Fi.

---

## 🛠️ Bill of Materials (BOM)
| Component | Specification / Role |
| :--- | :--- |
| **NodeMCU ESP8266 / ESP32** | Wi-Fi microcontroller handling peripheral control & cloud HTTP requests |
| **RC522 RFID Reader Module** | 13.56MHz contactless electromagnetic reader |
| **RFID Cards / Keychains (Mifare)** | Unique UID transponder tokens |
| **1602 I2C LCD Display** | Visual feedback screen for user names and status |
| **Buzzer & LEDs** | Audio-visual feedback for granted (green/beep) or denied access |

---

## 📌 GPIO Pinout Mapping (SPI Interface)
| Component | Component Pin | ESP32 / ESP8266 Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **RC522 RFID** | `SDA (SS)` | `GPIO 4 (D2)` | SPI Slave Select |
| **RC522 RFID** | `SCK` | `GPIO 14 (D5)` | SPI Clock |
| **RC522 RFID** | `MOSI` | `GPIO 13 (D7)` | SPI Master Out Slave In |
| **RC522 RFID** | `MISO` | `GPIO 12 (D6)` | SPI Master In Slave Out |
| **RC522 RFID** | `RST` | `GPIO 5 (D1)` | Hardware Reset |
| **I2C LCD Display** | `SDA / SCL` | `GPIO 21 / 22` (ESP32) | Screen Telemetry Data |

---

## 📂 Repository Structure
```text
📂 rfid-attendance-system
├── 📂 firmware             <-- C++ source code (rfid_attendance.ino)
├── 📂 schematics           <-- SPI wiring and power connections
└── 📄 README.md            <-- Project documentation# rfid-attendance-system
Contactless IoT attendance and access control system using RC522 RFID, ESP32, and cloud logging.
