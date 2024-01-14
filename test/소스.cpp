#include <iostream>
#include <Windows.h>
#include <conio.h>

// ���� ������ �� ũ��
#define MAX_WIDTH 12
#define MAX_HEIGHT 12
#define MAX_TAIL 101

// �÷��̾ ������ �� �ִ� ����
const int width = 10;
const int height = 10;
int gameMode;

enum eMapType
{
	EMPTY,
	WALL
};

enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum eGameMode
{
	NONE,
	EASY,
	HARD
};

class CPlayer
{
public:
	CPlayer() :
		m_tPos({ 0, 0 }),
		m_eDir(STOP),
		m_nTail(0)
	{

	}
	~CPlayer()
	{

	}

private:
	POINT m_tPos;
	eDirection m_eDir;

	// ���� �κ�
	int m_Tailarray[MAX_TAIL][2];
	// ���� ����
	int m_nTail;

public:
	POINT GetPos()
	{
		return m_tPos;
	}
	void SetPos(int x, int y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}
	void SetX(int x)
	{
		m_tPos.x = x;
	}
	void SetY(int y)
	{
		m_tPos.y = y;
	}

	void SetDir(eDirection dir)
	{
		m_eDir = dir;
	}

	void AddTail()
	{
		m_nTail++;
	}

	int GetTail()
	{
		return m_nTail;
	}

	eDirection GetDir()
	{
		return m_eDir;
	}

	int(*GetTailArray())[2]
	{
		return m_Tailarray;
	}
};

using namespace std;

// int�� �Է¹ޱ�
int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void gotoxy(int x, int y)
{
	COORD Pos;

	Pos.X = x * 2;
	Pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

bool ChoiceMode()
{
	gotoxy(3, 5);
	cout << "������ ���̵��� �����ϼ���";
	gotoxy(4, 6);
	cout << "(EASY : 1, HARD : 2)" << endl;
	gotoxy(3, 8);
	cout << "Easy : ���� ����� �� ����";
	gotoxy(3, 9);
	cout << "Hard : ���� ����� �� ����" << endl;

	gotoxy(6, 11);
	cout << "Select : ";
	while (1)
	{
		gameMode = InputInt();
		if (gameMode == INT_MAX) return false;

		if (gameMode < 1 || gameMode > 2) continue;
		else break;
	}
	return true;
}

// ���� �ʱ�ȭ
bool Setup(int(*map)[MAX_HEIGHT], CPlayer* pPlayer, bool gameOver, POINT& itemPos)
{
	if (!ChoiceMode()) return false;

	// �� init
	for (int i = 0; i < MAX_WIDTH; ++i) map[0][i] = WALL;

	for (int i = 1; i < MAX_HEIGHT - 1; ++i)
	{
		for (int j = 0; j < MAX_WIDTH; ++j)
		{
			if (j == 0 || j == MAX_WIDTH - 1)
				map[i][j] = WALL;
			else
				map[i][j] = EMPTY;
		}
	}

	for (int i = 0; i < MAX_WIDTH; ++i)
	{
		map[MAX_HEIGHT - 1][i] = WALL;
	}

	// player init
	pPlayer->SetPos(width / 2, height / 2);
	pPlayer->SetDir(STOP);

	// gameOver init
	gameOver = false;


	itemPos.x = (rand() % width) + 1;
	itemPos.y = (rand() % height) + 1;

	return true;
}

// �� ���
void Draw(int(*map)[MAX_HEIGHT], POINT itemPos, CPlayer* pPlayer, int& iScore)
{
	system("cls");

	int(*tTail)[2] = pPlayer->GetTailArray();

	for (int i = 0; i < MAX_HEIGHT; ++i)
	{
		for (int j = 0; j < MAX_WIDTH; ++j)
		{
			// �÷��̾�
			if (i == pPlayer->GetPos().y && j == pPlayer->GetPos().x)
				cout << "��";
			// ������
			else if (i == itemPos.y && j == itemPos.x)
				cout << "��";

			else if (map[i][j] == WALL)
				cout << "��";
			else
			{
				bool tailFlag = false;
				for (int k = 0; k < pPlayer->GetTail(); ++k)
				{
					if (j == tTail[k][0] && i == tTail[k][1])
					{
						cout << "��";
						tailFlag = true;
						break;
					}
				}
				if (!tailFlag) cout << "  ";
			}
		}
		cout << endl;
	}
	cout << "Score : " << iScore << endl;
	cout << "Quit : Press x" << endl;
}

// Ű �Է¹ޱ�
void Input(CPlayer* pPlayer, bool& gameOver)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			pPlayer->SetDir(UP);
			break;
		case 's':
			pPlayer->SetDir(DOWN);
			break;
		case 'a':
			pPlayer->SetDir(LEFT);
			break;
		case 'd':
			pPlayer->SetDir(RIGHT);
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		}
	}
}

