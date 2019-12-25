#ifndef FINDOPTION_H
#define FINDOPTION_H

#include "PrintOption.h"

typedef list<Node>::iterator NodeNode;

class FindOption :
	public BaseState
{
private:
	Button* button[3];	//	Chọn option tìm kiếm (Mã SV, mã lớp, họ tên)
	TextBox* findTextBox; // Khung tìm kiếm
	ListView* listView;	//	Listview của các đối tượng tìm được

	ListControl* foundList;	//	Danh sách các đối tượng tìm được
	string str;			//	Từ khóa tìm kiếm
	Option option;
	bool isSelected;	//	true = chọn xem thông tin đối tượng

	Node previousNode(Node node);
	void standardized(string& str);
public:
	FindOption(GraphicData* graphicData, ListControl* list);
	~FindOption();

	void findFoundList();
	void findAllList();
	void update();
	void draw();
};

#endif // !FINDOPTION_H