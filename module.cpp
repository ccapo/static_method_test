#include "main.hpp"

Module::Module() {}

Module::~Module() {}

static void sensorUpdate(bool &sensorReady) {
  sensorReady = !sensorReady;
}

// Declare static variables
sensor_msg_t Module::sensorMsg;
uint8_t Module::sensorPayload[PAYLOADSIZE] = {0};
Serializer Module::serializer;
Logger Module::logger;