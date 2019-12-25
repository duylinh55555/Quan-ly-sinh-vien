#include "BaseState.h"

BaseState::BaseState(GraphicData* graphicData, ListControl* list)
{
	option = Option::EMPTY;
	this->graphicData = graphicData;
	this->listOfStudent = list;
	isClick = false;

	//	Tọa độ
	for (int i = 0; i < 16; i++)	// (64, 45)
	{
		for (int j = 0; j < 20; j++)
		{
			int num = 20 * i + j;
			position[num].x = 64 * j;
			position[num].y = 45 * i;
		}
	}

	//	Title
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Error open file";
		system("pause");
	}
	title.setString(L"Quản lý sinh viên");
	title.setFont(font);
	title.setCharacterSize(44);
	title.setFillColor(Color(163, 183, 237));
	title.setPosition(Vector2f(80, 26));

	notification.setString(L"");
	notification.setFont(font);
	notification.setCharacterSize(22);
	notification.setPosition(Vector2f(600, 675));

	//	Menu1
	button[0] = new Button(this->graphicData, position[62], 251, 35, L"  Thêm mới hồ sơ", Color(89, 159, 230, 140), Option::ADD);
	button[1] = new Button(this->graphicData, position[66], 251, 35, L"     In danh sách", Color(89, 159, 230, 140),  Option::PRINT);
	button[2] = new Button(this->graphicData, position[70], 251, 35, L"        Tìm kiếm", Color(89, 159, 230, 140), Option::FIND);
	button[3] = new Button(this->graphicData, position[74], 256, 35, L"       Thống kê", Color(89, 159, 230, 140), Option::STATISTIC);

	background.setPosition((float)position[82].x, (float)position[82].y);
	background.setSize(Vector2f(64 * 16, 45 * 11 - 3));
	background.setFillColor(Color(92, 94, 109, 150));
	background.setOutlineThickness(3);
	background.setOutlineColor(Color(19, 65, 113));


	list = new ListControl();
}


bool BaseState::checkClick()
{
	return isClick;
}

void BaseState::setOption(Option option)
{
	this->option = option;
}

Option BaseState::getOption()
{
	return option;
}

void BaseState::refresh()
{
}

void BaseState::update()
{
	for (int i = 0; i < 4; i++)
	{
		button[i]->update();
		if (button[i]->isClick)
		{
			isClick = true;
			option = button[i]->getOption();
			break;
		}
	}
}

void BaseState::draw()
{
	for (int i = 0; i < 4; i++)
		button[i]->draw();

	graphicData->window->draw(background);
	graphicData->window->draw(title);
	graphicData->window->draw(notification);
}