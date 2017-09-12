#include "character.h"

Character::Character(char d) : Element(d)
{
	health = damage = 10;
	accuracy = 100;
	dodge = 0;
	armor = 0;
	speed = 0;
	name = "";
	type = "Character";
}

Character::~Character()
{

}