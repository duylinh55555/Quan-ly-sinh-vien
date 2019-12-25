#ifndef ADDOPTION_H
#define ADDOPTION_H

#include "BaseState.h"

class AddOption :
	public BaseState
{
private:
	InformationTable* inforTable;
	Text *errorMessage;

public:
	AddOption(GraphicData* graphicData, ListControl* list);
	void update();
	void draw();
};

#endif // !ADDOPTION_H