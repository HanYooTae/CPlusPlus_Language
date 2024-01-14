#include <iostream>
using namespace std;

//상속할 클래스라면 소멸자에는 virtual을
//상속하지 않을 클래스라면 final 붙이기
class Base
{
public:
	//1. 업 캐스팅 시 파생 클래스의 소멸자가 호출 안됨
	//~Base() { cout << "~Base()" << endl; }
	
	//2. virtual 키워드를 사용하여 각 객체에 맞는 소멸자가 호출되도록 함
	virtual ~Base() { cout << "~Base()" << endl; }		//오버헤드가 되긴 하지만 best 방법
};

class Derived : public Base
{
public:
	~Derived() 
	{
		cout << "~Derived()" << endl;
		//arr멤버 동적 해제
	}

private:
	int* arr = nullptr;		//동적 할당받은 멤버는 특수한 경우가 아니면 소멸자에서 해제함
};

int main()
{
	{
		Derived b;
	}

	cout << "1###############" << endl;

	//상위 클래스로 업 캐스팅한 상태에서 파생 클래스를 삭제할 때
	//소멸자를 가상 함수로 지정하지 않으며 파생 클래스의 소멸자가 호출안되는 문제가 발생
	//-> 파생 클래스에서 소멸자에서 중요한 작업을 해준다면 해당 작업이 실행되지 않고 무시된다.
	//따라서 상속하는 부모 클래스의 소멸자는 virtual을 붙이도록 하자		-> virtual을 붙이면 약간의 메모리가 늘어나긴 함
	{
		Base* base = new Derived;

		delete base;
	}

	return 0;
}