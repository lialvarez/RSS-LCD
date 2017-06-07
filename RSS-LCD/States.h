#ifndef STATES_H
#define STATES_H

#include "Events.h"
#include "genericState.h"

class ST_Idle : public genericState
{
public:
	genericState * onChannelStartTag(genericEvent* ev);

private:

};

class ST_Channel : public genericState
{
public:

	genericState * onTitleStartTag(genericEvent* ev);
	genericState * onItemStartTag(genericEvent* ev);
	genericState * onChannelEndTag(genericEvent* ev);

private:

};

class ST_ChannelTitle : public genericState
{
public:
	genericState * onTitleEndTag(genericEvent* ev);
private:

};

class ST_Item : public genericState
{
public:
	genericState * onTitleStartTag(genericEvent* ev);
	genericState * onDateStartTag(genericEvent* ev);
	genericState * onItemEndTag(genericEvent* ev, void* data);

private:

};

class ST_ItemTitle : public genericState
{
public:
	genericState * onTitleEndTag(genericEvent* ev);

private:

};

class ST_ItemDate : public genericState
{
public:
	genericState * onDateEndTag(genericEvent* ev);
private:

};


#endif // !STATES_H



