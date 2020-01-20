#include "classes.h"
#include "Level.h"
#include "Menu.h"
#include "Options.h"
#include "Player.h"
#include "Leaderboard.h"
#include "functions.h"

int main()
{
	RenderWindow W;
	Event e;
	Vector2f moveDirect(0, 0);
	Vector2f side(20, 20);
	Vector2f startP(60, WINDOW_SIZE_Y / 2);

	bool START = false;

	Player P(side, moveDirect);

	Menu menuM(WINDOW_SIZE_X,WINDOW_SIZE_Y);
	Options menuO(WINDOW_SIZE_X,WINDOW_SIZE_Y);
	Level menuL(WINDOW_SIZE_X,WINDOW_SIZE_Y);
	Leaderboard menuLe(WINDOW_SIZE_X, WINDOW_SIZE_Y);

	OptionBase* pointer = NULL;

	NPC obstacle(M_PI / 180, MOVING_SPEED);

	StartAndEnd start_and_end;

	SoundBuffer hit_;
	SoundBuffer theme_;
	Sound hit;
	Sound theme;

	Texture texture_g;
	Sprite sprite_g;
	Texture texture_m;
	Sprite sprite_m;

	int current_level = 1;

	ifstream leaderboard;
	leaderboard.open("leaderboard.txt", ios::in);
	menuLe.reading_from_file(leaderboard);
	leaderboard.close();

	configure(W, hit_, hit, theme_, theme, texture_g, sprite_g, texture_m, sprite_m);
	theme.play();

	///=================================================G£ÓWNA PÊTLA============================

	while (W.isOpen())
	{
		while (W.pollEvent(e))
		{
			operating_event(W, e, P, menuLe, menuO, menuL, menuM, current_level, sprite_m, START, theme, obstacle);
		}
	
		W.clear(Color::Black);

		if (START == false)
		{
			stopped_playing(W, P, menuLe, menuO, pointer, menuL, menuM, current_level, sprite_m);
		}		

		if (START == true)	
		{
			if (P.getPosition() == startP)
				P.setBeginTime(chrono::steady_clock::now());

			P.drawing_game(W, P, e, obstacle, sprite_g, hit, start_and_end.Start, start_and_end.End, START, hit_, current_level);
		}		
		 
		W.display();
	}

	menuLe.saving_to_file();
	return 0;
}