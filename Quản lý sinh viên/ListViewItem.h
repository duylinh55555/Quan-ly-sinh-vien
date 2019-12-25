#ifndef LISTVIEWITEM_H
#define LISTVIEWITEM_H

#include "InformationTable.h"

class ListViewItem :
	public Button
{
private:
	Node pStudent;
	Text maSinhVien;
	Text maLop;
	Text hoTen;
	Text ngaySinh;
	Text diemTrungBinh;

	//	Đường phân cách
	RectangleShape line[4];

public:
	ListViewItem();
	ListViewItem(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option);

	void setParameter(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option);
	void setNode(Node temp);
	Node getNode();
	void update();
	void draw();
};

#endif // !LISTVIEWITEM_H