//Standard Libraries
#include <iostream>
#include <string>

//Overarching Class
#include "element.h"
#include "character.h"
#include "ally.h"
#include "enemy.h"

//For Random
#include <stdlib.h>
#include <time.h>

#ifndef BOARD_H
#define BOARD_H
class Board
{
public:
	Board(int = 10, int = 10);
	~Board();

	int get_width(){ return width; }
	int get_height(){ return height; }
	int move_object_to(int, int, int, int);
	//void destroy_char_at(int, int);
	void destroy_board_at(int, int);
	int valid_move(int, int, int, int);
	int add_object(int, int, Element);

	//std::string get_char_at(int x, int y){ return character_array[x][y].get_type(); }
	Element get_element(int x, int y){ return board_array[x*height + y]; }
	std::string get_board_at(int x, int y){ return board_array[y*height + x].get_type(); }

	friend std::ostream& operator<<(std::ostream& ostream, const Board& input_board);

private:
	int width, height;
	
	//Access via board_array[y*height + x];
	Element* board_array;

	//Standard Implementation
	//Element** board_array;

	//Unsure if necessary
	//Character** character_array;
};

#endif /* BOARD_H */
