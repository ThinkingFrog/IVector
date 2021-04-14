#pragma once
#include "RC.h"
#include "Interfacedllexport.h"

/*
* Defines for comfortable logging with information about caller
*/

/*
#define SendLog(Logger, Code, Level) Logger->log((Code), (Level), __FILE__, __func__, __LINE__)
#define SendSevere(Logger, Code) Logger->severe((Code), __FILE__, __func__, __LINE__)
#define SendWarning(Logger, Code) Logger->warning((Code), __FILE__, __func__, __LINE__)
#define SendInfo(Logger, Code) Logger->info((Code), __FILE__, __func__, __LINE__)
*/

class LIB_EXPORT ILogger {
public:
    enum class Level {
        SEVERE,   // Critical error that prevents application from running further
        WARNING, // Non-critical error
        INFO     // Optional information
    };

    /*
    * Create logger to log into standard output
    */
    static ILogger *createLogger();

    /*
    * @param [in] filename Name of file for log output
    *
    * @param [in] rewrite_if_exist Flag indicating if existing log file should be overwritten
    * True if you want to write over existing file (passed by default)
    * False if you want to append into existing file
    */
    static ILogger *createLogger(const char* const& filename, bool overwrite = true);

    /*
    * Logging is supposed to be implemented by receiving RC error code and writing corresponding string to output
    * 
    * It means that you have to store pre-defined {RC: string} pairs in any way
    * 
    * It's recommended to use std::map<RC, std::string> to call std::map::operator[] for easy string retrieval
    * 
    * @param [in] code Error code
    *
    * @param [in] level Level of threat, that caused logging
    *
    * @param [in] srcfile Name of file from where log() was called
    *
    * @param [in] function Name of function from where log() was called
    *
    * @param [in] line Number of line from where log() was called
    *
    */
    virtual RC log(RC code, Level level, const char* const& srcfile, const char* const& function, int line) = 0;

    /*
    * Same as log() but without information about caller
    */
    virtual RC log(RC code, Level level) = 0;

    /*
    * Same as log() but Level == SEVERE
    */
    virtual RC severe(RC code, const char* const& srcfile, const char* const& function, int line) {
        return log(code, Level::SEVERE, srcfile, function, line);
    };

    /*
    * Same as severe() but without information about caller
    */
    virtual RC severe(RC code) {
        return log(code, Level::SEVERE);
    };

    /*
    * Same as log() but Level == WARNING
    */
    virtual RC warning(RC code, const char* const& srcfile, const char* const& function, int line) {
        return log(code, Level::WARNING, srcfile, function, line);
    };

    /*
    * Same as warning() but without information about caller
    */
    virtual RC warning(RC code) {
        return log(code, Level::WARNING);
    };

    /*
    * Same as log() but Level == INFO
    */
    virtual RC info(RC code, const char* const& srcfile, const char* const& function, int line) {
        return log(code, Level::INFO, srcfile, function, line);
    };

    /*
    * Same as info() but without information about caller
    */
    virtual RC info(RC code) {
        return log(code, Level::INFO);
    };

    virtual ~ILogger() = 0;

private:
    ILogger(const ILogger &) = delete;
    ILogger &operator=(const ILogger &) = delete;

protected:
    ILogger() = default;
};