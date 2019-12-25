#include "List.h"

List::List()
{
	head = tail = nullptr;
	numberOfStudent = 0;
	type = Type::MA_SINH_VIEN;
}

List::~List()
{
}

void List::reverseName()
{
	for (Node* temp = head; temp != nullptr; temp = temp->pRight)
	{
		//	Đảo họ tên
		string name = temp->getStudent().getHoTen();
		string str, str2;
		int location = 1;

		while (location > 0)
		{
			location = name.find(" ");
			str2 = name.substr(0, location);
			name.erase(0, location + 1);
			str.insert(0, str2 + ' ');
		}
		str.pop_back();

		temp->getStudent().setHoTen(str);
	}
}

Node* List::init(Student student)
{
	Node* p = new Node;
	p->setStudent(student);
	p->pLeft = nullptr;
	p->pRight = nullptr;
	return p;
}

Node* List::partition(Node* min, Node* max)
{
	Node* key = max;
	Node* left = min;
	Node* right = max - 1;

	while (true)
	{
		switch (type)
		{
		case Type::MA_SINH_VIEN:
			while (left->pLeft != right->pRight && left->getStudent().getMaSinhVien() < key->getStudent().getMaSinhVien())
				left = left->pRight;
			while (left->pLeft != right->pRight && right->getStudent().getMaSinhVien() > key->getStudent().getMaSinhVien())
				right = right->pLeft;
			break;

		case List::Type::MA_LOP:
			while (left->pLeft != right->pRight && left->getStudent().getMaLop() < key->getStudent().getMaLop())
				left = left->pRight;
			while (left->pLeft != right->pRight && right->getStudent().getMaLop() > key->getStudent().getMaLop())
				right = right->pLeft;
			break;

		case List::Type::HO_TEN:
			while (left->pLeft != right->pRight && left->getStudent().getHoTen() < key->getStudent().getHoTen())
				left = left->pRight;
			while (left->pLeft != right->pRight && right->getStudent().getHoTen() > key->getStudent().getHoTen())
				right = right->pLeft;
			break;
		default:
			break;
		}

		if (left->pLeft == right->pRight)
			break;

		swap(left, right);
		left->pRight;
		right->pLeft;
	}
	swap(left, max);
	return left;
}

void List::quickSort(Node* min, Node* max)
{
	if (min != max)
	{
		Node* p = partition(min, max);

		quickSort(min, p->pLeft);
		quickSort(p->pRight, max);
	}
}

int List::getNumber()
{
	return numberOfStudent;
}

void List::Insert(Student student)
{
	numberOfStudent++;

	if (head == NULL && tail == NULL)
		head = init(student);

	else
	{
		Node* temp = head;
		Node* p = init(student);

		while (temp->getStudent().getMaSinhVien() < student.getMaSinhVien() && temp->pRight != NULL)
			temp = temp->pRight;

		if (temp->getStudent().getMaSinhVien() == student.getMaSinhVien())
		{
			//	Throw Exception
		}

		//	Duyệt hết list
		if (temp->pRight == NULL)
		{
			p->pLeft = temp;
			temp->pRight = p;
			tail = p;
		}

		else if (temp->pLeft == NULL)
		{
			p->pRight = temp;
			temp->pLeft = p;
			p->pLeft = NULL;
			head = temp;
		}
		else
		{
			p->pLeft = temp->pLeft;
			temp->pLeft->pRight = p;
			
			temp->pLeft = p;
			p->pRight = temp;
		}
	}
}

void List::idSort()
{
	type = Type::MA_SINH_VIEN;
	quickSort(head, tail);
}

void List::classIdSort()
{
	type = Type::MA_LOP;
	quickSort(head, tail);
}

void List::nameSort()
{
	type = Type::HO_TEN;

	reverseName();

	quickSort(head, tail);

	reverseName();
}

void List::loadFromFile()
{
	Student student;

	file.open("Data/Student.txt");

	string num;
	getline(file, num);
	stringstream str2num(num);

	str2num >> numberOfStudent;

	for (int i = 0; i < numberOfStudent; i++)
	{
		student.loadFromFile(file);
		Insert(student);
	}
}

void List::saveToFile()
{
	file << numberOfStudent << endl;
	for (Node* temp = head; temp != nullptr; temp = temp->pRight)
		temp->writeData(file);
}