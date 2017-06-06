#ifndef GENERICEVENT_H
#define GENERICEVENT_H

#include <string>

typedef enum { NO_EV, CH_TAG_S, TITLE_TAG_S, ITEM_TAG_S, DATE_TAG_S, OTHER_TAG_S, CH_TAG_E, TITLE_TAG_E, ITEM_TAG_E, DATE_TAG_E, OTHER_TAG_E }eventsCode_t;


class genericEvent
{
public:
	genericEvent() { ev = NO_EV; }//por default, se setea el tipo de evento en NO_EV. Si otra clase hereda genericEvent, puede cambiar el constructor para setear el evento como el que corresponda
	eventsCode_t getEventType() { return ev; }	//getter del tipo de evento
protected:
	eventsCode_t ev;
};


#endif // !GENERICEVENT_H