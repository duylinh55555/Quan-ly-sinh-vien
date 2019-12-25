#include "ClassListViewItem.h"

ClassListViewItem::ClassListViewItem()
{
}

ClassListViewItem::ClassListViewItem(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option)
	:Button(graphicData, position, length, width, s, color, option)
{
	maLop.setFont(font);
	maLop.setCharacterSize(26);
	maLop.setPosition((float)position.x + 80, (float)position.y);

	tenLop.setFont(font);
	tenLop.setString("");
	tenLop.setCharacterSize(26);
	tenLop.setPosition((float)position.x + 300, (float)position.y);

	soSinhVien.setFont(font);
	soSinhVien.setCharacterSize(26);
	soSinhVien.setPosition((float)position.x + 880, (float)position.y);

	line[0].setPosition((float)position.x + 252, (float)position.y);
	line[0].setSize(Vector2f(3, 35));

	line[1].setPosition((float)position.x + 765, (float)position.y);
	line[1].setSize(Vector2f(3, 35));
}

void ClassListViewItem::setParameter(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option)
{
	Button::setParameter(graphicData, position, length, width, s, color, option);

	maLop.setFont(font);
	maLop.setCharacterSize(26);
	maLop.setPosition((float)position.x + 80, (float)position.y);

	tenLop.setFont(font);
	tenLop.setCharacterSize(26);
	tenLop.setPosition((float)position.x + 300, (float)position.y);

	soSinhVien.setFont(font);
	soSinhVien.setCharacterSize(26);
	soSinhVien.setPosition((float)position.x + 880, (float)position.y);

	line[0].setPosition((float)position.x + 252, (float)position.y);
	line[0].setSize(Vector2f(3, 35));

	line[1].setPosition((float)position.x + 765, (float)position.y);
	line[1].setSize(Vector2f(3, 35));
}

void ClassListViewItem::setNode(classNode pClass)
{
	this->pClass = pClass;

	maLop.setString(pClass->getClassName());

	if (pClass->getClassName() == "CNTT1")
		tenLop.setString(L"Công nghệ thông tin 1");
	else if (pClass->getClassName() == "CNTT2")
		tenLop.setString(L"Công nghệ thông tin 2");
	else if (pClass->getClassName() == "ANHTTT")
		tenLop.setString(L"An ninh hệ thống thông tin");
	else if (pClass->getClassName() == "BDATTT")
		tenLop.setString(L"Bảo đảm an toàn thông tin");
	else if (pClass->getClassName() == "DTH")
		tenLop.setString(L"Địa tin học");

	string num;
	stringstream str2num;
	str2num << pClass->getNumberOfStudent();
	num = str2num.str();
	soSinhVien.setString(num);
}

classNode ClassListViewItem::getNode()
{
	return pClass;
}

void ClassListViewItem::update()
{
	Button::update();
}

void ClassListViewItem::draw()
{
	Button::draw();
	graphicData->window->draw(maLop);
	graphicData->window->draw(tenLop);
	graphicData->window->draw(soSinhVien);

	graphicData->window->draw(line[0]);
	graphicData->window->draw(line[1]);
}