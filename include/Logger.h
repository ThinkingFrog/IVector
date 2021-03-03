#prgama once
#include <string>

class Logger {
public:
	static Logger *createLogger(std::string filename);

	virtual RC log(std::string message) = 0;
	virtual ~Logger() = 0;

private:
	Logger(const Logger &);
	Logger &operator=(const Logger&);

protected:
	Logger() = default;
};

