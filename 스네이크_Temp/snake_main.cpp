#include"snake.h"

int main()
{
	snake_game game;

	game.SetUp();

	bool is_play = true;
	while (is_play)
	{
		is_play = game.Update();
		game.Render();
	}

	return 0;
}