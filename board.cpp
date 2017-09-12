#include "board.h"

Board::Board(int a, int b) : width(a), height(b)
{
/* Light-weight Implementation
 * To be used to create one large chunk of memory.
 * Access is slightly harder, but makes cleanup easier.
 */
	//Access via board_array[y*height + x];
	board_array = new Element[height * width];
	//Typecast to unsigned int to avoid warning.
	srand((unsigned int)time(NULL));
	for (int i = 0; i < height * width; i++)
	{
		if (rand() % 2 == 1)
		{
			if (rand() % 4 == 1)
			{
				board_array[i] = Ally(rand() % 3 + 48);
			}
			else
			{
			}
		}
		else
		{
			board_array[i] = Enemy();
		}
	}
	//Pad default spaces to prevent "closed off" game.
	board_array[height] = Element();
	board_array[1] = Enemy();
/* Standard Implementation
	board_array = new Element*[height];
	for (int i = 0; i < a; i++)
	{
		board_array[i] = new Element[width];
	}
 */
}

Board::~Board()
{
	delete [] board_array;
/* Standard Implementation
	for (int i = 0; i < width; i++)
	{
		delete [] board_array[i];
	}
	delete [] board_array;
 */
}

int Board::move_object_to(int ini_x, int ini_y, int des_x, int des_y)
{
	//Places object from initial location to destination location. Assumes destination is empty.
	board_array[des_y + height * des_x] = board_array[ini_y + height * ini_x];

	//Sets previous spot to 0, 1, 2. Needs to be re-written for moving AI (not planned).
	board_array[ini_y + height * ini_x] = Ally(rand() % 3 + 48);

	return 1;
}

//Automatically places an Ally on the "used" space.
void Board::destroy_board_at(int x, int y)
{
	//Force destructor (virtual call)
	board_array[y + height * x].~Element();
	//Just to be safe
	board_array[y + height * x] = NULL;
}

int Board::valid_move(int ini_x, int ini_y, int des_x, int des_y)
{
	if (ini_x + des_x >= 0 && ini_x + des_x < width && ini_y + des_y >= 0 && ini_y + des_y < height && (board_array[(ini_x + des_x) * height + ini_y + des_y].get_type().compare("Ally")))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Board::add_object(int x, int y, Element e)
{
	board_array[y + height * x] = e;
	return 1;
}

std::ostream & operator<<(std::ostream& ostream, const Board& input_board)
{
/*	for (int i = 0; i < input_board.height; i++)
	{
		for (int j = 0; j < input_board.width; j++)
		{
			std::cout << input_board.board_array[i * input_board.height + j].get_display() << " ";
		}
		std::cout << std::endl;
	}*/
	std::cout << "    ";
	for (int y = 0; y < input_board.height; y++)
	{
		std::cout << " " << y << "  ";
	}
	std::cout << std::endl;
	for (int y = 0; y < input_board.height; y++)
	{
		std::cout << "   :";
		for (int x = 0; x < input_board.width; x++)
		{
			std::cout << "----";
		}
		std::cout << std::endl << " " << y << " :";
		for (int x = 0; x < input_board.width; x++)
		{
			std::cout << " " << input_board.board_array[x + input_board.height * y] << " |";
		}
		/*if (input != 0 && y == input_board.height - 1)
		{
			std::cout << "\tEnter: Q, O, H, or Move Inputs.";
		}*/
		std::cout << std::endl;
	}
	std::cout << "    ";
	for (int x = 0; x < input_board.width; x++)
	{
		std::cout << "----";
	}
	std::cout << std::endl;

	return ostream;
}
