#ifndef TITULARES_H
#define TITULARES_H

#include "Noticia.h"
#include "State.h"
#include <string>
#include <list>
#include <utility>
#include <vector>

class Titulares
{
public:

	Titulares();
	void startLocation(const char *name);
	void endLocation(const char *name);
	void push(const char *data);
	void addNew();
	State feedState;
	std::string getChannelTitle();
	std::list<Noticia> items;
private:

	std::vector<std::pair<std::string, std::string>> replace;
	std::string channelTitle;
	Noticia currentNew;

};

#endif // !TITULARES_H