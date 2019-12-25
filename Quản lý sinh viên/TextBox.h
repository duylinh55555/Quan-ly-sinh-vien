#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <sstream>
#include "Button.h"

#define DELETE 8
#define ENTER  13
#define ESCAPE 27

//	Khung ký tự
class TextBox :
	public Button
{
private:
	GraphicData* graphicData;
	string str;
	Text text;
	wstring instruction;

	//	Xóa ký tự cuối cùng
	void deleteCharacter();
	//	Xử lý sự kiện
	void typeOn();

public:
	TextBox(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option);
	virtual ~TextBox();

	void deleteText();
	//	Xóa text mặc định của button (VD: Nguyen Van A)
	void setStringEmpty();
	//	true = sẵn sàng nhập
	bool isSecleted;
	//	true = nhảy sang textbox kế tiếp
	bool isNext;
	//	Cài đặt text trong khung textbox
	void setText(string str);
	//	Xuất text
	string getText();
	float getNumber();
	void update();
	void draw();
};

#endif