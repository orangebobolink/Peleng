#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <ctime>

struct Event
{
	time_t timestamp;
	int eventId;
	int param1;
	int param2;
	int param3;
};

#endif
