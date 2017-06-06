#ifndef NOTICIA_H
#define NOTICIA_H

#include <string>

class Noticia
{
public:
	void setTitle(const char * title);
	void setDate(const char * date);
	std::string getTitle();
	std::string getDate();

private:
	unsigned int decodeMonth(const char *month);
	std::string date;
	std::string title;
};

#endif // !NOTICIA_H