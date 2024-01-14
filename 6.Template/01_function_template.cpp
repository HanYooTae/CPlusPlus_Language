/*
	Template
	- 프로그래머가 원하는 타입을 넣어주면 알맞게 코드를 찍어내주는 틀
	- int나 double같은 구체적인 자료형을 포괄할 수 있는 일반형(generic type)으로 정의한다.
	- 어떤 데이터형을 템플릿 매개변수로 전달하면, 컴파일러가 그 데이터형에 맞는 코드를 생성해준다.
	- 구체적인 데이터형 대신 일반형으로 프로그래밍하는데, 이것을 일반화 프로그래밍이라고 부른다.
	- 다양한 자료형을 동일한 알고리즘을 적용해야 한다면, 템플릿을 사용한다.
		-> 일부 자료형에 대해서는 로직이 다르다면 특수화를 사용해 예외처리를 해준다.
*/

#include <iostream>
using namespace std;

//오버로딩으로 다양한 타입에 대해 처리가 가능하지만 새로운 타입이 필요할 때마다 추가해야 함
//-> 번거롭고 코드 자체에 변경점이 있을 경우, 모두 수정해줘야 한다.
//int GetMax(int x, int y) { return (x > y) ? x : y; }
//float GetMax(float x, float y) { return (x > y) ? x : y; }
//short GetMax(short x, short y) { return (x > y) ? x : y; }
//long GetMax(long x, long y) { return (x > y) ? x : y; }
//double GetMax(double x, double y) { return (x > y) ? x : y; }

template<typename T, typename T2>		//템플릿 매개변수 T선언, 코드를 작성할 때 사용할 자료형 타입            
//template<class T>			//class라고도 쓸 수는 있으나, 내부적으로 처리를 해줘서 차이는 없다.
T GetMax(T x, T2 y)			//T를 하나의 자료형처럼 생각하여 사용
{
	return (x > y) ? x : y;
}

//int GetMax(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//double GetMax(double x, double y)
//{
//	return (x > y) ? x : y;
//}

class Won
{
public:
	Won(int value = 0) :value(value) {}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

private:
	int value = 0;
};

int main()
{
	//<>를 사용해 템플릿 인자를 넣어줄 수 있다.
	cout << GetMax<int>(1, 2u) << endl;

	//템플릿의 매개변수 타입을 맞춰서 넣어주면 <> 생략 가능
	cout << GetMax(1l, 2l) << endl;
	cout << GetMax(1ll, 2ll) << endl;
	cout << GetMax(1llu, 2llu) << endl;
	cout << GetMax(1.0f, 2.0f) << endl;

	//우리가 만든 함수 템플릿은 두 개의 인자를 같은 자료형으로 받고 있다.
	//-> 넣어주는 두 인자의 타입이 달라 T를 어떤 자료형으로 정의해야 할지 몰라 생략안됨.
	//typename을 추가하여 정상화
	GetMax(1.0f, 2.0);

	//사용자가 정의한 자료형도 사용 가능
	cout << GetMax(Won(6), Won(2)) << endl;

	return 0;
}