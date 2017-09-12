#include <iostream>
#include <string>
#include <ctime>

#ifndef SCORE_H
#define SCORE_H
class Score
{
public:
	Score(int, int);
	~Score();
	
	void get_score();
	int get_moves(){ return moves; }
	int get_turns(){ return turns; }
	int get_health(){ return hp; }
	int get_pieces(){ return pieces; }
	int get_remaining(){ return remaining; }
	double get_time();

	void moved(){ moves++; }
	void turn(){ turns++; }
	void health(int a){ hp += a; }
	void piece(){ pieces++; remaining--; }
	void apply_time();
	void apply_score();

	friend std::ostream& operator<<(std::ostream& ostream, Score& input_element);


protected:
	int moves, turns, hp, pieces, remaining, total_score;
	double time;
	std::clock_t start;
};

#endif /* SCORE_H */
