#ifndef INFORMATIONTABLE_H
#define INFORMATIONTABLE_H

#include "TextBox.h"
#include "ClassStatistic.h"

//	Khung chỉnh sửa thông tin
class InformationTable
{
private:
	GraphicData* graphicData;
	Vector2i position[320];
	RectangleShape background;
	TextBox* textBox[7];
	Font font;
	Text* title[8];
	Button* enter;
	Text* errorMessage[5];
	Text* textEnter;

	Student student;

public:
	InformationTable(GraphicData* graphicData);

	void setStringEmpty();
	bool isEnter;
	void setStudent(Student student);
	Student getStudent();
	void update();
	void draw();
};

#endif // !INFORMATIONTABLE_H