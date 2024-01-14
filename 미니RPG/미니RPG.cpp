#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "미니RPG.h"
#include <stdlib.h>      //srand를 이용한 보스몬스터가 공격 시 miss확률 추가
#include <time.h>

int map[20][20] =
{
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,2,0,0,1,0,0,0,0,0,0,0,0,0,8,0,0,0,8,1},
   {1,1,1,0,1,1,1,1,0,0,0,0,7,1,1,1,8,0,0,1},
   {1,6,1,0,1,0,7,1,4,1,1,1,1,1,5,1,1,0,0,1},   //트랩위치 (x = 6, y = 4)
   {1,9,1,3,1,8,0,1,1,1,0,10,0,1,0,0,1,0,8,1},
   {1,0,1,1,1,0,0,0,0,1,10,0,10,1,0,0,1,1,0,1}, // 트랩에 걸린 후 플레이어 위치 x = 11, y = 5
   {1,8,0,0,1,1,0,0,0,1,0,10,0,1,0,0,7,1,0,1},
   {1,8,0,0,0,1,0,0,8,1,1,1,1,1,1,1,1,1,0,1}, // 열릴 문 위치 (x = 14, y = 7)
   {1,8,0,0,0,0,0,0,0,0,8,0,7,0,5,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
//(x = 11, y = 4)
//(x = 11, y = 6)
//(x = 10, y = 5)
//(x = 12, y = 5)

typedef enum Num_type {
    blank = 0,
    wall = 1,
    Player = 2,
    NPC = 3,
    A = 4,      //A열쇠를 가지고 있는 몬스터
    B = 5,      //열쇠조각을 가지고 있는 몬스터
    Boss = 6,
    Trap = 7,   //함정에 빠지면 몬스터를 강제로 잡아야하며, 몬스터 한 마리 처치 시 함정 바로 왼쪽 칸으로 이동
    monster = 8,
    barrior = 9,   //B열쇠로 열 수 있음
    Trap_Monster = 10
}object;

struct Monster_info {
    int HP;
    int Damage;
    int Def;
    int exp;
};      // 몬스터 정보

struct Player_info {
    int Level;
    int HP;
    int Damage;
    int Def;
    int exp;
    int A_Key;
    int B_key;
};      //플레이어 정보

typedef enum {
    up = 'w',
    down = 's',
    left = 'a',
    right = 'd'
}move;   // 방향키

typedef struct {
    int x;
    int y;
}location;   // 플레이어 위치

void RPG_map()
{
    system("cls");
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 20; x++) {
            switch (map[y][x]) {
            case blank: printf("  "); break;
            case wall: printf("■"); break;
            case Player: printf("Ｐ"); break;
            case NPC: printf("Ｎ"); break;
            case A: printf("Ａ"); break;
            case B: printf("Ｂ"); break;
            case Boss: printf("！"); break;
            case Trap: printf("Ｔ"); break;
            case monster: printf("Ｍ"); break;
            case barrior: printf("**"); break;
            case Trap_Monster: printf("Ｍ"); break;
            }
        }
        printf("\n");
    }
}   // 맵 모양

Player_info P[1] =
{
   {1, 500, 150, 50, 0, 0, 0}
};   //레벨, 체력, 공격력, 방어력, 경험치, A키, B키

Monster_info m[4] =
{
   {150, 80, 20, 50},   // A몬스터
   {200, 100, 50, 80},   // 일반 몬스터
   {250, 130, 80, 100},   // B몬스터
   {2500, 300, 150, 0}
};   //체력, 공격력, 방어력, 경험치

int NPC_count;
int B_count;

