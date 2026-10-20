```cpp
// ==========================================
// RFID AUTOMATED ATTENDANCE & ACCESS SYSTEM
// RC522 SPI Reader & ESP Telemetry
// Developer: Aditya Kumar Gupta (aditya.geninfo.in)
// ==========================================

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN  4  // D2
#define RST_PIN 5  // D1
#define BUZZER  2  // Status Buzzer

MFRC522 rfid(SS_PIN, RST_PIN);

// Authorized Master UID Example
String authorizedUID = "A3 B4 C5 D6";

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
  
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  
  Serial.println("RFID Attendance System Initialized. Waiting for card...");
}

void loop() {
  // Look for new cards
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  // Read card UID
  String content = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(rfid.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  String scannedUID = content.substring(1);

  Serial.println("Scanned UID: " + scannedUID);

  if (scannedUID == authorizedUID) {
    Serial.println("Access Granted: Attendance Logged!");
    digitalWrite(BUZZER, HIGH); delay(200); digitalWrite(BUZZER, LOW);
  } else {
    Serial.println("Access Denied: Unrecognized Token!");
    digitalWrite(BUZZER, HIGH); delay(600); digitalWrite(BUZZER, LOW);
  }
  
  delay(1000);
}
