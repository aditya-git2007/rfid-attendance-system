# RFID Attendance System — SPI Wiring Specification

## ⚡ Hardware Connections
* **SPI Bus Communication:** The RC522 communicates via high-speed SPI. Ensure shared clock (`SCK`), master-out (`MOSI`), and master-in (`MISO`) lines are connected directly to the microcontroller.
* **Power Regulation:** The RC522 module operates strictly on **3.3V**. Connecting it to a 5V pin will permanently damage the onboard transceiver IC.
