#include <iostream>

using namespace std;

#define THIS_POINTER
//#define CHAINING_MEMBER_FUNCTION

#ifdef THIS_POINTER
/*
	this pointer : 함수가 호출한 객체를 구별하기 위해
	기본적으로 넣어주는 해당 객체의 포인터
*/

class Test
{
public:
	Test() {}
	~Test() {}

	auto /*this call*/ GetA()
	{
		cout << &this->a << endl;		//this는 a의 레퍼런스
		return a;
	}

	auto /*this call*/ GetB()
	{
		cout << &this->b << endl;
		return b;
	}

	auto /*this call*/ GetC()
	{
		cout << &this->c << endl;
		return c;
	}

	//매개변수와 멤버변수의 이름이 같다면, name hiding이 발생
	//void SetA(const int& a) { a = a; }		//name hiding, 매개변수가 우선시 된다.
	//void SetA(const int& in_a) { a = in_a; }	//구분하기 위해 이름을 바꿈										//사용 가능
	void SetA(const int& a) { this->a = a; }	//this를 사용하면 매개변수와 이름이 같아도 멤버변수 사용 가능		//사용 가능(추천하는 방식)
	void SetB(const int& b) { this->b = b; }	//this를 사용하면 매개변수와 이름이 같아도 멤버변수 사용 가능		//사용 가능(추천하는 방식)
	void SetC(const int& c) { this->c = c; }	//this를 사용하면 매개변수와 이름이 같아도 멤버변수 사용 가능		//사용 가능(추천하는 방식)

//private:
	int a = 1;
	int b = 2;
	int c = 3;
};

int main()
{
	Test test1;		//지역변수는 메모리가 스택에 쌓인다
	test1.GetA();
	test1.GetB();
	test1.GetC();
	cout << endl;

	Test test2;
	test2.GetA();
	test2.GetB();
	test2.GetC();
	cout << endl;

	cout << test1.a << ", " << test2.a << endl;
	cout << test1.b << ", " << test2.b << endl;
	cout << test1.c << ", " << test2.c << endl;
	//cout << &test1 << ", " << &test2 << endl;

	return 0;
}
#endif

#ifdef CHAINING_MEMBER_FUNCTION

/*
	chaining member function
	- 자신을 연쇄적으로 호출하는 함수
*/

class Calc
{
public:
	Calc(int value) : value(value) {}

	//1.
	//void Add(int value) { this->value += value; cout << this->value << endl; }
	//void Sub(int value) { this->value -= value; cout << this->value << endl; }
	//void Mul(int value) { this->value *= value; cout << this->value << endl; }
	//void Div(int value) { this->value /= value; cout << this->value << endl; }
	//void Mod(int value) { this->value %= value; cout << this->value << endl; }

	//2.
	// reference 형태로 리턴
	// 반환값이 Calc&(나 자신)
	//Calc* Add(int value) { this->value += value; return this; }	//동일		//이렇게 쓴다면 메인함수에서 애로우를 사용해야 함
	Calc& Add(int value) { this->value += value; cout << this->value; return *this; }
	Calc& Sub(int value) { this->value -= value; cout << this->value; return *this; }
	Calc& Mul(int value) { this->value *= value; cout << this->value; return *this; }
	Calc& Div(int value) { this->value /= value; cout << this->value; return *this; }
	Calc& Mod(int value) { this->value %= value; cout << this->value; return *this; }

private:
	int value;
};

int main()
{
	Calc calc(10);
	//1.
	//너무 길다.
	/*calc.Add(5);
	calc.Div(2);
	calc.Mul(3);
	calc.Mod(3);
	calc.Sub(3);*/

	//2.
	//Chaining을 사용하면 한줄로 사용 가능
	calc.Add(5).Div(2).Mul(3).Mod(3).Sub(3);

	//3. anonymous object를 사용한 연쇄 호출

	//Calc(10).Add(5).Div(2);
	//이렇게 연쇄적으로 사용 가능 -> chaining
	//앞에서부터 차례대로 호출된다.
	//이 방법을 권장하는 언어도 있지만, C++에서는 권장하지 않음


	return 0;
}

#endif
