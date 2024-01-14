#include <iostream>
using namespace std;

//부품
class Point2D
{
public:
	int x;
	int y;
};

//전체
class Monster
{
public:

	Monster(int x, int y)
	{
		position1.x = x;
		position1.y = y;
	}

	Monster(Point2D* point)
	{
		this->position2 = point;
	}

private:
	std::string name;
	Point2D position1;		//Monster 인스턴스가 소멸하면 같이 소멸 -> composition
	Point2D* position2;		//Monster 인스턴스가 소멸해도 존재 -> Aggregation		//소유관계 해제 has-a

};

int main()
{
	//composition
	Monster mon(10, 20);

	//Aggregation
	Point2D point;
	{
		Monster mon(&point);
	}

	return 0;
}