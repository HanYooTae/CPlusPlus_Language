/*
	special member function - 특수 멤버 함수
	- 자동으로 작성되는 함수 6가지
	- 각 함수는 명시적으로 작성하지 않을 경우 자동으로 작성
	- 각 종류/함수별로 특정 조건에 의해 자동 작성이 되지 않을 수 있다.

	메서드 종류

	default constructor - 기본 생성자
	- 작성한 생성자가 하나라도 없을 때 작성된다.
	- 아무런 기능이 없다.

	destructor - 소멸자
	- 소멸자를 작성하지 않을 경우 자동 작성된다.

	copy constructor/assignment operator - 복사 생성자/대입 연산자
	- 둘 중 하나라도 작성되어 있을 경우, 다른 하나는 작성X
	- move constructor/assignment operator가 하나라도 작성되어 있다면, 작성X

	move constructor/assignment operator - 이동 생성자/대입 연산자
	- 둘 중 하나라도 작성되어 있을 경우, 다른 하나는 작성X
	- copy constructor/assignment operator가 하나라도 작성되어 있다면, 작성X
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

	//Lvalue를 받았을 때
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

	//일반 생성자에서 파라미터로 int val만 추가
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
	//소멸자 호출은 생성의 역순
	//-> 가장 먼저 생성된 인스턴스일수록 이후의 인스턴스들과 관계를 맺고있을 가능성이 크기 때문에
	//생성된 역순으로 해제해주는게 안전하다.
	cout << "1########################" << endl;
	Test t1;
	Test t2(2);

	//Test t3 = t1;	//복사 생성자 호출 but 권장하는 방법이 아님
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