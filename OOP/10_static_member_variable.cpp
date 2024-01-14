//https://boycoding.tistory.com/169
// 10_static_member_variable.cpp

/*
	static member vairable
	- 클래스 내부에 하나만 존재하는, 크랠스의 모든 객체가 공유하는 변수
	- 선언은 클래스에서, 초기화는 소스파일(.cpp, .c)에서 해주어야 한다.(중요!)
*/

#include<iostream>
using namespace std;

class Test
{
public:
	// 컴파일은 되는데 실체가 없기에 링크 x -> 정의부 선언해야 함.
	void Add();

	int value = 1;

	//static int count = 10; // error
	// 이 안에 있는 static은 프로그램 시작과 동시에 메모리가 생성되어야 한다.
	// 그러나 class 상상의 개념 -> 여기서는 그저 선언만 되고 초기화가 되지 않음
	// -> 실 메모리에 올라갈 수 없다.
	static int count;

	// const가 붙으면 선언과 동시에 초기화 되기 때문에 가능하다.
	static const int test = 10;

private:
};

// define int cpp -> 헤더 파일에서 초기화할 경우 error가 발생할 확률이 높다. -> 여러 소스파일에서 중복 정의가 될 수 있음
int Test::count = 10;

int main()
{
	// 인스턴스를 만들지 않아도 존재하므로 따로 사용이 가능
	cout << &Test::count << ", " << Test::count << endl;

	Test t1, t2;
	
	t1.value = 10;
	t2.value = 20;

	cout << "value" << endl;
	cout << & t1.value << ", " << t1.value << endl;
	cout << &t2.value << ", " << t2.value << endl;

	t1.count = 30;
	t2.count = 40;

	cout << "count" << endl;
	cout << &t1.count << ", " << t1.count << endl;
	cout << &t2.count << ", " << t2.count << endl;

	t1.Add();		//LNK에러 -> 링크에러

	return 0;
}

/*
	과제 : 싱글톤 패턴 조사하기
*/

void Test::Add()
{
	//cout << "test" << endl;
}
