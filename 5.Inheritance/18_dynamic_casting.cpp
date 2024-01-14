#include <iostream>
using namespace std;

class Base
{
public:
	virtual void  Print() { cout << "Base" << endl; }

public:
	int i = 0;
};

class Derived1 : public Base
{
public:
	virtual void Print() override { cout << "Derived1" << endl; }

public:
	int j = 0;
};

class Derived2 : public Base
{
public:
	virtual void Print() override { cout << "Derived2" << endl; }

public:
	int k = 0;
};

void DoSomething(Base* b)
{
	//static_cast : 자료형끼리의 형변환이 논리적으로 가능하다면 변환해준다.
	//Derived2* base_to_d2 = static_cast<Derived2*>(b);

	//static_cast를 사용할 경우 실제 객체가 Derived1인
	//b가 Derived2로 형변환되어 Derived1의 j가 수정이 된다.
	//base_to_d2->k = 888;

	//dynamic_cast : 형변환이 가능한 형태라면 형변환을 처리해주고 안된다면 nullptr를 반환
	//dynamic_cast가 안전하지만 사용하진 않는다. -> 런타임 때 체크하는거라 느림
	//사용하지 않고 빠르게 처리하는 법 -> 타입 확인이 가능한 변수를 두어 검사한다.(enum으로 한다고 하는데 우선은 그냥 넘어가자.)
	Derived2* base_to_d2 = dynamic_cast<Derived2*>(b);
	
	if (base_to_d2 == nullptr)
		cout << "캐스팅할 수 없는 객체입니다." << endl;
	else
		base_to_d2->k = 888;
}

int main()
{
	//업 캐스팅
	Derived1 d1;
	d1.j = 100;
	Base* base = &d1;

	//다운 캐스팅
	Derived1* base_to_d1 = static_cast<Derived1*>(base);
	base_to_d1->Print();


	//Derived1 : i i i i j j j j
	//Derived2 : i i i i k k k k
	//상대적인 위치가 같기 때문에 Derived2의 888이 Derived1의 j의 값이 888로 바뀐다.
	DoSomething(&d1);
	cout << d1.j << endl;

	return 0;
}