#include "Titulares.h"
#include <boost\algorithm\string.hpp>

Titulares::Titulares()
{
	char tildea[3] = { 0xC3, 0xA1, '\0' };
	char tildee[3] = { 0xC3, 0xA9, '\0' };
	char tildei[3] = { 0xC3, 0xAD, '\0' };
	char tildeo[3] = { 0xC3, 0xB3, '\0' };
	char tildeu[3] = { 0xC3, 0xBA, '\0' };
	char enie[3] = { 0xC3, 0xB1, '\0' };
	char tildeA[3] = { 0xC3, 0x81, '\0' };
	char tildeE[3] = { 0xC3, 0x89, '\0' };
	char tildeI[3] = { 0xC3, 0x8D, '\0' };
	char tildeO[3] = { 0xC3, 0x93, '\0' };
	char tildeU[3] = { 0xC3, 0x9A, '\0' };
	char ENIE[3] = { 0xC3, 0x91, '\0' };
	char openExclamation[3] = { 0xC2, 0xA1, '\0' };
	char openQuestion[3] = { 0xC2, 0xBF, '\0' };
	replace.push_back(std::make_pair(std::string(tildea), "a"));
	replace.push_back(std::make_pair(std::string(tildeA), "A"));
	replace.push_back(std::make_pair(std::string(tildee), "e"));
	replace.push_back(std::make_pair(std::string(tildeE), "E"));
	replace.push_back(std::make_pair(std::string(tildei), "i"));
	replace.push_back(std::make_pair(std::string(tildeI), "I"));
	replace.push_back(std::make_pair(std::string(tildeo), "o"));
	replace.push_back(std::make_pair(std::string(tildeO), "O"));
	replace.push_back(std::make_pair(std::string(tildeu), "u"));
	replace.push_back(std::make_pair(std::string(tildeU), "U"));
	replace.push_back(std::make_pair(std::string(enie), "n"));
	replace.push_back(std::make_pair(std::string(ENIE), "N"));
	replace.push_back(std::make_pair(std::string(openExclamation), ""));
	replace.push_back(std::make_pair(std::string(openQuestion), ""));
}

void Titulares::startLocation(const char *name)
{
	feedState.ev = feedState.eventGenerator(name, START);
	feedState.FSM.dispatch(feedState.ev, this);
}

void Titulares::endLocation(const char *name)
{
	feedState.ev = feedState.eventGenerator(name, END);
	feedState.FSM.dispatch(feedState.ev, this);
}

void Titulares::push(const char *data)
{
	std::string aux(data);
	for (std::vector<std::pair<std::string, std::string>>::iterator it = replace.begin(); it != replace.end(); it++)
	{
		boost::replace_all(aux, it->first, it->second);
	}
	switch (feedState.FSM.getCurrentState()->currentStateCode)
	{
	case CH_TITLE:
		channelTitle = aux;
		currentNew.setSource(channelTitle.c_str());
		break;
	case ITEM_TITLE:
		currentNew.setTitle(aux.c_str());
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