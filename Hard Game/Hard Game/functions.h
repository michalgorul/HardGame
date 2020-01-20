#pragma once
#include "classes.h"
#include "Leaderboard.h"
#include "Options.h"
#include "Level.h"

//funkcja wykonuje niezbêdne operacje po wygraniu lub opuszczeniu rozgrywki
void stopped_playing(RenderWindow& W, Player& P, Leaderboard& menuLe, Options& menuO, OptionBase* pointer, Level& menuL, Menu& menuM, int& current_level, Sprite& sprite_m);

//funkcja wykonuje niezbêdne operacje podczas poruszania siê po menu
void operating_event(RenderWindow& W, Event& e, Player& P, Leaderboard& menuLe, Options& menuO, Level& menuL, Menu& menuM, int& current_level, Sprite& sprite_m, bool& START, Sound& theme, NPC& obstacle);
