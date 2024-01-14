#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "�̴�RPG.h"
#include <stdlib.h>      //srand�� �̿��� �������Ͱ� ���� �� missȮ�� �߰�
#include <time.h>

int map[20][20] =
{
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,2,0,0,1,0,0,0,0,0,0,0,0,0,8,0,0,0,8,1},
   {1,1,1,0,1,1,1,1,0,0,0,0,7,1,1,1,8,0,0,1},
   {1,6,1,0,1,0,7,1,4,1,1,1,1,1,5,1,1,0,0,1},   //Ʈ����ġ (x = 6, y = 4)
   {1,9,1,3,1,8,0,1,1,1,0,10,0,1,0,0,1,0,8,1},
   {1,0,1,1,1,0,0,0,0,1,10,0,10,1,0,0,1,1,0,1}, // Ʈ���� �ɸ� �� �÷��̾� ��ġ x = 11, y = 5
   {1,8,0,0,1,1,0,0,0,1,0,10,0,1,0,0,7,1,0,1},
   {1,8,0,0,0,1,0,0,8,1,1,1,1,1,1,1,1,1,0,1}, // ���� �� ��ġ (x = 14, y = 7)
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
    A = 4,      //A���踦 ������ �ִ� ����
    B = 5,      //���������� ������ �ִ� ����
    Boss = 6,
    Trap = 7,   //������ ������ ���͸� ������ ��ƾ��ϸ�, ���� �� ���� óġ �� ���� �ٷ� ���� ĭ���� �̵�
    monster = 8,
    barrior = 9,   //B����� �� �� ����
    Trap_Monster = 10
}object;

struct Monster_info {
    int HP;
    int Damage;
    int Def;
    int exp;
};      // ���� ����

struct Player_info {
    int Level;
    int HP;
    int Damage;
    int Def;
    int exp;
    int A_Key;
    int B_key;
};      //�÷��̾� ����

typedef enum {
    up = 'w',
    down = 's',
    left = 'a',
    right = 'd'
}move;   // ����Ű

typedef struct {
    int x;
    int y;
}location;   // �÷��̾� ��ġ

void RPG_map()
{
    system("cls");
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 20; x++) {
            switch (map[y][x]) {
            case blank: printf("  "); break;
            case wall: printf("��"); break;
            case Player: printf("��"); break;
            case NPC: printf("��"); break;
            case A: printf("��"); break;
            case B: printf("��"); break;
            case Boss: printf("��"); break;
            case Trap: printf("��"); break;
            case monster: printf("��"); break;
            case barrior: printf("**"); break;
            case Trap_Monster: printf("��"); break;
            }
        }
        printf("\n");
    }
}   // �� ���

Player_info P[1] =
{
   {1, 500, 150, 50, 0, 0, 0}
};   //����, ü��, ���ݷ�, ����, ����ġ, AŰ, BŰ

Monster_info m[4] =
{
   {150, 80, 20, 50},   // A����
   {200, 100, 50, 80},   // �Ϲ� ����
   {250, 130, 80, 100},   // B����
   {2500, 300, 150, 0}
};   //ü��, ���ݷ�, ����, ����ġ

int NPC_count;
int B_count;

