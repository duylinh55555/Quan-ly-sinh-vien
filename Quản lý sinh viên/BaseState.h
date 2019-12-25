#ifndef BASESTATE_H
#define BASESTATE_H

#include "ClassListView.h"

class BaseState
{
protected:
	GraphicData* graphicData;
	Vector2i position[320];
	Option option;
	RectangleShape background;
	Font font;
	Text title;
	Text notification;
	Button* button[6];
	bool isClick;

	ListControl* listOfStudent;

public:
	BaseState(GraphicData* graphicData, ListControl* list);
	bool checkClick();
	void setOption(Option option);
	Option getOption();
	virtual void refresh();
	virtual void update();
	virtual void draw();
};

#endif // !BASESTATE_H