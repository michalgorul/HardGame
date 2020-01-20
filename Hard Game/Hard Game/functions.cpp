#include "functions.h"

void stopped_playing(RenderWindow& W, Player& P, Leaderboard& menuLe, Options& menuO, OptionBase* pointer, Level& menuL, Menu& menuM, int& current_level, Sprite& sprite_m)
{
	W.draw(sprite_m);

	if (P.get_ifWon())
	{
		menuLe.saveToLeaderboard(P.getTime(), current_level);
		P.changeIfWon();
	}

	if (menuO.getIfChosen())
	{
		pointer = &menuL;				//stosuje polimorfizm
		if (menuL.getIfChosen())
			draw_option(pointer, W);
		else if (menuLe.getIfChosen())
		{
			pointer = &menuLe;			//stosuje polimorfizm
			draw_option(pointer, W);
			menuLe.draw_level_1(W);
			menuLe.draw_level_2(W);
			menuLe.draw_level_3(W);
		}
		else
		{
			pointer = &menuO;			//stosuje polimorfizm
			draw_option(pointer, W);
		}
	}
	else
	{
		pointer = &menuM;				//stosuje polimorfizm
		draw_option(pointer, W);
	}
}

void operating_event(RenderWindow& W, Event& e, Player& P, Leaderboard& menuLe, Options& menuO,  Level& menuL, Menu& menuM, int& current_level, Sprite& sprite_m, bool& START, Sound& theme, NPC& obstacle)
{
	if (e.type == Event::Closed)
		W.close();

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		START = false;
		P.restartGame();
	}

	if (menuO.getIfChosen())
	{
		if (menuL.getIfChosen())
		{
			if (menuLe.getIfChosen())
				menuLe.mainMenu(e, W);
			else
				menuL.mainMenu(e, W, current_level, obstacle.angle);
		}
		else
			menuO.mainMenu(e, W, theme, menuL, menuLe);
	}
	else
		menuM.mainMenu(e, W, START, menuO);
}
