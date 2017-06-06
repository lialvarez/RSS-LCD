#ifndef TITULARES_H
#define TITULARES_H

#include "Noticia.h"
#include <string>
#include <list>
#include "State.h"

class Titulares
{
public:

	void startLocation(const char *name);
	void endLocation(const char *name);
	void push(const char *data);
	void addNew();
	State feedState;
	std::string getChannelTitle();

private:

	std::string channelTitle;
	std::list<Noticia> items;
	Noticia currentNew;

};

#endif // !TITULARES_H