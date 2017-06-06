#ifndef HANDLERS_H
#define HANDLERS_H

#include "expat.h"

XML_StartElementHandler startCallback;
XML_EndElementHandler endCallback;
XML_CharacterDataHandler dataCallback;

#endif // !HANDLERS_H
