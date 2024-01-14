// https://min-zero.tistory.com/47
#include <iostream>
#include <utility>		//std::move()
using namespace std;

class Fraction	//�м�
{
public:
	/*
		constructor - ������
		- ��ü�� �ν��Ͻ�ȭ�� �� ȣ��ȴ�.
		- �ٸ� �Լ��� �����ϱ� ���� ��ȯ ���� ����.
	*/

	Fraction(int a, int b)
	{
		numerator = a;
		denominator = b;
		cout << "Constructor2!!" << endl;
	}

	//Fraction(int a = 10, int b = 10)		//��ȣ�� ����
	//{
	//	numerator = a;
	//	denominator = b;
	//	cout << "Constructor2!!" << endl;
	//}


	/*
		�⺻������ �����ε��� ������ 3����
		- default constructor - �⺻ ������
			�� �����ڸ� �ϳ��� �������� ���� ��� �⺻������ �����Ǵ� ������.
			�� �ϳ��� �����ڸ� �������� ��� �������� ����

		- copy constructor - ���� ������
			�� �ڽŰ� ���� Ÿ���� Ŭ������ & ���·� �޴� ��� ȣ��ȴ�.
			�� �������� ��� �ܺο� �����ϴ� ������ ���� �����Ͽ� �ʱ�ȭ�Ϸ��� �� �� ����Ѵ�.
			�� ���� ����� ���� ���簡 �ִ�.

		- move constructor - �̵� ������
			�� �ڽŰ� ���� Ÿ���� Ŭ������ &&���·� �޴� ��� ȣ��ȴ�.
			�� �������� ��� ���� ��ü�� ���� �����Ͽ� �ʱ�ȭ�Ϸ��� �� �� ����Ѵ�.
	*/

	//Fraction();					//default constructor		// �����ڰ� �ϳ��� ������ ���� X
	//Fraction(const Fraction&);	//copy constructor		//�ܺο� ������ �����Ƿ� const ��� ����
	//Fraction(Fraction&&);			//move constructor		//���� ��ü�� ���������Ƿ� const ��� x


	Fraction()	//default constructor		//�⺻ �����ڰ� ���ٸ� Fraction frac;�� ������ �� ����.
	{
		cout << "Constructor1!!" << endl;
	}

	Fraction(const Fraction& data)
	{
		cout << "Constructor3!!" << endl;
	}

	//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=mug896&logNo=140167721658
	Fraction(Fraction&& data) noexcept
	{
		cout << "Constructor4!!" << endl;
	}

private:
	int numerator = 10;		//����
	int denominator = 10;	//�и�
};

int main()
{
	Fraction frac;

	Fraction frac1(1.0, 2);
	
	//L-value ���·� �ٲ���
	Fraction frac2(frac1);				//���� ������ ȣ��

	//move() : ���� �����͸� R-value ���·� �ٲ��ش�.
	Fraction frac3(std::move(frac1));	//�̵� ������ ȣ��

	return 0;
}