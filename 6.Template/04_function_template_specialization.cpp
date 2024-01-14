/*
	function template specialization - 함수 템플릿 특수화
	- 특정 자료형에 대해서 다른 기능을 구현하고 싶을 때 사용
	- 특정 자료형에 대해 예외처리가 가능
*/

#include <iostream>
using namespace std;

template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}


//template specialization
//특수화한 타입에 한해서 다른 동작을 수행함
template<>
char GetMax(char x, char y)
{
	cout << "warning : comparing chars" << endl;
	return (x > y) ? x : y;
}

template<class T>
class Storage
{
public:
	Storage(T value)
		:value(value)
	{

	}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

//멤버 함수 특수화
template<>
void Storage<double>::Print()
{
	cout << scientific << value << endl;
}

int main()
{
	cout << GetMax<int>(1, 2) << endl;
	cout << GetMax<float>(2.0f, 4.0f) << endl;
	cout << GetMax('a', 'b') << endl;
	
	cout << endl;

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(5.2);
	s2.Print();

	return 0;
}