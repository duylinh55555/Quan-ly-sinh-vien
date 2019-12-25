#include "ClassInformation.h"

ClassInformation::ClassInformation(GraphicData* graphicData)
{
	this->graphicData = graphicData;

	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Error open file";
		system("pause");
	}
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

	table.setPosition((float)position[123].x, (float)position[123].y);
	table.setSize(Vector2f(512, 315));
	table.setOutlineThickness(3);
	table.setOutlineColor(Color(19, 65, 113));
	table.setFillColor(Color(90, 155, 194, 60));

	line[0].setPosition((float)position[129].x, (float)position[129].y);
	line[0].setSize(Vector2f(3, 35 * 9));
	line[0].setOutlineColor(Color(19, 65, 113));

	line[1].setPosition((float)position[143].x, (float)position[143].y);
	line[1].setSize(Vector2f(512, 3));
	line[1].setOutlineColor(Color(19, 65, 113));

	line[2].setPosition((float)position[243].x, (float)position[243].y);
	line[2].setSize(Vector2f(512, 3));
	line[2].setOutlineColor(Color(19, 65, 113));

	for (int i = 0; i < 19; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(28);
	}

	text[0].setFillColor(Color(193, 172, 106));
	text[6].setFillColor(Color(193, 172, 106));

	for (int i = 2; i < 19; i++)
		text[i].setFillColor(Color(177, 228, 198));

	text[12].setFillColor(Color(207, 117, 128));
	text[13].setFillColor(Color(207, 117, 128));

	text[0].setString(L"Xếp loại");
	text[0].setPosition((float)position[123].x + 155, (float)position[123].y + 5);
	text[1].setString(L"Xuất sắc");
	text[1].setPosition((float)position[143].x + 75, (float)position[143].y + 5);
	text[2].setString(L"Giỏi");
	text[2].setPosition((float)position[163].x + 75, (float)position[163].y + 5);
	text[3].setString(L"Khá");
	text[3].setPosition((float)position[183].x + 75, (float)position[183].y + 5);
	text[4].setString(L"Trung bình");
	text[4].setPosition((float)position[203].x + 75, (float)position[203].y + 5);
	text[5].setString(L"Yếu");
	text[5].setPosition((float)position[223].x + 75, (float)position[223].y + 5);
	text[6].setString(L"Số sinh viên");
	text[6].setPosition((float)position[129].x + 10, (float)position[129].y + 5);
	text[6].setCharacterSize(20);
	text[7].setString(L"");
	text[7].setPosition((float)position[149].x + 45, (float)position[149].y + 5);
	text[8].setString(L"");
	text[8].setPosition((float)position[169].x + 45, (float)position[169].y + 5);
	text[9].setString(L"");
	text[9].setPosition((float)position[189].x + 45, (float)position[189].y + 5);
	text[10].setString(L"");
	text[10].setPosition((float)position[209].x + 45, (float)position[209].y + 5);
	text[11].setString(L"");
	text[11].setPosition((float)position[229].x + 45, (float)position[229].y + 5);
	text[12].setString(L"Tổng số");
	text[12].setPosition((float)position[243].x + 155, (float)position[243].y + 5);
	text[13].setString(L"");
	text[13].setPosition((float)position[249].x + 45, (float)position[249].y + 5);

	text[14].setString(L"Xuất sắc");
	text[14].setPosition((float)position[176].x, (float)position[176].y);
	text[14].setFillColor(Color::Blue);
	text[14].setCharacterSize(20);
	text[15].setString(L"Giỏi");
	text[15].setPosition((float)position[196].x, (float)position[196].y);
	text[15].setFillColor(Color::Cyan);
	text[15].setCharacterSize(20);
	text[16].setString(L"Khá");
	text[16].setPosition((float)position[216].x, (float)position[216].y);
	text[16].setFillColor(Color::Green);
	text[16].setCharacterSize(20);
	text[17].setString(L"Trung bình");
	text[17].setPosition((float)position[236].x, (float)position[236].y);
	text[17].setFillColor(Color::Magenta);
	text[17].setCharacterSize(20);
	text[18].setString(L"Yếu");
	text[18].setPosition((float)position[256].x, (float)position[256].y);
	text[18].setFillColor(Color::Red);
	text[18].setCharacterSize(20);

	circleSector[0] = new CircleSector(graphicData, Vector2f(850, 400), Color::Blue);
	circleSector[1] = new CircleSector(graphicData, Vector2f(850, 400), Color::Cyan);
	circleSector[2] = new CircleSector(graphicData, Vector2f(850, 400), Color::Green);
	circleSector[3] = new CircleSector(graphicData, Vector2f(850, 400), Color::Magenta);
	circleSector[4] = new CircleSector(graphicData, Vector2f(850, 400), Color::Red);
}

void ClassInformation::setNode(classNode node)
{
	this->node = node;
}

void ClassInformation::update()
{
	string num;
	stringstream strExcellent, strGood, strAverage, strBelowAverage, strWeak, strSum;

	strExcellent << node->getNumberExcellent();
	num = strExcellent.str();
	text[7].setString(num);

	strGood << node->getNumberGood();
	num = strGood.str();
	text[8].setString(num);

	strAverage << node->getNumberAverage();
	num = strAverage.str();
	text[9].setString(num);

	strBelowAverage << node->getNumberBelowAverage();
	num = strBelowAverage.str();
	text[10].setString(num);

	strWeak << node->getNumberWeak();
	num = strWeak.str();
	text[11].setString(num);

	strSum << node->getNumberOfStudent();
	num = strSum.str();
	text[13].setString(num);

	float percent = 0;

	circleSector[0]->setPercent(0, node->getPercentExcellent());

	percent += node->getPercentExcellent();
	circleSector[1]->setPercent(percent, node->getPercentGood());

	percent += node->getPercentGood();
	circleSector[2]->setPercent(percent, node->getPercentAverage());

	percent += node->getPercentAverage();
	circleSector[3]->setPercent(percent, node->getPercentBelowAverage());

	percent += node->getPercentBelowAverage();
	circleSector[4]->setPercent(percent, node->getPercentWeak());

}

void ClassInformation::draw()
{
	for (int i = 0; i < 3; i++)
		graphicData->window->draw(line[i]);

	graphicData->window->draw(table);

	for (int i = 0; i < 19; i++)
		graphicData->window->draw(text[i]);

	for (int i = 0; i < 5; i++)
		circleSector[i]->draw();
}
