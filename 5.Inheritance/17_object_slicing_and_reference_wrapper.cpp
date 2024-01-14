/*
	Object Slicing - 객체 슬라이싱
	- 파생 클래스의 인스턴스를 기반 클래스의 인스턴스로 복사할 때 발생
	- 파생 클래스가 가진 정보가 손실된다.
*/

#include <iostream>
#include <vector>
#include <functional>		//reference_wrapper

using namespace std;

class Base
{
public:
	virtual void Print() { cout << "Base" << endl; }
public:
	int i = 0;
};

class Derived1 : public Base
{
public:
	virtual void Print() { cout << "Derived1" << endl; }
public:
	int j = 1;		//object slicing됨
};

class Derived2 : public Base
{
public:
	virtual void Print() { cout << "Derived2" << endl; }
public:
	int k = 1;		//object slicing됨
};

int main()
{
	//1. call by reference
	Derived1 d;
	//reference -> d를 Base 형태로 참조한 것
	//메모리는 그대로고 크기를 작게 쓰는 것
	Base& ref = d;
	ref.Print();

	//2. call by value
	//copy -> d의 Base부분만 복사해 새로운 메모리를 만듬
	//파생 클래스의 데이터 부분이 손실이 된다.
	Base base = d;	//object slicing
	base.Print();

	//3.
	// 손실없이 vector에 넣고 싶을 때
	Derived1 derived1;
	Derived1 derived2;
	Derived2 derived3;
	Derived2 derived4;

	//들어간 타입이 단순 base라, copy가 되어 관계가 깨진다.
	// 래퍼런스 형태로 넣어줘야 한다.
	//vector<Base> my_vec;	//자료 다 짤림

	// &는 백터에 안들어감 -> 쓰고싶으면 reference_wrapper나 포인터를 사용하자

	// * 사용 
	vector<Base*> my_vec1;

	my_vec1.push_back(&derived1);
	my_vec1.push_back(&derived2);
	my_vec1.push_back(&derived3);
	my_vec1.push_back(&derived4);

	for (auto& vec : my_vec1)
		vec->Print();


	// reference_wrapper 사용		//reference로 사용할 수 있도록 포장

	vector<reference_wrapper<Base>> my_vec2;

	my_vec2.push_back(derived1);
	my_vec2.push_back(derived2);
	my_vec2.push_back(derived3);
	my_vec2.push_back(derived4);

	for (auto& vec : my_vec2)
		vec.get().Print();

	return 0;
}

/*
   과제 : 슈팅 게임 만들기



   필요한 데이터

	미사일
	{
	  위치
	}

   적
   {
	  모델
	  위치
	  HP
   }

   플레이어
   {
	  모델
	  위치
	  HP
   }

   필요한 동작
   기본적인 게임 세팅
   이동(플레이어)
   이동(적)
   미사일 발사
   충돌 처리


   // 로직 순서

   //세팅
   게임 세팅

   // 업데이트
   플레이어 입력(이동, 발사);
   적 AI(이동, 발사)
   미사일 이동(적, 플레이어)
   충돌처리

   // 렌더
   플레이어
   적
   미사일
   벽(맵)
   플레이어 UI
   점수

   std::vector 사용해보기
*/