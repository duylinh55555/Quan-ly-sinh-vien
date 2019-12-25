#ifndef CLASSSTATISTIC_H
#define CLASSSTATISTIC_H

#include "ListControl.h"

class ClassStatistic
{
private:
	string className;
	int numberOfStudent;
	int numberExcellent;
	int numberGood;
	int numberAverage;
	int numberBelowAverage;
	int numberWeak;

public:
	ClassStatistic(string className);
	void setClassName(string className);
	void addStudent(float mark);

	string getClassName();
	int getNumberOfStudent();
	int getNumberExcellent();
	int getNumberGood();
	int getNumberAverage();
	int getNumberBelowAverage();
	int getNumberWeak();

	float getPercentExcellent();
	float getPercentGood();
	float getPercentAverage();
	float getPercentBelowAverage();
	float getPercentWeak();

	void display()
	{
		cout << className << endl;
		cout << numberOfStudent << "  " << numberExcellent << "  " << numberGood
			<< "  " << numberAverage << "  " << numberBelowAverage << "  " << numberWeak << endl;
	}
};

#endif // !CLASSSTATISTIC_H