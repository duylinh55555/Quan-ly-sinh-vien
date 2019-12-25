#include "ListView.h"

void ListView::calTotalPage()
{
	if (numberOfObject % 10 == 0)
		totalPage = numberOfObject / 10;
	else
		totalPage = (numberOfObject / 10) + 1;
}

void ListView::refreshPage()
{
	nodeEndOfPage = nodeBeginOfPage;

	setNextPage();
}

void ListView::refreshNumberOfObject()
{
	numberOfObject = list->getSize();
	calTotalPage();
	refreshPage();
}

void ListView::moveToFirstPage()
{
	nodeBeginOfPage = list->getBegin();
	page = 0;
}

void ListView::setNextPage()
{
	nodeBeginOfPage = nodeEndOfPage;

	for (int i = 0; i < 10; i++)
	{
		if (nodeEndOfPage != list->getEnd())
		{
			object[i].setNode(nodeEndOfPage);
			nodeEndOfPage++;
		}

		else
			//	Kết thúc danh sách
			break;
	}
}

void ListView::setPreviousPage()
{
	nodeEndOfPage = nodeBeginOfPage;

	for (int i = 9; i >= 0; i--)
	{
		nodeBeginOfPage--;
		object[i].setNode(nodeBeginOfPage);
	}
}

ListView::ListView(GraphicData* graphicData, ListControl* list)
{
	this->graphicData = graphicData;
	this->list = list;
	numberOfObject = list->getSize();
	inforTable = new InformationTable(graphicData);
	isSelected = false;
	locationOfSelectedObject = 0;
	option = Option::LISTVIEW;
	isChangeButtonClick = false;

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

	// Button sắp xếp
	sortButton[0] = new Button(graphicData, position[82], 187, 35, L" Mã sinh viên", Color(153, 157, 242), Option::MA_SINH_VIEN);
	sortButton[0]->setTextColor(Color(44, 64, 51));

	sortButton[1] = new Button(graphicData, position[85], 123, 35, L"  Mã lớp", Color(153, 157, 242), Option::MA_LOP);
	sortButton[1]->setTextColor(Color(44, 64, 51));

	sortButton[2] = new Button(graphicData, position[87], 379, 35, L"\t\t\t\t\tHọ tên", Color(153, 157, 242), Option::HO_TEN);
	sortButton[2]->setTextColor(Color(44, 64, 51));

	sortButton[3] = new Button(graphicData, position[93], 187, 35, L"  Ngày sinh", Color(153, 157, 242), Option::NGAY_SINH);
	sortButton[3]->setTextColor(Color(44, 64, 51));

	sortButton[4] = new Button(graphicData, position[96], 128, 35, L"   Điểm", Color(153, 157, 242), Option::DIEM_TRUNG_BINH);
	sortButton[4]->setTextColor(Color(44, 64, 51));


	//	Lấy từ object từ list gán vào từng ô listviewitem
	nodeBeginOfPage = list->getBegin();
	nodeEndOfPage = nodeBeginOfPage;

	for (int i = 0; i < 10; i++)
		object[i].setParameter(graphicData, position[20 * (i % 10) + 102], 1014, 35, L"", Color(38, 185, 255, 100), Option::EMPTY);

	setNextPage();

	//	Button trước, sau, trở lại
	prePage = new Button(graphicData, position[281], 58, 45, L"Trước", Color(72, 81, 232), Option::EMPTY);
	prePage->setTextSize(20);

	nextPage = new Button(graphicData, Vector2i(position[298].x + 6, position[298].y), 56, 45, L"Sau", Color(72, 81, 232), Option::EMPTY);
	nextPage->setTextSize(24);

	backButton = new Button(graphicData, Vector2i(position[298].x + 6, position[298].y), 56, 45, L"Back", Color(96, 106, 134), Option::EMPTY);
	backButton->setTextSize(24);

	changeButton = new Button(graphicData, position[141], 56, 45, L"Sửa", Color(99, 171, 124), Option::EMPTY);
	changeButton->setTextSize(24);

	deleteButton = new Button(graphicData, position[241], 56, 45, L"Xóa", Color(202, 68, 88), Option::EMPTY);
	deleteButton->setTextSize(24);

	notification = "Trang ";
}

string ListView::getNofication()
{
	return notification;
}

void ListView::update()
{
	switch (option)
	{
	case Option::LISTVIEW:
		if (numberOfObject > 0)
		{
			for (int i = 0; i < 5; i++)
			{
				sortButton[i]->update();

				//	Lựa chọn kiểu sắp xếp
				if (sortButton[i]->isClick)
				{
					Option option = sortButton[i]->getOption();

					switch (option)
					{
					case Option::MA_SINH_VIEN:
						list->idSort();
						break;

					case Option::MA_LOP:
						list->classIdSort();
						break;

					case Option::HO_TEN:
						list->nameSort();
						break;

					case Option::NGAY_SINH:
						list->birthdaySort();
						break;

					case Option::DIEM_TRUNG_BINH:
						list->markSort();
						break;

					default:
						break;
					}

					//	refresh
					numberOfObject = list->getSize();
					calTotalPage();
					nodeBeginOfPage = list->getBegin();
					page = 0;
					refreshPage();
				}
			}
		}

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
			Node node = object[locationOfSelectedObject].getNode();
			inforTable->setStudent(*node);
			inforTable->setStringEmpty();
			inforTable->update();

			isSelected = false;
			option = Option::TABLE;
		}

		isChangeButtonClick = false;
		break;

	case Option::TABLE:
		if (!isChangeButtonClick)
		{
			changeButton->update();

			if (changeButton->isClick)
				isChangeButtonClick = true;
		}

		if (isChangeButtonClick)
		{
			inforTable->update();

			if (inforTable->isEnter)
			{
				/*for (Node temp = list->getBegin(); temp != list->getEnd(); temp++)
				{
					Student student = *temp;

					cout << student.getHoTen() << endl;
					cout << student.getMaSinhVien() << endl;
					cout << student.getMaLop() << endl;
					cout << student.getNgaySinh().day << "/" << student.getNgaySinh().month << "/" << student.getNgaySinh().year << endl;
					cout << student.getDiemTrungBinh() << endl;
				}*/

				Node node = object[locationOfSelectedObject].getNode();
				*node = inforTable->getStudent();
				object[locationOfSelectedObject].setNode(node);

				list->saveToFile();

				option = Option::LISTVIEW;
				inforTable->isEnter = false;
			}
		}

		deleteButton->update();
		if (deleteButton->isClick)
		{
			Node node = object[locationOfSelectedObject].getNode();
			if (node == list->getBegin())
				nodeBeginOfPage++;

			list->Delete(node);
			numberOfObject--;
			calTotalPage();
			list->saveToFile();

			refreshPage();
			option = Option::LISTVIEW;
		}

		backButton->update();
		if (backButton->isClick)
			option = Option::LISTVIEW;

		break;

	default:
		break;
	}
}

void ListView::draw()
{
	switch (option)
	{
	case Option::LISTVIEW:
		for (int i = 0; i < 5; i++)
			sortButton[i]->draw();

		for (int i = 0; i < objectInPage; i++)
		{
			if (i < numberOfObject)
				object[i].draw();
		}

		nextPage->draw();
		prePage->draw();
		break;

	case Option::TABLE:
		inforTable->draw();
		backButton->draw();
		changeButton->draw();
		deleteButton->draw();
		break;

	default:
		break;
	}
}
