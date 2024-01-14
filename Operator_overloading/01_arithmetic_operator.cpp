#include <iostream>
using namespace std;

//#define case_1
#define case_2

#ifdef case_1

class Won
{
public:
	Won(int value) : value(value) {}		//Won인스턴스를 Won이라는 자료형 타입이라고 생각하면 편함
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
	//리턴 값에 알맞는 적절한 생성자가 있을 시 가능
	return lhs.value - rhs.value;
}

int main()
{
	Won l(10), r(20);

	int result = l + r;
	cout << result << endl;

	Won result2(l - r);
	cout << (l - r).GetValue() << endl;
	//cout << result2 << endl;		//error 나중에 배울거

	return 0;
}

#endif // case_1


#ifdef case_2
class Won
{
public:
	Won(int value) : value(value) {}		//Won인스턴스를 Won이라는 자료형 타입이라고 생각하면 편함
	int GetValue() { return value; }

	//this + rhs
	//l + r을 한다면 내부적으로 l.operator+(r)로 처리된다.
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
	cout << l.operator+(r) << endl;		//l.operator(r)은 int operator+를 의미

	Won result2(l - r);
	cout << (l - r).GetValue() << endl;


	return 0;
}
#endif // case_2

/*
	과제 : 연산자 오버로딩 해보기
	*, /, %, +=, -=, *=, /=, %=
*/