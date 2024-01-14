/*
	Overriding
	- 파생 클래스가 상속받은 기반 클래스의 메서드를 파생 클레스에서 새로 정의하는 것
	
	- 리턴 타입과 인자 구성이 서로 같아야 한다.

	- 오버라이딩된 기반 클래스의 함수는 가려지고 파생 클래스의 함수가 호출이 된다.
		ㅁ 기반 클래스의 함수를 범위 지정 연산자(namespace)로 호출은 가능하다.

	- 단순히 함수 오버라이딩을 할 경우, 업캐스팅 시 파생 클래스의 함수가 아닌 기반 클래스의 함수가 호출된다.
	  그 이유는, C++컴파일러가 실제로 가리키는 객체의 자료형을 기준으로 하는게 아니라 포인터 변수의 자료형을 기준으로 하기 때문이다.

	- virtual
		ㅁ 자신을 호출하는 객체의 실제 타입에 따라 호출할 함수를 결정하게 해준다.
		ㅁ 기반 함수에만 키워드를 추가해도 된다. -> 파생 클래스에서는 생략 가능
*/

#include <iostream>
using namespace std;


class A
//class A final		//클래스 A를 상속하고 싶지 않다면 final키워드를 추가한다.
// final : 클래스를 상속시킬 수 없게 제한하는 키워드
// 메서드에 붙이면 해당 메서드가 오버라이딩되지 않게 제한한다.
//상속 관계의 끝을 의미
{
public:
	virtual void Print(int x) { cout << "A" << endl; }		//가상 함수
};

class B : public A		//상속할 클래스에 final키워드가 있다면 상속을 할 수 없다.
{
public:
	//보이지 않지만, 상위 클래스함수에 virtual을 넣었다면 자동으로 넣어짐. 그래도 가독성을 위해 virtual을 붙여주자
	/*virtual*/ void Print(/*short*/int x) override { cout << "B" << endl; }		//overriding : 같은 함수를 재정의하는 것, virtual까지 붙여야 정확한 오버라이딩
	
	//오버라이딩은 자료형까지 일치해야 함(프로토타입이 일치해야 오버라이딩이 됨
	//-> 부모의 함수를 재정의하는 것이기 대문에 형태가 같아야 함(안에 있는 구현만 달라지는 것)
	//매개변수를 다르게 할 경우 컴퓨터는 오버로딩으로 인식한다.
	
	/*
		override - 오버라이드
		- 파생 클래스에서 재정의한 함수에 붙인다.
		- overriding이 가능한 함수인지 판단해주고(맞는 형태가 있는지) 없다면 error를 방생시킴
		- overriding이 된 함수임을 명시적으로 표시한다. -> 코드 가독성이 좋아짐
	*/

	//메서드에 final 키워드를 추가하면 해당 클래스를 상속시켜줄 경우
	//파생 클래스에서 오버라이딩을 할 수 없다.
	//virtual void Print(int x) override final { cout << "B" << endl; }
};

class C : public B
{
public:
	void Print(int x) override { cout << "C" << endl; }
};



int main()
{
	A a;
	B b;
	C c;

	a.Print(0);
	b.Print(0);
	c.Print(0);

	cout << endl;

	A& ab = b;
	A& ac = c;

	a.Print(0);
	ab.Print(0);
	ac.Print(0);

	cout << endl;

	A* a_array[]{ &a, &b, &c };

	for (auto ele : a_array)
		ele->Print(0);

	return 0;
}