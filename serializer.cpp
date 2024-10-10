#include "main.hpp"

Serializer::Serializer() {
  Module::logger.info("Serializer Initialization Complete");
}

Serializer::~Serializer() {}

void Serializer::serialize(sensor_msg_t *msg, uint8_t *data) {
  uint8_t *p = (uint8_t *)data;
  *p = msg->type;
  p++;

  float *q = (float *)p;
  *q = msg->bat_rpi;
  q++;
  *q = msg->bat_ard;
  q++;
}

void Serializer::deserialize(uint8_t *data, sensor_msg_t *msg) {
  // Extract message type
  uint8_t *p = (uint8_t *)data;
  msg->type = *p;
  p++;

  float *q = (float *)p;
  msg->bat_rpi = *q;
  q++;
  msg->bat_ard = *q;
  q++;
}

void Serializer::print(sensor_msg_t msg) {
  std::cout << "type        = 0x" << std::hex << static_cast<uint16_t>(msg.type) << std::dec << std::endl;
  std::cout << "bat_rpi     = " << msg.bat_rpi << std::endl;
  std::cout << "bat_ard     = " << msg.bat_ard << std::endl;
}