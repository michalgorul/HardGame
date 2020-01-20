#pragma once
#include "classes.h"

//jedna klasa bazowa dla hierarchi klas
//u¿ywam klasy abstrakcyjnej
class OptionBase
{
public:
	//metody wirtualne
	virtual void draw(RenderWindow& W) = 0;

	virtual void MoveUp() = 0;

	virtual void MoveDown() = 0;

	virtual int GetPressedItem() = 0;

};

//funkcja pomocnicza
void draw_option(OptionBase* pointer, RenderWindow& W);

