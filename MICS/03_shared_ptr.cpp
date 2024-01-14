/*
	shared_ptr
		- 유니크 포인터와 달리 소유권 공유가 가능한 포인터
		- 포인터를 함수에 자주 전달해야할 때 유니크 포인터 대신 사용하기 적합
		- 참조 카운팅 방식을 사용한다.
			ㄴ 해당 dull pointer를 소유하고 있는 스마트 포인터 개수를 카운팅하여
			   마지막 스마트 포인터가 소멸할 때 해제해주는 방식
*/

#include <iostream>
#include <memory>
#include "02_02_resource.h"
using namespace std;

int main()
{
	{
		// res1이 생성되며 카운트 0 -> 1 증가
		auto res1 = std::make_shared<Resource>(5);

		// use_count() : 현재 자신이 소유한 dull pointer를 소유하고있는 스마트 포인터의 수
		cout << "Count : " << res1.use_count() << endl;

		{
			// res1이 소유한 dull 포인터를 res2가 공유받는다, 카운트 증가 1 -> 2
			auto res2 = res1;

			cout << "Count : " << res2.use_count() << " " << res1.use_count() << endl;
		}	// res2 소멸, 카운트 감소 2 -> 1, 아직 nullptr를 소유한 스마트 포인터가 있어 해제X

		cout << "Count : " << res1.use_count() << endl;
	}	 // res1 소멸, 카운트 감소 1 -> 0, dull 포인터를 소유한 마지막 스마트 포인터가 소멸하여 dull pointer 해제 O

	// 주의점
	Resource* ptr = new Resource(10);

	{
		// res1이 생성되면서 카운트 증가 0 -> 1
		std::shared_ptr<Resource> res1(ptr);

		cout << "Count : " << res1.use_count() << endl;
		{
			// res2가 생성되면서 카운트 증가 0 -> 1
			std::shared_ptr<Resource> res2(ptr);

			// res1과 연관이 없으므로 count : 1 출력
			cout << "Count : " << res2.use_count() << endl;
		}	//res2 소멸, 카운트 감소 1 -> 0, 마지막 스마트 포인터가 소멸하여 소유한 dull pointer 해제

		// 카운트가 1 출력
		cout << "Count : " << res1.use_count() << endl;
	}	//res2 소멸, 카운트 감소 1 -> 0, 마지막 스마트 포인터가 소멸하여 소유한 dull pointer 해제
	// 하지만 res2에서 먼저 해당 포인터를 해제함 -> 허상 포인터 문제 발생

	return 0;
}