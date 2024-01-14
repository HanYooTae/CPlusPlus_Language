#include <iostream>
using namespace std;

//#define case_1
#define case_2

#ifdef case_1

class Won
{
public:
	Won(int value) : value(value) {}		//Won�ν��Ͻ��� Won�̶�� �ڷ��� Ÿ���̶�� �����ϸ� ����
	int GetValue() { return value; }

private:
	int value;

	friend int operator+(const Won& lhs, const Won& rhs);
	friend Won operator-(const Won& lhs, const Won& rhs);
};

int operator+(const Won& lhs, const Won& rhs)
{
	return lhs.value + rhs.value;
}

Won operator-(const Won& lhs, const Won& rhs)
{
	//���� ���� �˸´� ������ �����ڰ� ���� �� ����
	return lhs.value - rhs.value;
}

int main()
{
	Won l(10), r(20);

	int result = l + r;
	cout << result << endl;

	Won result2(l - r);
	cout << (l - r).GetValue() << endl;
	//cout << result2 << endl;		//error ���߿� ����

	return 0;
}

#endif // case_1


#ifdef case_2
class Won
{
public:
	Won(int value) : value(value) {}		//Won�ν��Ͻ��� Won�̶�� �ڷ��� Ÿ���̶�� �����ϸ� ����
	int GetValue() { return value; }

	//this + rhs
	//l + r�� �Ѵٸ� ���������� l.operator+(r)�� ó���ȴ�.
	int operator+(const Won& rhs)
	{
		return value + rhs.value;	//l + r
	}

	Won operator-(const Won& rhs)
	{
		return value - rhs.value;
	}

private:
	int value;

};


int main()
{
	Won l(10), r(20);

	int result = l + r;
	cout << result << endl;
	cout << l.operator+(r) << endl;		//l.operator(r)�� int operator+�� �ǹ�

	Won result2(l - r);
	cout << (l - r).GetValue() << endl;


	return 0;
}
#endif // case_2

/*
	���� : ������ �����ε� �غ���
	*, /, %, +=, -=, *=, /=, %=
*/