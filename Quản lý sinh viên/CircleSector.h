#ifndef CIRCLESECTOR_H
#define CIRCLESECTOR_H

#include "GraphicData.h"

class CircleSector
{
private:
	const float PI = 3.141592654;
	GraphicData* graphicData;
	Vector2f position;
	int radius;
	float percentOfCircle;
	float percentStart;
	Color color;

public:
	CircleSector(GraphicData* graphicData, Vector2f position, Color color)
	{
		this->graphicData = graphicData;
		this->position = position;
		this->percentOfCircle = 0;
		this->percentStart = 0;
		this->color = color;

		radius = 100;
	}

	void setPercent(float percentStart, float percentOfCircle)
	{
		this->percentOfCircle = percentOfCircle;
		this->percentStart = percentStart;
	}

	Vector2f findPosition(float percert)
	{
		float radian = 2 * PI * percert;

		float x = position.x;
		float y = position.y;

		x = x + radius * sin(radian);
		y = y - radius * cos(radian);

		return Vector2f(x, y);
	}

	void draw()
	{
		VertexArray arr(TriangleFan);

		Vertex point0 = position;
		point0.color = Color(color.r, color.g, color.b, 10);
		arr.append(Vertex(point0));

		arr.append(Vertex(findPosition(percentStart)));

		for (float i = 0; i <= percentOfCircle; i += 0.005)
		{
			Vertex point = findPosition(percentStart + i);
			point.color = color;
			arr.append(point);
		}

		graphicData->window->draw(arr);
	}
};

#endif // !CIRCLESECTOR_H