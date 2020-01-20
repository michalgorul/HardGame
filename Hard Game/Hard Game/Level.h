#pragma once
#include "classes.h"
#include "Options.h"

class Level : public Options
{
private:
	int choosenLevel;
	bool ifChosen;
	bool ifChanged;
	Texture texture[MAX_NUMBER_OF_ITEMS];
	Sprite sprite[MAX_NUMBER_OF_ITEMS];
public:
	Level() : choosenLevel(0), ifChosen(false), ifChanged(false) { };

	Level(float width, float height);

	void draw(RenderWindow& W);

	void MoveUp();

	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }

	void mainMenu(Event& e, RenderWindow& W, int& current_level, float& angle);

	bool getIfChosen();

	void changeIfChosen();

	void changeLevel(int level);

	int getLevel();

	bool getIfChanged();

	void changeIfChanged();
};

