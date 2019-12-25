#include "PrintOption.h"

PrintOption::PrintOption(GraphicData* graphicData, ListControl* list)
	:BaseState(graphicData, list)
{
	listView = new ListView(graphicData, list);
}

void PrintOption::refresh()
{
	listView->moveToFirstPage();
	listView->refreshNumberOfObject();
}

void PrintOption::update()
{
	BaseState::update();

	listView->update();

	BaseState::notification.setString(listView->getNofication());
}

void PrintOption::draw()
{
	BaseState::draw();

	listView->draw();
}
