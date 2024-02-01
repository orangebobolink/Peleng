#include <iostream>
#include <conio.h>
#include <functional>
#include "Logger.h"
#include <map>
#include <thread>
#include <ctime>

using namespace std;

using CommandHandler = std::function<void(const char*)>;

void eventGeneratorThread(Logger* logger, bool& generateEvents, int& eventCounter, int& eventInterval)
{
	while(true)
	{
		if(generateEvents)
		{
			Event event;
			event.timestamp = time(nullptr);
			event.eventId = rand();
			event.param1 = rand();
			event.param2 = rand();
			event.param3 = rand();

			logger->Write(event);

			eventCounter++;
			this_thread::sleep_for(chrono::milliseconds(eventInterval));
		}
		else
		{
			this_thread::sleep_for(chrono::milliseconds(100));
		}
	}
}

int main()
{
	bool generateEvents = true;
	int eventCounter = 0;
	int eventInterval = 1000;

	Logger* logger = Logger::GetLogger(0);

	thread eventGenerator([&] { eventGeneratorThread(logger, generateEvents, eventCounter, eventInterval); });

	map<string, CommandHandler> commandHandlers = {
		{"date", static_cast<CommandHandler>([](const char*) { cout << "Current date" << std::endl; })},
		{"time", static_cast<CommandHandler>([](const char*) { cout << "Current time" << std::endl; })},
		{"exit", static_cast<CommandHandler>([](const char*) { exit(0); })},
		{"faster", static_cast<CommandHandler>([&eventInterval](const char*) { eventInterval /= 2; })},
		{"slower", static_cast<CommandHandler>([&eventInterval](const char*) { eventInterval *= 2; })},
		{"pause", static_cast<CommandHandler>([&generateEvents](const char*) { generateEvents = false; })},
		{"resume", static_cast<CommandHandler>([&generateEvents](const char*) { generateEvents = true; })},
		{"level 0", static_cast<CommandHandler>([&logger](const char*) { logger = Logger::GetLogger(0); })},
		{"level 1", static_cast<CommandHandler>([&logger](const char*) { logger = Logger::GetLogger(1); })},
		{"level 2", static_cast<CommandHandler>([&logger](const char*) { logger = Logger::GetLogger(2); })},
		{"stat", static_cast<CommandHandler>([&eventCounter](const char*) { cout << "Events occurred: " << eventCounter << endl; })}
	};

	while(true)
	{
		string userInput;
		cin >> userInput;

		size_t firstNonSpace = userInput.find_first_not_of(" \t");

		if(firstNonSpace != string::npos)
		{
			userInput = userInput.substr(firstNonSpace);
		}

		size_t spacePos = userInput.find(' ');
		string command = (spacePos != string::npos) ? userInput.substr(0, spacePos) : userInput;
		const char* params = (spacePos != string::npos) ? userInput.c_str() + spacePos + 1 : nullptr;

		auto it = commandHandlers.find(command);

		if(it != commandHandlers.end())
		{
			it->second(params);
		}
		else
		{
			cerr << "Invalid command: " << command << endl;
		}
	}

	return 0;
}
