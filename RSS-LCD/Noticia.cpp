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

std::string Noticia::getSource()
{
	return source;
}



void Noticia::setDate(const char * date)
{
	this->date = changeDateFormat(date);
}

void Noticia::setTitle(const char * title)
{
	this->title = std::string(title);
}

void Noticia::setSource(const char * source)
{
	this->source = std::string(source);
}

std::string Noticia::changeDateFormat(std::string fecha_inicial)
{
	std::string dia = fecha_inicial.substr(fecha_inicial.find_first_of(", ") + 2, 2);
	std::string mes = fecha_inicial.substr(fecha_inicial.find_first_of(", ") + 5, 3);
	std::string año = fecha_inicial.substr(fecha_inicial.find_first_of(", ") + 11, 2);
	std::string hora = fecha_inicial.substr(fecha_inicial.find_first_of(", ") + 14, 5);
	std::string nueva_fecha;

	std::map<std::string, std::string>meses = {
		{ "Jan","01" },
		{ "Feb","02" },
		{ "Mar","03" },
		{ "Apr","04" },
		{ "May","05" },
		{ "Jun","06" },
		{ "Jul","07" },
		{ "Aug","08" },
		{ "Sep","09" },
		{ "Oct","10" },
		{ "Nov","11" },
		{ "Dec","12" }
	};

	nueva_fecha = dia + "/" + meses.find(mes)->second + "/" + año + " - " + hora;

	return nueva_fecha;
}