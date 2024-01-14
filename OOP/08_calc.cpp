#include <iostream>
#include "08_calc.h"

//멤버 함수이기 때문에 어디 클래스의 소속인지를 명시해야 사용 가능하다. -> Calc::
inline Calc& Calc::Add(int value) { this->value += value; return *this; }

inline Calc& Calc::Sub(int value) { this->value -= value; return *this; }

inline Calc& Calc::Mul(int value) { this->value *= value; return *this; }

inline Calc& Calc::Div(int value) { this->value /= value; return *this; }

inline Calc& Calc::Mod(int value) { this->value %= value; return *this; }

inline void Calc::Print()
{
	//using은 가급적이면 사용하는 부분에만 넣어 전역에 포함되지 않도록 하자
	using namespace std;

	cout << value << endl;
}

void Calc::Test()
{
}

void Test()		//전역함수이기 때문에 소속(namespace)이 없다.
{
}
