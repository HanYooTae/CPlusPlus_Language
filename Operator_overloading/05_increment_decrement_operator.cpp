#include <iostream>
using namespace std;

class Number
{
public:
	Number(const int& num = 0) : num(num){}

	//prefix
	Number& operator++()
	{
		++num;
		return *this;		//자기자신을 return
	}

	//postfix
	Number operator++(int)		//(int) dummy -> 전위와 후위를 구분하기 위해 넣음
	{
		Number temp(num);		
		++(*this);				// == ++num;
		return temp;
	}

	friend ostream& operator << (ostream& out, const Number& number)
	{
		out << number.num;
		return out;
	}

	/*
		//postfix
		Number& operator++(int)		//(int) dummy -> 전위와 후위를 구분하기 위해 넣음
		{
			static Number temp;
			return temp;
		}


		Main
		{
			temp = 10;
		}
	*/

private:
	int num;
};

int main()
{
	Number num1(1);
	Number num2(1);
	
	cout << num1 << endl;
	cout << num2 << endl;
	
	++++num1;		//원본이 반환되므로 이후의 ++에서 원본의 값이 증가된다.
	num2++++;		//사본이 반환되므로 이후의 ++에서 원본이 증가하지 않는다.


	cout << num1 << endl;	//두번 증가했으므로 3
	cout << num2 << endl;	//한번만 증가했으므로 2

	
	//2가 더 빠름. -> 결과는 같지만 prefix가 연산 과정이 짧다.
	//하지만 현대 컴파일러는 알아서 최적화 해준다.
	//최적화 기능이 없을 수도 있으니 가급적이면 2번 방법으로 하자.
	for (int i = 0; i < 100; i++) {};	//1
	for (int i = 0; i < 100; ++i) {};	//2


	return 0;
}