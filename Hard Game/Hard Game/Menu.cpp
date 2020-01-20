#include "Menu.h"
#include "Options.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("PremierLeague.ttf"))
		cout << "cant load file" << endl;

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setCharacterSize(48);
	menu[0].setString("Play");
	menu[0].setPosition(Vector2f((width / 2)-50, height / (MAX_NUMBER_OF_ITEMS-1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(48);
	menu[1].setString("Options");
	menu[1].setPosition(Vector2f((width / 2) - 85, height / (MAX_NUMBER_OF_ITEMS - 0.3) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setCharacterSize(48);
	menu[2].setString("Exit");
	menu[2].setPosition(Vector2f((width / 2) - 40, height / (MAX_NUMBER_OF_ITEMS) * 3));

	selectedItemIndex = 0;
}

void Menu::draw(RenderWindow& W)
{
	tekstHead(W, "HARD GAME", 360, 40, 100);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		W.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS - 1)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::mainMenu(Event& e, RenderWindow& W, bool& START, Options& menuO)
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
				cout << "Play button has been pressed" << std::endl;
				START = true;
			}
				break;
			case 1:
			{
				cout << "Option button has been pressed" << std::endl;
				START = false;
				menuO.changeIfChosen();

			}
				break;
			case 2:
				W.close();
				break;
			}

			break;
		}
	}
}

