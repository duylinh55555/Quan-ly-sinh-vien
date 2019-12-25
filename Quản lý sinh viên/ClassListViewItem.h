#ifndef CLASLISTVIEWITEM
#define CLASLISTVIEWITEM

#include "ClassInformation.h"


class ClassListViewItem
	: public Button
{
private:
	classNode pClass;
	Text maLop;
	Text tenLop;
	Text soSinhVien;

	//	Đường phân cách
	RectangleShape line[2];

public:
	ClassListViewItem();
	ClassListViewItem(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option);

	void setParameter(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option);
	void setNode(classNode pStudent);
	classNode getNode();
	void update();
	void draw();
};

#endif // !CLASLISTVIEWITEM