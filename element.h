#include <iostream>
#include <string>

#ifndef ELEMENT_H
#define ELEMENT_H
class Element
{
public:
	Element(char ='-');
	virtual ~Element();

	virtual std::string get_type(){ return type; }
	virtual char get_display(){ return display; }
	virtual int get_effect(){ return 0; }
	friend std::ostream& operator<<(std::ostream& ostream, const Element& input_element);

	virtual int add_health(int inp){ return 0; }
	virtual int get_health(){ return health; }
	virtual int get_damage(){ return 0; }
	virtual int get_accuracy(){ return 0; }
	virtual int get_dodge(){ return 0; }
	virtual int get_armor(){ return 0; }
	virtual int get_speed(){ return 0; }


	//void(*function)(void*, void*, void*);
	//virtual void action(void *, void *, void *);

protected:
	int health;
	char display;
	std::string type;
};

#endif /* BOARD_H */
