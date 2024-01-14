/*
	Inheritance - 상속
	- 다른 클래스의 내용을 그대로 포함할 수 있는 기능
	- 공통된 동작을 모듈화하여 코드를 재사용하기에 유리하다.
	- 하생 클래스를 만들어 기반 클래스의 기능을 수정/확장하기에 유리
	- 코드의 중복을 줄여 간소화할 수 있다.
*/
#include <iostream>
using namespace std;

//Base class - 기반 클래스
class Mother
{
public:
	int GetA() const
	{
		cout << "mother" << endl;
		return a;
	}

	void SetA(const int& a) { this->a = a; }

private:
	int a;

protected:
	int b;

public:
	int c;
};

//Derived class - 파생 클래스, 기반 클래스의 내용을 그대로 물려받음
class Daughter : public Mother
{
public:
	//기반 클래스의 private멤버는 상속되어도 접근 불가능
	//자식에서는 protected나 public만 접근 가능
	//int GetA() const { return a; }	//error

	int GetA() const
	{
		//부모의 멤버를 그대로 사용가능 -> 다중 상속 시에는 모호할 수 있음
		//다중상속 - 한 클래스가 한 번에 두 개 이상의 클래스를 상속받는 것
		c;			//Mother::c

		//기반/파생 클래스의 멤버가 겹칠 경우, 파생 클래스의 멤버가 우선시된다.
		b;			//Daughter::b
		//네임스페이스를 사용하여 구분가능
		Mother::b;

		cout << "Daughter" << endl;

		return Mother::GetA();
	}

	//__super로 부모 클래스 표현 가능, VC전용 키워드
	int GetAA() const { return __super::GetA(); }

private:
	int b;
};

int main()
{
	//인스턴스화할 때 상속받은 클래스가 존재한다면
	//최상위 클래스부분부터 생성됨	(우선시되는 거랑 호출되는 것은 다른 것)
	//Mother 생성 -> Daughter 생성
	Daughter d;

	//기반 클래스 Mother로부터 상속받은 멤버 함수 SetA 호출
	d.SetA(10);

	//기반 클래스와 파생 클래스에 서로 이름이 겹치는 멤버가 있을 경우,
	//사라지는게 아니라 자신의 것이 우선이다.
	d.GetA();

	cout << "1####################" << endl;

	//숨겨진 기반 클래스의 멤버를 사용하고 싶다면
	d.Mother::GetA();

	return 0;
}