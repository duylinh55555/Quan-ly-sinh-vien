#ifndef GRAPHICDATA_H
#define GRAPHICDATA_H

#include"stdafx.h"

class GraphicData
{
public:
	RenderWindow* window;
	Event* event;

	GraphicData(RenderWindow* window, Event* event)
	{
		this->window = window;
		this->event = event;
	}
};

#endif // !GRAPHICDATA_H