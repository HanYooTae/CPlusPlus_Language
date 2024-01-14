#include <iostream>

using namespace std;

/*
	auto
	- 초기화하는 값에 따라서 데이터 타입을 자동으로 정리해주는 키워드
*/

//파라미터로 auto는 안된다.
//int add(auto x, auto y);

auto add(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 10;
	float b = 3.14f;
	double c = 45.0;
	int d = 15;
	float e = 15.0f;

	auto test = d + e;

	cout << test << endl;
	cout << endl;

	//모든 자료형으로 변할 수 있다.
	auto result = a + b;
	auto result1 = 10;		// int

	cout << result << endl;
	cout << result1 << endl;


	return 0;
}