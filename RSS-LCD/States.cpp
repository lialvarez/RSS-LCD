#include "States.h"
#include "Titulares.h"

// IDLE STATE

genericState * ST_Idle::onChannelStartTag(genericEvent *ev)
{
	genericState * ret = new ST_Channel;
	return ret;
}

// CHANNLEL STATE

genericState * ST_Channel::onTitleStartTag(genericEvent *ev)
{
	genericState * ret = new ST_ChannelTitle;
	return ret;
}

genericState * ST_Channel::onOtherStartTag(genericEvent *ev)
{
	genericState * ret = new ST_Ignore;
	return ret;
}

genericState * ST_Channel::onItemStartTag(genericEvent *ev)
{
	genericState * ret = new ST_Item;
	return ret;
}

genericState * ST_Channel::onChannelEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Idle;
	return ret;
}

// CHANNEL TITLE STATE

genericState * ST_ChannelTitle::onTitleEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Channel;
	return ret;
}

// IGNORE STATE

genericState * ST_Ignore::onOtherEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Channel;
	return ret;
}

// ITEM STATE

genericState * ST_Item::onTitleStartTag(genericEvent *ev)
{
	genericState * ret = new ST_ItemTitle;
	return ret;
}

genericState * ST_Item::onDateStartTag(genericEvent *ev)
{
	genericState * ret = new ST_ItemDate;
	return ret;
}

genericState * ST_Item::onItemEndTag(genericEvent *ev, void *data)
{
	Titulares *myData = (Titulares *)data;
	myData->addNew();
	return nullptr;
}

// ITEM TITLE STATE

genericState * ST_ItemTitle::onTitleEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Item;
	return ret;
}

// ITEM DATE STATE

genericState * ST_ItemDate::onDateEndTag(genericEvent *ev)
{
	genericState * ret = new ST_Item;
	return ret;
}

