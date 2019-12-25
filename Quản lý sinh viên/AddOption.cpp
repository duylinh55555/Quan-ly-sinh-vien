#include "AddOption.h"

AddOption::AddOption(GraphicData* graphicData, ListControl* list)
	:BaseState(graphicData, list)
{
	inforTable = new InformationTable(graphicData);

	errorMessage = new Text(L"", font, 22);
	errorMessage->setFillColor(Color::Red);
	errorMessage->setPosition((float)position[146].x, (float)position[146].y + 10);

	BaseState::notification.setPosition(Vector2f(550, 675));
	BaseState::notification.setString(L"Nhập thông tin sinh viên");
}

void AddOption::update()
{
	BaseState::update();

	inforTable->update();

	if (inforTable->isEnter)
	{
		Student student = inforTable->getStudent();

		try
		{
			listOfStudent->Insert(student);
			listOfStudent->saveToFile();
			BaseState::notification.setString(L"Lưu thành công");
			errorMessage->setString(L"");
		}
		catch (const wstring ex)
		{
			errorMessage->setString(ex);
		}

		inforTable = new InformationTable(graphicData);
		BaseState::notification.setString(L"Nhập thông tin sinh viên");
	}
}

void AddOption::draw()
{
	BaseState::draw();

	inforTable->draw();

	graphicData->window->draw(*errorMessage);
}

