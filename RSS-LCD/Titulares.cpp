#include "Titulares.h"

void Titulares::startLocation(const char *name)
{
	feedState.ev = feedState.eventGenerator(name, START);
}

void Titulares::endLocation(const char *name)
{
	feedState.ev = feedState.eventGenerator(name, END);
}

void Titulares::push(const char *data)
{
	switch (feedState.FSM.getCurrentState()->getCurrentStateCode())
	{
	case CH_TITLE:
		channelTitle = std::string(data);
		break;
	case ITEM_TITLE:
		currentNew.setTitle(data);
		break;
	case ITEM_DATE:
		currentNew.setDate(data);
		break;
	default:
		break;
	}
}

void Titulares::addNew()
{
	items.push_back(currentNew);
}

std::string Titulares::getChannelTitle()
{
	return channelTitle;
}