#include "main.hpp"

const std::string Global::I2CPath = "/dev/i2c-1";

int main() {
	Module::logger.info("Starting...");

  if (Global::Debug) {
    std::cout << std::boolalpha << "Debug = " << Global::Debug << '\n';
    std::cout << "Microsecond    = " << Global::Microsecond << '\n';
    std::cout << "SensorDelay    = " << Global::SensorDelay << '\n';
    std::cout << "BroadcastDelay = " << Global::BroadcastDelay << '\n';
    std::cout << "NAK            = 0x" << std::hex << static_cast<uint16_t>(Global::Nak) << std::dec << std::endl;
    std::cout << "Alpha          = " << Global::Alpha << std::endl;
    std::cout << "AlphaInv       = " << Global::AlphaInv << std::endl;
    std::cout << Module::mag_offsets[0] << '\n';
    std::cout << Module::mag_offsets[1] << '\n';
    std::cout << Module::mag_offsets[2] << '\n';
  }

	sensor_msg_t tmpMsg;

	Module::sensorMsg.type = 0x80;
	Module::sensorMsg.bat_rpi = 8.73067;
	Module::sensorMsg.bat_ard = 7.97521;

	Module::serializer.print(Module::sensorMsg);

	Module::serializer.serialize(&Module::sensorMsg, Module::sensorPayload);

	std::cout << "sensorPayload = ";
	for (uint8_t i = 0; i < SENSORSIZE; i++) {
		std::cout << "0x" << std::hex << static_cast<uint16_t>(Module::sensorPayload[i]) << ",";
	}
	std::cout << std::dec << std::endl;

	Module::serializer.deserialize(Module::sensorPayload, &tmpMsg);

	Module::serializer.print(tmpMsg);

	Module::logger.info("Stopping...");
}