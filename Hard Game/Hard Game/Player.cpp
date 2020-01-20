#include "Player.h"

Vector2f Player::getV(Vector2f& moveDirect, int choosen_level)
{
	float i = 0;

	if (choosen_level == 1)
		i = 2;
	else if (choosen_level == 2 || choosen_level == 3)
		i = 4;

	if (!(Keyboard::isKeyPressed(Keyboard::Up)) || !(Keyboard::isKeyPressed(Keyboard::Right))
		|| !(Keyboard::isKeyPressed(Keyboard::Down)) || !(Keyboard::isKeyPressed(Keyboard::Left)))	//jeœli nie jest wciœniêty to stój 
	{
		moveDirect = Vector2f(0, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
		moveDirect = Vector2f(0, -i);

	if (Keyboard::isKeyPressed(Keyboard::Right))
		moveDirect = Vector2f(i, 0);

	if (Keyboard::isKeyPressed(Keyboard::Down))
		moveDirect = Vector2f(0, i);

	if (Keyboard::isKeyPressed(Keyboard::Left))
		moveDirect = Vector2f(-i, 0);

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Right)))
		moveDirect = Vector2f(i, -i);

	if ((Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Down)))
		moveDirect = Vector2f(i, i);

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Left)))
		moveDirect = Vector2f(-i, -i);

	if ((Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Left)))
		moveDirect = Vector2f(-i, i);

	return moveDirect;
}

bool Player::isWin(RectangleShape& r)
{
	if (r.getGlobalBounds().intersects(getGlobalBounds()))
		return true;

	return false;
}

bool Player::isCollision(vector<RectangleShape>& v)
{
	RectangleShape r;
	for (auto& r : v)	//dla ka¿dego elementu z kontenera v
	{
		if (r.getGlobalBounds().intersects(getGlobalBounds()))
			return true;
	}

	return false;
}

void Player::restartPosition()
{
	this->setPosition(60, WINDOW_SIZE_Y / 2);
}

void Player::moving_inside_bounds(int choosen_level)
{
	if (this->getPosition().x >= 15 && this->getPosition().x <= 1285 && this->getPosition().y >= 15 && this->getPosition().y <= 685)
		this->move(this->getV(this->moveDirect, choosen_level));

	else			//jeœli próbuje wyjœæ poza plansze
	{
		if (this->getPosition().x <= 15)
			this->setPosition(this->getPosition().x + 1, this->getPosition().y);
		if (this->getPosition().x >= 1285)
			this->setPosition(this->getPosition().x - 1, this->getPosition().y);
		if (this->getPosition().y <= 15)
			this->setPosition(this->getPosition().x, this->getPosition().y + 1);
		if (this->getPosition().y >= 685)
			this->setPosition(this->getPosition().x, this->getPosition().y - 1);
	}
}

bool Player::get_played_sound()
{
	return this->played_sound;
}

bool Player::get_ifWon()
{
	return ifWon;
}

void Player::changeIfWon()
{
	ifWon = !ifWon;
}

void Player::change_played_sound()
{
	this->played_sound = !this->played_sound;
}

void Player::hitAction()
{
	hits++;

	SoundBuffer hit_;
	Sound hit;

	hit_.loadFromFile("hit.wav");
	hit.setBuffer(hit_);

	hit.play();
}

void Player::setBeginTime(chrono::steady_clock::time_point begin)
{
	this->beginT = begin;
}

void Player::setEndTime(chrono::steady_clock::time_point end)
{
	this->endT = end;
}

float Player::getTime()
{
	float x = chrono::duration_cast<chrono::microseconds>(endT - beginT).count() / 1000000.0;

	cout << "Time difference (sec) = " << setprecision(4) << x << endl;

	return x;
}

void Player::drawing_game(RenderWindow& W, Player& P, Event& e, NPC& obstacle, Sprite& sprite_g, Sound& hit, RectangleShape& Start, RectangleShape& End, bool& START, SoundBuffer hit_, int current_level)
{
	W.draw(sprite_g);

	switch (current_level)
	{
	case 1:
	{
		tekstHead(W, "LEVEL ONE", 550, 40, 48);
		obstacle.movingRocks_1(W, obstacle.Rocks1, obstacle.moving_speed);
	}
	break;
	case 2:
	{
		tekstHead(W, "LEVEL TWO", 530, 40, 48);
		obstacle.movingRocks_2(W, obstacle.Rocks2, obstacle.angle);
	}
	break;
	case 3:
	{
		tekstHead(W, "LEVEL THREE", 550, 40, 48);
		obstacle.movingRocks_3(W, obstacle.Rocks3, obstacle.moving_speed, obstacle.angle);
	}
	break;
	default:
		break;
	}

	if(((current_level == 1) && (P.isCollision(obstacle.Rocks1))) 
	|| ((current_level == 2) && (P.isCollision(obstacle.Rocks2)))
	|| ((current_level == 3) && (P.isCollision(obstacle.Rocks3))))
	{
		hit.play();
		P.hitAction();
		P.restartPosition();
		P.setBeginTime(chrono::steady_clock::now());
	}

	if (P.isWin(End))
	{
		if (!P.get_played_sound())
		{
			P.setEndTime(chrono::steady_clock::now());
			P.getTime();
			wonAction(W, e);
			P.changeIfWon();
			P.change_played_sound();
			START = false;

		}
		P.restartGame();
	}

	P.moving_inside_bounds(current_level);

	W.draw(Start);
	W.draw(End);
	W.draw(P);
}

void Player::restartGame()
{
	this->restartPosition();
	this->change_played_sound();
}
