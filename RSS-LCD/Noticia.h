#ifndef NOTICIA_H
#define NOTICIA_H

#include <string>

class Noticia
{
public:
	void setTitle(const char * title);
	void setDate(const char * date);
	void setSource(const char * source);
	std::string getTitle();
	std::string getDate();
	std::string getSource();

private:
	std::string changeDateFormat(std::string fecha_inicial);
	std::string date;
	std::string title;
	std::string source;
};

#endif // !NOTICIA_H