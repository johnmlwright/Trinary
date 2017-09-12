#include "character.h"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Character
{
public:
	Enemy(char = '*');
	//Enemy(string a, float b, bool c) : Character( a, b);
	virtual ~Enemy();
	virtual int get_effect(){ return 2; }
	virtual int get_health(){ return 5; }

protected:
};


#endif /* ENEMY_H */