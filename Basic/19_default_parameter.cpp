#include <iostream>
using namespace std;

//void print(int x)
//{
//	cout << x << endl;
//}

void print(int x = 7)		//아무것도 입력하지 않을 때 x에 기본 값으로 7을 주고 싶다. -> default parameter
{
	cout << x << endl;
}

//주의할 점1 : 항상 고정 값을 넣어야 한다
void print(int x = 7, int y = 7)
//void print(int x = 7, int y)			//안됨
{
	cout << x << endl;
}

//주의할 점2 : 수정할 값이 뒤에 있다면, 앞의 값도 넣어줘야 한다.
void test(int x = 10, int y = 10, int z = 10)
{
	cout << x << ", " << y << ", " << z << endl;
}

int main()
{
	//print();		//7
	//print(10);	//10
	//print();		//7

	//주의할 점 3 : default parameter와 overload는 동시에 쓰지 않는다.
	//print(1);	//ambiguous

	//주의할 점2 : 수정할 값이 뒤에 있다면, 앞의 값도 넣어줘야 한다.
	test(10, 10, 15);

	return 0;
}