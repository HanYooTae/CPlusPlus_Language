/*
	conversion constructor - 변환 생성자
	- 매개변수가 하나인 생성자
	- 다른 자료형이 들어오게 되면 묵시적 형변환이 일어나면서 호출이 된다.
	- 함수에서 변환 생성자가 있는 클래스의 매개변수를 값으로 받을 때 임시 객체가 생성될 수 있다.
		-> explicit 키워드를 추가하여 예방 가능
*/

#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int num, int den)
		:numerator(num)
		, denominator(den)
	{
		cout << "constructor" << endl;
	}

	Fraction(const Fraction& other)
		:numerator(other.numerator)
		, denominator(other.denominator)
	{
		cout << "copy constructor" << endl;
	}

	//Fraction(int a)		//매개변수 하나만 있음 -> 변환 생성자
	//	: numerator(a)
	//	, denominator(1)
	//{
	//	cout << " conversion constructor" << endl;
	//}

	explicit Fraction(int a)		//explicit 키워드를 사용하여 변환 기능을 막을 수 있음.
		: numerator(a)
		, denominator(1)
	{
		cout << " conversion constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& frac)		//const Fraction frac라면 copy constructor가 2번 출력됨.
	{
		out << frac.numerator << " / " << frac.denominator << endl;
		return out;
	}

private:
	int numerator;
	int denominator;
};

void PrintFraction(Fraction frac)
{
	cout << frac << endl;		
}

int main()
{
	Fraction frac1(10, 20);	//일반 생성자
	Fraction frac2(frac1);	//복사 생성자

	//다른 자료형이 들어와도 값을 형변환하여 생성자 호출
	Fraction frac3(10);		//알맞은 자료형이 들어온 변환 생성자 호출
	Fraction frac4('a');	//자료형이 다름 -> 암시적 형변환
	Fraction frac5(3.14f);	//형변환이 되긴 하지만 데이터 손실이 일어남


	PrintFraction(frac1);

	//PrintFraction(10);		//explicit를 사용했다면 클래스 객체를 받아줘야 함
	//PrintFraction(3.14f);

	return 0;
}