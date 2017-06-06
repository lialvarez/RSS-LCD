#ifndef STATE_H
#define STATE_H

#include "genericFSM.h"

typedef enum { START, END, DATA }inputTypes;

class State
{
public:
	State();
	genericEvent * eventGenerator(const char *name, inputTypes type);
	genericEvent * ev;
	genericFSM FSM;
private:
	
};

#endif // !STATE_H