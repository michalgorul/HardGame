#include "NPC.h"

NPC::NPC(float angle_, float moving_speed_)
{
	genRocks_1(Rocks1);
	genRocks_2(Rocks2);
	genRocks_3(Rocks3);
	moving_speed = moving_speed_;
	angle = angle_;
}

void NPC::genRocks_1(vector<RectangleShape>& Rocks1)
{
	//n do ustawiania w poziomie
	float n = 120;

	for (int i = 0; i <= 30; i++)
	{
		Rocks1.push_back(RectangleShape(Vector2f(27, 27)));
		Rocks1.back().setFillColor(Color::Blue);
		Rocks1.back().setOrigin(15, 15);
		Rocks1.back().setOutlineThickness(3);
		Rocks1.back().setOutlineColor(Color::Black);

		if (i % 2 == 0)
			Rocks1.back().setPosition(n, 50);
		else
			Rocks1.back().setPosition(n, 650);

		n += 35;
	}
}

void NPC::movingRocks_1(RenderWindow& W, vector<RectangleShape>& Rocks1, float& moving_speed)
{
	for (size_t i = 0; i < Rocks1.size(); i++)
	{
		W.draw(Rocks1[i]);
		if (i % 2 == 0)
		{
			Rocks1[i].setPosition(Rocks1[i].getPosition().x, Rocks1[30].getPosition().y);
			Rocks1[i].move(0, moving_speed);

			if (Rocks1[i].getPosition().y >= 700 || Rocks1[i].getPosition().y <= 0)
				moving_speed *= -1;
		}
		else
		{
			Rocks1[i].setPosition(Rocks1[i].getPosition().x, Rocks1[29].getPosition().y);
			Rocks1[i].move(0, -moving_speed);
		}
	}
}

void NPC::genRocks_2(vector<RectangleShape>& Rocks2)
{
	float n = 35;

	for (int i = 0; i <= 18; i++)
	{
		Rocks2.push_back(RectangleShape(Vector2f(27, 27)));
		Rocks2.back().setFillColor(Color::Blue);
		Rocks2.back().setOrigin(15, 15);
		Rocks2.back().setOutlineThickness(3);
		Rocks2.back().setOutlineColor(Color::Black);

		Rocks2.back().setPosition(640, n);

		n += 35;
	}

	n = 325;

	for (int i = 19; i <= 37; i++)
	{
		Rocks2.push_back(RectangleShape(Vector2f(27, 27)));
		Rocks2.back().setFillColor(Color::Blue);
		Rocks2.back().setOrigin(15, 15);
		Rocks2.back().setOutlineThickness(3);
		Rocks2.back().setOutlineColor(Color::Black);

		Rocks2.back().setPosition(n, 350);

		n += 35;
	}
}

void NPC::movingRocks_2(RenderWindow& W, vector<RectangleShape>& Rocks2, float& angle)
{
	int k = 1;
	int m = 9;

	for (size_t i = 0; i < Rocks2.size(); i++)
		W.draw(Rocks2[i]);

	for (size_t i = 0; i < Rocks2.size() / 4; i++)
	{
		Rocks2[i].move(cos(angle + M_PI) * m, sin(angle + M_PI) * m);
		m--;
	}

	for (size_t i = Rocks2.size() / 4 + 1; i < Rocks2.size() / 2; i++)
	{
		Rocks2[i].move(cos(angle) * k, sin(angle) * k);
		k++;
	}

	k = 1;
	m = 9;

	for (size_t i = Rocks2.size() / 2; i < Rocks2.size() * 3 / 4; i++)
	{
		Rocks2[i].move(cos(angle + M_PI / 2) * m, sin(angle + M_PI / 2) * m);
		m--;
	}

	for (size_t i = Rocks2.size() * 3 / 4 + 1; i < Rocks2.size(); i++)
	{
		Rocks2[i].move(cos(angle - M_PI / 2) * k, sin(angle - M_PI / 2) * k);
		k++;
	}

	angle -= 3.14 / 112;
}

void NPC::genRocks_3(vector<RectangleShape>& Rocks3)
{
	float n = 120;

	for (int i = 0; i <= 30; i++)
	{
		Rocks3.push_back(RectangleShape(Vector2f(27, 27)));
		Rocks3.back().setFillColor(Color::Blue);
		Rocks3.back().setOrigin(15, 15);
		Rocks3.back().setOutlineThickness(3);
		Rocks3.back().setOutlineColor(Color::Black);

		if (i % 2 == 0)
			Rocks3.back().setPosition(n, 50);
		else
			Rocks3.back().setPosition(n, 650);

		n += 35;
	}

	n = 35;

	for (int i = 31; i < 50; i++)
	{
		Rocks3.push_back(RectangleShape(Vector2f(27, 27)));
		Rocks3.back().setFillColor(Color::Blue);
		Rocks3.back().setOrigin(15, 15);
		Rocks3.back().setOutlineThickness(3);
		Rocks3.back().setOutlineColor(Color::Black);

		Rocks3.back().setPosition(640, n);

		n += 35;
	}

	n = 325;

	for (int i = 50; i < 69; i++)
	{
		Rocks3.push_back(RectangleShape(Vector2f(27, 27)));
		Rocks3.back().setFillColor(Color::Blue);
		Rocks3.back().setOrigin(15, 15);
		Rocks3.back().setOutlineThickness(3);
		Rocks3.back().setOutlineColor(Color::Black);

		Rocks3.back().setPosition(n, 350);

		n += 35;
	}
}

void NPC::movingRocks_3(RenderWindow& W, vector<RectangleShape>& Rocks3, float& moving_speed, float& angle)
{
	for (size_t i = 0; i < 31; i++)
	{
		W.draw(Rocks3[i]);
		if (i % 2 == 0)
		{
			Rocks3[i].setPosition(Rocks3[i].getPosition().x, Rocks3[30].getPosition().y);
			Rocks3[i].move(0, moving_speed);

			if (Rocks3[i].getPosition().y >= 700 || Rocks3[i].getPosition().y <= 0)
				moving_speed *= -1;
		}
		else
		{
			Rocks3[i].setPosition(Rocks3[i].getPosition().x, Rocks3[29].getPosition().y);
			Rocks3[i].move(0, -moving_speed);
		}
	}

	int k = 1;
	int m = 9;

	for (size_t i = 31; i < Rocks3.size(); i++)
		W.draw(Rocks3[i]);

	for (size_t i = 31; i < 40; i++)
	{
		Rocks3[i].move(cos(angle + M_PI) * m, sin(angle + M_PI) * m);
		m--;
	}

	for (size_t i = 41; i < 50; i++)
	{
		Rocks3[i].move(cos(angle) * k, sin(angle) * k);
		k++;
	}

	k = 1;
	m = 9;

	for (size_t i = 50; i < 60; i++)
	{
		Rocks3[i].move(cos(angle + M_PI / 2) * m, sin(angle + M_PI / 2) * m);
		m--;
	}

	for (size_t i = 60; i < 70; i++)
	{
		Rocks3[i].move(cos(angle - M_PI / 2) * k, sin(angle - M_PI / 2) * k);
		k++;
	}

	angle -= 3.14 / 112;
}