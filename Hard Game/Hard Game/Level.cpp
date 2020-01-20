#include "Level.h"

Level::Level(float width, float height)
{
	if (!font.loadFromFile("PremierLeague.ttf"))
		cout << "cant load file" << endl;

	int xfont = 100;
	int xfoto = 10;

	for (int i = 0; i < 3; i++)
	{
		menu[i].setFont(font);
		menu[i].setCharacterSize(48);
		menu[i].setPosition(Vector2f(xfont, 210));
		
		if (i != 0)
			menu[1].setFillColor(Color::White);

		sprite[i].setPosition(Vector2f(xfoto, 330));

		xfont += 430;
		xfoto += 440;
	}

	menu[0].setFillColor(Color::Red);
	menu[0].setString("Level One");

	menu[1].setString("Level Two");

	menu[2].setString("Level Three");

	texture[0].loadFromFile("Level_1.png");
	sprite[0].setTexture(texture[0]);

	texture[1].loadFromFile("Level_2.png");
	sprite[1].setTexture(texture[1]);

	texture[2].loadFromFile("Level_3.png");
	sprite[2].setTexture(texture[2]);

	selectedItemIndex = 0;
	choosenLevel = 1;
	ifChosen = false;
	ifChanged = false;
}

void Level::draw(RenderWindow& W)
{
	tekstHead(W, "CHOOSE LEVEL", 410, 40, 70);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		W.draw(menu[i]);
		W.draw(sprite[i]);
	}
}

void Level::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Level::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS - 1)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Level::mainMenu(Event& e, RenderWindow& W, int& current_level, float& angle)
{
	switch (e.type)
	{
	case Event::KeyReleased:
		switch (e.key.code)
		{
		case Keyboard::Left:
			this->MoveUp();
			break;

		case Keyboard::Right:
			this->MoveDown();
			break;

		case Keyboard::Return:
			switch (this->GetPressedItem())
			{
			case 0:
			{
				cout << "level one button has been pressed" << std::endl;
				this->changeLevel(1);
				this->changeIfChosen();
			}
			break;
			case 1:
			{
				cout << "level two button has been pressed" << std::endl;
				this->changeLevel(2);
				this->changeIfChosen();
				angle = M_PI / 180;
			}
			break;
			case 2:
			{
				cout << "level three button has been pressed" << std::endl;
				this->changeLevel(3);
				this->changeIfChosen();
				angle = M_PI / 180;

			}
			break;
			}
		break;
		}
	}
	current_level = choosenLevel;
}

bool Level::getIfChosen()
{
	return ifChosen;
}

void Level::changeIfChosen()
{
	ifChosen = !ifChosen;
}

void Level::changeLevel(int level)
{
	choosenLevel = level;
	ifChanged = true;
}

int Level::getLevel()
{
	return choosenLevel;
}

bool Level::getIfChanged()
{
	return ifChanged;
}

void Level::changeIfChanged()
{
	ifChanged = !ifChanged;
}
