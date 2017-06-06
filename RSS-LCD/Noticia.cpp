#include "Noticia.h"

#include <ctime>
#include <map>

std::string Noticia::getDate()
{
	return date;
}

std::string Noticia::getTitle()
{
	return title;
}

void Noticia::setDate(const char * date)
{
	//Ver conversion de formato
	
	std::string aux(date);
	this->date = aux.substr(aux.find_first_of(", "), aux.find_first_of(", " + 2));
}

void Noticia::setTitle(const char * date)
{
	this->date = std::string(date);
}

unsigned int decodeMonth(const char month)
{
	std::map<std::string, unsigned int> meses
	{
		{"Jan", 1},
		{"Feb", 2},
		{"Mar", 3},
		{"Apr", 4},
		{"May", 5},
		{"Jun", 6},
		{"Jul", 7},
		{"Ago", 8},

	}
}