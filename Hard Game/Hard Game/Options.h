#pragma once
#include "classes.h"
#include "Menu.h"

class Options : public Menu
{
private:
	bool ifChosen;

public:
	Options() : ifChosen(false) { }

	Options(float width, float height);

	void draw(RenderWindow& W);

	void MoveUp();

	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }

	void mainMenu(Event& e, RenderWindow& W, Sound& theme, Level& menuL, Leaderboard& menuLe);

	bool getIfChosen();

	void changeIfChosen();

};

