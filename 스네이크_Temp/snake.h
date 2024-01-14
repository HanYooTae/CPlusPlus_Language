#pragma once

void gotoxy(int x, int y);

constexpr int max_body_size = 20;
constexpr float delay_sec = 0.1f;
constexpr int map_size_row = 20;
constexpr int map_size_col = 30;

class snake_game
{
private:
	struct body
	{
		int x;
		int y;
	};

	enum direction
	{
		UP = 72,
		LEFT = 75,
		RIGHT = 77,
		DOWN = 80
	};

	struct snake
	{
		body body[max_body_size];
		int body_size;
		int head;
		int tail;
		direction dir;
	};

public:
	void SetUp();
	bool Update();
	void Render();

private:
	snake snake;

	int start_time;
	float current_time;
};

/*
	  0 1 2 3 4 5 6
	0
	1 ★ㅁㅁ
	2
	3
	4
	5
	6

	  0 1 2 3 4 5 6
	0
	1 ㅁㅁ
	2 ★
	3
	4
	5
	6

	  0 1 2 3 4 5 6
	0
	1 ㅁ
	2 ㅁ★
	3
	4
	5
	6

	  0 1 2 3 4 5 6
	0
	1
	2 ㅁㅁ★
	3
	4
	5
	6

	struct body
	{
		int x;
		int y;
	}

	struct snake
	{
		body arr[5];
		int max_size;
		int size;
		int tail;
		int head;
	}

	// body arr[5]
	0 : (2,2) -> head
	1 : (1,1)
	2 : (1,0)
	3 : (2,0) -> tail
	4 : (2,1)

	head = head + 1 % max_size;
	tail = tail + 1 % max_size;

	start = tail;
	while(true)
	{
		// arr[start] 위치에 도형 출력, 만약 헤드라면 ㅁ이 아닌 ☆출력후 브레이크

		start = start + 1 % max_size;
	}

*/