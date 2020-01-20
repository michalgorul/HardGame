#pragma once
#include "classes.h"
#include "OptionBase.h"

class Menu : public OptionBase
{
	friend class Options;
	friend class Level;
	friend class Leaderboard;
	private:
		int selectedItemIndex;
		Font font;
		Text menu[MAX_NUMBER_OF_ITEMS];
	
	public:
		Menu() : selectedItemIndex(0) { }
		
		Menu(float width, float height);
	
		void draw(RenderWindow& W);
	
		void MoveUp();
	
		void MoveDown();
	
		int GetPressedItem() { return selectedItemIndex; }
	
		void mainMenu(Event& e, RenderWindow& W, bool& START, Options& menuO);

};

