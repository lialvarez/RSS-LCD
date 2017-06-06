#ifndef GENERICSTATE_H
#define GENERICSTATE_H

#include "genericEvent.h"

typedef enum { IDLE, CHANNEL, CH_TITLE, ITEM, ITEM_TITLE, ITEM_DATE, IGNORE }stateCode_t;

class genericState
{
public:
	
	virtual genericState * onNoEv(genericEvent* ev) { return nullptr; }
	virtual genericState * onChannelStartTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onTitleStartTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onItemStartTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onDateStartTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onOtherStartTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onChannelEndTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onTitleEndTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onItemEndTag(genericEvent* ev, void* data) { return nullptr; }
	virtual genericState * onDateEndTag(genericEvent* ev) { return nullptr; }
	virtual genericState * onOtherEndTag(genericEvent* ev) { return nullptr; }

	stateCode_t getCurrentStateCode() { return currentStateCode; }

protected:
	stateCode_t currentStateCode;
};

#endif // !GENERICSTATE_H


