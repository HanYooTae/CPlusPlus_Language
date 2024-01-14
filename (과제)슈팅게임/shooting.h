#pragma once
void gotoxy(int x, int y);

constexpr float delay_sec = 0.1f;
constexpr int map_size_row = 20;
constexpr int map_size_col = 30;

class shooting
{
private:
	enum direction
	{
		UP = 72,
		LEFT = 75,
		RIGHT = 77,
		DOWN = 80,
		Space = 32		//АјАн
	};

	struct location
	{
		int x;
		int y;
	};

	struct player
	{
		int p_HP = 3;
		location p_loc;
		direction dir;
	};

	struct enemy
	{
		int e_HP = 1;
		location e_loc;
	};

public:
	void Setup();
	bool Update();
	void Render();

private:
	player player;
	enemy enemy;

	int start_time;
	float current_time;
};

