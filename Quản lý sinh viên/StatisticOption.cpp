#include "StatisticOption.h"

classNode StatisticOption::nextNode(classNode node)
{
	return ++node;
}

void StatisticOption::refresh()
{
	statistic();

	classListView->moveToFirstPage();
	classListView->refreshNumberOfObject();
}

void StatisticOption::statistic()
{
	listOfClass.clear();
	ClassStatistic* classStatistic;

	Node temp = listOfStudent->getBegin();
	classStatistic = new ClassStatistic(temp->getMaLop());
	classStatistic->addStudent(temp->getDiemTrungBinh());
	listOfClass.push_back(*classStatistic);

	for (Node temp = ++listOfStudent->getBegin(); temp != listOfStudent->getEnd(); temp++)
	{
		for (classNode node = listOfClass.begin(); node != listOfClass.end(); node++)
		{
			if (temp->getMaLop() == node->getClassName())
			{
				node->addStudent(temp->getDiemTrungBinh());
				break;
			}
			else if (nextNode(node) == listOfClass.end())
			{
				classStatistic = new ClassStatistic(temp->getMaLop());
				listOfClass.push_back(*classStatistic);
			}
		}
	}

	for (classNode temp = listOfClass.begin(); temp != listOfClass.end(); temp++)
		temp->display();
}

StatisticOption::StatisticOption(GraphicData* graphicData, ListControl* list)
	:BaseState(graphicData, list)
{
	classListView = new ClassListView(graphicData, &listOfClass);
}

StatisticOption::~StatisticOption()
{
}

void StatisticOption::update()
{
	BaseState::update();

	classListView->update();
}

void StatisticOption::draw()
{
	BaseState::draw();

	classListView->draw();

	
}
