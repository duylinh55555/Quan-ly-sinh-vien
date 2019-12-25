#include "ClassStatistic.h"

ClassStatistic::ClassStatistic(string className)
{
	this->className = className;
	numberOfStudent = 0;
	numberExcellent = 0;
	numberGood = 0;
	numberAverage = 0;
	numberBelowAverage = 0;
	numberWeak = 0;
}

void ClassStatistic::setClassName(string className)
{
	this->className = className;
}

void ClassStatistic::addStudent(float mark)
{
	numberOfStudent++;

	//	Phân loại học lực
	if (mark >= 8)
		numberExcellent++;
	else if (mark >= 7 && mark < 8)
		numberGood++;
	else if (mark >= 5.5 && mark < 7)
		numberAverage++;
	else if (mark >= 4 && mark < 5.5)
		numberBelowAverage++;
	else
		numberWeak++;
}

string ClassStatistic::getClassName()
{
	return className;
}

int ClassStatistic::getNumberOfStudent()
{
	return numberOfStudent;
}

int ClassStatistic::getNumberExcellent()
{
	return numberExcellent;
}

int ClassStatistic::getNumberGood()
{
	return numberGood;
}

int ClassStatistic::getNumberAverage()
{
	return numberAverage;
}

int ClassStatistic::getNumberBelowAverage()
{
	return numberBelowAverage;
}

int ClassStatistic::getNumberWeak()
{
	return numberWeak;
}

float ClassStatistic::getPercentExcellent()
{
	return (float)numberExcellent / (float)numberOfStudent;
}

float ClassStatistic::getPercentGood()
{
	return (float)numberGood / (float)numberOfStudent;
}

float ClassStatistic::getPercentAverage()
{
	return (float)numberAverage / (float)numberOfStudent;

}

float ClassStatistic::getPercentBelowAverage()
{
	return (float)numberBelowAverage / (float)numberOfStudent;
}

float ClassStatistic::getPercentWeak()
{
	return (float)numberWeak / (float)numberOfStudent;
}
