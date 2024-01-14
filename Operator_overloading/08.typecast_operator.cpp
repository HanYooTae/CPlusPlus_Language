#include <iostream>
using namespace std;

class Won
{
public:
	Won(int value = 0) : value(value) {}

	//int�� casting
	operator int()
	{
		return value;
	}

private:
	int value = 0;
};

void Print(int val)
{
	cout << val << endl;
}

class Point
{
public:
	Point(float x, float y, float z)
		: x(x), y(y), z(z)
	{

	}

	operator float* ()
	{
		//�����Ͱ� ���������� �Ǿ��־� x�� �ּҸ� �ѱ��
		//x, y, z ������� ���� ����
		return &x;
	}

private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;	//x
	cout << points[1] << endl;	//y
	cout << points[2] << endl;	//z
}

int main()
{
	Won w(1000);

	//int�� casting�Ͽ� error����
	Print(w);

	Point p(1.0f, 2.0f, 3.0f);
	PrintPoint(p);

	return 0;
}

/*
	����
	1. class 4�� �����(Hour, Minute, Second, Milli_Second)
	2. Hour�� �ٸ� �ڷ������� ĳ������ �� ������ �°� ����ǵ��� �����ε��ϱ�
	3. Milli_Second�� �ٸ� �ڷ������� ĳ������ �� ������ �°� ����ǵ��� �����ε�
	4. �� �ڷ����� ���� ������ִ� Print�Լ� �����
		- PrintHour(Hour time)
		- PrintMinute(Minute time)
		- PrintSecond(Second time)
		- PrintMilli(Milli_second time)
	5. �� �Լ��� Hour�� Milli_Second�� �־��� �� �����۵��ϵ��� �����

	���� : ������ũ ����
*/