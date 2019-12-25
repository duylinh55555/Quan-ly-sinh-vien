#include "SetStudent.h"


SetStudent::SetStudent()
{
}


SetStudent::~SetStudent()
{
}

void SetStudent::setMaLop(string malop)
{
	maLop = malop;
}

void SetStudent::setMaSinhVien(string maSV)
{
	maSinhVien = maSV;
}

void SetStudent::setHoTen(string hoten)
{
	hoTen = hoten;
}

void SetStudent::setDay(string d)
{
	stringstream str2num(d);
	str2num >> day;
}

void SetStudent::setMonth(string m)
{
	stringstream str2num(m);
	str2num >> month;
}

void SetStudent::setYear(string y)
{
	stringstream str2num(y);
	str2num >> year;
}

void SetStudent::setDiemTrungBinh(string diemTB)
{
	stringstream str2num(diemTB);
	str2num >> diemTrungBinh;
}

void SetStudent::exportToStudent()
{

}