#include "genericFSM.h"
#include "States.h"

genericFSM::genericFSM()
{
	currentState = (genericState *) new ST_Idle();
}

genericFSM::~genericFSM()
{
	delete currentState;
}

genericState * genericFSM::getCurrentState()
{
	return currentState;
}

void genericFSM::dispatch(genericEvent *ev, void * data)
{
	genericState *newState = nullptr;
	{
		switch (ev->getEventType())	
		{
		case NO_EV:
			newState = currentState->onNoEv(ev);
			break;
		case CH_TAG_S:
			newState = currentState->onChannelStartTag(ev);
			break;
		case TITLE_TAG_S:
			newState = currentState->onTitleStartTag(ev);
			break;
		case ITEM_TAG_S:
			newState = currentState->onItemStartTag(ev);
			break;
		case DATE_TAG_S:
			newState = currentState->onDateStartTag(ev);
			break;
		case OTHER_TAG_S:
			newState = currentState->onOtherStartTag(ev);
			break;
		case CH_TAG_E:
			newState = currentState->onChannelEndTag(ev);
			break;
		case TITLE_TAG_E:
			newState = currentState->onTitleEndTag(ev);
			break;
		case ITEM_TAG_E:
			newState = currentState->onItemEndTag(ev, data);
			break;
		case DATE_TAG_E:
			newState = currentState->onDateEndTag(ev);
			break;
		case OTHER_TAG_E:
			newState = currentState->onOtherEndTag(ev);
			break;
		default:
			break;
		}
		if (newState != nullptr)
		{
			delete currentState;
			currentState = newState;
		}
	}
}

