#include "ally.h"

Ally::Ally(char d) : Character(d)
{
	type = "Ally";
	//Reduces health from 10 to 1;
	add_health(-9);
}

Ally::~Ally()
{
}