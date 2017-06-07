#ifndef EVENTS_H
#define EVENTS_H

#include "genericEvent.h"

class EV_NoEv : public genericEvent
{
public:
	EV_NoEv() { ev = NO_EV; }

private:

};

class EV_ChannelStartTag : public genericEvent
{
public:
	EV_ChannelStartTag() { ev = CH_TAG_S; }

private:

};

class EV_TitleStartTag : public genericEvent
{
public:
	EV_TitleStartTag() { ev = TITLE_TAG_S; }

private:

};

class EV_ItemStartTag : public genericEvent
{
public:
	EV_ItemStartTag() { ev = ITEM_TAG_S; }

private:

};

class EV_DateStartTag : public genericEvent
{
public:
	EV_DateStartTag() { ev = DATE_TAG_S; }

private:

};

class EV_ChannelEndTag : public genericEvent
{
public:
	EV_ChannelEndTag() { ev = CH_TAG_E; }

private:

};

class EV_TitleEndTag : public genericEvent
{
public:
	EV_TitleEndTag() { ev = TITLE_TAG_E; }

private:

};

class EV_ItemEndTag : public genericEvent
{
public:
	EV_ItemEndTag() { ev = ITEM_TAG_E; }

private:

};

class EV_DateEndTag : public genericEvent
{
public:
	EV_DateEndTag() { ev = DATE_TAG_E; }

private:

};

#endif // !EVENTS_H

