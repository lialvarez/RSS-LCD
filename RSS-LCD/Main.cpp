#include <expat.h>
#include "Titulares.h"
#include "Handlers.h"
#include "FileSystem.h"
#include "HitachiLCD.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <chrono>
#include <thread>
#include "curses.h"
#include "User.h"


#define EXPECTED_ARGS	2

static void XMLCALL
startElementHandler(void *userData, const XML_Char *name, const char **atts);

static void XMLCALL
endElementHandler(void *userData, const XML_Char *name);

static void XMLCALL
characterDataHandler(void *userData, const XML_Char *s, int len);

int main(int argc, char **argv)
{

	if (argc < EXPECTED_ARGS)
	{
		std::cout << "Error de forma, revise los argumentos ingresados" << std::endl;
		std::cout << "Presione una tecla para salir..." << std::endl;
		getchar();
		return -1;
	}
	std::list<Titulares *>news;


	std::list<std::pair<char *, unsigned int>> buffList;
	FileSystem fileSyst;
	for (int i = 1; i < argc; i++)
	{
		if (!fileSyst.loadFileToList(argv[i], buffList))
		{
			std::cout << "Error al leer archivo " + std::string(argv[i]) << std::endl;
			std::cout << "Presione una tecla para salir..." << std::endl;
			getchar();
			return -1;
		}
	}

	while (!buffList.empty())
	{
		Titulares * newTitular = new Titulares;

		XML_Parser Parser = XML_ParserCreate(NULL);
		XML_SetStartElementHandler(Parser, startElementHandler);
		XML_SetEndElementHandler(Parser, endElementHandler);
		XML_SetCharacterDataHandler(Parser, characterDataHandler);
		XML_SetUserData(Parser, newTitular);

		if (XML_Parse(Parser, buffList.back().first, buffList.back().second, 1) == XML_STATUS_OK)
		{
			news.push_back(newTitular);
		}
		else
		{
			delete newTitular;
		}
		buffList.pop_back();
	}

	std::vector<Noticia> selectedNews;
	for (std::list<Titulares *>::iterator it1 = news.begin(); it1 != news.end(); it1++)
	{
		for (std::list<Noticia>::iterator it2 = (*it1)->items.begin(); it2 != (*it1)->items.end(); it2++)
		{
			selectedNews.push_back(*it2);
		}
	}

	HitachiLCD myLCD;
	myLCD.lcdInit(1);
	if (!myLCD.lcdInitOk())
	{
		std::cout << "Error al incializar el display" << std::endl;
		std::cout << "Presione una tecla para salir..." << std::endl;
		getchar();
		return -1;
	}

	User usr;
	userEvents_t ev;
	std::vector<Noticia>::iterator newsIterator = selectedNews.begin();
	unsigned int delay = 0;
	std::string spaces = "               ";
	std::string aux = spaces + newsIterator->getSource() + ": " + newsIterator->getTitle() + " ";
	std::string date = newsIterator->getDate();
	do
	{
		ev = usr.getEvent();
		switch (ev)
		{
		case SPEED_UP:
			if (delay >= 50)
			{
				delay -= 50;
			}
			break;
		case SPEED_DOWN:
			if (delay < 500)
			{
				delay += 50;
			}
			break;
		case PREV:
			
			if (newsIterator != selectedNews.begin())
			{
				newsIterator--;
				aux = spaces + newsIterator->getSource() + ": " + newsIterator->getTitle() + " ";
				date = newsIterator->getDate();
			}
			break;
		case NEXT:
			if (newsIterator + 1 != selectedNews.end())
			{
				newsIterator++;
				aux = spaces + newsIterator->getSource() + ": " + newsIterator->getTitle() + " ";
				date = newsIterator->getDate();
			}
			break;
		case REPEAT:
			aux = spaces + newsIterator->getSource() + ": " + newsIterator->getTitle() + " ";
			break;
		case NO_EVENT:
			if (aux.length() > 0)
			{
				aux = aux.substr(1);
			}
			break;
		default:
			break;
		}

		myLCD.lcdPrintFront(date.c_str(), 1);
		myLCD.lcdPrintFront(aux.c_str(), 2);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));

	} while (ev != QUIT);

	myLCD.lcdClear();
	return 0;
}

static void XMLCALL
startElementHandler(void *userData, const XML_Char *name, const char **atts)
{
	Titulares * myData = (Titulares *)userData;
	myData->startLocation((char *)name);
}

static void XMLCALL
endElementHandler(void *userData, const XML_Char *name)
{
	Titulares * myData = (Titulares *)userData;
	myData->endLocation((char *)name);
}

static void XMLCALL
characterDataHandler(void *userData, const XML_Char *s, int len)
{
	Titulares * myData = (Titulares *)userData;
	std::string aux = std::string((const char *)s, (rsize_t)len);
	if (len > 1)
	{
		myData->push(aux.c_str());
	}
}