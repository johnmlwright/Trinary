#include "element.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character : public Element
{
public:
	Character(char ='C');
	virtual ~Character();

	virtual int add_health(int inp){ health += inp; return health; }
	virtual int get_health(){ return health; }
	virtual int get_damage(){ return damage; }
	virtual int get_accuracy(){ return accuracy; }
	virtual int get_dodge(){ return dodge; }
	virtual int get_armor(){ return armor; }
	virtual int get_speed(){ return speed; }

protected:
	int health, damage, accuracy, dodge, armor, speed;
	std::string name;
};


#endif /* CHARACTER_H */