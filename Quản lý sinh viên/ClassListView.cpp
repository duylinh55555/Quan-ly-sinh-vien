#include "ClassListView.h"

void ClassListView::calTotalPage()
{
	if (numberOfObject % 10 == 0)
		totalPage = numberOfObject / 10;
	else
		totalPage = (numberOfObject / 10) + 1;
}

void ClassListView::refreshPage()
{
	nodeEndOfPage = nodeBeginOfPage;

	setNextPage();
}

void ClassListView::refreshNumberOfObject()
{
	numberOfObject = classList->size();
	calTotalPage();
	refreshPage();
}

void ClassListView::moveToFirstPage()
{
	nodeBeginOfPage = classList->begin();
	page = 0;
}

void ClassListView::setNextPage()
{
	nodeBeginOfPage = nodeEndOfPage;

	for (int i = 0; i < 10; i++)
	{
		if (nodeEndOfPage != classList->end())
		{
			object[i].setNode(nodeEndOfPage);
			nodeEndOfPage++;
		}

		else
			//	Kết thúc danh sách
			break;
	}
}

void ClassListView::setPreviousPage()
{
	nodeEndOfPage = nodeBeginOfPage;

	for (int i = 9; i >= 0; i--)
	{
		nodeBeginOfPage--;
		object[i].setNode(nodeBeginOfPage);
	}
}

ClassListView::ClassListView(GraphicData* graphicData, list<ClassStatistic>* classList)
{
	this->graphicData = graphicData;
	this->classList = classList;
	numberOfObject = classList->size();
	classInformation = new ClassInformation(graphicData);
	isSelected = false;
	locationOfSelectedObject = 0;
	option = Option::LISTVIEW;

	page = 0;
	calTotalPage();

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

	//	Lấy từ object từ list gán vào từng ô listviewitem
	nodeBeginOfPage = classList->begin();
	nodeEndOfPage = nodeBeginOfPage;

	for (int i = 0; i < 10; i++)
		object[i].setParameter(graphicData, position[20 * (i % 10) + 102], 1014, 35, L"", Color(38, 185, 255, 100), Option::EMPTY);

	//setNextPage();

	//	Button trước, sau, trở lại
	prePage = new Button(graphicData, position[281], 58, 45, L"Trước", Color(72, 81, 232), Option::EMPTY);
	prePage->setTextSize(20);

	nextPage = new Button(graphicData, Vector2i(position[298].x + 6, position[298].y), 56, 45, L"Sau", Color(72, 81, 232), Option::EMPTY);
	nextPage->setTextSize(24);

	backButton = new Button(graphicData, Vector2i(position[298].x + 6, position[298].y), 56, 45, L"Back", Color(96, 106, 134), Option::EMPTY);
	backButton->setTextSize(24);

	notification = "Trang ";

	titleBox.setPosition((float)position[82].x, (float)position[82].y);
	titleBox.setSize(Vector2f(1024, 35));
	titleBox.setOutlineThickness(3);
	titleBox.setOutlineColor(Color(19, 65, 113));
	titleBox.setFillColor(Color(90, 155, 194, 60));

	totalBox.setPosition((float)position[302].x, (float)position[302].y);
	totalBox.setSize(Vector2f(1024, 35));
	totalBox.setOutlineThickness(3);
	totalBox.setOutlineColor(Color(19, 65, 113));
	totalBox.setFillColor(Color(90, 155, 194, 60));

	line[0].setPosition((float)position[82].x + 252, (float)position[82].y);
	line[0].setFillColor(Color(19, 65, 113));
	line[0].setSize(Vector2f(3, 35));
	line[1].setPosition((float)position[82].x + 765, (float)position[82].y);
	line[1].setFillColor(Color(19, 65, 113));
	line[1].setSize(Vector2f(3, 35));
	line[2].setPosition((float)position[302].x + 765, (float)position[302].y);
	line[2].setFillColor(Color(19, 65, 113));
	line[2].setSize(Vector2f(3, 35));

	
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Error open file";
		system("pause");
	}
	for (int i = 0; i < 3; i++)
	{
		titleInBox[i].setFont(font);
		titleInBox[i].setCharacterSize(28);
		titleInBox[i].setFillColor(Color(193, 172, 106));
	}

	titleInBox[0].setString(L"Mã lớp");
	titleInBox[0].setPosition((float)position[82].x + 85, (float)position[82].y);
	titleInBox[1].setString(L"Tên lớp");
	titleInBox[1].setPosition((float)position[82].x + 460, (float)position[82].y);
	titleInBox[2].setString(L"Số sinh viên");
	titleInBox[2].setPosition((float)position[82].x + 820, (float)position[82].y);

	totalClass.setString(L"Tổng số");
	totalClass.setFont(font);
	totalClass.setCharacterSize(28);
	totalClass.setFillColor(Color(89, 159, 230, 140));
	totalClass.setPosition(Vector2f(450, 675));


	numberOfStudent.setFont(font);
	numberOfStudent.setCharacterSize(30);
	numberOfStudent.setFillColor(Color(137, 148, 197));
	numberOfStudent.setPosition((float)position[302].x + 865, (float)position[302].y);
}

