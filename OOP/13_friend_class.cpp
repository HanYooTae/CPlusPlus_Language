#include <iostream>

using namespace std;

/*
	friend
	- 외부에서 클래스의 private, protected 멤버에 접근할 수 있게 해주는 키워드
	- 정보를 접근하게 해줄 쪽에서 선언한다. -> 단방향
	- friend는 상속되지 않는다.
*/

/*
	A(B에 접근가능)

	B(A에 접근불가능)
*/

//#define friend_global_function
//#define friend_member_class
#define friend_class

#ifdef friend_global_function
/*
	전역 함수에서 클래스에 접근하는 경우
*/

class A
{
private:
	//1.
	//friend키워드를 사용하면 전역함수에서 private에 속한 멤버에 접근가능하다.
	friend void do_something1(A& a);		//클래스 내부에 어디에든 있다면 상관없음

	//2.
	//바로 함수의 정의부를 만들어도 된다. (밖에 쓰나 안에 쓰나 같다.)
	//내부에 구현해도 전역함수 취급
	friend void do_something2(A& a)
	{
		cout << a.value << endl;
	}

	//friend int main();					main도 가능

private:
	int value = 1;
};

void do_something1(A& a)
{
	cout << a.value << endl;
}

int main()
{
	A a;
	do_something1(a);
	do_something2(a);

	return 0;
}

#endif

#ifdef friend_member_class
/*
	타입이 다른 클래스의 특정 멤버 함수가 접근하는 경우
*/

//전방 선언
//뒤에 작성한 코드를 앞의 코드에서 인지시키고 싶을 때 사용
//전방 선언을 해주어야 class A에서 class B의 존재를 인식할 수 있다.
class B;

//전방 선언을 했을 때는 B의 존재유무만 알 뿐 내부는 모른다.
//-> B의 실제 메모리를 잡을 수 없어서 error
//B b;

//B* b1;						//포인터는 됨 -> 실제 B인스턴스를 생성하는게 아니기 때문에 가능

//class B* b2;					//전방 선언과 동시에 사용 가능

class A
{
public:
	void attack(B& b);		//B를 전방선언해줘야 class B가 인지가 됨
	//전방선언으로 class의 존재유무만 알고 있을 뿐, 실제 내부는 알 수 없다. -> error
	//프로토타입과 정의부를 분리해 해결 -> 해당 함수의 정의부를 class B를 정의한 부분 아래에 두어야 함
	/*{
		cout << "b의 hp : " << b.hp << endl;

		cout << "공격!" << endl;
		b.hp -= 10;

		cout << "b의 hp : " << b.hp << endl;
	}*/
};

class B
{
	//class B에서 class A의 멤버 함수 attack에서 자신의 모든 멤버에 접근 가능하도록 허용
	friend void A::attack(B& b);
private:
	int hp = 100;
};




int main()
{
	A a;
	B b;

	a.attack(b);

	return 0;
}

void A::attack(B& b)
{
	cout << "b의 hp : " << b.hp << endl;

	cout << "공격!" << endl;
	b.hp -= 10;

	cout << "b의 hp : " << b.hp << endl;
}

#endif // friend_member_class

#ifdef friend_class
/*
   타입이 다른 클래스의 모든 영역에 접근 하려고할때
*/

class A
{
public:
	void Print_B_value1(class B& b);		//파라미터에 class B& b를 작성하면, 아래부터 선언되는 함수들의 파라미터는
											//class를 제외한 B& b만 작성해도 전방선언으로 인하여 문제없이 실행됨.
	void Print_B_value2(class B& b);
};

class B
{
public:
	// class A에서 B의 모든 멤버에 접근 가능
	// B에서 A의 접근은 안됨 -> 단뱡향
	friend class A;

private:
	int value1;
	int value2;
};
void A::Print_B_value1(B& b)
{
	b.value1 = 1;
	cout << "value1 : " << b.value1 << endl;
}

void A::Print_B_value2(B& b)
{
	b.value2 = 2;
	cout << "value2 : " << b.value2 << endl;
}

int main()
{
	A a;
	B b;
	a.Print_B_value1(b);
	a.Print_B_value2(b);

	return 0;
}

#endif // friend_class
