#include "FindOption.h"

Node FindOption::previousNode(Node node)
{
	return --node;
}

void FindOption::standardized(string& str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
	str[0] = toupper(str[0]);

	for (int i = 1; i < (int)str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1])
			str[i + 1] = toupper(str[i + 1]);
	}
}

FindOption::FindOption(GraphicData* graphicData, ListControl* list)
	:BaseState(graphicData, list)
{
	isSelected = false;
	option = Option::EMPTY;
	str = "";

	foundList = new ListControl();

	listView = new ListView(graphicData, foundList);

	findTextBox = new TextBox(graphicData, position[311], 448, 35, L"Nhập ký tự cần tìm kiếm", Color(145, 173, 202, 150), Option::FIND);

	button[0] = new Button(graphicData, position[302], 187, 35, L" Mã sinh viên", Color(90, 155, 194, 150), Option::MA_SINH_VIEN);
	button[0]->setTextColor(Color(182, 192, 200));
	button[1] = new Button(graphicData, position[305], 187, 35, L"      Mã lớp", Color(90, 155, 194, 150), Option::MA_LOP);
	button[1]->setTextColor(Color(182, 192, 200));
	button[2] = new Button(graphicData, position[308], 187, 35, L"      Họ tên", Color(90, 155, 194, 150), Option::HO_TEN);
	button[2]->setTextColor(Color(182, 192, 200));

	notification.setPosition(Vector2f(540, 90));
}

FindOption::~FindOption()
{

}

void FindOption::findFoundList()
{
	Node temp = foundList->getBegin();
	int size = foundList->getSize();

	switch (option)
	{
	case Option::MA_SINH_VIEN:
		for (int i = 0; i < size; i++)
		{
			if ((int)temp->getMaSinhVien().find(str) < 0)
			{
				temp++;
				foundList->Delete(previousNode(temp));
			}
			else
				temp++;
		}
		break;

	case Option::MA_LOP:
		for (int i = 0; i < size; i++)
		{
			if ((int)temp->getMaLop().find(str) < 0)
			{
				temp++;
				foundList->Delete(previousNode(temp));
			}
			else
				temp++;
		}
		break;

	case Option::HO_TEN:
		for (int i = 0; i < size; i++)
		{
			if ((int)temp->getHoTen().find(str) < 0)
			{
				temp++;
				foundList->Delete(previousNode(temp));
			}
			else
				temp++;
		}
		break;

	default:
		break;
	}
}

void FindOption::findAllList()
{
	switch (option)
	{
	case Option::MA_SINH_VIEN:
		for (Node temp = listOfStudent->getBegin(); temp != listOfStudent->getEnd(); temp++)
		{
			if ((int)temp->getMaSinhVien().find(str) >= 0)
				foundList->push_back(*temp);
		}
		break;

	case Option::MA_LOP:
		for (Node temp = listOfStudent->getBegin(); temp != listOfStudent->getEnd(); temp++)
		{
			if ((int)temp->getMaLop().find(str) >= 0)
				foundList->push_back(*temp);
		}
		break;

	case Option::HO_TEN:
		for (Node temp = listOfStudent->getBegin(); temp != listOfStudent->getEnd(); temp++)
		{
			if ((int)temp->getHoTen().find(str) >= 0)
				foundList->push_back(*temp);
		}
		break;

	default:
		break;
	}
}

void FindOption::update()
{
	BaseState::update();

	//	Chọn kiểu tìm kiếm
	for (int i = 0; i < 3; i++)
	{
		button[i]->update();

		if (button[i]->isClick)
		{
			option = button[i]->getOption();
			isSelected = true;
			break;
		}
	}

	if (option != Option::EMPTY)
	{
		if (isSelected == true)
		{
			findTextBox->deleteText();
			isSelected = false;
		}

		findTextBox->update();

		string findText = findTextBox->getText();

		if (option == Option::HO_TEN)
			standardized(findText);
		else
			transform(findText.begin(), findText.end(), findText.begin(), toupper);

		if (findText == "" && str != "")
		{
			str = "";
			notification.setString(L"Tìm thấy 0 kết quả");
			foundList->DeleteList();
			listView->moveToFirstPage();
			listView->refreshNumberOfObject();
			listView->update();
		}
		//	Chạy tìm kiếm mỗi khi nhập ký tự
		else if (findText != "")
		{
			if (str != findText)
			{
				if ((int)findText.find(str) < 0 || str == "")
				{
					foundList->DeleteList();
					str = findText;
					findAllList();
				}
				else if (foundList->getSize() > 0)
				{
					str = findText;
					findFoundList();
				}

				listView->moveToFirstPage();
				listView->refreshNumberOfObject();

				//	Thông báo
				string num;
				stringstream str2num;
				str2num << foundList->getSize();
				num = str2num.str();

				notification.setString(L"Tìm thấy " + num + L" kết quả");
			}

			listView->update();
		}
	}
}

void FindOption::draw()
{
	BaseState::draw();

	for (int i = 0; i < 3; i++)
		button[i]->draw();

	findTextBox->draw();

	if (foundList->getSize() > 0)
		listView->draw();
}