int ClassListView::getNumberOfStudent()
{
	int number = 0;
	for (classNode node = classList->begin(); node != classList->end(); node++)
		number += node->getNumberOfStudent();

	return number;
}

string ClassListView::getNofication()
{
	return notification;
}

void ClassListView::update()
{
	string num;
	stringstream str2num;
	switch (option)
	{
	case Option::LISTVIEW:

		str2num << getNumberOfStudent();
		num = str2num.str();

		numberOfStudent.setString(num);

		notification = "Trang ";
		notification += (char)(page + 1 + 48);
		notification += " / ";
		notification += (char)(totalPage + 48);
		//	Chuyển trang
		if (page > 0)
		{
			prePage->setColor(Color(72, 81, 232));
			prePage->update();
			if (prePage->isClick)
			{
				setPreviousPage();
				page--;
			}
		}
		else if (page == 0)
		{
			prePage->setColor(Color::Red);
			prePage->update();
		}

		if (page < totalPage - 1)
		{
			nextPage->setColor(Color(72, 81, 232));
			nextPage->update();
			if (nextPage->isClick)
			{
				setNextPage();
				page++;
			}
		}
		else if (page == totalPage - 1)
		{
			nextPage->setColor(Color::Red);
			nextPage->update();
		}

		//	Chọn từng đối tượng sinh viên
		for (int i = 0; i < 10; i++)
		{
			if (page == totalPage - 1)
				objectInPage = numberOfObject - 10 * page;
			else
				objectInPage = 10;

			if (i < objectInPage)
			{
				object[i].update();

				if (object[i].isClick)
				{
					isSelected = true;
					locationOfSelectedObject = i;
					break;
				}
				else if (i == numberOfObject)
					isSelected = false;
			}
		}

		if (isSelected)
		{
			classNode node = object[locationOfSelectedObject].getNode();
			classInformation->setNode(node);

			isSelected = false;
			option = Option::TABLE;
		}

		break;

	case Option::TABLE:
		classInformation->update();

		backButton->update();
		if (backButton->isClick)
			option = Option::LISTVIEW;

		break;

	default:
		break;
	}
}

void ClassListView::draw()
{
	switch (option)
	{
	case Option::LISTVIEW:

		for (int i = 0; i < objectInPage; i++)
		{
			if (i < numberOfObject)
				object[i].draw();
		}

		nextPage->draw();
		prePage->draw();

		for (int i = 0; i < 3; i++)
			graphicData->window->draw(titleInBox[i]);

		graphicData->window->draw(titleBox);
		graphicData->window->draw(totalBox);

		for (int i = 0; i < 3; i++)
			graphicData->window->draw(line[i]);

		graphicData->window->draw(totalClass);
		graphicData->window->draw(numberOfStudent);
		break;

	case Option::TABLE:
		classInformation->draw();

		backButton->draw();
		break;

	default:
		break;
	}
}
