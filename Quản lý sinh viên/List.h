#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
private:
	fstream file;
	int numberOfStudent;

	enum class Type {
		MA_SINH_VIEN,
		MA_LOP,
		HO_TEN,
		DIEM_TRUNG_BINH,
	};
	Type type;

	//	Đảo thứ tự họ tên => Sắp xếp
	void reverseName();
	
	//	Khởi tạo list
	Node* init(Student student);

	//	QuickSort
	Node* partition(Node* min, Node* max);
	void quickSort(Node* min, Node* max);

public:
	Node* head;
	Node* tail;
	List();
	~List();

	int getNumber();

	//	Thêm đối tượng vào list
	void Insert(Student student);

	void idSort();
	void classIdSort();
	void nameSort();

	void loadFromFile();
	void saveToFile();
};

#endif // !LIST_H