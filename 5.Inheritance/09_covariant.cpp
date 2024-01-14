/*
	Covariant - 공변 반환형
	- 자신의 참조를 반환하는 경우, 상속관계에서 같은 형태의 함수로 인정되는 것
	- is a 관계이기 때문에 자신의 참조를 리턴할 때 같은 것으로 인식한다.
	- 반환 값을 다르게 해도 오버라이딩이 가능한 방법
*/

#include <iostream>
using namespace std;

class A
{
public:
	virtual A* GetThisPointer() { cout << "A" << endl; return this; }
};

class B : public A
{
public:
	virtual B* GetThisPointer() override { cout << "B" << endl; return this; }
};

int main()
{
	B b;
	cout << "Adress : " << b.GetThisPointer() << endl;
	cout << "typeid : " << typeid(b.GetThisPointer()).name() << endl << endl;

	cout << "###############" << endl;

	A& ref = b;
	cout << "Adress : " << b.GetThisPointer() << endl;
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl;
	

	return 0;
}