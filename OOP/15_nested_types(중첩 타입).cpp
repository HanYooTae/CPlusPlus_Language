#include <iostream>

using namespace std;

class Collision
{
	struct Rect
	{
		int a;
		int b;
		int c;
	};

	struct Circle
	{
		int a;
		int b;
		int c;
	};
};

struct pos
{
	int x;
	int y;
};

class Character		//¡ﬂ√∏ ≈∏¿‘
{
public:
	enum class Movement
	{
		Idle,
		Walk,
		Run
	};
private:
	pos i;
};

enum class Movement
{
	Hi
};

int main()
{
	Movement::Hi;
	Character::Movement::Idle;

	return 0;
}