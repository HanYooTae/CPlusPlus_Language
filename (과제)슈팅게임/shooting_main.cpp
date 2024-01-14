#include "shooting.h"

int main()
{
	shooting game;

	game.Setup();

	bool is_play = true;
	while (is_play)
	{
		is_play = game.Update();
		game.Render();
	}

	return 0;
}