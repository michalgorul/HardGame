#include "classes.h"

void configure(RenderWindow& W, SoundBuffer& hit_, Sound& hit, SoundBuffer& theme_, Sound& theme, Texture& texture_g, Sprite& sprite_g, Texture& texture_m, Sprite& sprite_m)
{
	W.create(VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32), "Hard Game");
	W.setActive(true);
	W.setKeyRepeatEnabled(false);
	W.setFramerateLimit(60);
	W.setPosition(Vector2i(350, 200));

	hit_.loadFromFile("hit.wav");
	theme_.loadFromFile("main.wav");
	hit.setBuffer(hit_);
	theme.setBuffer(theme_);
	theme.setLoop(true);

	texture_g.loadFromFile("in_game.png");
	sprite_g.setTexture(texture_g);

	texture_m.loadFromFile("menu.png");
	sprite_m.setTexture(texture_m);
}

void tekstHead(RenderWindow& W, string s, float x, float y, int size)
{
	Font ttf;
	ttf.loadFromFile("KickTheFont-Bold final.ttf");
	Text txt(s, ttf);

	txt.setFont(ttf);
	txt.setPosition(x, y);
	txt.setCharacterSize(size);
	txt.setFillColor(Color(0, 128, 0));

	W.draw(txt);
}

void tekstStat(RenderWindow& W, string s, float x, float y, int size)
{
	Font ttf;
	ttf.loadFromFile("Roboto.ttf");
	Text txt(s, ttf);

	txt.setFont(ttf);
	txt.setPosition(x, y);
	txt.setCharacterSize(size);
	txt.setFillColor(Color::White);

	W.draw(txt);
}

void wonAction(RenderWindow& W, Event& e)
{
	Texture texture_w;
	Sprite sprite_w;
	texture_w.loadFromFile("Smile.png");
	sprite_w.setTexture(texture_w);

	SoundBuffer end_;
	Sound end;
	end_.loadFromFile("ending.wav");
	end.setBuffer(end_);

	W.draw(sprite_w);
	end.play();
	W.display();
	Sleep(2500);
}

StartAndEnd::StartAndEnd()
{
	Start.setSize(Vector2f(BEGIN_END_SIZE, BEGIN_END_SIZE));
	Start.setFillColor(Color(255, 72, 72));
	Start.setOrigin(BEGIN_END_SIZE / 2, BEGIN_END_SIZE / 2);
	Start.setPosition(60, WINDOW_SIZE_Y / 2);

	End.setSize(Vector2f(BEGIN_END_SIZE, BEGIN_END_SIZE));
	End.setFillColor(Color(255, 72, 72));
	End.setOrigin(BEGIN_END_SIZE / 2, BEGIN_END_SIZE / 2);
	End.setPosition(1240, WINDOW_SIZE_Y / 2);
}
