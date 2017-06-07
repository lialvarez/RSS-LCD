//#include "Handlers.h"
//#include <expat.h>
//#include <expat.h>
//#include "Titulares.h"
//
//static void XMLCALL
//startElementHandler(void *userData, const XML_Char *name, const char **atts)
//{
//	Titulares * myData = (Titulares *)userData;
//	myData->startLocation((char *)name);
//}
//
//static void XMLCALL
//endElementHandler(void *userData, const XML_Char *name)
//{
//	Titulares * myData = (Titulares *)userData;
//	myData->endLocation((char *)name);
//}
//
//static void XMLCALL
//characterDataHandler(void *userData, const XML_Char *s, int len)
//{
//	Titulares * myData = (Titulares *)userData;
//	std::string aux = std::string((const char *)s, (rsize_t)len);
//	if (len > 1)
//	{
//		myData->push(aux.c_str());
//	}
//}