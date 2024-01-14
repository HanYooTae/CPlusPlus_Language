//괄호 연산자

#include <iostream>
using namespace std;

class Counter
{
public:
	int operator()(int i) { return count += i; }

private:
	int count = 0;
};

int main()
{
	Counter ct;

	cout << ct(30) << endl;		//Function object - Functor
	cout << ct(300) << endl;	//객체를 함수처럼 사용

	return 0;
}