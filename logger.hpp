#pragma once

#include <iostream>

/* Logging Tags */
#define DEBUG   "[debug]"
#define INFO    "[info]"
#define NOTICE  "[notice]"
#define ALERT   "[alert]"
#define WARNING "[warning]"
#define ERROR   "[error]"

/**
 * Logger Class
 */
class Logger {
public:
	/* Logger Constructor */
	Logger();

	/* Logger Destructor */
	~Logger();

	/* Generic logging function */
	void log(const char *tag, const char *message);

	/* Debug logging function */
	void debug(const char *message);

	/* Info logging function */
	void info(const char *message);
};