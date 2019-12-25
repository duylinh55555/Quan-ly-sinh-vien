#include "Program.h"

Program::Program()
{
	window = new RenderWindow(VideoMode(1280, 730), L"Quản lý sinh viên", Style::Close);
	Event* e = &event;
	graphicData = new GraphicData(window, e);

	list.loadFromFile();

	baseState = new BaseState(graphicData, &list);
	addOption = new AddOption(graphicData, &list);
	printOption = new PrintOption(graphicData, &list);
	findOption = new FindOption(graphicData, &list);
	statisticOption = new StatisticOption(graphicData, &list);

	states.push(baseState);
}

void Program::run()
{
	//	Main Loop
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			//	Sự kiện đóng cửa sổ chương trình
			if (event.type == Event::Closed)
				window->close();

			window->clear();

			states.top()->update();

			//	Render
			states.top()->draw();

			window->display();

			//	Nhảy các option
			if (states.top()->getOption() != Option::EMPTY)
			{
				switch (states.top()->getOption())
				{
				case Option::ADD:
					if (states.top() != addOption)
						states.push(addOption);

					states.top()->setOption(Option::EMPTY);
					break;

				case Option::PRINT:
					if (states.top() != printOption && list.getSize() != 0)
					{
						printOption->refresh();
						states.push(printOption);
					}

					states.top()->setOption(Option::EMPTY);
					break;

				case Option::FIND:
					if (states.top() != findOption && list.getSize() != 0)
						states.push(findOption);

					states.top()->setOption(Option::EMPTY);
					break;

				case Option::STATISTIC:
					if (states.top() != statisticOption && list.getSize() != 0)
					{
						statisticOption->refresh();
						states.push(statisticOption);
					}

					states.top()->setOption(Option::EMPTY);
					break;

				default:
					break;
				}
			}
		}
	}
}