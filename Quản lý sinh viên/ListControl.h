#ifndef LISTCONTROL_H
#define LISTCONTROL_H

#include<list>
#include "Student.h"

typedef list<Student>::iterator Node;

class ListControl
{
private:
	list<Student> listOfStudent;

	enum class Type {
		MA_SINH_VIEN,
		MA_LOP,
		HO_TEN,
		NGAY_SINH,
		DIEM_TRUNG_BINH,
	};
	Type type;

	//	Con trỏ trước
	Node previous(Node temp);
	//	Con trỏ kế tiếp
	Node next(Node temp);

	//	Đảo thứ tự họ tên => Sắp xếp
	void reverseName();

	//	QuickSort
	Node partition(Node min, Node max);
	void quickSort(Node min, Node max);

public:
	ListControl();

	//	Thêm đối tượng vào cuối list
	void push_back(Student student);
	//	Thêm đối tượng vào list
	void Insert(Student student);
	//	Xóa đối tượng
	void Delete(Node node);

	void DeleteList();
	//void Replace(Node pStudent);
	Node getBegin();
	Node getEnd();
	int getSize();

	void idSort();
	void classIdSort();
	void nameSort();
	void birthdaySort();
	void markSort();

	void loadFromFile();
	void saveToFile();
};

#endif // !LISTCONTROL_H