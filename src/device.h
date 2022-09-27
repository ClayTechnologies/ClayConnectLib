#pragma once

#include <Arduino.h>

#ifndef FIRMWARE_DEVICE_TYPES_H
#define FIRMWARE_DEVICE_TYPES_H

#endif //FIRMWARE_DEVICE_TYPES_H

class Device {
private:
    int type;
    String repo;
    int id;

public:
    explicit Device(int type, int id);
    explicit Device(int type, String repo, int id);

    int getType() const { return type; }
    String getRepo() const { return repo; }
    int getId() const { return id; }
};
