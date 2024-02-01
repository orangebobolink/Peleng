#include "Logger.h"
#include <iostream>

Logger::Logger(const char* fileName)
{
	file.open(fileName, std::ios::app);
	if(!file.is_open())
	{
		std::cerr << "Fail to open " << fileName << std::endl;
	}
}

Logger::~Logger()
{
	if(file.is_open())
	{
		file.close();
	}
}

Logger* Logger::GetLogger(int level)
{
	const char* fileName = "loge.txt";
	switch(level)
	{
	case 0: return new Level0Logger(fileName);
	case 1: return new Level1Logger(fileName);
	case 2: return new Level2Logger(fileName);
	default:
		return nullptr;
	}
}