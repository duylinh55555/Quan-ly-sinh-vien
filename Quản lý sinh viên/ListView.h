#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "ListViewItem.h"

class ListView
{
private:
	GraphicData* graphicData;
	Vector2i position[320];

	Button* sortButton[5];
	ListControl* list;
	ListViewItem object[10];
	Button* nextPage;
	Button* prePage;
	Button* backButton;
	Button* changeButton;
	Button* deleteButton;

	InformationTable* inforTable;

	//	Con trỏ đầu trang
	Node nodeBeginOfPage;
	//	Con trỏ đầu trang kế tiếp (node++ 10x)
	Node nodeEndOfPage;
	Option option;
	string notification;
	int numberOfObject;
	int locationOfSelectedObject;
	int page;
	int totalPage;
	int objectInPage;
	bool isChangeButtonClick;

	//	Tính tổng số trang
	void calTotalPage();
	//	Cài đặt object student cho trang trước
	void setNextPage();
	//	Cài đặt object student cho trang sau
	void setPreviousPage();

public:
	ListView(GraphicData* graphicData, ListControl* list);

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

#endif // !LISTVIEW_H