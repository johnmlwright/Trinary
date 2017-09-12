#include "character.h"

#ifndef TRAP_H
#define TRAP_H

class Trap : public Character
{
public:
	Trap(char ='T');
	//Enemy(string a, float b, bool c) : Character( a, b);
	virtual ~Trap();

protected:

};


#endif /* ENEMY_H */