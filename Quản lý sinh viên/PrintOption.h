#ifndef PRINTOPTION_H
#define PRINTOPTION_H

#include "AddOption.h"

class PrintOption :
	public BaseState
{
private:
	ListView* listView;

public:
	PrintOption(GraphicData* graphicData, ListControl* list);

	void refresh();
	void update();
	void draw();
};

#endif // !PRINTOPTION_H