/*
	unique_ptr
		- 특정 개체를 하나의 스마트 포인터만 소유권을 가지게 하는 스마트 포인터
		- auto_ptr의 문제점을 개선함
		- unique_ptr이 소멸할 때, 자신이 소유한 dull 포인터를 해제한다.
			ㅁ dull pointer : 스마트 포인터가 소유한 원시 포인터
*/

#include <iostream>
#include <memory>
#include "02_02_resource.h"
using namespace std;

std::unique_ptr<Resource> DoSomething(std::unique_ptr<Resource> res)
{
	res->SetAll(10);
	res->Print();

	return res;
}

int main()
{
	// 1
	{
		// 이동 대입, 이동 생성자 사용 가능
		// res1이 빠르게 생성되었지만 new Resource(5)(동적 할당)가 늦게 생성되는 생성 시점이 맞지 않아 예상치 못한 문제 발생 가능
		// 스마트 포인터 자체는 빠르게 만들어지는데 소유할 동적 데이터는 느리기 때문에 동적 할당을 할 때는 make_함수를 사용
		std::unique_ptr<Resource> res1(new Resource(5));		// 다이렉트 초기화

		// 하나만 존재해야 하기 때문에 복사가 되면 안됨
		//std::unique_ptr<Resource> res2 = new Resource(5);		// 복사 초기화



		// make_스마트 포인터 : 안전하게 객체를 할당해주도록 하는 함수, 내부적으로 동적 할당을 해준다.
		// 생성 시점을 알아서 맞춰줌
		std::unique_ptr<Resource> res3 = std::make_unique<Resource>(5);

		res3->SetAll(5);
		res3->Print();

		//res3 = res1;	// 복사 대입 X
		res3 = std::move(res1);		// r-value 형태로 바꿔 이동 연산자를 호출해주어야 한다.

		// res1은 res3로 소유권을 옮겼기 때문에 소유권 상실. 그 후에 접근 시도하면 에러 발생
		res1->Print();
	}

	// 2
	{
		auto res1 = std::make_unique<Resource>(5);
		res1->SetAll(5);
		res1->Print();

		// 레퍼런스로 넘기지 않을 경우 복사가 되기 때문에 에러
		//DoSomething(res1);		// copy

		// r-value 형태로 넘기면 가능
		// 이동 생성자(소유권을 빌려줬다가 다시 본인이 받는 형태
		// 반환 값으로 다시 소유권을 받아주어야 데이터가 해제되지 않음
		res1 = DoSomething(std::move(res1));

		// 2.
		// dull pointer 형태로 데이터를 꺼내 r-value형태로 만들어 보냄
		DoSomething(make_unique<Resource>(res1.get()));

		// get() : 스마트 포인터가 가지고 있는 실질적인 dull pointer를 반환
	}

	// 3
	{
		// dull pointer와 스마트 포인터를 섞어서 사용하면 발생하는 문제점
		Resource* res = new Resource(5);

		// res가 소유한 주소를 넘겨준다. res는 스마트 포인터가 아니기 때문에 소유권을 상실하지 않는다.
		// -> unique_ptr은 한 객체에 대하여 하나의 포인터만 존재해야 하는데, 2개 이상의 포인터가 소유하게 됨
		std::unique_ptr<Resource> res1(res);
		
		// 중간에
		// res1 = nullptr;	// 이걸 넣어줄 경우, nullptr로 초기화 해주기 때문에 문제가 발생하지 않음

		// res1과 res2가 같은 주소를 소유하게 된다.
		std::unique_ptr<Resource> res2(res1.get());		// res1.get() = res

		/*
			해당 지역을 벗어나면 res1과 res2 소멸 -> 둘 다 자기가 소유한 res의 주소를 해제
			같은 주소를 2번 해제하려고 시도함 -> 허상 포인터 문제 발생
			그렇기 때문에 dull 포인터와 스마트 포인터를 섞어쓰는 것은 좋지 않음
		*/
	}


//class a
//{
//public:
//	a(int* data) : data(data) {}
//	a(const a& data) {}
//public:
//	int* data;
//};
//
//int* data = new int;
//
//a test(data);
//a test2(test);
//a test3(test.data);

	return 0;
}