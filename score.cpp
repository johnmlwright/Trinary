#include "score.h"

Score::Score(int x, int y) : moves(0), turns(0), hp(100), pieces(0), remaining(x * y), start(std::clock())
{
}

Score::~Score()
{
}

void Score::get_score()
{
	std::cout << this;
}

double Score::get_time()
{
	apply_time();
	return time;
}

void Score::apply_time()
{
	time = (std::clock() - start) / (double)CLOCKS_PER_SEC;
}

void Score::apply_score()
{
	total_score = moves * 50 + hp * 10 - time - remaining * 10;
	if (total_score < 0)
	{
		total_score = 0;
	}
}

std::ostream& operator<<(std::ostream& ostream, Score& input_element)
{
	input_element.apply_time();
	input_element.apply_score();
	std::cout <<
		"/                               \\\n" <<
		"/  ****  ***   ***  *****  **** \\\n" <<
		"/ **    ** ** ** ** **  * **    \\\n" <<
		"/  ***  **    ** ** ***** ***** \\\n" <<
		"/    ** ** ** ** ** ** *  **    \\\n" <<
		"/ ****   ***   ***  ** **  **** \\\n" <<
		"/                               \\\n" <<
		"/ Moves: Turns:\tHealth:\t  Left: \\\n" <<
		"/   " << input_element.moves << "\t   " <<
		input_element.turns << "\t  " <<
		input_element.hp << "\t   " << 
		input_element.remaining << "\t\\\n" <<
		"/ Time: " << input_element.time << "s\t\t\t\\\n" <<
		"\tTotal Score: " << input_element.total_score << 
		"\n/                               \\\n";
	return ostream;
}