#include "스네이크게임.h"
#include <iostream>
#include <conio.h>
using namespace std;

int arr[15][20] =
{
    //head(1,1)
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

enum Object
{
    blank,
    wall,
    head,
    body,
    tail,
    eat
};

enum Move
{
    up = 'w',
    down = 's',
    le = 'a',
    ri = 'd'
};

struct H_location   //머리 위치
{
    int x;
    int y;
};
struct B_location   //몸통 위치
{
    int x = 6;
    int y = 7;
};

//struct T_location   //꼬리 위치
//{
//    int x = 7;
//    int y = 7;
//};

void Map()
{
    system("cls");
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            switch (arr[y][x])
            {
            case blank: cout << "  ";
                break;
            case wall: cout << "■";
                break;
            case head: cout << "★";
                break;
            case body: cout << "☆";
                break;
            case tail: cout << "☆";
                break;
            case eat: cout << "＠";
            default:
                break;
            }
        }
        cout << endl;
    }
}

//void Change()
//{
//   //5(eat)가 먹히면 0(blank) 중 5(eat)랜덤 생성
//}

void H_Dir(H_location& const h, H_location add)
{
    H_location sum;

    sum.x = h.x + add.x;
    sum.y = h.y + add.y;

    Object ob = (Object)arr[sum.y][sum.x];

    switch (ob)
    {
    case blank:
        arr[h.y][h.x] = blank;
        h.x = sum.x;
        h.y = sum.y;

        arr[h.y][h.x] = head;
        break;
    }
}

void B_Dir(B_location& const b, B_location add)
{
    B_location sum;

    sum.x = b.x + add.x;
    sum.y = b.y + add.y;

    Object ob = (Object)arr[sum.y][sum.x];

    switch (ob)
    {
    case blank:
        arr[b.y][b.x] = blank;
        b.x = sum.x;
        b.y = sum.y;

        arr[b.y][b.x] = body;
        break;
    }
}


void Moving()
{
    //움직임 (body, tail 움직임 따로)
    H_location h;       //head의 현재 위치
    h.x = 2;
    h.y = 2;
   
    B_location b;
    b.x = 3;
    b.y = 2;

    Move move;
    H_location a1;       //head의 추가 위치
    B_location a2;

    while (1)
    {
        Map();
        move = (Move)_getch();

        int up_count = 0;
        int down_count = 0;

            switch (move)
            {
            case up:
                a1.x = 0; a1.y = -1;
                a2.x = 0; a2.y = -1;
                break;

            case down:
                a1.x = 0; a1.y = 1;
                a2.x = 0; a2.y = 1;
                break;

            case le:
                a1.x = -1; a1.y = 0;
                a2.x = -1; a2.y = 0;
                break;

            case ri:
                a1.x = 1; a1.y = 0;
                a2.x = 1; a2.y = 0;
                break;

            default:
                a1.x = 0, a1.y = 0;
                break;
            }
            H_Dir(h, a1);
            //B_Dir(b, a2);
    }
}

//void Ate()
//{
//   //먹었을 경우 tail_count 1증가
//}

//void Colision()
//{
//   //머리가 벽 or 꼬리에 부딪힐 경우 game over
//}