#include "Button.h"

Button::Button()
{
	isClick = false;
	length = 200;
	width = 300;
	option = Option::EMPTY;
}

Button::Button(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option)
{
	this->graphicData = graphicData;
	this->position = position;
	this->length = length;
	this->width = width;
	this->color = color;
	this->option = option;
	isClick = false;

	button.setPosition((float)this->position.x, (float)this->position.y);
	button.setSize(Vector2f((float)this->length, (float)this->width));
	button.setOutlineThickness(3);
	button.setOutlineColor(Color(19, 65, 113));

	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Error open file";
		system("pause");
	}

	text.setString(s);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::Color(166, 96, 25));
	text.setPosition(Vector2f((float)this->position.x, (float)this->position.y));
}

Button::~Button()
{
}

void Button::setParameter(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option)
{
	this->graphicData = graphicData;
	this->position = position;
	this->length = length;
	this->width = width;
	this->color = color;
	this->option = option;
	isClick = false;

	button.setPosition((float)this->position.x, (float)this->position.y);
	button.setSize(Vector2f((float)this->length, (float)this->width));
	button.setOutlineThickness(3);
	button.setOutlineColor(Color(19, 65, 113));

	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Error open file";
		system("pause");
	}

	text.setString(s);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::Color(166, 96, 25));
	text.setPosition(Vector2f((float)this->position.x, (float)this->position.y));
}

void Button::setTextSize(int size)
{
	text.setCharacterSize(size);
}

void Button::setColor(Color color)
{
	this->color = color;
}

void Button::setTextColor(Color color)
{
	text.setFillColor(color);
}

bool Button::isInside()
{
	int mouseX = Mouse::getPosition(*graphicData->window).x;
	int mouseY = Mouse::getPosition(*graphicData->window).y;

	if (mouseX > position.x&& mouseX < (position.x + length) && mouseY > position.y&& mouseY < (position.y + width))
	{
		button.setFillColor(color);
		return true;
	}
	else
	{
		button.setFillColor(Color::Color(color.r, color.g, color.b, color.a - 80));
		return false;
	}
}

void Button::update()
{
	if (isInside())
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			isClick = true;
		else
			isClick = false;
	}
	else
	{
		isClick = false;
	}
}

void Button::draw()
{
	graphicData->window->draw(button);
	graphicData->window->draw(text);
}

Option Button::getOption()
{
	return option;
}

void Button::setOption(Option option)
{
	this->option = option;
}