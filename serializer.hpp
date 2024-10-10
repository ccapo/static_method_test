#pragma once

#include <iostream>

#define SENSORSIZE (9)

// Sensor message
struct sensor_msg_t {
  // Message Type
  uint8_t type;
  
  // Battery Data
  float bat_rpi, bat_ard;
};

class Serializer {
  public:
  // Constructor
  Serializer();
  
  // Destructor
  ~Serializer();

  /* Serialize Sensor Message */
  void serialize(sensor_msg_t *msg, uint8_t *data);
  
  // Deserialize Sensor Message
  void deserialize(uint8_t *data, sensor_msg_t *msg);
  
  // Print Sensor Message
  void print(sensor_msg_t msg);
};

