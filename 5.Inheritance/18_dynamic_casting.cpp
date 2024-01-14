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
	//static_cast : �ڷ��������� ����ȯ�� �������� �����ϴٸ� ��ȯ���ش�.
	//Derived2* base_to_d2 = static_cast<Derived2*>(b);

	//static_cast�� ����� ��� ���� ��ü�� Derived1��
	//b�� Derived2�� ����ȯ�Ǿ� Derived1�� j�� ������ �ȴ�.
	//base_to_d2->k = 888;

	//dynamic_cast : ����ȯ�� ������ ���¶�� ����ȯ�� ó�����ְ� �ȵȴٸ� nullptr�� ��ȯ
	//dynamic_cast�� ���������� ������� �ʴ´�. -> ��Ÿ�� �� üũ�ϴ°Ŷ� ����
	//������� �ʰ� ������ ó���ϴ� �� -> Ÿ�� Ȯ���� ������ ������ �ξ� �˻��Ѵ�.(enum���� �Ѵٰ� �ϴµ� �켱�� �׳� �Ѿ��.)
	Derived2* base_to_d2 = dynamic_cast<Derived2*>(b);
	
	if (base_to_d2 == nullptr)
		cout << "ĳ������ �� ���� ��ü�Դϴ�." << endl;
	else
		base_to_d2->k = 888;
}

int main()
{
	//�� ĳ����
	Derived1 d1;
	d1.j = 100;
	Base* base = &d1;

	//�ٿ� ĳ����
	Derived1* base_to_d1 = static_cast<Derived1*>(base);
	base_to_d1->Print();


	//Derived1 : i i i i j j j j
	//Derived2 : i i i i k k k k
	//������� ��ġ�� ���� ������ Derived2�� 888�� Derived1�� j�� ���� 888�� �ٲ��.
	DoSomething(&d1);
	cout << d1.j << endl;

	return 0;
}