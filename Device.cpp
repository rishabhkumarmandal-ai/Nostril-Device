#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <Servo.h>

#define SERVO_LEFT_PIN 13
#define SERVO_RIGHT_PIN 12

Servo leftServo;
Servo rightServo;


#define SERVICE_UUID           "19b10010-e8f2-537e-4f6c-d104768a1214"
#define CHARACTERISTIC_UUID_TX "19b10011-e8f2-537e-4f6c-d104768a1214"

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Connected to app.");
  }

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("Disconnected from app.");
  }
};

class CommandCallback : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    std::string rxValue = pCharacteristic->getValue();
    if (rxValue.length() > 0) {
      Serial.print("Received command: ");
      Serial.println(rxValue.c_str());

      if (rxValue == "LEFT") {
        leftServo.write(90);   // Close left nostril
        rightServo.write(0);   // Open right nostril
      }
      else if (rxValue == "RIGHT") {
        rightServo.write(90);  // Close right nostril
        leftServo.write(0);    // Open left nostril
      }
      else if (rxValue == "OFF") {
        leftServo.write(0);
        rightServo.write(0);
      }
    }
  }
};

void setup() {
  Serial.begin(115200);
  
  // Servo setup
  leftServo.attach(SERVO_LEFT_PIN);
  rightServo.attach(SERVO_RIGHT_PIN);
  leftServo.write(0);
  rightServo.write(0);

  // BLE setup
  BLEDevice::init("NostrilActuatorESP32");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_WRITE
                    );

  pCharacteristic->setCallbacks(new CommandCallback());

  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->start();

  Serial.println("Waiting for app to connect...");
}

void loop() {
  // All handled via BLE callback
}
