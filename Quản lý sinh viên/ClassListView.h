#ifndef CLASSLISTVIEW_H
#define CLASSLISTVIEW_H

#include "ClassListViewItem.h"

class ClassListView
{
	GraphicData* graphicData;
	Vector2i position[320];
	Font font;

	list<ClassStatistic>* classList;

	ClassInformation* classInformation;
	ClassListViewItem object[10];
	Button* nextPage;
	Button* prePage;
	Button* backButton;

	RectangleShape titleBox;
	RectangleShape totalBox;
	RectangleShape line[3];
	Text titleInBox[3];
	Text totalClass;
	Text numberOfStudent;

	//InformationTable* inforTable;

	//	Con trỏ đầu trang
	classNode nodeBeginOfPage;
	//	Con trỏ đầu trang kế tiếp (node++ 10x)
	classNode nodeEndOfPage;
	Option option;
	string notification;
	int numberOfObject;
	int locationOfSelectedObject;
	int page;
	int totalPage;
	int objectInPage;

	//	Tính tổng số trang
	void calTotalPage();
	//	Cài đặt object student cho trang trước
	void setNextPage();
	//	Cài đặt object student cho trang sau
	void setPreviousPage();

public:
	ClassListView(GraphicData* graphicData, list<ClassStatistic>* list);

	int getNumberOfStudent();
	//	Làm mới trang
	void refreshPage();
	//	Page tới đầu danh sách
	void moveToFirstPage();
	//	Tính lại số trang, refresh trang
	void refreshNumberOfObject();
	Student selectedObject;
	bool isSelected;
	string getNofication();
	void update();
	void draw();
};

#endif // !CLASSLISTVIEW_H