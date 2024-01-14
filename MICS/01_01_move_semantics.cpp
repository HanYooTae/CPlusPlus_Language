/*
	스마트 포인터
	- 포인터처럼 동작하는 클래스 템플릿.
	- 허상 포인터, 메모리 누수를 관리하기 위해 등장
	- memory 헤더에 포함되어있음

	스마트 포인터의 종류
	- auto_ptr
	- unique_ptr
	- shared_ptr
	- weak_ptr
*/

#include<iostream>
#include<memory>
#include"01_02_resource.h"
#include"01_03_auto_ptr.h"
using namespace std;

/*
	RAII : Resource Acquisition is initialization
	- 생성한 지역에서 삭제하는 것
	- RAII 원칙이 스마트 포인터에 적용되어있다.
*/

// RAII 원칙이 지켜지지 않았을 때
void DoSomething1()
{
	Resource* resource = new Resource;
	// *resource : new Resource(재할당한 데이터)의 메모리/주소에 접근

	// ...
	// early return -> 메모리 누수 발생
	//if (true) return;		// Resource*는 사라지지만 동적할당한 데이터는 사라지지 않음
	// ...

	// 해결법1 : 리턴하는 곳마다 해제
	// 단점 : 해제 코드를 추가하지 않는 실수를 할 수 있다.
	// -> 해당 영역을 벗어날 때 자동으로 해제되게 하고 싶다. -> 스마트 포인터
	if (true)
	{
		delete resource;
		return;
	}

	delete resource;
}

// 해결법 2 : 소멸자에서 해제하기
// 객체가 소멸하면서 소멸자가 호출된다.
// 그러므로 소멸자에 동적해제를 시켜주는 코드를 추가하여
// 동적 데이터를 본인이 소멸할 때 자동으로 삭제하도록 함
// -> 스마트 포인터의 원리
void DoSomething2()
{
	AutoPtr<Resource> resource(new Resource);

	// 위의 resource 객체 자체는 지역 변수이기 때문에
	// 함수가 종료될 때 자동으로 소멸자가 호출된다.
	if (true) return;
}

void DoSomething3(AutoPtr<Resource> temp)
{

}

int main()
{
	// 지역을 벗어날 때 자동으로 소멸시킨다.

	cout << "{" << endl;
	AutoPtr<Resource> res = new Resource;
	cout << "}" << endl;

	// 스마트 포인터 주의점
	AutoPtr<Resource> res1 = new Resource;

	// .연산자를 통해 나오는 것은 스마트 포인터 클래스의 멤버
	//res1.Test();

	// 소유한 포인터의 멤버에 접근하기 위해서는 -> 연산자를 통해 접근해야 함
	//res1->~Resource();


	// AutoPtr의 문제점
	AutoPtr<Resource> res2 = new Resource;

	// 1 : auto_ptr이 가진 포인터의 소유권이 넘어가버린다.
	DoSomething3(res2);

	//res2->;		// res2가 가지고 있는 주소가 nullptr이 되어 문제 발생

	// 2 : autoptr은 배열 단위의 생성, 해제를 지원하지 않음.
	// delete만 있고 delete[]은 없음
	

	return 0;
}