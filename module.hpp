#pragma once

#include "serializer.hpp"
#include "logger.hpp"

#define PAYLOADSIZE (16)

class Module {
public:
	/* Module Constructor */
	Module();

	/* Module Destructor */
	~Module();

	/* Module Sensor Update */
	static void sensorUpdate(bool &sensorReady);

  // Static Variables
  static sensor_msg_t sensorMsg;
  static uint8_t sensorPayload[PAYLOADSIZE];
  static Serializer serializer;
  static Logger logger;

  static const constexpr float mag_offsets[3] = { 0.93F, -7.47F, -35.23F };
};