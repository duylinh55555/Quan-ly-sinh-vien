#ifndef PROGRAM_H
#define PROGRAM_H

#include "StatisticOption.h"

class Program
{
private:
	RenderWindow* window;
	Event event;
	GraphicData* graphicData;

	typedef BaseState* State;
	State baseState;
	State addOption;
	State printOption;
	State findOption;
	State statisticOption;

	stack<State>  states;

	ListControl list;

public:
	Program();
	void run();
};

#endif // !PROGRAM_H