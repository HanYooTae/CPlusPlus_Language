/*
   과제 : 슈팅 게임 만들기

   필요한 데이터

	미사일
	{
	  위치
	}

   적
   {
	  모델
	  위치
	  HP
   }

   플레이어
   {
	  모델
	  위치
	  HP
   }

   필요한 동작
   기본적인 게임 세팅
   이동(플레이어)
   이동(적)
   미사일 발사
   충돌 처리


   // 로직 순서

   //세팅
   게임 세팅

   // 업데이트
   플레이어 입력(이동, 발사);
   적 AI(이동, 발사)
   미사일 이동(적, 플레이어)
   충돌처리

   // 렌더
   플레이어
   적
   미사일
   벽(맵)
   플레이어 UI
   점수

   std::vector 사용해보기
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
	cout << "점수 출력" << endl;
}

void shooting::Setup()
{
	// 커서를 안보이게 하는 코드
	{
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	}

	//플레이어 미사일은 {x, y - 1}, 적 미사일은 {x, y + 1}
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
		std::cout << "※";
		gotoxy(map_size_col - 1, row);
		std::cout << "※";
	}

	for (int col = 0; col < map_size_col; col++)
	{
		gotoxy(col, 0);
		std::cout << "※";
		gotoxy(col, map_size_row - 1);
		std::cout << "※";
	}

	//적
	gotoxy(enemy.e_loc.x, enemy.e_loc.y);
	cout << "▼" << endl << endl;

	//플레이어
	while (true)
	{
		gotoxy(player.p_loc.x, player.p_loc.y);
		cout << "▲" << endl;
		
		//플레이어 점수
		Score();
	}
}
