#include "Student.h"

Student::Student()
{
	maLop = "111111"; 
	maSinhVien = "111111";
	hoTen = "Nguyen Van A";
	diemTrungBinh = 1;
}

Student::Student(string maLop, string maSinhVien, string hoTen, Date ngaySinh, float diemTrungBinh)
{
	this->maLop = maLop;
	this->maSinhVien = maSinhVien;
	this->hoTen = hoTen;
	this->ngaySinh = ngaySinh;
	this->diemTrungBinh = diemTrungBinh;
}

Student::~Student()
{
}

//	Nên cho vào infoTable
void Student::deleteSpace(string& str)
{
	for (int i = 1; i < (int)str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ' || str[i] == ' ' && str[i + 1] == NULL)
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
}

void Student::standardized(string& str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
	str[0] = toupper(str[0]);

	deleteSpace(str);

	for (int i = 1; i < (int)str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1])
			str[i + 1] = toupper(str[i + 1]);
	}
}


void Student::setMaLop(string maLop)
{
	transform(maLop.begin(), maLop.end(), maLop.begin(), toupper);
	deleteSpace(maLop);

	this->maLop = maLop;
}

void Student::setMaSinhVien(string maSV)
{
	transform(maSV.begin(), maSV.end(), maSV.begin(), toupper);
	deleteSpace(maSV);

	this->maSinhVien = maSV;
}

void Student::setHoTen(string hoten)
{
	standardized(hoten);
	this->hoTen = hoten;
}

void Student::setBirthDay(Date date)
{
	ngaySinh = date;
}

void Student::setDiemTrungBinh(float diemTrungBinh)
{
	this->diemTrungBinh = diemTrungBinh;
}

string Student::getMaLop()
{
	return maLop;
}

//	DHTH53A17
string Student::getMaSinhVien()
{
	return maSinhVien;
}

string Student::getHoTen()
{
	return hoTen;
}

Date Student::getNgaySinh()
{
	return ngaySinh;
}

float Student::getDiemTrungBinh()
{
	return diemTrungBinh;
}

bool Student::loadFromFile(ifstream& file)
{
	int size;
	char* buf;

	try
	{
		file.read((char*)&size, sizeof(int));
		buf = new char[size];
		file.read((char*)buf, size);
		maLop = "";
		maLop.append(buf, size);

		file.read((char*)&size, sizeof(int));
		buf = new char[size];
		file.read((char*)buf, size);
		maSinhVien = "";
		maSinhVien.append(buf, size);

		file.read((char*)&size, sizeof(int));
		buf = new char[size];
		file.read((char*)buf, size);
		hoTen = "";
		hoTen.append(buf, size);

		int d, m, y;
		file.read((char*)&d, sizeof(int));
		file.read((char*)&m, sizeof(int));
		file.read((char*)&y, sizeof(int));
		ngaySinh.setDate(d, m, y);

		file.read((char*)&diemTrungBinh, sizeof(float));

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

void Student::saveToFile(ofstream& file)
{
	int size;

	size = maLop.size();
	file.write((char*)&size, sizeof(int));
	file.write((char*)maLop.c_str(), size);

	size = maSinhVien.size();
	file.write((char*)&size, sizeof(int));
	file.write((char*)maSinhVien.c_str(), size);

	size = hoTen.size();
	file.write((char*)&size, sizeof(int));
	file.write((char*)hoTen.c_str(), size);

	file.write((char*)&ngaySinh.day, sizeof(int));
	file.write((char*)&ngaySinh.month, sizeof(int));
	file.write((char*)&ngaySinh.year, sizeof(int));

	file.write((char*)&diemTrungBinh, sizeof(float));
}