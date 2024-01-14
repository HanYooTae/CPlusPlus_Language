#include <iostream>
using namespace std;

class Won
{
public:
	Won(int value = 0) : value(value){}

	//�Ű������� ������ ����, ������ �����Ѵ�.
	//const�� ���� �� ������ ���̴°� ����
	Won operator -() const		//(Won& int a)		 
	{
		return -value;		//������ �������̱� ������ ����
	}

	bool operator !() const
	{
		return value == 0 ? true : false;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

private:
	int value;
};

int main()
{
	const Won w1(10);
	const Won w2{ 0 };

	cout << w1 << endl;
	cout << w2 << endl;

	cout << -w1 << endl;

	cout << boolalpha << endl;		//0�� 1�� false true�� ���
	cout << !w1 << endl;
	cout << !w2 << endl;

	return 0;
}