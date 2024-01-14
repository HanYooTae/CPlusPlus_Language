#include <iostream>

using namespace std;

class Data
{
public:
	Data(const int a, int b, int c/*, int& d*/)

		//생성과 동시에 초기화하는 것과 동일하다.
		//초기화 리스트에서 값을 넣어주면 예약한 값이 무시됨
		: a(a)	//a(a)   a -> 멤버변수, (a) -> 지역변수
		, b(b)
		, c(c)

	{	//생성자 내부
		
		//이미 a, b, c 메모리가 만들어진 상태로 실행되어 const가 붙으면 실행이 안됨
		//this->a = a;
		//this->b = b;
		//this->c = c;

	
	}
	

	int GetA() { return a; }

private:
	const int a;
	const int b;
	const int c;
	//int& d;	//이런 문법도 가능
};

int main()
{
	Data test(20, 10, 10);

	cout << test.GetA() << endl;

	//초기화 리스트에서 값을 넣어주면 예약한 값이 무시되고, 아래 입력한 상수 변수가 만들어짐
	Data data(30, 20, 20);
	
	cout << data.GetA() << endl;

	return 0;
}