#include "InformationTable.h"

InformationTable::InformationTable(GraphicData* graphicData)
{
	isEnter = false;
	this->graphicData = graphicData;

	for (int i = 0; i < 16; i++)	// (64, 45)
	{
		for (int j = 0; j < 20; j++)
		{
			int num = 20 * i + j;
			position[num].x = 64 * j;
			position[num].y = 45 * i;
		}
	}

	if (!font.loadFromFile("Robika.otf"))
	{
		cout << "Error open file";
		system("pause");
	}

	background.setPosition((float)position[82].x + 20, (float)position[82].y + 20);
	background.setSize(Vector2f(64 * 16 - 40, 45 * 11 - 40));
	background.setFillColor(Color(92, 94, 109, 150));
	background.setOutlineThickness(3);
	background.setOutlineColor(Color(19, 65, 215));

	textBox[0] = new TextBox(graphicData, position[126], 375, 35, L"VD: Nguyen Van A", Color(35, 46, 154, 255), Option::HO_TEN);
	textBox[1] = new TextBox(graphicData, position[166], 375, 35, L"VD: VS1213w", Color(35, 46, 154, 255), Option::MA_SINH_VIEN);
	textBox[2] = new TextBox(graphicData, position[206], 375, 35, L"VD: CNTT1", Color(35, 46, 154, 255), Option::MA_LOP);
	textBox[3] = new TextBox(graphicData, position[246], 80, 35, L"VD: 8.5", Color(35, 46, 154, 255), Option::DIEM_TRUNG_BINH);
	textBox[4] = new TextBox(graphicData, position[134], 45, 35, L"Ngày", Color(35, 46, 154, 255), Option::DAY);
	textBox[5] = new TextBox(graphicData, position[135], 45, 35, L"Tháng", Color(35, 46, 154, 255), Option::MONTH);
	textBox[6] = new TextBox(graphicData, position[136], 65, 35, L"Năm", Color(35, 46, 154, 255), Option::YEAR);

	title[0] = new Text(L"Nhập thông tin sinh viên", font, 35);
	title[0]->setPosition(165, 200);
	title[0]->setFillColor(Color(64, 55, 168));

	title[1] = new Text(L"Họ tên:", font, 28);
	title[1]->setPosition((float)position[123].x, (float)position[123].y);

	title[2] = new Text(L"Mã sinh viên:", font, 28);
	title[2]->setPosition((float)position[163].x, (float)position[163].y);

	title[3] = new Text(L"Mã lớp:", font, 28);
	title[3]->setPosition((float)position[203].x, (float)position[203].y);

	title[4] = new Text(L"Điểm trung bình:", font, 22);
	title[4]->setPosition((float)position[243].x, (float)position[243].y);

	title[5] = new Text(L"  Ngày sinh:", font, 22);
	title[5]->setPosition((float)position[132].x, (float)position[132].y);

	title[6] = new Text(L"/", font, 22);
	title[6]->setPosition((float)position[134].x + 51, (float)position[134].y);

	title[7] = new Text(L"/", font, 22);
	title[7]->setPosition((float)position[135].x + 51, (float)position[135].y);

	enter = new Button(graphicData, position[255], 64 * 2, 45 * 2, L"", Color(79, 126, 191), Option::Enter);

	textEnter = new Text(L"Enter", font, 30);
	textEnter->setPosition(position[255].x + 20, position[255].y + 20);
	textEnter->setFillColor(Color(180, 203, 197));

	for (int i = 0; i < 5; i++)
	{
		errorMessage[i] = new Text(L"", font, 22);
		errorMessage[i]->setFillColor(Color::Red);
	}
	errorMessage[0]->setPosition((float)position[106].x, (float)position[106].y + 10);
	errorMessage[1]->setPosition((float)position[146].x, (float)position[146].y + 10);
	errorMessage[2]->setPosition((float)position[186].x, (float)position[186].y + 10);
	errorMessage[3]->setPosition((float)position[226].x, (float)position[226].y + 10);
	errorMessage[4]->setPosition((float)position[114].x, (float)position[114].y + 10);
}

void InformationTable::setStringEmpty()
{
	for (int i = 0; i < 7; i++)
		textBox[i]->setStringEmpty();
}

