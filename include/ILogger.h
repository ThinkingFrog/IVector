#pragma once
#include <string>
#include "RC.h"

/*
* Defines for comfortable logging with information about caller
*/
#define SendLog(Logger, Code, Level) Logger->log((Code), (Level), __FILE__, __func__, __LINE__)
#define SendSever(Logger, Code) Logger->sever((Code), __FILE__, __func__, __LINE__)
#define SendWarning(Logger, Code) Logger->warning((Code), __FILE__, __func__, __LINE__)
#define SendInfo(Logger, Code) Logger->info((Code), __FILE__, __func__, __LINE__)

class ILogger {
public:
	enum class Level {
		SEVER,// maximum threat
		WARNING,// this guy is usually ignored
		INFO// just thought you want to know
	};

public:
	/*
	* Create logger, to log into standard output
	*/
	static ILogger* createLogger();

	/*
	* @param [in] filename Name of file for log output
	*
	* @param [in] rewrite_if_exist True if you want to write over existing file (passed by default)
	* False if you want to append into existing file
	*/
	static ILogger* createLogger(const std::string& filename, bool rewrite_if_exist = true);

	/*
	* @param [in] code Error code
	*
	* @param [in] srcfile File from where log() was called
	*
	* @param [in] line Number of line from where log() was called
	*
	* @param [in] function Function from where log() was called
	*
	* @param [in] level Level of threat, that caused logging
	*/
	virtual RC log(RC code, Level level, const std::string& srcfile, const std::string& function, int line) = 0;

	/*
	* Same as log() but without information about caller
	*/
	virtual RC log(RC code, Level level) = 0;

	/*
	* Same as log() but Level == SEVER
	*/
	virtual RC sever(RC code, const std::string& srcfile, const std::string& function, int line) = 0;

	/*
	* Same as sever() but without information about caller
	*/
	virtual RC sever(RC code) = 0;

	/*
	* Same as log() but Level == WARNING
	*/
	virtual RC warning(RC code, const std::string& srcfile, const std::string& function, int line) = 0;

	/*
	* Same as warning() but without information about caller
	*/
	virtual RC warning(RC code) = 0;

	/*
	* Same as log() but Level == INFO
	*/
	virtual RC info(RC code, const std::string& srcfile, const std::string& function, int line) = 0;

	/*
	* Same as info() but without information about caller
	*/
	virtual RC info(RC code) = 0;

	virtual ~ILogger() = 0;

private:
	ILogger(const ILogger&);
	ILogger& operator=(const ILogger&);

protected:
	ILogger() = default;
};