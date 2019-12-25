#ifndef CLASSINFORMATION_H
#define CLASSINFORMATION_H

#include "ListView.h"

typedef list<ClassStatistic>::iterator classNode;

class ClassInformation
{
private:
	GraphicData* graphicData;
	Vector2i position[320];
	Font font;
	RectangleShape table;
	RectangleShape line[3];
	CircleSector* circleSector[5];

	Text text[19];

	classNode node;

public:
	ClassInformation(GraphicData* graphicData);

	void setNode(classNode node);

	void update();
	void draw();
};

#endif // !CLASSINFORMATION_H