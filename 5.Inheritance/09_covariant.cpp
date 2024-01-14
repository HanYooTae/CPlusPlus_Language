/*
	Covariant - ���� ��ȯ��
	- �ڽ��� ������ ��ȯ�ϴ� ���, ��Ӱ��迡�� ���� ������ �Լ��� �����Ǵ� ��
	- is a �����̱� ������ �ڽ��� ������ ������ �� ���� ������ �ν��Ѵ�.
	- ��ȯ ���� �ٸ��� �ص� �������̵��� ������ ���
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