void Level_Up()
{
    if (P[0].Level < 3) {
        if (P[0].exp >= 100)
        {
            printf("�÷��̾� ������!\n");
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
            printf("�÷��̾� ������!\n");
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
            printf("�÷��̾� ������!\n");
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
    int Atk = rand() % 2;   //�������� ���� �� 0�� ������ miss, 1�� ������ ����

    if (Atk == 1)
    {
        printf("�÷��̾� ü�� : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[3].Damage);
        Sleep(1000);
        P[0].HP = P[0].HP + P[0].Def - m[3].Damage;
    }
    else if (Atk == 0)
    {
        printf("Miss!\n");
    }
}

void Dir(location* const p, location add)   // p : �÷��̾� ��ġ, add : �÷��̾� ��ġ�� �̵��� �Ÿ� �߰�
{
    location des;   //�˾ƺ��� ���� ���ο� ���� �߰� ����(p + add)

    des.x = p->x + add.x;
    des.y = p->y + add.y;

    object dest = (object)map[des.y][des.x];      // ������Ʈ���� ��ġ�� ��ǥ��� �ʿ� ǥ��

       //blank = 0,
       //wall = 1,
       //Player = 2,
       //NPC = 3,
       //A = 4,      //A���踦 ������ �ִ� ����
       //B = 5,      //���������� ������ �ִ� ����
       //Boss = 6,
       //Trap = 7,   //������ ������ ���͸� ������ ��ƾ��ϸ�, ���� �� ���� óġ �� ���� �ٷ� ���� ĭ���� �̵�
       //monster = 8,
       //barrior = 9   //B����� �� �� ����
       //Trap_Monster = 10


    switch (dest)      // blank������ �÷��̾ ������ �� �ְ� ����
    {
    case blank:
        map[p->y][p->x] = blank;   //�÷��̾ �̵��� ���� blank(�� ����)��� �̵��ϰ�,
        p->x = des.x;
        p->y = des.y;


        map[p->y][p->x] = Player;   //�÷��̾ �̵��� ��ġ�� �÷��̾��� ��ġ(�� ����)�� �ȴ�.
        break;

    case NPC:
        map[p->y][p->x] = Player;
        if (NPC_count == 0)
        {
            printf("\n�ڳ״� �̰� ����� �ƴ� �� ����.. ��°�� �̷� ������ ���� �ִ°ǰ�?\n");
            Sleep(1500);
            printf("�Ƿʰ� �ȵȴٸ� �� ��Ź �ϳ��� ����ְڴ°�?\n");
            Sleep(1500);
            printf("�� �Ƶ��� ������ ������ 2���� �Ǿ��µ��� ���ƿ��� �ʰ� �ִٳ�..\n�����ٸ� �� �Ƶ��� ������� ã�ƺ��� �� �ְڴ°�?\n");
            Sleep(1500);
            printf("*** Quest ***\n������ �Ƶ��� �����Ǿ����ϴ�. �ҽ��� ������ ���ؼ� �Ƶ��� ������ ã���ּ���.\n��ó�� �ִ� A���͸� óġ�ϸ� ������ ã�� �� �������� �𸨴ϴ�.\n");
            Sleep(3000);
            printf("���� �����ϴ�.\n");
            Sleep(1500);
            map[1][4] = blank;
            NPC_count++;
        }

        else if (NPC_count == 1)
        {
            printf("�� �Ƶ��� ������ ã�Ҵ°�?\n");
            Sleep(1500);
        }   // A������� �Ƶ��� ����(�ֺ��� ���͵��� ��ǰŷ���.. �ʹ� ��������)�߰�. �������� �������ָ� ������ �Ƶ��� �����ش޶�� �Ѵ�.

        else if (NPC_count == 2)
        {
            P[0].A_Key--;
            printf("��.. �� �Ƶ��� �������� ���� �ܼ��� ã�Ҵ°�?\n");
            Sleep(1500);
            printf("(������ �ǳ��ش�)\n");
            Sleep(1500);
            printf("�� �Ƶ��� ���͵��� �ִ� ���� �ִٰ�?? �̸� ��Ѵ�..\n");
            Sleep(1500);
            printf("�ڳ� Ȥ�� �� �Ƶ��� �������� �� �ְڳ�? �������شٸ� ū ������ ����!\n");
            Sleep(1500);
            printf("*** Quest ***\n�Ƶ��� �����ּ���!\n");
            Sleep(3000);
            NPC_count++;
        }
        else if (NPC_count == 3)
        {
            printf("�ε� �����ϱ⸦..\n");
            Sleep(1500);
        }

        else if (NPC_count == 4)
        {
            printf("��! �ڳ� ���ƿԱ���.. �� �Ƶ��� ����ִ°�?\n");
            Sleep(1000);
            printf("�׷� ���� �־�����.. �̷��� �ڽ�..\n");
            Sleep(1000);
            printf("��Ӵ�� ū ������ �ֵ��� ����.\n");
            Sleep(1000);
            printf("������ Ŭ�����Ͽ����ϴ�!\n");
            Sleep(1000);
            NPC_count++;
            break;
        }

        break;
        //Monster_info m[3] =
        //{
        //   {150, 80, 20, 50},   // A����
        //   {200, 100, 50, 80},   // �Ϲ� ����
        //   {250, 130, 80, 100}   // B����
        //};   //ü��, ���ݷ�, ����
    case A:
        map[p->y][p->x] = Player;

        if (P[0].HP <= 0)
        {
            printf("��������...\n");
            Sleep(1000);
            break;
        }
        printf("A���� �߰�! Fight!\n");
        Sleep(1000);
        printf("�÷��̾� ����!\n");
        Sleep(1000);
        while (1)
        {
            printf("�÷��̾� ����!\n");
            Sleep(1000);
            printf("A���� ü�� : %d => %d\n", m[0].HP, m[0].HP + m[0].Def - P[0].Damage);
            Sleep(1000);
            m[0].HP = m[0].HP + m[0].Def - P[0].Damage;

            if (m[0].HP <= 0) {
                printf("A���� óġ! ����ġ %d ����!\n�Ƶ��� ���� �߰�!\n'�ֺ��� ���͵��� ��ǰŷ���.. �ʹ� ��������Ф�'\n", m[0].exp);
                Sleep(1000);
                P[0].A_Key++;
                P[0].exp += m[0].exp;
                NPC_count++;

                map[des.y][des.x] = blank;
                break;
            }

            printf("A���� ����!\n");
            Sleep(1000);
            printf("�÷��̾� ü�� : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[0].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[0].Damage;

            if (P[0].HP <= 0) {
                printf("�÷��̾� ���!\n");
                break;
            }
        }
        break;

    case monster:
        map[p->y][p->x] = Player;

        if (P[0].HP <= 0)
        {
            printf("��������...\n");
            Sleep(1000);
            break;
        }
        printf("�Ϲݸ��� �߰�! Fight!\n");
        Sleep(1000);
        printf("�÷��̾� ����!\n");
        Sleep(1000);
        while (1)
        {
            printf("�÷��̾� ����!\n");
            Sleep(1000);
            printf("�Ϲݸ��� ü�� : %d => %d\n", m[1].HP, m[1].HP + m[1].Def - P[0].Damage);
            Sleep(1000);
            m[1].HP = m[1].HP + m[1].Def - P[0].Damage;

            if (m[1].HP <= 0) {
                printf("�Ϲݸ��� óġ! ����ġ %d ����!\n", m[1].exp);
                Sleep(1000);
                P[0].exp += m[1].exp;
                m[1].HP = 200 + 50 * (P[0].Level - 1);

                map[des.y][des.x] = blank;
                break;
            }

            printf("�Ϲݸ��� ����!\n");
            Sleep(1000);
            printf("�÷��̾� ü�� : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[1].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[1].Damage;

            if (P[0].HP <= 0) {
                printf("�÷��̾� ���!\n");
                break;
            }
        }
        break;

    case Trap:
        map[p->y][p->x] = Player;
        map[des.y][des.x] = blank;

        printf("Ʈ���� �ɷȽ��ϴ�. �÷��̾ ���� �̵��˴ϴ�.");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n");
        printf("Ʈ�� �ȿ� �ִ� ���� �� �� ������ óġ�� �� Ż���� �� �ֽ��ϴ�.\n");
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
            printf("��������...\n");
            Sleep(1000);
            break;
        }
        printf("�Ϲݸ��� �߰�! Fight!\n");
        Sleep(1000);
        printf("�÷��̾� ����!\n");
        Sleep(1000);
        while (1)
        {
            printf("�÷��̾� ����!\n");
            Sleep(1000);
            printf("�Ϲݸ��� ü�� : %d => %d\n", m[1].HP, m[1].HP + m[1].Def - P[0].Damage);
            Sleep(1000);
            m[1].HP = m[1].HP + m[1].Def - P[0].Damage;

            if (m[1].HP <= 0) {
                printf("�Ϲݸ��� óġ! ����ġ %d ����!\n", m[1].exp);
                Sleep(1000);
                P[0].exp += m[1].exp;
                m[1].HP = 200 + 50 * (P[0].Level - 1);

                map[des.y][des.x] = blank;
                printf("���͸� óġ�߽��ϴ�. Ʈ������ �������ɴϴ�.\n");
                Sleep(1000);

                map[p->y][p->x] = blank;
                p->y = 2;
                p->x = 12;
                map[p->y][p->x] = Player;
                break;
            }

            printf("�Ϲݸ��� ����!\n");
            Sleep(1000);
            printf("�÷��̾� ü�� : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[1].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[1].Damage;

            if (P[0].HP <= 0) {
                printf("�÷��̾� ���!\n");
                break;
            }
        }
        break;

    case B:
        map[p->y][p->x] = Player;

        if (P[0].HP <= 0)
        {
            printf("��������...\n");
            Sleep(1000);
            break;
        }
        printf("B���� : ũ������..\n");
        Sleep(1000);
        printf("(B���Ͱ� ������ ������ ���ϰ� �ִ�. ���� ������ ��ó�� ���δ�.)\n");
        Sleep(1000);
        printf("(óġ�ϰ� ���������� �տ� ����.)\n");
        Sleep(1000);
        printf("�÷��̾� ����!\n");
        Sleep(1000);
        while (1)
        {
            printf("�÷��̾� ����!\n");
            Sleep(1000);
            printf("B���� ü�� : %d => %d\n", m[2].HP, m[2].HP + m[2].Def - P[0].Damage);
            Sleep(1000);
            m[2].HP = m[2].HP + m[2].Def - P[0].Damage;

            if (m[2].HP <= 0) {
                printf("B���� óġ! ����ġ %d ����!\n �������� ȹ��!\n", m[0].exp);
                Sleep(1000);
                map[7][14] = blank;
                P[0].B_key++;
                P[0].exp += m[2].exp;
                m[2].HP = 250 + 50 * (P[0].Level - 1);


                if (B_count == 0)
                {
                    printf("�̴�� ������ �ʴ´�..\n");
                    Sleep(1000);
                    printf("�������ִ� ���� �����ϴ�.");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".\n");
                    Sleep(1000);
                    B_count++;
                }

                else if (B_count == 1)
                {
                    printf("�˼��մϴ�.. �ӹ���..\n");
                    Sleep(1000);
                }

                map[des.y][des.x] = blank;
                break;
            }

            printf("B���� ����!\n");
            Sleep(1000);
            printf("�÷��̾� ü�� : %d => %d\n", P[0].HP, P[0].HP + P[0].Def - m[2].Damage);
            Sleep(1000);
            P[0].HP = P[0].HP + P[0].Def - m[2].Damage;

            if (P[0].HP <= 0) {
                printf("�÷��̾� ���!\n");
                break;
            }
        }
        break;

    case barrior:
        if (P[0].B_key < 2) {
            printf("���� �� ���谡 �����մϴ�.\n");
            Sleep(1000);
        }

        else if (P[0].B_key == 2)
        {
            printf("���� �����ϴ�.\n");
            Sleep(1000);
            map[4][1] = blank;
        }
        break;

    case Boss:
        map[p->y][p->x] = Player;
        if (P[0].Level >= 10) {
            printf("ũ�ƾƾ�..!!\n");
            Sleep(1000);
            printf("�̺���! �����غ���!\n");
            Sleep(1000);
            printf("(�Ƶ��� �̹� �̼��� �Ҿ���. �̴�� �θ� �ϴ밡 ������� ������ �𸣴� ��������.)\n");
            Sleep(1000);

            printf("�÷��̾� ����!\n");
            Sleep(1000);

            if (P[0].HP <= 0)
            {
                printf("��������...\n");
                Sleep(1000);
                break;
            }
            while (1)
            {
                printf("�÷��̾� ����!\n");
                Sleep(1000);
                printf("�������� ü�� : %d => %d\n", m[3].HP, m[3].HP + m[3].Def - P[0].Damage);
                Sleep(1000);
                m[3].HP = m[3].HP + m[3].Def - P[0].Damage;

                if (m[3].HP <= 0) {
                    printf("�ƹ���.. �˼��մϴ�..\n");
                    Sleep(1000);
                    printf("�������� óġ! ����ġ %d ����!\n", m[3].exp);
                    Sleep(1000);
                    map[3][1] = blank;
                    P[0].exp += m[3].exp;
                    NPC_count++;
                    break;
                }

                printf("�������� ����!\n");
                Sleep(1000);
                Random();

                if (P[0].HP <= 0) {
                    printf("�÷��̾� ���!\n");
                    break;
                }
            }
        }

        else if (P[0].Level < 10)
        {
            printf("�̰��� �ʹ� �����ϴ�. ���� 10�� ����� �ٽ� ���ƿ���.\n");
            Sleep(1000);
        }
        break;

    default: break;
    }
}

void Player_Print()
{
    printf("\n\nLevel %d\nHP : %d Damage : %d, Def : %d, exp : %d\n�ܼ� 1 : %d, �ܼ� 2 : %d\n", P->Level, P->HP, P->Damage, P->Def, P->exp, P->A_Key, P->B_key);
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