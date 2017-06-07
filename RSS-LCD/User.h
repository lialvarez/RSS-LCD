#ifndef USER_H
#define USER_H

#include "curses.h"

#define PLUS	43
#define MINUS	45

typedef enum { SPEED_UP, SPEED_DOWN, PREV, NEXT, REPEAT, QUIT, NO_EVENT }userEvents_t;

class User
{
public:
	User();
	~User();
	userEvents_t getEvent();
private:
	WINDOW *terminal;
};

#endif // !USER_H

