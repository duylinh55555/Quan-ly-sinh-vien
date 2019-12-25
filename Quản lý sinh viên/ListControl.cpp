#include "ListControl.h"

ListControl::ListControl()
{
	type = Type::MA_SINH_VIEN;
}

void ListControl::push_back(Student student)
{
	listOfStudent.push_back(student);
}

Node ListControl::previous(Node temp)
{
	return --temp;
}

Node ListControl::next(Node temp)
{
	return ++temp;
}

void ListControl::reverseName()
{
	for (Node temp = listOfStudent.begin(); temp != listOfStudent.end(); temp++)
	{
		//	Đảo họ tên
		string name = temp->getHoTen();
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

		temp->setHoTen(str);
	}
}

Node ListControl::partition(Node min, Node max)
{
	Node key = max;
	Node left = min;
	Node right = previous(max);

	while (true)
	{
		switch (type)
		{
		case Type::MA_SINH_VIEN:
			while (left != next(right) && left->getMaSinhVien() <= key->getMaSinhVien())
				left++;
			while (left != next(right) && right->getMaSinhVien() > key->getMaSinhVien() && right != listOfStudent.begin())
				right--;
			break;

		case Type::MA_LOP:
			while (left != next(right) && left->getMaLop() <= key->getMaLop())
				left++;
			while (left != next(right) && right->getMaLop() > key->getMaLop() && right != listOfStudent.begin())
				right--;
			break;

		case Type::HO_TEN:
			while (left != next(right) && left->getHoTen() <= key->getHoTen())
				left++;
			while (left != next(right) && right->getHoTen() > key->getHoTen() && right != listOfStudent.begin())
				right--;
			break;

		case Type::NGAY_SINH:
			while (left != next(right) && !left->getNgaySinh().isBigger(key->getNgaySinh()))
				left++;
			while (left != next(right) && right->getNgaySinh().isBigger(key->getNgaySinh()) && right != listOfStudent.begin())
				right--;
			break;

		case Type::DIEM_TRUNG_BINH:
			while (left != next(right) && left->getDiemTrungBinh() <= key->getDiemTrungBinh())
				left++;
			while (left != next(right) && right->getDiemTrungBinh() > key->getDiemTrungBinh() && right != listOfStudent.begin())
				right--;
			break;

		default:
			break;
		}

		if (left == next(right) || right == listOfStudent.begin())
			break;

		swap(*left, *right);
		left++;
		right--;
	}
	swap(*left, *max);

	return left;
}

void ListControl::quickSort(Node left, Node right)
{
	if (left != right && left != next(right))
	{
		Node p = partition(left, right);

		if (p != listOfStudent.begin())
			quickSort(left, previous(p));

		quickSort(next(p), right);
	}
}

void ListControl::Insert(Student student)
{
	const wstring ex = L"Mã sinh viên đã tồn tại";

	Node temp = listOfStudent.begin();

	while (temp != listOfStudent.end())
	{
		if (temp->getMaSinhVien() < student.getMaSinhVien())
			temp++;
		else if (temp->getMaSinhVien() == student.getMaSinhVien())
			throw(ex);
		else
			break;
	}

	listOfStudent.insert(temp, student);
}

void ListControl::Delete(Node node)
{
	listOfStudent.erase(node);
}

void ListControl::DeleteList()
{
	listOfStudent.clear();
}

Node ListControl::getBegin()
{
	return listOfStudent.begin();
}

Node ListControl::getEnd()
{
	return listOfStudent.end();
}

int ListControl::getSize()
{
	return listOfStudent.size();
}

void ListControl::idSort()
{
	type = Type::MA_SINH_VIEN;
	quickSort(listOfStudent.begin(), previous(listOfStudent.end()));
}

void ListControl::classIdSort()
{
	type = Type::MA_LOP;
	quickSort(listOfStudent.begin(), previous(listOfStudent.end()));
}

void ListControl::nameSort()
{
	type = Type::HO_TEN;

	reverseName();

	quickSort(listOfStudent.begin(), previous(listOfStudent.end()));

	reverseName();
}

void ListControl::birthdaySort()
{
	type = Type::NGAY_SINH;
	quickSort(listOfStudent.begin(), previous(listOfStudent.end()));
}

void ListControl::markSort()
{
	type = Type::DIEM_TRUNG_BINH;
	quickSort(listOfStudent.begin(), previous(listOfStudent.end()));
}

void ListControl::loadFromFile()
{
	ifstream input("student.bin", ios::binary | ios::in);

	//	Tạo file nếu không tìm thấy
	if (input.fail())
	{
		ofstream file("student.bin", ios::binary | ios::out);
		file.close();

		input.open("student.bin", ios::binary | ios::in);
	}

	//	Khi file không phải file rỗng
	if (!(input.peek() == ifstream::traits_type::eof()))
	{
		Student student;

		while (student.loadFromFile(input))
			listOfStudent.push_back(student);
	}

	input.close();
}

void ListControl::saveToFile()
{
	ofstream output("student.bin", ios::binary | ios::out);

	Node temp = listOfStudent.begin();

	for (int i = 0; i < (int)listOfStudent.size(); i++)
	{
		temp->saveToFile(output);
		temp++;
	}

	output.close();
}

