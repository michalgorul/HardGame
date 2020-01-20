#pragma once
#include "classes.h"

class NPC
{
public:
	vector<RectangleShape> Rocks1;
	vector<RectangleShape> Rocks2;
	vector<RectangleShape> Rocks3;
	float angle;
	float moving_speed;

	NPC(float angle_, float moving_speed_);

	//funkcja generuje kontener przeszkód na pierwszym poziomie
	void genRocks_1(vector<RectangleShape>& Rocks1);

	//funkcja porusza npc na pierwszym poziomie
	void movingRocks_1(RenderWindow& W, vector<RectangleShape>& Rocks1, float& moving_speed);

	//funkcja generuje kontener przeszkód na drugim poziomie
	void genRocks_2(vector<RectangleShape>& Rocks2);

	//funkcja porusza npc na drugim poziomie
	void movingRocks_2(RenderWindow& W, vector<RectangleShape>& Rocks2, float& angle);

	//funkcja generuje kontener przeszkód na trzecim poziomie
	void genRocks_3(vector<RectangleShape>& Rocks3);
	
	//funkcja porusza npc na trzecim poziomie
	void movingRocks_3(RenderWindow& W, vector<RectangleShape>& Rocks3, float& moving_speed, float& angle);
};

