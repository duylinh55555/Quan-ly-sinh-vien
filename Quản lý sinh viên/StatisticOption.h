#ifndef STATISTICOPTION_H
#define STATISTICOPTION_H

#include "FindOption.h"

class StatisticOption :
	public BaseState
{
private:
	list<ClassStatistic> listOfClass;
	classNode nextNode(classNode node);

	ClassListView* classListView;

	

public:
	StatisticOption(GraphicData* graphicData, ListControl* list);
	~StatisticOption();

	void refresh();
	void statistic();
	void update();
	void draw();
};

#endif // !STATISTICOPTION_H