#pragma once
#include <string>
#include "RC.h"

class Logger {
public:
	static Logger* createLogger();
	static Logger* createLogger(const std::string& filename);

	/*
	* @param [in] code Error code
	*
	* @param [in] scrfile File from where log() was called
	*
	* @param [in] line Number of line from where log() was called 
	*/
	virtual RC log(RC code, const std::string& srcfile, int line) = 0;
	virtual ~Logger() = 0;

private:
	Logger(const Logger&);
	Logger& operator=(const Logger&);

protected:
	Logger() = default;
};