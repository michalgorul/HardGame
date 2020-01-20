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

constexpr auto MOVING_SPEED = 3;				//prêdkoœæ NPC
constexpr auto WINDOW_SIZE_X = 1300;			//szerokoœæ okna
constexpr auto WINDOW_SIZE_Y = 700;				//wysokoœæ okna
constexpr auto BEGIN_END_SIZE = 60;				//rozmiar obszaru koñcz¹cego i rozpoczynaj¹cego

constexpr auto MAX_NUMBER_OF_ITEMS = 4;			//max elementów menu

//funkcja konfiguruje pocz¹tkowe elementy gry
void configure(RenderWindow& W, SoundBuffer& hit_, Sound& hit, SoundBuffer& theme_, Sound& theme, Texture& texture_g, Sprite& sprite_g, Texture &texture_m, Sprite &sprite_m);

//funkcja wypisuje tekst nag³ówkowy
void tekstHead(RenderWindow& W, string s, float x, float y, int size);

//funkcja wypisuje tekst w statystykach
void tekstStat(RenderWindow& W, string s, float x, float y, int size);

//funkcja wyœwietla obrazek i odtwarza dŸwiêk po wygraniu poziomu
void wonAction(RenderWindow& W, Event& e);

//klasa obiektów koñca i pocz¹tku rozgrywki
class StartAndEnd : public RectangleShape
{
public:
	RectangleShape Start;
	RectangleShape End;

	StartAndEnd();
};


#endif