void Level_Up()
{
    if (P[0].Level < 3) {
        if (P[0].exp >= 100)
        {
            printf("플레이어 레벨업!\n");
            ++P[0].Level;
            P[0].HP = 500;
            P[0].HP += 100 * (P[0].Level - 1);
            P[0].Damage += 50;
            P[0].Def += 10;
            P[0].exp -= 100;

            for (int i = 0; i < 3; i++)
            {
                m[i].HP += 50 * (P[0].Level - 1);
                m[i].Damage += 20;
                m[i].Def += 5;
                m[i].exp += 30 * (P[0].Level - 1);   //1 : 80, 2 : 110(+30), 3: 170(+60) 
            }
        }
    }

    else if (P[0].Level < 5) {
        if (P[0].exp >= 500)
        {
            printf("플레이어 레벨업!\n");
            ++P[0].Level;
            P[0].HP = 500;
            P[0].HP += 100 * (P[0].Level - 1);
            P[0].Damage += 50;
            P[0].Def += 10;
            P[0].exp -= 500;

            for (int i = 0; i < 3; i++)
            {
                m[i].HP += 50 * (P[0].Level - 1);
                m[i].Damage += 20;
                m[i].Def += 5;
                m[i].exp += 30 * (P[0].Level - 1);
            }
        }
    }

    else {
        if (P[0].exp >= 1000)
        {
            printf("플레이어 레벨업!\n");
            ++P[0].Level;
            P[0].HP = 500;
            P[0].HP += 100 * (P[0].Level - 1);
            P[0].Damage += 50;
            P[0].Def += 10;
            P[0].exp -= 1000;

            for (int i = 0; i < 3; i++)
            {
                m[i].HP += 50 * (P[0].Level - 1);
                m[i].Damage += 20;
                m[i].Def += 5;
                m[i].exp += 30 * (P[0].Level - 1);
            }
        }
    }
}

