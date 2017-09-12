#include "player.h"

Player::Player(int x_loc, int y_loc, char d) : Ally(d), x(x_loc), y(y_loc)
{
	display = 'P';
	type = "Player";
	//sets health to 100 (Ally constructor reduces it from 10 to 1)
	add_health(99);
}

Player::~Player()
{
}