#include "Leaderboard.h"

Leaderboard::Leaderboard(float width, float height)
{
	if (!font.loadFromFile("PremierLeague.ttf"))
		cout << "cant load file" << endl;

	float xfont = 100;

	for (int i = 0; i < 3; i++)
	{
		menu[i].setFont(font);
		menu[i].setCharacterSize(48);
		menu[i].setPosition(Vector2f(xfont, 210));
		menu[i].setFillColor(Color::White);

		xfont += 430;
	}

	menu[0].setString("Level One");
	menu[1].setString("Level Two");
	menu[2].setString("Level Three");

	menu[3].setFont(font);
	menu[3].setCharacterSize(48);
	menu[3].setPosition(Vector2f((width / 2) - 95, 600));
	menu[3].setFillColor(Color::Red);
	menu[3].setString("Return");

	ifChosen = false;
	level_1[4] = {0};
	level_2[4] = {0};
	level_3[4] = {0};
}

void Leaderboard::draw(RenderWindow& W)
{
	tekstHead(W, "LEADERBOARD", 410, 40, 70);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		W.draw(menu[i]);
	}
}

void Leaderboard::draw_level_1(RenderWindow& W)
{
	string tab[5];

	for (int i = 0; i < 5; i++)
	{
		tab[i] = to_string(i+1) + ". " + to_string(level_1[i]) + "s";	//zamieniam liczbe na string w celu jej wyœwietlenia za pom. funkcji tekstStat()
	}

	tekstStat(W, tab[0], 90, 310, 32);			//liczby wybiera³em metod¹ prób i b³êdów, a¿ przerwy pomiêdzy nimi mi odpowiada³y
	tekstStat(W, tab[1], 90, 365, 32);
	tekstStat(W, tab[2], 90, 420, 32);
	tekstStat(W, tab[3], 90, 475, 32);
	tekstStat(W, tab[4], 90, 530, 32);
}

void Leaderboard::draw_level_2(RenderWindow& W)
{
	string tab[5];

	for (int i = 0; i < 5; i++)
	{
		tab[i] = to_string(i + 1) + ". " + to_string(level_2[i]) + "s";		//zamieniam liczbe na string w celu jej wyœwietlenia za pom. funkcji tekstStat()
	}

	tekstStat(W, tab[0], 530, 310, 32);			//liczby wybiera³em metod¹ prób i b³êdów, a¿ przerwy pomiêdzy nimi mi odpowiada³y
	tekstStat(W, tab[1], 530, 365, 32);
	tekstStat(W, tab[2], 530, 420, 32);
	tekstStat(W, tab[3], 530, 475, 32);
	tekstStat(W, tab[4], 530, 530, 32);
}

void Leaderboard::draw_level_3(RenderWindow& W)
{
	string tab[5];

	for (int i = 0; i < 5; i++)
	{
		tab[i] = to_string(i + 1) + ". " + to_string(level_3[i]) + "s";		//zamieniam liczbe na string w celu jej wyœwietlenia za pom. funkcji tekstStat()
	}

	tekstStat(W, tab[0], 970, 310, 32);			//liczby wybiera³em metod¹ prób i b³êdów, a¿ przerwy pomiêdzy nimi mi odpowiada³y
	tekstStat(W, tab[1], 970, 365, 32);
	tekstStat(W, tab[2], 970, 420, 32);
	tekstStat(W, tab[3], 970, 475, 32);
	tekstStat(W, tab[4], 970, 530, 32);
}

void Leaderboard::mainMenu(Event& e, RenderWindow& W)
{
	if (e.type == Event::KeyReleased && e.key.code== Keyboard::Return)	//jeœli wybra³em leaderboard - zmieniam atrybut ifChosen
		this->changeIfChosen();
}

bool Leaderboard::getIfChosen()
{
	return ifChosen;
}

void Leaderboard::changeIfChosen()
{
	ifChosen = !ifChosen;
}

void Leaderboard::reading_from_file(ifstream& leaderboard)
{

	if (leaderboard.good())
	{
		while (leaderboard >> this->level_1[0])
		{
								leaderboard >> this->level_1[1] >> this->level_1[2] >> this->level_1[3] >> this->level_1[4];
			leaderboard >> this->level_2[0] >> this->level_2[1] >> this->level_2[2] >> this->level_2[3] >> this->level_2[4];
			leaderboard >> this->level_3[0] >> this->level_3[1] >> this->level_3[2] >> this->level_3[3] >> this->level_3[4];

		}
	}
	else
		cout << "That file doesn't exist" << endl;
}

void Leaderboard::saving_to_file()
{
	ofstream save("Leaderboard.txt");		//otwieram plik do zapisu

	for (int i = 0; i < 5; i++)
		save << this->level_1[i] << endl;

	for (int i = 0; i < 5; i++)
		save << this->level_2[i] << endl;;

	for (int i = 0; i < 5; i++)
		save << this->level_3[i] << endl;;

	save.close();							//zamykam plik do zapisu
}

void Leaderboard::saveToLeaderboard(float time, int current_level)
{
	if (current_level == 1)
	{		
		for (int i = 0; i < 5; i++)
		{
			if (time < level_1[i])
			{
				for (int j = 3; j >= 0; j--)
					level_1[j + 1] = level_1[j];

				level_1[i] = time;
				break;
			}
		}

	}
	else if (current_level == 2)
	{
		for (int i = 0; i < 5; i++)
		{
			if (time < level_2[i])
			{
				for (int j = 3; j >= 0; j--)
					level_2[j + 1] = level_2[j];

				level_2[i] = time;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (time < level_3[i])
			{
				for (int j = 3; j >= 0; j--)
					level_3[j + 1] = level_3[j];

				level_3[i] = time;
				break;
			}
		}
	}
}