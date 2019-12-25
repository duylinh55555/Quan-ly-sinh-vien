#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node
{
private:
	Student student;
	
public:
	Node* pLeft;
	Node* pRight;
	Node();

	void setStudent(Student student);
	Student getStudent();
	void readData(fstream& file);
	void writeData(fstream& file);
};

#endif // !NODE_H