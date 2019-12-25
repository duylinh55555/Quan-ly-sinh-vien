#include "TextBox.h"

/*
	q 13
	w 17
	e 13
	r 11
	t 8
	y 15
	u 14
	i 6
	o 15
	p 13
	a 13
	s 13
	d 13
	f 9
	g 13
	h 13
	j 7
	k 13
	l 5
	z 13
	x 13
	c 11
	v 13
	b 13
	n 13
	m 19

	space 7

	1	9
	2	13
	3	13
	4	14
	5	12
	6	13
	7
	8
	9
	0
*/

TextBox::TextBox(GraphicData* graphicData, Vector2i position, int length, int width, wstring s, Color color, Option option)
	: Button(graphicData, position, length, width, s, color, option)
{
	this->graphicData = graphicData;
	instruction = s;
	isSecleted = false;
	isNext = false;

	text.setFont(font);
	text.setFillColor(Color::Yellow);
	text.setPosition(Vector2f((float)this->position.x, (float)this->position.y));

	str = "";
	Button::text.setFillColor(Color(150, 145, 44));
	if (option == Option::DAY || option == Option::MONTH || option == Option::YEAR)
	{
		text.setCharacterSize(20);
		Button::text.setCharacterSize(16);
	}
	else
	{
		text.setCharacterSize(24);
		Button::text.setCharacterSize(20);
	}
}


TextBox::~TextBox()
{
}

void TextBox::deleteText()
{
	str = "";
}

void TextBox::setStringEmpty()
{
	Button::text.setString("");
}

void TextBox::deleteCharacter()
{
	str.pop_back();
	str.pop_back();
	str += "_";
}

void TextBox::typeOn()
{
	int charType = graphicData->event->text.unicode;

	if (charType < 128)
	{
		if (charType == DELETE)
		{
			if (str != "_")
				deleteCharacter();
		}

		else if (charType == ENTER)
		{
			isNext = true;
		}

		else
		{
			//	Chỉ cho phép nhập số đối với ngày sinh
			if (option == Option::DAY || option == Option::MONTH || option == Option::YEAR)
			{
				if (14 * str.size() < Button::length - 5)
				{
					if (charType >= 48 && charType <= 57)
					{
						str.pop_back();
						str += static_cast<char>(charType);
						str += "_";
					}
				}
			}
			//	Chỉ cho phép nhập số, dấu chấm đối với điểm
			else if (option == Option::DIEM_TRUNG_BINH)
			{
				if (14 * str.size() < Button::length)
				{
					if (charType >= 48 && charType <= 57 || charType == 46)
					{
						str.pop_back();
						str += static_cast<char>(charType);
						str += "_";
					}
				}
			}
			else
			{
				if (14 * str.size() < Button::length - 25)
				{
					if (charType >= 48 && charType <= 57 || charType >= 65 && charType <= 90 || charType >= 97 && charType <= 122 || charType == 32)
					{
						str.pop_back();
						str += static_cast<char>(charType);
						str += "_";
					}
				}
			}
		}
	}
}

void TextBox::setText(string str)
{
	this->str = str;
}

string TextBox::getText()
{
	if (str != "" && str.back() == '_')
		str.pop_back();

	return str;
}

float TextBox::getNumber()
{
	float number;
	stringstream str2num(str);
	str2num >> number;

	return number;
}

void TextBox::update()
{
	isNext = false;

	if (isInside())
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			isSecleted = true;
	}
	else
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			isSecleted = false;
	}

	if (isSecleted)
	{
		if (str != "")
		{
			if (str.back() != '_')
				str.push_back('_');
		}
		else
			str.push_back('_');

		Button::text.setString("");

		if (graphicData->event->type == Event::TextEntered)
			typeOn();
	}
	else
	{
		if (str == "_")
			str = "";

		else if (str != "" && str.back() == '_')
			str.pop_back();

		else if (str == "")
			Button::text.setString(instruction);
	}

	text.setString(str);
}

void TextBox::draw()
{
	Button::draw();
	graphicData->window->draw(text);
}