void Random()
{
    srand(time(NULL));
    int Atk = rand() % 2;   //보스몬스터 공격 시 0이 나오면 miss, 1이 나오면 온힛

    if (Atk == 1)
    {
        printf("플레이어 체력 : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[3].Damage);
        Sleep(1000);
        P[0].HP = P[0].HP + P[0].Def - m[3].Damage;
    }
    else if (Atk == 0)
    {
        printf("Miss!\n");
    }
}

void Dir(location* const p, location add)   // p : 플레이어 위치, add : 플레이어 위치에 이동한 거리 추가
{
    location des;   //알아보기 쉽게 새로운 변수 추가 지정(p + add)

    des.x = p->x + add.x;
    des.y = p->y + add.y;

    object dest = (object)map[des.y][des.x];      // 오브젝트들의 위치를 좌표대로 맵에 표기

       //blank = 0,
       //wall = 1,
       //Player = 2,
       //NPC = 3,
       //A = 4,      //A열쇠를 가지고 있는 몬스터
       //B = 5,      //열쇠조각을 가지고 있는 몬스터
       //Boss = 6,
       //Trap = 7,   //함정에 빠지면 몬스터를 강제로 잡아야하며, 몬스터 한 마리 처치 시 함정 바로 왼쪽 칸으로 이동
       //monster = 8,
       //barrior = 9   //B열쇠로 열 수 있음
       //Trap_Monster = 10


    switch (dest)      // blank에서만 플레이어가 움직일 수 있게 설정
    {
    case blank:
        map[p->y][p->x] = blank;   //플레이어가 이동할 곳이 blank(로 대입)라면 이동하고,
        p->x = des.x;
        p->y = des.y;


        map[p->y][p->x] = Player;   //플레이어가 이동한 위치가 플레이어의 위치(로 대입)가 된다.
        break;

    case NPC:
        map[p->y][p->x] = Player;
        if (NPC_count == 0)
        {
            printf("\n자네는 이곳 사람이 아닌 것 같군.. 어째서 이런 위험한 곳에 있는건가?\n");
            Sleep(1500);
            printf("실례가 안된다면 내 부탁 하나만 들어주겠는가?\n");
            Sleep(1500);
            printf("내 아들이 집에서 나간지 2달이 되었는데도 돌아오지 않고 있다네..\n괜찮다면 내 아들이 어딨는지 찾아봐줄 수 있겠는가?\n");
            Sleep(1500);
            printf("*** Quest ***\n노인의 아들이 실종되었습니다. 불쌍한 노인을 위해서 아들의 흔적을 찾아주세요.\n근처에 있는 A몬스터를 처치하면 흔적을 찾을 수 있을지도 모릅니다.\n");
            Sleep(3000);
            printf("길이 열립니다.\n");
            Sleep(1500);
            map[1][4] = blank;
            NPC_count++;
        }

        else if (NPC_count == 1)
        {
            printf("내 아들의 흔적은 찾았는가?\n");
            Sleep(1500);
        }   // A몬스터잡고 아들의 쪽지(주변에 몬스터들이 득실거려요.. 너무 무서워요)발견. 노인한테 가져다주면 노인이 아들을 구출해달라고 한다.

        else if (NPC_count == 2)
        {
            P[0].A_Key--;
            printf("오.. 내 아들이 있을만한 곳의 단서를 찾았는가?\n");
            Sleep(1500);
            printf("(쪽지를 건네준다)\n");
            Sleep(1500);
            printf("내 아들이 몬스터들이 있는 곳에 있다고?? 이를 어떡한다..\n");
            Sleep(1500);
            printf("자네 혹시 내 아들을 구출해줄 수 있겠나? 구출해준다면 큰 보상을 주지!\n");
            Sleep(1500);
            printf("*** Quest ***\n아들을 구해주세요!\n");
            Sleep(3000);
            NPC_count++;
        }
        else if (NPC_count == 3)
        {
            printf("부디 무사하기를..\n");
            Sleep(1500);
        }

        else if (NPC_count == 4)
        {
            printf("오! 자네 돌아왔구먼.. 내 아들은 어디있는가?\n");
            Sleep(1000);
            printf("그런 일이 있었구먼.. 미련한 자식..\n");
            Sleep(1000);
            printf("약속대로 큰 보상을 주도록 하지.\n");
            Sleep(1000);
            printf("게임을 클리어하였습니다!\n");
            Sleep(1000);
            NPC_count++;
            break;
        }

        break;
        //Monster_info m[3] =
        //{
        //   {150, 80, 20, 50},   // A몬스터
        //   {200, 100, 50, 80},   // 일반 몬스터
        //   {250, 130, 80, 100}   // B몬스터
        //};   //체력, 공격력, 방어력
    case A:
        map[p->y][p->x] = Player;

        if (P[0].HP <= 0)
        {
            printf("게임종료...\n");
            Sleep(1000);
            break;
        }
        printf("A몬스터 발견! Fight!\n");
        Sleep(1000);
        printf("플레이어 선공!\n");
        Sleep(1000);
        while (1)
        {
            printf("플레이어 공격!\n");
            Sleep(1000);
            printf("A몬스터 체력 : %d => %d\n", m[0].HP, m[0].HP + m[0].Def - P[0].Damage);
            Sleep(1000);
            m[0].HP = m[0].HP + m[0].Def - P[0].Damage;

            if (m[0].HP <= 0) {
                printf("A몬스터 처치! 경험치 %d 증가!\n아들의 쪽지 발견!\n'주변에 몬스터들이 득실거려요.. 너무 무서워요ㅠㅠ'\n", m[0].exp);
                Sleep(1000);
                P[0].A_Key++;
                P[0].exp += m[0].exp;
                NPC_count++;

                map[des.y][des.x] = blank;
                break;
            }

            printf("A몬스터 공격!\n");
            Sleep(1000);
            printf("플레이어 체력 : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[0].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[0].Damage;

            if (P[0].HP <= 0) {
                printf("플레이어 사망!\n");
                break;
            }
        }
        break;

    case monster:
        map[p->y][p->x] = Player;

        if (P[0].HP <= 0)
        {
            printf("게임종료...\n");
            Sleep(1000);
            break;
        }
        printf("일반몬스터 발견! Fight!\n");
        Sleep(1000);
        printf("플레이어 선공!\n");
        Sleep(1000);
        while (1)
        {
            printf("플레이어 공격!\n");
            Sleep(1000);
            printf("일반몬스터 체력 : %d => %d\n", m[1].HP, m[1].HP + m[1].Def - P[0].Damage);
            Sleep(1000);
            m[1].HP = m[1].HP + m[1].Def - P[0].Damage;

            if (m[1].HP <= 0) {
                printf("일반몬스터 처치! 경험치 %d 증가!\n", m[1].exp);
                Sleep(1000);
                P[0].exp += m[1].exp;
                m[1].HP = 200 + 50 * (P[0].Level - 1);

                map[des.y][des.x] = blank;
                break;
            }

            printf("일반몬스터 공격!\n");
            Sleep(1000);
            printf("플레이어 체력 : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[1].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[1].Damage;

            if (P[0].HP <= 0) {
                printf("플레이어 사망!\n");
                break;
            }
        }
        break;

    case Trap:
        map[p->y][p->x] = Player;
        map[des.y][des.x] = blank;

        printf("트랩에 걸렸습니다. 플레이어가 강제 이동됩니다.");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n");
        printf("트랩 안에 있는 몬스터 중 한 마리를 처치할 시 탈출할 수 있습니다.\n");
        Sleep(1000);

        map[p->y][p->x] = blank;
        p->y = 5;
        p->x = 11;
        map[p->y][p->x] = Player;

        break;

    case Trap_Monster:
        map[p->y][p->x] = Player;

        if (P[0].HP <= 0)
        {
            printf("게임종료...\n");
            Sleep(1000);
            break;
        }
        printf("일반몬스터 발견! Fight!\n");
        Sleep(1000);
        printf("플레이어 선공!\n");
        Sleep(1000);
        while (1)
        {
            printf("플레이어 공격!\n");
            Sleep(1000);
            printf("일반몬스터 체력 : %d => %d\n", m[1].HP, m[1].HP + m[1].Def - P[0].Damage);
            Sleep(1000);
            m[1].HP = m[1].HP + m[1].Def - P[0].Damage;

            if (m[1].HP <= 0) {
                printf("일반몬스터 처치! 경험치 %d 증가!\n", m[1].exp);
                Sleep(1000);
                P[0].exp += m[1].exp;
                m[1].HP = 200 + 50 * (P[0].Level - 1);

                map[des.y][des.x] = blank;
                printf("몬스터를 처치했습니다. 트랩에서 빠져나옵니다.\n");
                Sleep(1000);

                map[p->y][p->x] = blank;
                p->y = 2;
                p->x = 12;
                map[p->y][p->x] = Player;
                break;
            }

            printf("일반몬스터 공격!\n");
            Sleep(1000);
            printf("플레이어 체력 : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[1].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[1].Damage;

            if (P[0].HP <= 0) {
                printf("플레이어 사망!\n");
                break;
            }
        }
        break;

    case B:
        map[p->y][p->x] = Player;

        if (P[0].HP <= 0)
        {
            printf("게임종료...\n");
            Sleep(1000);
            break;
        }
        printf("B몬스터 : 크르르르..\n");
        Sleep(1000);
        printf("(B몬스터가 수상한 물건을 지니고 있다. 열쇠 조각인 것처럼 보인다.)\n");
        Sleep(1000);
        printf("(처치하고 열쇠조각을 손에 넣자.)\n");
        Sleep(1000);
        printf("플레이어 선공!\n");
        Sleep(1000);
        while (1)
        {
            printf("플레이어 공격!\n");
            Sleep(1000);
            printf("B몬스터 체력 : %d => %d\n", m[2].HP, m[2].HP + m[2].Def - P[0].Damage);
            Sleep(1000);
            m[2].HP = m[2].HP + m[2].Def - P[0].Damage;

            if (m[2].HP <= 0) {
                printf("B몬스터 처치! 경험치 %d 증가!\n 열쇠조각 획득!\n", m[0].exp);
                Sleep(1000);
                map[7][14] = blank;
                P[0].B_key++;
                P[0].exp += m[2].exp;
                m[2].HP = 250 + 50 * (P[0].Level - 1);


                if (B_count == 0)
                {
                    printf("이대로 끝나지 않는다..\n");
                    Sleep(1000);
                    printf("숨겨져있던 문이 열립니다.");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".\n");
                    Sleep(1000);
                    B_count++;
                }

                else if (B_count == 1)
                {
                    printf("죄송합니다.. 임무를..\n");
                    Sleep(1000);
                }

                map[des.y][des.x] = blank;
                break;
            }

            printf("B몬스터 공격!\n");
            Sleep(1000);
            printf("플레이어 체력 : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[2].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[2].Damage;

            if (P[0].HP <= 0) {
                printf("플레이어 사망!\n");
                break;
            }
        }
        break;

    case barrior:
        if (P[0].B_key < 2) {
            printf("문을 열 열쇠가 부족합니다.\n");
            Sleep(1000);
        }

        else if (P[0].B_key == 2)
        {
            printf("문이 열립니다.\n");
            Sleep(1000);
            map[4][1] = blank;
        }
        break;

    case Boss:
        map[p->y][p->x] = Player;
        if (P[0].Level >= 10) {
            printf("크아아아..!!\n");
            Sleep(1000);
            printf("이봐요! 진정해봐요!\n");
            Sleep(1000);
            printf("(아들은 이미 이성을 잃었다. 이대로 두면 일대가 쑥대밭이 될지도 모르니 제압하자.)\n");
            Sleep(1000);

            printf("플레이어 선공!\n");
            Sleep(1000);

            if (P[0].HP <= 0)
            {
                printf("게임종료...\n");
                Sleep(1000);
                break;
            }
            while (1)
            {
                printf("플레이어 공격!\n");
                Sleep(1000);
                printf("보스몬스터 체력 : %d => %d\n", m[3].HP, m[3].HP + m[3].Def - P[0].Damage);
                Sleep(1000);
                m[3].HP = m[3].HP + m[3].Def - P[0].Damage;

                if (m[3].HP <= 0) {
                    printf("아버지.. 죄송합니다..\n");
                    Sleep(1000);
                    printf("보스몬스터 처치! 경험치 %d 증가!\n", m[3].exp);
                    Sleep(1000);
                    map[3][1] = blank;
                    P[0].exp += m[3].exp;
                    NPC_count++;
                    break;
                }

                printf("보스몬스터 공격!\n");
                Sleep(1000);
                Random();

                if (P[0].HP <= 0) {
                    printf("플레이어 사망!\n");
                    break;
                }
            }
        }

        else if (P[0].Level < 10)
        {
            printf("이곳은 너무 위험하다. 레벨 10을 만들고 다시 돌아오자.\n");
            Sleep(1000);
        }
        break;

    default: break;
    }
}

void Player_Print()
{
    printf("\n\nLevel %d\nHP : %d Damage : %d, Def : %d, exp : %d\n단서 1 : %d, 단서 2 : %d\n", P->Level, P->HP, P->Damage, P->Def, P->exp, P->A_Key, P->B_key);
}

void RPG()
{
    location p;
    p.x = 1;
    p.y = 1;

    move mo;
    location a;

    NPC_count = 0;
    B_count = 0;

    while (1) {
        RPG_map();
        Player_Print();
        Level_Up();
        mo = (move)_getch();

        switch (mo) {
        case up:
            a.x = 0;
            a.y = -1;
            break;

        case down:
            a.x = 0;
            a.y = +1;
            break;

        case left:
            a.x = -1;
            a.y = 0;
            break;

        case right:
            a.x = +1;
            a.y = 0;
            break;

        default:
            a.x = 0;
            a.y = 0;
            break;
        }
        Dir(&p, a);
    }
}