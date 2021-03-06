#pragma once
#include <string>
#include "RC.h"

class ILogger {
public:
	static ILogger* createLogger();
	static ILogger* createLogger(const std::string& filename);

	/*
	* @param [in] code Error code
	*
	* @param [in] scrfile File from where log() was called
	*
	* @param [in] line Number of line from where log() was called 
	*/
	virtual RC log(RC code, const std::string& srcfile, int line) = 0;
	virtual ~ILogger() = 0;

private:
	ILogger(const ILogger&);
	ILogger& operator=(const ILogger&);

protected:
	ILogger() = default;
};