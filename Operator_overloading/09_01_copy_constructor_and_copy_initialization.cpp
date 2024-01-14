//���Կ����� ó��
//�������� �ʾƵ� �ڵ� �����Ǵ� �Ͻ��� �޼ҵ�

#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
public:
	Fraction(int num = 0, int den = 0)
		: numerator(num)
		, denominator(den)
	{
		cout << "constructor!!" << endl;
	}

	//copy constructor
	Fraction(const Fraction& fraction)
	{
		cout << "copy constructor!!" << endl;
	}

	//copy_operator =
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operation" << endl;
		return *this;
	}

private:
	int numerator;
	int denominator;
};

Fraction CreateFraction()
{
	Fraction temp(5, 2);		//constructor
	return temp;				//copy constructor �޽��� �߻�
	//RVO, NRVO ����ȭ�� �ذ� ����
}

int main()
{
	Fraction frac(3, 5);

	Fraction copy1(frac);	//copy_initialization
	Fraction copy2;			//copy_initialization
	// ���� �������� copy1(frac)�� �����ϴ�, ȥ���ǹǷ� ������� �ʴ°� ����.

	copy2 = frac;			//copy_operator =

	cout << "##############" << endl;
	CreateFraction();

	return 0;
}