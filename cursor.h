#include <iostream>

#ifndef CURSOR_H
#define CURSOR_H
class Cursor
{
public:
	Cursor();
	~Cursor();
	int get_x(){ return x; }
	int get_y(){ return y; }
	void set_x(int inp){ x = inp; }
	void set_y(int inp){ y = inp; }
	friend std::ostream& operator<<(std::ostream& ostream, const Cursor& input_cursor);

private:
	int x, y;
};

#endif /* CURSOR_H */
