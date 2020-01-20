#ifndef classes_h
#define classes_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <iomanip> 
#include <fstream>

using namespace sf;
using namespace std;

constexpr float M_PI = 3.14159265358979323846;   // pi;

constexpr auto MOVING_SPEED = 3;				//pr�dko�� NPC
constexpr auto WINDOW_SIZE_X = 1300;			//szeroko�� okna
constexpr auto WINDOW_SIZE_Y = 700;				//wysoko�� okna
constexpr auto BEGIN_END_SIZE = 60;				//rozmiar obszaru ko�cz�cego i rozpoczynaj�cego

constexpr auto MAX_NUMBER_OF_ITEMS = 4;			//max element�w menu

//funkcja konfiguruje pocz�tkowe elementy gry
void configure(RenderWindow& W, SoundBuffer& hit_, Sound& hit, SoundBuffer& theme_, Sound& theme, Texture& texture_g, Sprite& sprite_g, Texture &texture_m, Sprite &sprite_m);

//funkcja wypisuje tekst nag��wkowy
void tekstHead(RenderWindow& W, string s, float x, float y, int size);

//funkcja wypisuje tekst w statystykach
void tekstStat(RenderWindow& W, string s, float x, float y, int size);

//funkcja wy�wietla obrazek i odtwarza d�wi�k po wygraniu poziomu
void wonAction(RenderWindow& W, Event& e);

//klasa obiekt�w ko�ca i pocz�tku rozgrywki
class StartAndEnd : public RectangleShape
{
public:
	RectangleShape Start;
	RectangleShape End;

	StartAndEnd();
};


#endif



