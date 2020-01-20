#pragma once
#include "classes.h"
#include "NPC.h"

class Player : public RectangleShape
	{
	private:
		RectangleShape R;
		Vector2f moveDirect;
		Vector2f side;
		bool played_sound;
		bool ifWon;
		int hits;
		chrono::steady_clock::time_point beginT;
		chrono::steady_clock::time_point endT;
	
	public:
		Player() : moveDirect(0, 0), side(0, 0), played_sound(false), hits(0), ifWon(false)
			, beginT(chrono::steady_clock::now()), endT(chrono::steady_clock::now()) { };
			
		Player(Vector2f Side, Vector2f moveDirect)
			: RectangleShape(Side)
			, side(20, 20)
			, moveDirect(0, 0)
			, played_sound(false)
			, ifWon(false)
			, hits(0)
			, beginT(chrono::steady_clock::now())
			, endT(chrono::steady_clock::now())
		{
			setFillColor(Color::Green);
			setOrigin(10, 10);
			setPosition(60, WINDOW_SIZE_Y / 2);
			setOutlineThickness(3);
			setOutlineColor(Color::Black);
		};
	
		Vector2f getV(Vector2f& moveDirect, int choosen_level);
	
		bool isWin(RectangleShape& r);
	
		bool isCollision(vector<RectangleShape>& v);
	
		void restartPosition();
	
		void moving_inside_bounds(int choosen_level);
	
		bool get_played_sound();

		bool get_ifWon();
	
		void changeIfWon();

		void change_played_sound();
	
		void hitAction();
	
		void setBeginTime(chrono::steady_clock::time_point begin_or_end);
	
		void setEndTime(chrono::steady_clock::time_point begin_or_end);
	
		float getTime();

		void drawing_game(RenderWindow& W, Player& P, Event& e, NPC& obstacle, Sprite& sprite_g, Sound& hit, RectangleShape& Start, RectangleShape& End, bool& START, SoundBuffer hit_, int current_level);

		void restartGame();
	
	};	

