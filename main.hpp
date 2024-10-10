#pragma once

#include <iostream>
#include <type_traits>
#include "serializer.hpp"
#include "logger.hpp"
#include "module.hpp"

class Global {
  public:
  Global() {}
  ~Global() {}

  static const bool Debug = true;

  static const int Ok = 0;
  static const int Error = 1;

  static const int Major = 0;
  static const int Minor = 9;
  static const int Revision = 2;

  static const int MaxLength = 128;

  static const std::string I2CPath;

	static const int Microsecond = 1000000;
	static const int SensorDelay = Microsecond / 2;
	static const int ImageDelay = 100 * Microsecond;
	static const int BroadcastDelay = 9 * Microsecond / 100;
	static const int SpiTimeout = 150 * Microsecond;
	static const int MinDelay = 10;

	static const uint8_t Nul = 0x00;
	static const uint8_t Stx = 0x02;
	static const uint8_t Eot = 0x04;
	static const uint8_t Enq = 0x05;
	static const uint8_t Ack = 0x06;
	static const uint8_t Nak = 0x15;
	static const uint8_t Us = 0x1F;

	// Pressure-Altitude Coefficient
	static const constexpr double Alpha = 2.25577E-7;

	// Pressure-Altitude Exponent
	static const constexpr double Beta = 5.25588;

	// Inverse Pressure-Altitude Coefficient
	static const constexpr double AlphaInv = 1.0/Alpha;

	// Pressure-Altitude Exponent
	static const constexpr double BetaInv = 1.0/Beta;

	// Pressure at Sea Level [hPa]
	static const constexpr double P_0 = 1013.25;
};