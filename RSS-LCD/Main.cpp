#include "expat.h"
#include "Handlers.h"

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		XML_Parser Parser = XML_Parser(NULL);
		XML_SetStartElementHandler(Parser, )
	}
	// Parsear el document(FSM)
	// (Los Callbacks se encargan de guardar las noticias)

	// Mostrar las noticias
	// (Permitir eventos de usuario)
}