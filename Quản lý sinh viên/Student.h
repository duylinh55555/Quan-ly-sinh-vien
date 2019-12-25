#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include "Date.h"

using namespace std;

class Student
{
private:
	string maLop;
	string maSinhVien;
	string hoTen;
	Date ngaySinh;
	float diemTrungBinh;
	//	Chuẩn hóa họ tên
	void standardized(string& str);
	void deleteSpace(string& str);
public:
	Student();
	Student(string maLop, string maSinhVien, string hoTen, Date date, float diemTrungBinh);
	virtual ~Student();

	void setMaLop(string);
	void setMaSinhVien(string);
	void setHoTen(string);
	void setBirthDay(Date date);
	void setDiemTrungBinh(float);

	string getMaLop();
	string getMaSinhVien();
	string getHoTen();
	Date getNgaySinh();
	float getDiemTrungBinh();

	bool loadFromFile(ifstream& file);
	void saveToFile(ofstream& file);
};

#endif