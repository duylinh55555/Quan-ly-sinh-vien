#include "Node.h"

Node::Node()
{
	pLeft = nullptr;
	pRight = nullptr;
}

void Node::setStudent(Student student)
{
	this->student = student;
}

Student Node::getStudent()
{
	return student;
}

void Node::readData(fstream& file)
{

	student.loadFromFile(file);
}

void Node::writeData(fstream& file)
{

	student.saveToFile(file);
}

