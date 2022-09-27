#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "Arduino.h"
#include "device.h"

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID        "42345abf-5fff-45b0-871d-c172bb9c7254"
#define CHARACTERISTIC_UUID "ba67715d-bc14-4874-bf16-bdde2c303b3d"

DeviceType ClayConnectDeviceType = static_cast<DeviceType>(0);

void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE work!");

    BLEDevice::init("Long name works now");
    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);
    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
            CHARACTERISTIC_UUID,
            BLECharacteristic::PROPERTY_READ
    );

    pCharacteristic->setValue(&"ClayConnect " [ ClayConnectDeviceType]);
    pService->start();
    // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
    Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
    delay(2000);
}