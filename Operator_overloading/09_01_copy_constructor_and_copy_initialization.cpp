//대입연산자 처리
//생성하지 않아도 자동 제공되는 암시적 메소드

#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
public:
	Fraction(int num = 0, int den = 0)
		: numerator(num)
		, denominator(den)
	{
		cout << "constructor!!" << endl;
	}

	//copy constructor
	Fraction(const Fraction& fraction)
	{
		cout << "copy constructor!!" << endl;
	}

	//copy_operator =
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operation" << endl;
		return *this;
	}

private:
	int numerator;
	int denominator;
};

Fraction CreateFraction()
{
	Fraction temp(5, 2);		//constructor
	return temp;				//copy constructor 메시지 발생
	//RVO, NRVO 최적화로 해결 가능
}

int main()
{
	Fraction frac(3, 5);

	Fraction copy1(frac);	//copy_initialization
	Fraction copy2;			//copy_initialization
	// 생성 시점에는 copy1(frac)과 동일하다, 혼동되므로 사용하지 않는게 좋다.

	copy2 = frac;			//copy_operator =

	cout << "##############" << endl;
	CreateFraction();

	return 0;
}