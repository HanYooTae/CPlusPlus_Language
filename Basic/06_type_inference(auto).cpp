#include <iostream>

using namespace std;

/*
	auto
	- �ʱ�ȭ�ϴ� ���� ���� ������ Ÿ���� �ڵ����� �������ִ� Ű����
*/

//�Ķ���ͷ� auto�� �ȵȴ�.
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

	//��� �ڷ������� ���� �� �ִ�.
	auto result = a + b;
	auto result1 = 10;		// int

	cout << result << endl;
	cout << result1 << endl;


	return 0;
}