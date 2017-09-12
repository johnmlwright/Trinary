#include <iostream>
#include <conio.h>
#include <string>
#include "board.h"
#include "player.h"
#include "score.h"

#ifndef GAME_H
#define GAME_H


class Game
{
public:
	char get_input();
	void apply_effect(Element);
	int calculate_move(int, int);
	int move_up();
	int move_down();
	int move_right();
	int move_left();
	int right();
	int left();
	int up();
	int down();
	void game_init();
	Game();
	~Game();
	int apply_score(int moved);
	int in_corner();

private:
	//0 = up, 1 = down, 2 = right, 3 = left;
	/* Used for deprecated function array call.
	int(Game::*move_player[5])();
	*/

	char input;
	int over;

	Board game_board;
	Player user;
	Score score = Score(game_board.get_width(), game_board.get_height());
};

#endif /* GAME_H */
