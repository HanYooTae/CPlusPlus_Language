#include <iostream>
#include "08_calc.h"

//��� �Լ��̱� ������ ��� Ŭ������ �Ҽ������� ����ؾ� ��� �����ϴ�. -> Calc::
inline Calc& Calc::Add(int value) { this->value += value; return *this; }

inline Calc& Calc::Sub(int value) { this->value -= value; return *this; }

inline Calc& Calc::Mul(int value) { this->value *= value; return *this; }

inline Calc& Calc::Div(int value) { this->value /= value; return *this; }

inline Calc& Calc::Mod(int value) { this->value %= value; return *this; }

inline void Calc::Print()
{
	//using�� �������̸� ����ϴ� �κп��� �־� ������ ���Ե��� �ʵ��� ����
	using namespace std;

	cout << value << endl;
}

void Calc::Test()
{
}

void Test()		//�����Լ��̱� ������ �Ҽ�(namespace)�� ����.
{
}
