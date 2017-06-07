#include "State.h"
#include "Events.h"
#include <string>

State::State()
{
}

genericEvent* State::eventGenerator(const char *name, inputTypes types)
{
	genericEvent *ret = nullptr;
	switch (types)
	{
	case START:
		if (strcmp(name, "channel") == 0) 
		{
			ret = new EV_ChannelStartTag;
		}
		else if (strcmp(name, "title") == 0)
		{
			ret = new EV_TitleStartTag;
		}
		else if (strcmp(name, "item") == 0)
		{
			ret = new EV_ItemStartTag;
		}
		else if (strcmp(name, "pubDate") == 0)
		{
			ret = new EV_DateStartTag;
		}
		else
		{
			ret = new EV_NoEv;
		}
		break;
	case END:
		if (strcmp(name, "channel") == 0)
		{
			ret = new EV_ChannelEndTag;
		}
		else if (strcmp(name, "title") == 0)
		{
			ret = new EV_TitleEndTag;
		}
		else if (strcmp(name, "item") == 0)
		{
			ret = new EV_ItemEndTag;
		}
		else if (strcmp(name, "pubDate") == 0)
		{
			ret = new EV_DateEndTag;
		}
		else
		{
			ret = new EV_NoEv;
		}
		break;
	default:
		break;
	}
	return ret;
}





