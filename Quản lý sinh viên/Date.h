#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
private:

public:
	int day;
	int month;
	int year;

	Date()
	{
		day = 1;
		month = 1;
		year = 1900;
	}

	virtual ~Date()
	{
	}

	void setDate(int d = 1, int m = 1, int y = 1900)
	{
		const wstring ex = L"Ngày sinh không đúng!";
		const wstring ex2 = L"Tháng sinh không đúng!";
		const wstring ex3 = L"Năm sinh không đúng!";
		
		if (y < 1900 || y > 2018)
			throw (ex3);
		
		if (m < 1 || m > 12)
			throw(ex2);

		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			if (d < 1 || d > 31)
				throw (ex);

		if (m == 4 || m == 6 || m == 9 || m == 11)
			if (d < 1 || d > 30)
				throw (ex);

		if (m == 2)
		{
			if (y % 4 == 0)
			{
				if (d < 1 || d > 29)
					throw (ex);
			}

			else
				if (d < 1 || d > 28)
					throw (ex);
		}

		day = d;
		month = m;
		year = y;
	}

	bool isBigger(Date date)
	{
		if (this->year > date.year)
			return true;
		else if (this->year < date.year)
			return false;
		else
		{
			if (this->month > date.month)
				return true;
			else if (this->month < date.month)
				return false;
			else
			{
				if (this->day >= date.day)
					return true;
				else
					return false;
			}
		}
	}
};

#endif