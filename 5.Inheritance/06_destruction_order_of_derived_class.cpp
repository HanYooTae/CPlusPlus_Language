#include<iostream>
using namespace std;

//Ŭ���� ���� �Լ����� ũ�⸦ ������ �ʴ´�.
class A
{
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A destructor" << endl; }

private:
	int a;
};

class B : public A
{
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B destructor" << endl; }

private:
	double b;
	int c;
};

int main()
{
	// ���������� �⺻ Ŭ���� ����
	// �Ҹ������ �Ļ� Ŭ���� ����
	// ���� ������ ��ü�� �� ���� ���踦 ������ �־� 
	// ���� �����ϸ� ������ ���� �� �ִ�.
	B b;

	/*
		�е�
		- Ŭ������ ����ü�� �е� ����Ʈ�� �߰��Ͽ� CPU�� �����ϱ� �����ϰ� ���ִ� ���
		- CPU�� �����͸� ���� �� �ڷ����� �߷� ���� �����Ϳ� �� �� �����ϴ� ���� ����.
		- �Ϲ������� ���� ū ��� ������ ũ�⿡ ���� �е� ����Ʈ�� �߰��Ѵ�.
	*/
	//padding : ������ ������ �־��ִ� ��

	sizeof(A);		//int �ϳ� -> 4����Ʈ
	sizeof(B);		//A�� int, double -> �е������� ũ�Ⱑ 16����Ʈ�� ��.

	class P1
	{
		char c;
		short s1;
		short s2;
	};
	// c �� s1 s1 s2 s2

	class P2
	{
		short s1;
		int i;
		double d;
		char c;
	};
	// s1 s1 i i i i �� �� d d d d d d d d c �� �� �� �� �� �� ��

	sizeof(P1);		//���� ū �ڷ��� short�� �������� �е� -> 2����Ʈ �е�
	sizeof(P2);		//���� ū �ڷ��� double�� �������� �е� -> 8����Ʈ �е�
	sizeof(P3);		//���� ū �ڷ��� double�� �������� �е� -> 8����Ʈ �е�

}

/*
	�е� ��Ģ ã�ƺ���
*/

/*
	���� : �Ʒ� ����ü�� ����� �ּҷ� �����
*/

struct P3
{
	char c1;
	double d1;
	char c2;
	double d2;
	char c3;
	int i1;
	int i2;
	double d3;
};