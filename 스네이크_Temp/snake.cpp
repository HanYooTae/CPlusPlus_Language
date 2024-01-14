#include "snake.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x * 2 ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void snake_game::SetUp()
{
	// Ŀ���� �Ⱥ��̰� �ϴ� �ڵ�
	{
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	}

	// ������ũ ����
	snake.body[0] = { 10, 10 };
	snake.body[1] = { 10, 11 };
	snake.body[2] = { 10, 12 };
	
	snake.tail = 0;
	snake.head = 2;
	snake.dir = DOWN;

	// �ð� ����
	// clock() : ���α׷��� ����ð� ����
	start_time = clock();
}

bool snake_game::Update()
{
	// �� �̵� �Է�
	if (_kbhit() == true)
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();

			switch (key)
			{
			case UP:	snake.dir = UP; break;
			case LEFT:	snake.dir = LEFT; break;
			case RIGHT: snake.dir = RIGHT; break;
			case DOWN:	snake.dir = DOWN; break;
			}
		}
	}


	// �� �̵� ó��
	current_time = clock();

	if ((current_time - start_time) / 1000 >= delay_sec)
	{
		gotoxy(snake.body[snake.tail].x, snake.body[snake.tail].y);
		std::cout << "  ";

		/*snake.tail++;
		int prev_head = snake.head++;
		snake.tail %= max_body_size;
		snake.head %= max_body_size;*/

		//snake.body[snake.head] = snake.body[prev_head];

		switch (snake.dir)
		{
		case UP:	snake.body[snake.head].y--; break;
		case LEFT:	snake.body[snake.head].x--; break;
		case RIGHT: snake.body[snake.head].x++; break;
		case DOWN:	snake.body[snake.head].y++; break;
		}

		start_time = clock();
	}

	// �浹ó��
	if (
		(snake.body[snake.head].x) == (map_size_col - 1)
		|| (snake.body[snake.head].y) == (map_size_row - 1)
		|| (snake.body[snake.head].x) == 0
		|| (snake.body[snake.head].y) == 0
	   )
	{
		cout << "game over" << endl;

		return 0;
	}

	// ���� ���̰� ��ġ�� ���
	// 1. ����-- (�迭 ������ ����� �ʰ�)
	// 2. �� ������ ����
	// 3. �ʿ� ���� ������
	//���� �̵� ó��
	
	//// ���� ���
	//int feedX = rand() % (map_size_row - 1) + 1;
	//int feedY = rand() % (map_size_col - 1) + 1;

	//for (int row = 0; row < map_size_row - 1; row++)
	//{
	//	for (int col = 0; col < map_size_col - 1; col++)
	//	{
	//		gotoxy(feedY, feedX);
	//		cout << "@";
	//	}
	//	//cout << endl;
	//}

	//// �� ������ ����
	//if ((snake.body[snake.head].y, snake.body[snake.head].x) == (feedY, feedX))
	//{
	//	snake.body[snake.head++];
	//}

	//// �Ӹ��� ������ ������ ����
	//if (snake.body[snake.head].y == snake.body[snake.tail].y
	//	&& snake.body[snake.head].x == snake.body[snake.tail].x)
	//{
	//	cout << "game over!" << endl;

	//	return 0;
	//}

	return true;
}

void snake_game::Render()
{
	//system("cls");

	// �����
	for (int row = 0; row < map_size_row; row++)
	{
		gotoxy(0, row);
		std::cout << "��";
		gotoxy(map_size_col - 1, row);
		std::cout << "��";
	}

	for (int col = 0; col < map_size_col; col++)
	{
		gotoxy(col, 0);
		std::cout << "��";
		gotoxy(col, map_size_row - 1);
		std::cout << "��";
	}

	// �� ���

	int index = snake.tail;
	while (true)
	{
		gotoxy(snake.body[index].x, snake.body[index].y);
		if (index == snake.head)
		{
			std::cout << "��";
			break;
		}
		else
			std::cout << "��";

		index = (index + 1) % max_body_size;
	}
}

/*
	���� : ��Ƽ����Ʈ, �����ڵ� �����ϱ�
*/