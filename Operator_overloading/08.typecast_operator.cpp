#include <iostream>
using namespace std;

class Won
{
public:
	Won(int value = 0) : value(value) {}

	//int형 casting
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
		//데이터가 연속적으로 되어있어 x의 주소를 넘기면
		//x, y, z 순서대로 접근 가능
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

	//int형 casting하여 error없앰
	Print(w);

	Point p(1.0f, 2.0f, 3.0f);
	PrintPoint(p);

	return 0;
}

/*
	과제
	1. class 4개 만들기(Hour, Minute, Second, Milli_Second)
	2. Hour를 다른 자료형으로 캐스팅할 때 단위에 맞게 변경되도록 오버로딩하기
	3. Milli_Second를 다른 자료형으로 캐스팅할 때 단위에 맞게 변경되도록 오버로드
	4. 각 자료형의 값을 출력해주는 Print함수 만들기
		- PrintHour(Hour time)
		- PrintMinute(Minute time)
		- PrintSecond(Second time)
		- PrintMilli(Milli_second time)
	5. 각 함수에 Hour와 Milli_Second를 넣었을 때 정상작동하도록 만들기

	과제 : 스네이크 게임
*/