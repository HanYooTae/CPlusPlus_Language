/*
	special member function - Ư�� ��� �Լ�
	- �ڵ����� �ۼ��Ǵ� �Լ� 6����
	- �� �Լ��� ��������� �ۼ����� ���� ��� �ڵ����� �ۼ�
	- �� ����/�Լ����� Ư�� ���ǿ� ���� �ڵ� �ۼ��� ���� ���� �� �ִ�.

	�޼��� ����

	default constructor - �⺻ ������
	- �ۼ��� �����ڰ� �ϳ��� ���� �� �ۼ��ȴ�.
	- �ƹ��� ����� ����.

	destructor - �Ҹ���
	- �Ҹ��ڸ� �ۼ����� ���� ��� �ڵ� �ۼ��ȴ�.

	copy constructor/assignment operator - ���� ������/���� ������
	- �� �� �ϳ��� �ۼ��Ǿ� ���� ���, �ٸ� �ϳ��� �ۼ�X
	- move constructor/assignment operator�� �ϳ��� �ۼ��Ǿ� �ִٸ�, �ۼ�X

	move constructor/assignment operator - �̵� ������/���� ������
	- �� �� �ϳ��� �ۼ��Ǿ� ���� ���, �ٸ� �ϳ��� �ۼ�X
	- copy constructor/assignment operator�� �ϳ��� �ۼ��Ǿ� �ִٸ�, �ۼ�X
*/

#include <iostream>
using namespace std;

class Test
{
public:
	//constructor
	Test()
		:value1(1)
		, value2(++count)
	{
		cout << "default constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	//Lvalue�� �޾��� ��
	Test(const Test& t)
		: value1(1)
		, value2(++count)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	Test(Test&& t) noexcept
		: value1(1)
		, value2(++count)
	{
			cout << "move constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	//�Ϲ� �����ڿ��� �Ķ���ͷ� int val�� �߰�
	Test(int val)
		:value1(val)
		, value2(++count)
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	//assignment operator
	Test& operator=(const Test& t)
	{
		this->value1 = t.value1;
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;

		return *this;
	}

	Test& operator=(Test&& t)
	{
		this->value1 = t.value1;
		cout << "move constructor : " << this->value1 << ", " << this->value2 << endl;

		return *this;
	}

	//destructor
	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}

public:
	static int count;

private:
	int value1;
	int value2;
};

int Test::count = 0;

int main()
{
	//FILO
	//�Ҹ��� ȣ���� ������ ����
	//-> ���� ���� ������ �ν��Ͻ��ϼ��� ������ �ν��Ͻ���� ���踦 �ΰ����� ���ɼ��� ũ�� ������
	//������ �������� �������ִ°� �����ϴ�.
	cout << "1########################" << endl;
	Test t1;
	Test t2(2);

	//Test t3 = t1;	//���� ������ ȣ�� but �����ϴ� ����� �ƴ�
	cout << endl;

	cout << "2########################" << endl;
	Test t4(t1);

	cout << "3########################" << endl;
	Test t5(std::move(t1));
	cout << endl;

	cout << "4########################" << endl;
	t1 = t2;

	cout << "5########################" << endl;
	t1 = std::move(t4);
	cout << endl;

	cout << "6########################" << endl;


	return 0;
}