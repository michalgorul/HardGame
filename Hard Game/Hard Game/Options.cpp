#include "Options.h"
#include "Level.h"
#include "Leaderboard.h"

Options::Options(float width, float height)
{
	if (!font.loadFromFile("PremierLeague.ttf"))
		cout << "cant load file" << endl;

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setCharacterSize(48);
	menu[0].setString("Choose level");
	menu[0].setPosition(Vector2f((width / 2) - 160, height / (MAX_NUMBER_OF_ITEMS) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(48);
	menu[1].setString("Music ON/OF");
	menu[1].setPosition(Vector2f((width / 2) - 155, height / (MAX_NUMBER_OF_ITEMS + 0.7) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setCharacterSize(48);
	menu[2].setString("Leaderboard");
	menu[2].setPosition(Vector2f((width / 2) - 150, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(Color::White);
	menu[3].setCharacterSize(48);
	menu[3].setString("Return");
	menu[3].setPosition(Vector2f((width / 2) - 95, height / (MAX_NUMBER_OF_ITEMS - 0.18) * 3));

	selectedItemIndex = 0;
	ifChosen = false;
}

void Options::draw(RenderWindow& W)
{
	tekstHead(W, "OPTIONS", 490, 40, 70);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		W.draw(menu[i]);
	}
}

void Options::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Options::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Options::mainMenu(Event& e, RenderWindow& W, Sound& theme, Level& menuL, Leaderboard& menuLe)
{
	switch (e.type)
	{
	case Event::KeyReleased:
		switch (e.key.code)
		{
		case Keyboard::Up:
			this->MoveUp();
			break;

		case Keyboard::Down:
			this->MoveDown();
			break;

		case Keyboard::Return:
			switch (this->GetPressedItem())
			{
			case 0:
			{
				cout << "choosing level button has been pressed" << std::endl;
				menuL.changeIfChosen();
			}
			break;
			case 1:
			{
				cout << theme.getStatus() << std::endl;
				if (theme.getStatus() == 2)
					theme.stop();
				else 
					theme.play();
			}
			break;
			case 2:
			{
				cout << "leaderboard button has been pressed" << std::endl;
				menuLe.changeIfChosen();

			}
			break;
		case 3:
			this->changeIfChosen();
			break;
		}
		break;
		}
	}
}

bool Options::getIfChosen()
{
	return ifChosen;
}

void Options::changeIfChosen()
{
	ifChosen = !ifChosen;
}
