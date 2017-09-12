#include "ally.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Ally
{
public:
	Player(int =0, int =0, char ='P');
	//Player(string a, float b, bool c) : Character( a, b);
	virtual ~Player();
	int get_x(){ return x; }
	int get_y(){ return y; }
	void move(int a, int b){ x += a; y += b; };
	//std::string get_type(){ return "Player"; }

protected:
	int x, y;
};


#endif /* PLAYER_H */