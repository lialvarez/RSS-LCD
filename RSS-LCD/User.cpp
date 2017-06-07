#include "User.h"



User::User():terminal(NULL)
{
	terminal = initscr();
	nodelay(terminal, TRUE);
	noecho();
}

User::~User()
{
	delwin(terminal);
}

userEvents_t User::getEvent()
{
	userEvents_t ret;
	char c = getch();
	c = towlower(c);
	switch (c)
	{
	case PLUS:
		ret = SPEED_UP;
		break;
	case MINUS:
		ret = SPEED_DOWN;
		break;
	case 'a':
		ret = PREV;
		break;
	case 's':
		ret = NEXT;
		break;
	case 'r':
		ret = REPEAT;
		break;
	case 'q':
		ret = QUIT;
		break;
	default:
		ret = NO_EVENT;
		break;
	}
	return ret;
}