#include "character.h"

#ifndef ALLY_H
#define ALLY_H

class Ally : public Character
{
public:
	Ally(char ='A');
	virtual ~Ally();
	virtual int get_effect(){ return 1; }

protected:

};


#endif /* ALLY_H */