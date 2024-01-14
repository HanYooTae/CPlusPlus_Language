#include<iostream>
using namespace std;

//클래스 내의 함수들은 크기를 가지지 않는다.
class A
{
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A destructor" << endl; }

private:
	int a;
};

class B : public A
{
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B destructor" << endl; }

private:
	double b;
	int c;
};

int main()
{
	// 생성순서는 기본 클래스 먼저
	// 소멸순서는 파생 클래스 먼저
	// 먼저 생성된 객체는 더 많은 관계를 가지고 있어 
	// 먼저 삭제하면 문제가 생길 수 있다.
	B b;

	/*
		패딩
		- 클래스나 구조체의 패딩 바이트를 추가하여 CPU가 접근하기 용이하게 해주는 기법
		- CPU가 데이터를 읽을 때 자료형이 잘려 같은 데이터에 두 번 접근하는 것을 방지.
		- 일반적으로 가장 큰 멤버 변수의 크기에 맞춰 패딩 바이트를 추가한다.
	*/
	//padding : 쓰레기 공간을 넣어주는 것

	sizeof(A);		//int 하나 -> 4바이트
	sizeof(B);		//A에 int, double -> 패딩때문에 크기가 16바이트가 됨.

	class P1
	{
		char c;
		short s1;
		short s2;
	};
	// c ㅁ s1 s1 s2 s2

	class P2
	{
		short s1;
		int i;
		double d;
		char c;
	};
	// s1 s1 i i i i ㅁ ㅁ d d d d d d d d c ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ

	sizeof(P1);		//가장 큰 자료형 short를 기준으로 패딩 -> 2바이트 패딩
	sizeof(P2);		//가장 큰 자료형 double를 기준으로 패딩 -> 8바이트 패딩
	sizeof(P3);		//가장 큰 자료형 double를 기준으로 패딩 -> 8바이트 패딩

}

/*
	패딩 규칙 찾아보기
*/

/*
	과제 : 아래 구조체의 사이즈를 최소로 만들기
*/

struct P3
{
	char c1;
	double d1;
	char c2;
	double d2;
	char c3;
	int i1;
	int i2;
	double d3;
};