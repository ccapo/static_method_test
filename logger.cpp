#include "main.hpp"

/* Logger Constructor */
Logger::Logger() {}

/* Logger Destructor */
Logger::~Logger() {}

/* Generic logging function */
void Logger::log(const char *tag, const char *message) {
  /* Create logging record, with tag and message content */
  std::cout << tag << ": " << message << std::endl;
}

/* Debug logging function */
void Logger::debug(const char *message) {
  Logger::log(DEBUG, message);
}

/* Info logging function */
void Logger::info(const char *message) {
  Logger::log(INFO, message);
}