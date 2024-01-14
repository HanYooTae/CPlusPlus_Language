#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }

	//ostream : 출력 스트림
	//&로 리턴하여 체이닝
	friend ostream& operator <<(ostream& out, const Point& p)
	{
		out << "(" << p.x << ", " << p.y << ")";
		return out;
	}

	//istream : 입력 스트림
	friend istream& operator >>(istream& in, Point& p)		//받아주는 형태이기 때문에 상수 값을 받으면 안됨
	{
		in >> p.x >> p.y;
		return in;
	}

private:
	int x;
	int y;
};

int main()
{
	Point p1(0, 10), p2{ 5, 5 };

	cout << p1 << ", " << p2 << endl;

	cin >> p1 >> p2;

	cout << p1 << ", " << p2 << endl;


	return 0;
}

/*
	과제 : 재귀함수
		1. 재귀함수 조사하기
		2. 재귀함수를 사용해서 피보나치 수열 구현
		3. (선택) 재귀함수를 사용해서 하노이탑 구현

	과제 : 오셀로 만들기
*/