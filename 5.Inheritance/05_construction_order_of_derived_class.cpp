#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
		: a(10)
	{
		cout << "Base Constructor" << endl;
	}

private:
	int a;
};

class Child : public Parent
{
public:
	Child()
		// ������ ������ �⺻ Ŭ������ �����ڰ� �ִ�. -> �����ڰ� �ƴ϶� �ʱ�ȭ ����� ���ϴ� ���̴�. -> {}�� ����
		// ����� �غ��� �Ļ� Ŭ���� ������ ���� �⺻ Ŭ������ �����ڰ� ���� ȣ��ȴ�.
		// �ʱ�ȭ ����Ʈ����  ��� Ŭ���� �����ڸ� ��� ��ġ�� ��� ��� Ŭ���� �����ڰ� ���� ȣ��
		/*Parent*/ : b(10)
	{
		cout << "Derived Constructor" << endl;
	}

private:
	int b;
};

//�ֻ��� �θ���� ���ʴ�� �����ڰ� ȣ���
class A {public: A() { cout << "A Constructor" << endl; } };
class B : public A {public: B() { cout << "B Constructor" << endl; } };
class C : public B {public: C() { cout << "C Constructor" << endl; } };
class D : public C {public: D() { cout << "D Constructor" << endl; } };

int main()
{
	//��ӹ��� ��� Ŭ������ ������ �켱 ȣ��
	Child child;

	cout << "##################" << endl;

	D d;

	return 0;
}