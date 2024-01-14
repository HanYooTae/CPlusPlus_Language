/*
	conversion constructor - ��ȯ ������
	- �Ű������� �ϳ��� ������
	- �ٸ� �ڷ����� ������ �Ǹ� ������ ����ȯ�� �Ͼ�鼭 ȣ���� �ȴ�.
	- �Լ����� ��ȯ �����ڰ� �ִ� Ŭ������ �Ű������� ������ ���� �� �ӽ� ��ü�� ������ �� �ִ�.
		-> explicit Ű���带 �߰��Ͽ� ���� ����
*/

#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int num, int den)
		:numerator(num)
		, denominator(den)
	{
		cout << "constructor" << endl;
	}

	Fraction(const Fraction& other)
		:numerator(other.numerator)
		, denominator(other.denominator)
	{
		cout << "copy constructor" << endl;
	}

	//Fraction(int a)		//�Ű����� �ϳ��� ���� -> ��ȯ ������
	//	: numerator(a)
	//	, denominator(1)
	//{
	//	cout << " conversion constructor" << endl;
	//}

	explicit Fraction(int a)		//explicit Ű���带 ����Ͽ� ��ȯ ����� ���� �� ����.
		: numerator(a)
		, denominator(1)
	{
		cout << " conversion constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& frac)		//const Fraction frac��� copy constructor�� 2�� ��µ�.
	{
		out << frac.numerator << " / " << frac.denominator << endl;
		return out;
	}

private:
	int numerator;
	int denominator;
};

void PrintFraction(Fraction frac)
{
	cout << frac << endl;		
}

int main()
{
	Fraction frac1(10, 20);	//�Ϲ� ������
	Fraction frac2(frac1);	//���� ������

	//�ٸ� �ڷ����� ���͵� ���� ����ȯ�Ͽ� ������ ȣ��
	Fraction frac3(10);		//�˸��� �ڷ����� ���� ��ȯ ������ ȣ��
	Fraction frac4('a');	//�ڷ����� �ٸ� -> �Ͻ��� ����ȯ
	Fraction frac5(3.14f);	//����ȯ�� �Ǳ� ������ ������ �ս��� �Ͼ


	PrintFraction(frac1);

	//PrintFraction(10);		//explicit�� ����ߴٸ� Ŭ���� ��ü�� �޾���� ��
	//PrintFraction(3.14f);

	return 0;
}