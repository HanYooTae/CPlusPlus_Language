#include <iostream>
using namespace std;

class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1() { cout << "A1" << endl; }
	virtual void Print2() { cout << "A2" << endl; }
	virtual void Print3() { cout << "A3" << endl; }
	virtual void Print4() { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	virtual void Print1() { cout << "B1" << endl; }
	virtual void Print2() { cout << "B2" << endl; }
	virtual void Print3() { cout << "B3" << endl; }
};

class C : public B
{
public:
	void Print() { cout << "C" << endl; }
	virtual void Print1() { cout << "C1" << endl; }
	virtual void Print2() { cout << "C2" << endl; }
};

class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	virtual void Print1() { cout << "D1" << endl; }
	virtual void Print4() { cout << "D4" << endl; }
};

int main()
{
	A a;
	a.Print();

	B b;
	b.Print();

	C c;
	c.Print();

	D d;
	d.Print();

	/*
		업 캐스팅 시 오버라이딩한 파생 클래스의 메서드가 가려져 출력이 되지 않는다.
		상위 클래스에 오버라이딩할 메서드에 virtual 키워드를 붙여 해결이 가능하다.
		virtual 키워드는 객체에 가상함수 테이블을 생성하여 각 객체의 원래 자료형에 맞는 메서드를 호출시켜준다.

		virtual function table - 가상 함수 테이블
		- virtual 키워드가 붙은 메서드는 가상 함수가 되어 가상 함수 테이블에 추가되고,
		  가상 함수 테이블을 통해 호출이 된다.
		- 파생 클래스에서 기반 클래스 가상함수를 오버라이딩을 하면, 가상 함수 테이블이
		  가리키던 가상함수 주소를 파생 클래스가 오버라이딩한 함수 주소로 교체한다.
		- 클래스마다 1개만 존재한다. -> 여러 객체가 있어도 하나의 가상 함수 테이블을 가리킨다.
	*/

	//디버깅을 하면 가상함수 테이블 확인 가능
	A& ref_b = b;
	A& ref_c = c;
	A& ref_d = d;

	cout << "########## A" << endl;
	a.Print();
	a.Print1();
	a.Print2();
	a.Print3();
	a.Print4();

	cout << endl << "########## B" << endl;
	ref_b.Print();
	ref_b.Print1();
	ref_b.Print2();
	ref_b.Print3();
	ref_b.Print4();

	cout << endl << "########## C" << endl;
	ref_c.Print();
	ref_c.Print1();
	ref_c.Print2();
	ref_c.Print3();
	ref_c.Print4();

	cout << endl << "########## D" << endl;
	ref_d.Print();
	ref_d.Print1();
	ref_d.Print2();
	ref_d.Print3();
	ref_d.Print4();

	cout << endl << "############" << endl;

	// 가리키는 가상 함수 테이블의 주소가 같음
	D d1;
	D d2;

	return 0;
}

//과제 : virtual function table 조사하기