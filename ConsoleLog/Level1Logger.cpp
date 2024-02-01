#include "Logger.h"
#include <iomanip>

Level1Logger::Level1Logger(const char* fileName) : Logger(fileName) {}

void Level1Logger::Write(const Event& event)
{
	std::tm timeInfo;

	file << "level 0" << std::endl;
	file << "Event ID: " << event.eventId << std::endl;
	file << "Time: " << std::put_time(&timeInfo, "%Y-%m-%d %X") << std::endl;
	file << std::endl;
}