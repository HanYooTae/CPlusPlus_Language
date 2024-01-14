/*
   ���� : ���� ���� �����

   �ʿ��� ������

	�̻���
	{
	  ��ġ
	}

   ��
   {
	  ��
	  ��ġ
	  HP
   }

   �÷��̾�
   {
	  ��
	  ��ġ
	  HP
   }

   �ʿ��� ����
   �⺻���� ���� ����
   �̵�(�÷��̾�)
   �̵�(��)
   �̻��� �߻�
   �浹 ó��


   // ���� ����

   //����
   ���� ����

   // ������Ʈ
   �÷��̾� �Է�(�̵�, �߻�);
   �� AI(�̵�, �߻�)
   �̻��� �̵�(��, �÷��̾�)
   �浹ó��

   // ����
   �÷��̾�
   ��
   �̻���
   ��(��)
   �÷��̾� UI
   ����

   std::vector ����غ���
*/

#include "shooting.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x * 2 ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Score()
{
	cout << endl << endl;
	cout << "���� ���" << endl;
}

void shooting::Setup()
{
	// Ŀ���� �Ⱥ��̰� �ϴ� �ڵ�
	{
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	}

	//�÷��̾� �̻����� {x, y - 1}, �� �̻����� {x, y + 1}
	player.p_loc = { 15, 18 };
	enemy.e_loc = { 15, 1 };

	start_time = clock();
}

bool shooting::Update()
{
	if (_kbhit() == true)
	{
		int key = _getch();

		if (key == 224)
		{
			//system("cls");
			key = _getch();

			switch (key)
			{
			case UP:
				player.dir = UP;
				break;

			case LEFT:
				player.dir = LEFT;
				break;

			case RIGHT:
				player.dir = RIGHT;
				break;

			case DOWN:
				player.dir = DOWN;
				break;
			}
		}

		current_time = clock();

		if ((current_time - start_time) / 1000 >= delay_sec)
		{
			gotoxy(player.p_loc.x, player.p_loc.y);
			std::cout << "  ";

			switch (player.dir)
			{
			case UP:
				player.p_loc.y--;
				break;

			case LEFT:
				player.p_loc.x--;
				break;
				
			case RIGHT:
				player.p_loc.x++;
				break;

			case DOWN:
				player.p_loc.y++;
				break;
			}
			start_time = clock();
		}
	}

	return true;
}

void shooting::Render()
{
	//map
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

	//��
	gotoxy(enemy.e_loc.x, enemy.e_loc.y);
	cout << "��" << endl << endl;

	//�÷��̾�
	while (true)
	{
		gotoxy(player.p_loc.x, player.p_loc.y);
		cout << "��" << endl;
		
		//�÷��̾� ����
		Score();
	}
}
