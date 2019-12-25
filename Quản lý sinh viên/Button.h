#ifndef BUTTON_H
#define BUTTON_H

#include "CircleSector.h"

class Button
{
protected:
	GraphicData* graphicData;
	RectangleShape button;
	int length;
	int width;
	Font font;
	Text text;
	Vector2i position;
	Color color;
	Option option;

public:
	Button();
	Button(GraphicData* graphicData, Vector2i pos, int length, int width, wstring s, Color color, Option option);
	~Button();

	void setParameter(GraphicData* graphicData, Vector2i pos, int length, int width, wstring s, Color color, Option option);
	bool isClick;
	void setTextSize(int size);
	void setColor(Color color);
	void setTextColor(Color color);
	bool isInside();
	virtual void update();
	virtual void draw();
	Option getOption();
	void setOption(Option option);
};

#endif