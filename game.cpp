#include "game.h"


/*
int Game::*move[4]() =
{
	Game::move_up,
	Game::move_down,
	Game::move_right,
	Game::move_left,
};*/

char Game::get_input()
{
	char output;
	while (!_kbhit())
	{
		//Force keyboard hit.
	}

	output = _getch();
	if (output == 224)
	{
		return _getch(); // Two calls for arrow-key input.
	}
	return output;
}

void Game::apply_effect(Element e)
{
	char input = e.get_display();
	switch (input)
	{
	case '*':
		score.health(-10);
		break;
	case 1:
	case 0:
	default:
		score.health(5);
	}
}

int Game::calculate_move(int x, int y)
{
	int playerx = user.get_x();
	int playery = user.get_y();
	if (game_board.valid_move(playerx, playery, x, y))
	{
		apply_effect(game_board.get_element(playerx + x, playery + y));
		game_board.destroy_board_at(playerx + x, playery + y);
		game_board.move_object_to(playerx, playery, playerx + x, playery + y);
		user.move(x, y);
		score.piece();
		return 1;
	}
	return 0;
}

int Game::move_up()
{
	return calculate_move(-1, 0);
}

int Game::move_down()
{
	return calculate_move(1, 0);
}

int Game::move_left()
{
	return calculate_move(0,-1);
}

int Game::move_right()
{
	return calculate_move(0,1);
}

void Game::game_init()
{
	/* Player Location Set */

	int user_x = user.get_x(), user_y = user.get_y();
	Player p(user_x, user_y);
	game_board.destroy_board_at(user_x, user_y);
	game_board.add_object(user_x, user_y, p);

	//Deprecated Movement
	/* Movement Array Initialization*/
/*
	move_player[0] = &Game::move_up;
	move_player[1] = &Game::move_down;
	move_player[2] = &Game::move_right;
	move_player[3] = &Game::move_left;
	move_player[4] = NULL;*/
}

Game::Game()
{
	game_init();

	/* Initialize Score */
	// Do this last to start the game clock.
	//score = Score(game_board.get_width(), game_board.get_height());
	bool moved;

	/*while (true)
	{
		std::cout << (int)get_input();
	}*/
	while (!over)
	{
		moved = 0;
		std::cout << game_board << std::endl << "HP: " << score.get_health() << std::endl;
		input = get_input();
		switch (input)
		{
			case 'w':
			case 'H':
				(moved = move_up()); // move_player[0];
				break;
			case 's':
			case 'P':
				(moved = move_down()); // move_player[1];
				break;
			case 'd':
			case 'M':
				(moved = move_right()); // move_player[2];
				break;
			case 'a':
			case 'K':
				(moved = move_left()); // move_player[3];
				break;
			case 'p':
				std::cout << score;
				system("PAUSE");
				break;
			default:
				break;
		}
		over = apply_score(moved);
		system("CLS");
	}
	std::cout << game_board << std::endl << "\nThe Game has ended. . .\n\n";
	get_input();
	system("CLS");
	std::cout << score;
	get_input();
	std::cout << "Please enter any value to continue . . .";
	std::cin >> over;
}

Game::~Game()
{
}

int Game::apply_score(int moved)
{
	score.turn();
	if (moved)
	{
		score.moved();
		if (score.get_remaining() == 0 || score.get_health() <= 0)
		{
			return 1;
		}
		return in_corner();
	}
	return 0;
}

int Game::in_corner()
{
	int playerx = user.get_x();
	int playery = user.get_y();
	if (!(game_board.valid_move(playerx, playery, 1, 0) ||
		game_board.valid_move(playerx, playery, -1, 0) ||
		game_board.valid_move(playerx, playery, 0, 1) ||
		game_board.valid_move(playerx, playery, 0, -1)))
	{
		return 1;
	}
	return 0;
}