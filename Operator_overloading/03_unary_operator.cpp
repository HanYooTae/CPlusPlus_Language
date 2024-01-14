#include <iostream>
using namespace std;

class Won
{
public:
	Won(int value = 0) : value(value){}

	//매개변수의 개수로 이항, 단항을 구분한다.
	//const는 붙일 수 있으면 붙이는게 안전
	Won operator -() const		//(Won& int a)		 
	{
		return -value;		//정수형 생성자이기 때문에 가능
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

	cout << boolalpha << endl;		//0과 1을 false true로 출력
	cout << !w1 << endl;
	cout << !w2 << endl;

	return 0;
}