#include "States.h"
#include "Titulares.h"

// IDLE STATE

genericState * ST_Idle::onChannelStartTag(genericEvent *ev)
{
	genericState * ret = new ST_Channel;
	ret->currentStateCode = CHANNEL;
	return ret;
}

// CHANNLEL STATE

genericState * ST_Channel::onTitleStartTag(genericEvent *ev)
{
	genericState * ret = new ST_ChannelTitle;
	ret->currentStateCode = CH_TITLE;
	return ret;
}

genericState * ST_Channel::onItemStartTag(genericEvent *ev)
{
	genericState * ret = new ST_Item;
	ret->currentStateCode = ITEM;
	return ret;
}

genericState * ST_Channel::onChannelEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Idle;
	ret->currentStateCode = IDLE;
	return ret;
}

// CHANNEL TITLE STATE

genericState * ST_ChannelTitle::onTitleEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Channel;
	ret->currentStateCode = CHANNEL;
	return ret;
}

// ITEM STATE

genericState * ST_Item::onTitleStartTag(genericEvent *ev)
{
	genericState * ret = new ST_ItemTitle;
	ret->currentStateCode = ITEM_TITLE;
	return ret;
}

genericState * ST_Item::onDateStartTag(genericEvent *ev)
{
	genericState * ret = new ST_ItemDate;
	ret->currentStateCode = ITEM_DATE;
	return ret;
}

genericState * ST_Item::onItemEndTag(genericEvent *ev, void *data)
{
	Titulares *myData = (Titulares *)data;
	myData->addNew();
	genericState *ret = new ST_Channel;
	ret->currentStateCode = CHANNEL;
	return ret;
}

// ITEM TITLE STATE

genericState * ST_ItemTitle::onTitleEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Item;
	ret->currentStateCode = ITEM;
	return ret;
}

// ITEM DATE STATE

genericState * ST_ItemDate::onDateEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Item;
	ret->currentStateCode = ITEM;
	return ret;
}