void InformationTable::setStudent(Student student)
{
	this->student = student;
	textBox[0]->setText(student.getHoTen());
	textBox[1]->setText(student.getMaSinhVien());
	textBox[2]->setText(student.getMaLop());

	Date date = student.getNgaySinh();
	string d, m, y, diem;
	stringstream strD, strM, strY, strDiem;
	strD << date.day;
	d = strD.str();
	strM << date.month;
	m = strM.str();
	strY << date.year;
	y = strY.str();
	strDiem << student.getDiemTrungBinh();
	diem = strDiem.str();

	textBox[3]->setText(diem);
	textBox[4]->setText(d);
	textBox[5]->setText(m);
	textBox[6]->setText(y);
}

Student InformationTable::getStudent()
{
	return student;
}

void InformationTable::update()
{
	//	Cập nhật textbox
	for (int i = 0; i < 7; i++)
	{
		textBox[i]->update();

		/*if (textBox[i]->isNext == true && i < 6)
		{
			textBox[i]->isSecleted     = false;
			textBox[i + 1]->isSecleted = true;
		}*/
	}

	//	Cập nhật nút enter
	enter->update();

	if (enter->isClick)
	{
		Student tempStudent;

		//	Khởi tạo giá trị các ô textbox là true
		bool* isCorrect = new bool[5];
		for (int i = 0; i < 5; i++)
			isCorrect[i] = true;

		//	Bắt lỗi và lưu lại giá trị từng ô textbox
		//	Textbox 0 -> 2
		for (int i = 0; i < 3; i++)
		{
			try
			{
				string str = textBox[i]->getText();

				switch (textBox[i]->getOption())
				{
				case Option::MA_SINH_VIEN:
					if (str == "")
						throw (const wstring(L"Mã sinh viên không được để trống"));

					tempStudent.setMaSinhVien(str);
					break;

				case Option::MA_LOP:
					if (str == "")
						throw (const wstring(L"Mã lớp không được để trống"));

					tempStudent.setMaLop(str);
					break;

				case Option::HO_TEN:
					if (str == "")
						throw (const wstring(L"Họ tên không được để trống"));

					tempStudent.setHoTen(str);
					break;

				}
			}
			catch (const wstring ex)
			{
				errorMessage[i]->setString(ex);
				isCorrect[i] = false;
				enter->isClick = false;
			}

			if (isCorrect[i])
				errorMessage[i]->setString("");
		}

		//	Textbox 3
		try
		{
			if (textBox[3]->getText() == "")
				throw (const wstring(L"Điểm trung bình không được để trống"));

			float diemTB = textBox[3]->getNumber();

			if (diemTB < 0 || diemTB > 10)
				throw (const wstring(L"Điểm trung bình không hợp lệ"));

			tempStudent.setDiemTrungBinh(diemTB);
		}
		catch (const wstring ex)
		{
			errorMessage[3]->setString(ex);
			isCorrect[3] = false;
			enter->isClick = false;
		}

		if (isCorrect[3])
			errorMessage[3]->setString("");


		//	Textbox 4 -> 6 (Ngày tháng năm)
		int d = (int)textBox[4]->getNumber();
		int m = (int)textBox[5]->getNumber();
		int y = (int)textBox[6]->getNumber();

		try
		{
			Date date;
			date.setDate(d, m, y);
			tempStudent.setBirthDay(date);
		}
		catch (const wstring ex)
		{
			errorMessage[4]->setString(ex);
			isCorrect[4] = false;
			enter->isClick = false;
		}

		if (isCorrect[4])
			errorMessage[4]->setString("");

		//	Lưu dữ liệu vào object student
		for (int i = 0; i < 5; i++)
		{
			if (!isCorrect[i])
				break;
			if (i == 4)
			{
				student = tempStudent;
				isEnter = true;
			}
		}
	}
}

void InformationTable::draw()
{
	graphicData->window->draw(background);

	for (int i = 0; i < 7; i++)
		textBox[i]->draw();

	for (int i = 0; i < 8; i++)
		graphicData->window->draw(*title[i]);

	enter->draw();

	graphicData->window->draw(*textEnter);

	for (int i = 0; i < 5; i++)
		graphicData->window->draw(*errorMessage[i]);
}
