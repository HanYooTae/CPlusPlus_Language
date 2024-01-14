#include <iostream>
#include <functional>

using namespace std;

/*
	static_member_function
	- 클래스의 객체를 생성하지 않고도 클래스의 이름만으로 호출이 가능한 함수
	- 객체가 없으므로 this 포인터 사용이 안되고 정적 멤버 변수만 사용 가능하다.
	- const 함수로 만들 수 없다.
*/

class Test
{
public:
	void Temp1() { this->value1; }				//__this call형식이기 때문에 가능
	
	//__this call 방식이 아님. __standard call임.
	//그냥 클래스 카테고리에 포함된 전역 함수와 비슷하다.
	//static void Temp2() { this->value1; }		//error, this 사용 불가능
	//static void Temp2() const { this->value1; }		//error, 상수화시킬 멤버변수가 없음
	static void Temp2() { value2; }
	int temp1(int value) { this->value1 = value; }
	//mutable있으면 수정 가능
	//int temp2(int value) const { this->value1 = value; }
	static int temp3(int value) { value2 = value; }

private:
	/*mutable*/ int value1;
	static int value2;

public:
	int test;
};

int main()
{
	//Test::Temp1();		//__this call방식이기 때문에 인스턴스를 통해 호출해야 한다.
	Test t1;
	t1.Temp1();
	
	t1.Temp2();
	Test::Temp2();		//__this call이 아니기 때문에 인스턴스없이 호출이 가능

	//일반 함수와 같아 가능
	void (*ptr1)() = Test::Temp2;

	//__this call방식의 함수는 일반적인 형태의 함수포인터에 담을 수 없다.
	//void (*ptr1)() = Test::Temp1;

	/*
		멤버 포인터
		- 특정 클래스에 속한 멤버를 가리키는 포인터
		- 멤버 포인터를 사용해 멤버 함수를 넣을 수 있다.
		- 특정 인스턴스화된 멤버의 위치가 아닌 멤버가 클래스에
		  존재하는 상대적인 위치를 가지기 때문에 사용하기 위해선 실체를 넣어줘야 한다.
		- 주소에 접근할 때 (.*) 연산자를 사용한다.
		- 기본 포인터 형식에서 네임스페이스를 추가해주면 된다.

		멤버변수 포인터
		자료형 클래스이름::*포인터이름 = &클래스이름::변수이름

		멤버함수 포인터
		반환값 (클래스이름::*함수포인터이름) = &클래스이름::함수이름;
	*/

	//멤버변수 포인터
	int Test::*ptr3 = &Test::test;
	t1.*ptr3 = 10;		//멤버 포인터는 사용시 인스턴스가 필요

	//멤버함수 포인터
	void (Test::*ptr4)() = &Test::Temp1;
	(t1.*ptr4)();

	//functional을 사용한 멤버함수 포인터
	std::function<void(Test)> fp = &Test::Temp1;
	fp(t1);
	std::function<void()> fp1 = Test::Temp2;
	fp1();
	
	return 0;
}