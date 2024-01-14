#include <iostream>
using namespace std;

/*
	RVO - Return Value Optimization
	- � �Լ��� ��ü�� ��ȯ�ؾ��� ���,
	  �ʿ����� ���� �ӽ� ��ü�� �������� �ʵ��� ����ȭ
	- Debug/Release���� �ȴ�.
	- ��ȯ��ü�� �������� ������ ���� ��� ����ȭ �ȴ�.
	- �������� ���� ��� ����ȭ�� ���� �ʾ����� NRVO�� �߰��Ǿ� �����ϰ� �Ǿ���.

	NRVO - Named Return Value Optimization
	- RVO�� ���� ������� ����ȭ ����, �̸��ִ� ��ü ��ȯ �ÿ��� �����ϰ� �Ѵ�.
	- Debug������ ����ȭ x, Release������ ����ȭ O
*/

class Test
{
public:
	Test(int value)
		:value1(value)
		, value2(++count)
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	Test(const Test& rhs)
		:value1(rhs.value1)
		, value2(++count)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}

public:
	static int count;

private:
	int value1;		//������
	int value2;		//���° ������ ������
};

int Test::count = 0;

//Debug/Release ��� ����ȭ
Test MakeRVO(int value)
{
	return Test(value);		//RVO -> ��ȯ��ü�� �̸��� ���� ��� ����ȭ
}

//Debug������ ����ȭ X
//Release������ ����ȭ O
Test MakeNRVO(int value)
{
	Test test(value);
	return test;			//NRVO -> ��ȯ ��ü�� �̸��� ���� ��� ����ȭ
}

int main()
{
	cout << "----RVO----" << endl;
	MakeRVO(1);

	cout << "----NRVO----" << endl;
	MakeNRVO(2);

	cout << "----END----" << endl;

	return 0;
}