// �÷��̾� Update
void Logic(CPlayer* pPlayer, bool& gameOver, POINT& itemPos, int& iScore)
{
	// ���� �޾��ֱ�
	int(*tTail)[2] = pPlayer->GetTailArray();

	int prevFirstX = tTail[0][0];
	int prevFirstY = tTail[0][1];
	int prevSecondX, prevSecondY;
	tTail[0][0] = pPlayer->GetPos().x;
	tTail[0][1] = pPlayer->GetPos().y;

	for (int i = 1; i < pPlayer->GetTail(); ++i)
	{
		prevSecondX = tTail[i][0];
		prevSecondY = tTail[i][1];
		tTail[i][0] = prevFirstX;
		tTail[i][1] = prevFirstY;
		prevFirstX = prevSecondX;
		prevFirstY = prevSecondY;
	}

	// �÷��̾��� ��ġ �ҷ�����
	int tx = pPlayer->GetPos().x;
	int ty = pPlayer->GetPos().y;

	switch (pPlayer->GetDir())
	{
	case UP:
		pPlayer->SetPos(tx, ty - 1);
		break;
	case DOWN:
		pPlayer->SetPos(tx, ty + 1);
		break;
	case LEFT:
		pPlayer->SetPos(tx - 1, ty);
		break;
	case RIGHT:
		pPlayer->SetPos(tx + 1, ty);
		break;
	default:
		break;
	}

	if (gameMode == EASY)
	{
		if (pPlayer->GetPos().x < 1) pPlayer->SetX(width);
		else if (pPlayer->GetPos().x > width) pPlayer->SetX(1);

		if (pPlayer->GetPos().y < 1) pPlayer->SetY(height);
		else if (pPlayer->GetPos().y > height) pPlayer->SetY(1);
	}
	if (gameMode == HARD)
	{
		// ���� ���� ���
		if (pPlayer->GetPos().x < 1 || pPlayer->GetPos().x > width
			|| pPlayer->GetPos().y < 1 || pPlayer->GetPos().y > height)
			gameOver = true;
	}

	// �ڽ��� ������ ���� ���
	for (int i = 0; i < pPlayer->GetTail(); ++i)
	{
		if (pPlayer->GetPos().x == tTail[i][0] && pPlayer->GetPos().y == tTail[i][1])
		{
			gameOver = true;
			break;
		}
	}

	// �������� ���� ���
	if (pPlayer->GetPos().x == itemPos.x && pPlayer->GetPos().y == itemPos.y)
	{
		iScore += 10;

		// �������� ���ο� ��ġ�� �����
		itemPos.x = (rand() % width) + 1;
		itemPos.y = (rand() % height) + 1;

		// �÷��̾��� ���� ����
		pPlayer->AddTail();
	}
}

// �ܼ� â ����
void SetConsoleView()
{
	system("mode con: cols=40 lines=20"); // �ܼ�â ũ�� ����
	system("title Snake Game"); // �ܼ�â Ÿ��Ʋ ����
}

int main()
{
	SetConsoleView();

	CPlayer* player = new CPlayer;
	int map[MAX_HEIGHT][MAX_WIDTH];
	bool gameOver = false;
	POINT itemPos;
	int iScore = 0;

	// �ʱ�ȭ�� �����ߴٸ� ���α׷� ����
	if (!Setup(map, player, gameOver, itemPos))
		return 0;

	while (!gameOver)
	{
		Draw(map, itemPos, player, iScore);
		Input(player, gameOver);
		Logic(player, gameOver, itemPos, iScore);
		Sleep(100);
	}

	system("pause");
	return 0;
}