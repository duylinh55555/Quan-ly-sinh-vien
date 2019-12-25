#include "ListViewItem.h"

ListViewItem::ListViewItem()
{
}

ListViewItem::ListViewItem(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option)
	:Button(graphicData, position, length, width, s, color, option)
{
	maSinhVien.setFont(font);
	maSinhVien.setCharacterSize(26);
	maSinhVien.setPosition((float)position.x + 20, (float)position.y);

	maLop.setFont(font);
	maLop.setCharacterSize(26);
	maLop.setPosition((float)position.x + 192, (float)position.y);

	hoTen.setFont(font);
	hoTen.setCharacterSize(26);
	hoTen.setPosition((float)position.x + 340, (float)position.y);

	ngaySinh.setFont(font);
	ngaySinh.setCharacterSize(26);
	ngaySinh.setPosition((float)position.x + 720, (float)position.y);

	diemTrungBinh.setFont(font);
	diemTrungBinh.setCharacterSize(26);
	diemTrungBinh.setPosition((float)position.x + 927, (float)position.y);

	line[0].setPosition((float)position.x + 187, (float)position.y);
	line[0].setSize(Vector2f(3, 35));

	line[1].setPosition((float)position.x + 315, (float)position.y);
	line[1].setSize(Vector2f(3, 35));

	line[2].setPosition((float)position.x + 700, (float)position.y);
	line[2].setSize(Vector2f(3, 35));

	line[3].setPosition((float)position.x + 892, (float)position.y);
	line[3].setSize(Vector2f(3, 35));
}

void ListViewItem::setParameter(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option)
{
	Button::setParameter(graphicData, position, length, width, s, color, option);

	maSinhVien.setFont(font);
	maSinhVien.setCharacterSize(26);
	maSinhVien.setPosition((float)position.x + 20, (float)position.y);

	maLop.setFont(font);
	maLop.setCharacterSize(26);
	maLop.setPosition((float)position.x + 192, (float)position.y);

	hoTen.setFont(font);
	hoTen.setCharacterSize(26);
	hoTen.setPosition((float)position.x + 340, (float)position.y);

	ngaySinh.setFont(font);
	ngaySinh.setCharacterSize(26);
	ngaySinh.setPosition((float)position.x + 720, (float)position.y);

	diemTrungBinh.setFont(font);
	diemTrungBinh.setCharacterSize(26);
	diemTrungBinh.setPosition((float)position.x + 927, (float)position.y);

	line[0].setPosition((float)position.x + 187, (float)position.y);
	line[0].setSize(Vector2f(3, 35));

	line[1].setPosition((float)position.x + 315, (float)position.y);
	line[1].setSize(Vector2f(3, 35));

	line[2].setPosition((float)position.x + 700, (float)position.y);
	line[2].setSize(Vector2f(3, 35));

	line[3].setPosition((float)position.x + 892, (float)position.y);
	line[3].setSize(Vector2f(3, 35));
}

void ListViewItem::setNode(Node pStudent)
{
	this->pStudent = pStudent;

	maSinhVien.setString(pStudent->getMaSinhVien());
	maLop.setString(pStudent->getMaLop());
	hoTen.setString(pStudent->getHoTen());

	Date date = pStudent->getNgaySinh();
	string d, m, y, diem;
	stringstream strD, strM, strY, strDiem;
	strD << date.day;
	d = strD.str();
	strM << date.month;
	m = strM.str();
	strY << date.year;
	y = strY.str();
	strDiem << pStudent->getDiemTrungBinh();
	diem = strDiem.str();
	ngaySinh.setString(d + " / " + m + " / " + y);
	diemTrungBinh.setString(diem);
}

Node ListViewItem::getNode()
{
	return pStudent;
}

void ListViewItem::update()
{
	Button::update();
}

void ListViewItem::draw()
{
	Button::draw();
	graphicData->window->draw(maSinhVien);
	graphicData->window->draw(maLop);
	graphicData->window->draw(hoTen);
	graphicData->window->draw(ngaySinh);
	graphicData->window->draw(diemTrungBinh);

	for (int i = 0; i < 4; i++)
		graphicData->window->draw(line[i]);
}
