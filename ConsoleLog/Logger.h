#ifndef LOGGER_H
#define LOGGER_H

#include "Event.h"
#include <fstream>

class Logger
{
protected:
	std::ofstream file;

	Logger(const char* fileName);
	virtual ~Logger();
public:
	static Logger* GetLogger(int level);
	virtual void Write(const Event& event) = 0;
};

class Level0Logger : public Logger
{
public:
	Level0Logger(const char* fileName);
	void Write(const Event& event) override;
};

class Level1Logger : public Logger
{
public:
	Level1Logger(const char* fileName);
	void Write(const Event& event) override;
};

class Level2Logger : public Logger
{
public:
	Level2Logger(const char* fileName);
	void Write(const Event& event) override;
};

#endif