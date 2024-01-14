#include <iostream>

using namespace std;

#define THIS_POINTER
//#define CHAINING_MEMBER_FUNCTION

#ifdef THIS_POINTER
/*
	this pointer : �Լ��� ȣ���� ��ü�� �����ϱ� ����
	�⺻������ �־��ִ� �ش� ��ü�� ������
*/

class Test
{
public:
	Test() {}
	~Test() {}

	auto /*this call*/ GetA()
	{
		cout << &this->a << endl;		//this�� a�� ���۷���
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

	//�Ű������� ��������� �̸��� ���ٸ�, name hiding�� �߻�
	//void SetA(const int& a) { a = a; }		//name hiding, �Ű������� �켱�� �ȴ�.
	//void SetA(const int& in_a) { a = in_a; }	//�����ϱ� ���� �̸��� �ٲ�										//��� ����
	void SetA(const int& a) { this->a = a; }	//this�� ����ϸ� �Ű������� �̸��� ���Ƶ� ������� ��� ����		//��� ����(��õ�ϴ� ���)
	void SetB(const int& b) { this->b = b; }	//this�� ����ϸ� �Ű������� �̸��� ���Ƶ� ������� ��� ����		//��� ����(��õ�ϴ� ���)
	void SetC(const int& c) { this->c = c; }	//this�� ����ϸ� �Ű������� �̸��� ���Ƶ� ������� ��� ����		//��� ����(��õ�ϴ� ���)

//private:
	int a = 1;
	int b = 2;
	int c = 3;
};

int main()
{
	Test test1;		//���������� �޸𸮰� ���ÿ� ���δ�
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
	- �ڽ��� ���������� ȣ���ϴ� �Լ�
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
	// reference ���·� ����
	// ��ȯ���� Calc&(�� �ڽ�)
	//Calc* Add(int value) { this->value += value; return this; }	//����		//�̷��� ���ٸ� �����Լ����� �ַο츦 ����ؾ� ��
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
	//�ʹ� ���.
	/*calc.Add(5);
	calc.Div(2);
	calc.Mul(3);
	calc.Mod(3);
	calc.Sub(3);*/

	//2.
	//Chaining�� ����ϸ� ���ٷ� ��� ����
	calc.Add(5).Div(2).Mul(3).Mod(3).Sub(3);

	//3. anonymous object�� ����� ���� ȣ��

	//Calc(10).Add(5).Div(2);
	//�̷��� ���������� ��� ���� -> chaining
	//�տ������� ���ʴ�� ȣ��ȴ�.
	//�� ����� �����ϴ� �� ������, C++������ �������� ����


	return 0;
}

#endif
