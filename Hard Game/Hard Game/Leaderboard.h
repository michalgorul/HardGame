#pragma once
#include "Menu.h"
#include "Player.h"

class Leaderboard : public Menu
{
private:
	bool ifChosen;
	float level_1[5];		//atrybuty do wyœwietlenia statystyk
	float level_2[5];
	float level_3[5];
public:

	Leaderboard(float width, float height);

	void draw(RenderWindow& W);

	void draw_level_1(RenderWindow& W);
	
	void draw_level_2(RenderWindow& W);
	
	void draw_level_3(RenderWindow& W);

	void mainMenu(Event& e, RenderWindow& W);

	bool getIfChosen();

	void changeIfChosen();

	void saveToLeaderboard(float x, int current_level);

	void reading_from_file(ifstream& leaderboard);				//odczyt z pliku

	void saving_to_file();										//zapis do pliku

};

