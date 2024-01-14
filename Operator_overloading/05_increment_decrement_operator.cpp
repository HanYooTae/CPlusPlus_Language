#include <iostream>
using namespace std;

class Number
{
public:
	Number(const int& num = 0) : num(num){}

	//prefix
	Number& operator++()
	{
		++num;
		return *this;		//�ڱ��ڽ��� return
	}

	//postfix
	Number operator++(int)		//(int) dummy -> ������ ������ �����ϱ� ���� ����
	{
		Number temp(num);		
		++(*this);				// == ++num;
		return temp;
	}

	friend ostream& operator << (ostream& out, const Number& number)
	{
		out << number.num;
		return out;
	}

	/*
		//postfix
		Number& operator++(int)		//(int) dummy -> ������ ������ �����ϱ� ���� ����
		{
			static Number temp;
			return temp;
		}


		Main
		{
			temp = 10;
		}
	*/

private:
	int num;
};

int main()
{
	Number num1(1);
	Number num2(1);
	
	cout << num1 << endl;
	cout << num2 << endl;
	
	++++num1;		//������ ��ȯ�ǹǷ� ������ ++���� ������ ���� �����ȴ�.
	num2++++;		//�纻�� ��ȯ�ǹǷ� ������ ++���� ������ �������� �ʴ´�.


	cout << num1 << endl;	//�ι� ���������Ƿ� 3
	cout << num2 << endl;	//�ѹ��� ���������Ƿ� 2

	
	//2�� �� ����. -> ����� ������ prefix�� ���� ������ ª��.
	//������ ���� �����Ϸ��� �˾Ƽ� ����ȭ ���ش�.
	//����ȭ ����� ���� ���� ������ �������̸� 2�� ������� ����.
	for (int i = 0; i < 100; i++) {};	//1
	for (int i = 0; i < 100; ++i) {};	//2


	return 0;
}