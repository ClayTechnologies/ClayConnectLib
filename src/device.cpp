#include "device.h"

Device::Device(int type, int id) {
    this->type = type;
    this->id = id;
};

Device::Device(int type, String repo, int id) {
    this->type = type;
    this->repo = repo;
    this->id = id;
};