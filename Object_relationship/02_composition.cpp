#include <iostream>
using namespace std;

//��ǰ
class Point2D
{
public:
	int x;
	int y;
};

//��ü
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
	Point2D position1;		//Monster �ν��Ͻ��� �Ҹ��ϸ� ���� �Ҹ� -> composition
	Point2D* position2;		//Monster �ν��Ͻ��� �Ҹ��ص� ���� -> Aggregation		//�������� ���� has-a

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