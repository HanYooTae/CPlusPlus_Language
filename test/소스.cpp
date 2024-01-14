#include <iostream>
#include <Windows.h>
#include <conio.h>

// 벽을 포함한 맵 크기
#define MAX_WIDTH 12
#define MAX_HEIGHT 12
#define MAX_TAIL 101

// 플레이어가 움직일 수 있는 범위
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

	// 꼬리 부분
	int m_Tailarray[MAX_TAIL][2];
	// 꼬리 개수
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

// int형 입력받기
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
	cout << "게임의 난이도를 선택하세요";
	gotoxy(4, 6);
	cout << "(EASY : 1, HARD : 2)" << endl;
	gotoxy(3, 8);
	cout << "Easy : 벽을 통과할 수 있음";
	gotoxy(3, 9);
	cout << "Hard : 벽을 통과할 수 없음" << endl;

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

// 게임 초기화
bool Setup(int(*map)[MAX_HEIGHT], CPlayer* pPlayer, bool gameOver, POINT& itemPos)
{
	if (!ChoiceMode()) return false;

	// 맵 init
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

// 맵 출력
void Draw(int(*map)[MAX_HEIGHT], POINT itemPos, CPlayer* pPlayer, int& iScore)
{
	system("cls");

	int(*tTail)[2] = pPlayer->GetTailArray();

	for (int i = 0; i < MAX_HEIGHT; ++i)
	{
		for (int j = 0; j < MAX_WIDTH; ++j)
		{
			// 플레이어
			if (i == pPlayer->GetPos().y && j == pPlayer->GetPos().x)
				cout << "○";
			// 아이템
			else if (i == itemPos.y && j == itemPos.x)
				cout << "＠";

			else if (map[i][j] == WALL)
				cout << "■";
			else
			{
				bool tailFlag = false;
				for (int k = 0; k < pPlayer->GetTail(); ++k)
				{
					if (j == tTail[k][0] && i == tTail[k][1])
					{
						cout << "◀";
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

// 키 입력받기
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

// 플레이어 Update
void Logic(CPlayer* pPlayer, bool& gameOver, POINT& itemPos, int& iScore)
{
	// 꼬리 달아주기
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

	// 플레이어의 위치 불러오기
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
		// 벽에 닿은 경우
		if (pPlayer->GetPos().x < 1 || pPlayer->GetPos().x > width
			|| pPlayer->GetPos().y < 1 || pPlayer->GetPos().y > height)
			gameOver = true;
	}

	// 자신이 꼬리에 닿은 경우
	for (int i = 0; i < pPlayer->GetTail(); ++i)
	{
		if (pPlayer->GetPos().x == tTail[i][0] && pPlayer->GetPos().y == tTail[i][1])
		{
			gameOver = true;
			break;
		}
	}

	// 아이템을 먹은 경우
	if (pPlayer->GetPos().x == itemPos.x && pPlayer->GetPos().y == itemPos.y)
	{
		iScore += 10;

		// 아이템을 새로운 위치에 재생성
		itemPos.x = (rand() % width) + 1;
		itemPos.y = (rand() % height) + 1;

		// 플레이어의 꼬리 증가
		pPlayer->AddTail();
	}
}

// 콘솔 창 조절
void SetConsoleView()
{
	system("mode con: cols=40 lines=20"); // 콘솔창 크기 조정
	system("title Snake Game"); // 콘솔창 타이틀 변경
}

int main()
{
	SetConsoleView();

	CPlayer* player = new CPlayer;
	int map[MAX_HEIGHT][MAX_WIDTH];
	bool gameOver = false;
	POINT itemPos;
	int iScore = 0;

	// 초기화에 실패했다면 프로그램 종료
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